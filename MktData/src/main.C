#include <functional>
#include <memory>

#include "PcapReader.H"
#include "ItchParser.H"

int main(int ac, char* av[])
{
  std::string fname(av[1]);
  PcapReader pcapRdr(fname);
  ItchParser iparser;

  auto f = std::bind(&ItchParser::parseMoldPkt, &iparser, std::placeholders::_1, std::placeholders::_2);
  pcapRdr.regPktCB(f);

  pcapRdr.init();
  pcapRdr.run();

  return 0;
}
