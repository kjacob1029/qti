#ifndef PCAPREADER_H
#define PCAPREADER_H

#include <cstdint>
#include <functional>
#include <string>

// Pcap File header
struct PcapHeader
{
  uint32_t _magicNum;
  uint16_t _verMajor;
  uint16_t _verMinor;
  uint32_t _timeZone;
  uint32_t _sigfigs;
  uint32_t _snapLen;
  uint32_t _network;
} __attribute__((packed));

// Packet Header
struct PcapPktHeader
{
  uint32_t _tsSec;
  uint32_t _tsUSec;
  uint32_t _incLen;
  uint32_t _origLen;
} __attribute__((packed));

// Reads a pcap files and fires cb on packets
// after stripping the packet headers
class PcapReader
{
 public:
  typedef std::function<void (char*, uint64_t)> CBType;

 public:
  PcapReader(std::string& fname_);
  ~PcapReader();

  void init();
  void run();
  
  void regPktCB(CBType f_) { _f = f_; }

 protected:
  void handlePacket(char* buff_, uint64_t blen_);

 private:
  std::string _fname;
  CBType      _f;
};

#endif
