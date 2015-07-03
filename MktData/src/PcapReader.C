#include <iostream>
#include <fstream>

#include <netinet/in.h>
#include <netinet/ip.h>
#include <net/if.h>
#include <netinet/if_ether.h>
#include <netinet/udp.h>

#include "PcapReader.H"

PcapReader::
PcapReader(std::string& fname_)
  : _fname(fname_)
{}

PcapReader::
~PcapReader()
{}

void PcapReader::
init()
{
}

void PcapReader::
run()
{
  std::ifstream ifl(_fname.c_str(), std::ifstream::in|std::ifstream::binary);

  if (!ifl) {
    std::cerr << "PcapReader::run. Unable to open input file: " << _fname << std::endl;
    return;
  }

  PcapHeader hdr;
  PcapPktHeader pktHdr;

  // Read file header
  if (!ifl.read((char*)&hdr, sizeof(PcapHeader))) {
    std::cerr << "PcapReader::run. Unable to read file header: " << _fname << std::endl;
    ifl.close();
    return;
  }

  uint64_t bread=0; // No of bytes read
  uint64_t maxBufLen = hdr._snapLen; // Max buffer length
  char* buffer = new char[maxBufLen];
  uint64_t blen;
  int rv;

  while (ifl) {

      // read packet header
      if (!ifl.read((char*)&pktHdr, sizeof(PcapPktHeader))) {
        std::cout << "PcapReader::run. Cant rad PcapPktHeader." << std::endl;
        ifl.close();
        return;
      }
      bread += ifl.gcount();

      blen = pktHdr._incLen;
   
      // read the packet
      if (!ifl.read(buffer, blen)) {
          std::cout << "PcapReader::run. Cant read packet" << std::endl;
          ifl.close();
          return;
      }
      rv = ifl.gcount();
      bread += rv;

      // Parse the packet to remove all Network headers
      handlePacket(buffer, blen);
  }

  ifl.close();

  std::cout << "PcapReader::run. Close file and exit..." << std::endl;
}

void PcapReader::
handlePacket(char* buff_, uint64_t blen_)
{
  struct ether_header*  ethHdr;
  struct ip*            ipHdr;
  struct udphdr*        udpHdr;

  uint64_t slen;

  // Read ether_header
  slen = sizeof(struct ether_header);
  if (blen_<slen) {
    std::cout << "PcapReader::handlePacket. PacketLen less than ether_header" << std::endl;
    return;
  }
  ethHdr = reinterpret_cast<struct ether_header*>(buff_);
  if (ethHdr->ether_type != 0x08) {
    // std::cout << "handlePacket. ether_type: " << ethHdr->ether_type << ", " << (uint16_t)ETHERTYPE_IP << std::endl;
    return;
  }

  blen_ -= slen;
  buff_ = (char*)(buff_+slen);

  // Read ip header
  // We handle only UDP packets
  if (blen_<sizeof(struct ip)) {
    std::cout << "PcapReader::handlePacket. PacketLen less than struct ip" << std::endl;
    return;
  }
  ipHdr = reinterpret_cast<struct ip*>(buff_);
  slen = ipHdr->ip_hl*4; // header length in 4 bytes words
  if (blen_<slen) {
    std::cout << "PcapReader::handlePacket. PacketLen less than struct ip.hl: " << slen << std::endl;
    return;
  }

  if (ipHdr->ip_p != IPPROTO_UDP) {
    std::cout << "PcapReader::handlePacket. Not UDP protocol. proto: " << (int)ipHdr->ip_p << std::endl;
    return;
  }

  blen_ -= slen;
  buff_ = (char*)(buff_+slen);

  // Read UDP header 
  slen = sizeof(struct udphdr);
  udpHdr = reinterpret_cast<struct udphdr*>(buff_); 

  blen_ -= slen;
  buff_ = (char*)(buff_+slen);

  // firing cb
  if (_f != nullptr) {
     _f(buff_, blen_);
  }
}

