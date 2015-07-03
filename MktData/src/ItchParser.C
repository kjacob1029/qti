#include <iostream>
#include <cstring>

#include "ItchParser.H"
#include "ItchMsgType.H"
#include "MktDataMsgType.H"

void OrderBookStats::
print(std::ostream& os_) const
{
  os_ << "  NAdds: " << _nAdd;
  os_ << ", NAddAttr: " << _nAddAttrib;
  os_ << ", NDel: " << _nDel;
  os_ << ", NCancel: " << _nCancel;
  os_ << ", NReplace: " << _nReplace;
  os_ << ", NExec: " << _nExec;
  os_ << ", NExecPx: " << _nExecPx;
  os_ << ", NTrade: " << _nTrade;
  os_ << "\n";
}

// -----------------------------------------------------------------------
ItchParser::
ItchParser()
{
  _nPackets = 0;
  _allStats = new OrderBookStats();
  std::string empty("EMPTYSTRING");
  _stats.set_empty_key(empty);
}

ItchParser::
~ItchParser()
{
  if (_allStats) delete _allStats;
}

// Parse Itch Packet
void ItchParser::
parseMoldPkt(char* pktBuff_, uint64_t pktLen_)
{
  MoldUDPHeader* mold;
  uint64_t slen = sizeof(MoldUDPHeader);
  if (pktLen_<slen) {
    std::cerr << "ItchParser::parseMoldPkt. pktlen: " << pktLen_ << ", struct len: " << slen << std::endl;
    return;
  }

  mold = reinterpret_cast<MoldUDPHeader*>(pktBuff_);

  uint64_t mlen = pktLen_-slen;
  uint64_t nmsgs = __bswap_16(mold->_count);

  // std::cout << "Calling parseBuffer: mlen: " << mlen << ", nmsgs: " << nmsgs << std::endl;
  parseBuffer((char*)(pktBuff_+slen), mlen, nmsgs);

  _nPackets++;


  if (_nPackets%1000000==0) {
    std::cout << _nPackets << ", ";
    _allStats->print(std::cout);
  }
}

// Parse an Itch Message
// Itch Message has a message type header
void ItchParser::
parseBuffer(char* buffer_, uint64_t blen_, uint64_t nmsgs_)
{
  char mtype;
  uint64_t n  = 0;      // Num msgs
  uint32_t curOff = 0;  // current Offset in buffer
  uint16_t mlen;


  while (n<nmsgs_ && curOff<blen_)
  {
    // curr message length
    mlen = *reinterpret_cast<uint16_t*>(buffer_+curOff);
    curOff += sizeof(uint16_t);

    mlen = __bswap_16(mlen);
    n++;

    mtype = *(buffer_+curOff);

    // std::cout << "MsgType: " << mtype << ", mlen: " << mlen << std::endl;
    switch (mtype)
    {
      case 'S': // SysEvent
        break;
      case 'R': // Stock Dir
        break;
      case 'H': // Trading Action
        break;
      case 'Y': // RegSHO
        break;
      case 'L': // MktPartPos
        break;
      case 'V': // MWCBLevels
        break;
      case 'W': // MWCBBreach
        break;
      case 'K': // IPOQuote
        break;
      case 'A': // AddOrder
        {
          Itch::AddOrder* aop = reinterpret_cast<Itch::AddOrder*> (buffer_+curOff);
          handleAddOrder(aop);
          break;
        }
      case 'F': // AddOrder W/ Attrib
        {
          Itch::AddOrderAttrib* aop = reinterpret_cast<Itch::AddOrderAttrib*> (buffer_+curOff);
          handleAddOrderAttrib(aop);
          break;
        }
      case 'E': // Exec
        {
          Itch::Exec* ex = reinterpret_cast<Itch::Exec*>(buffer_+curOff);
          handleExec(ex);
          break;
        }
      case 'C': // Exec w/ Px
        {
          Itch::ExecPx* exp = reinterpret_cast<Itch::ExecPx*>(buffer_+curOff);
          handleExecPx(exp);
          break;
        }
      case 'X': // Cancel Order
        {
          Itch::CancelOrder* cop = reinterpret_cast<Itch::CancelOrder*>(buffer_+curOff);
          handleCancelOrder(cop);
          break;
        }
      case 'D': // DelOrder
        {
          Itch::DelOrder *dop = reinterpret_cast<Itch::DelOrder*>(buffer_+curOff);
          handleDelOrder(dop);
          break;
        }
      case 'U': // ReplaceOrder
        {
          Itch::ReplaceOrder *rop = reinterpret_cast<Itch::ReplaceOrder*>(buffer_+curOff);
          handleReplaceOrder(rop);
          break;
        }
      case 'P': // Trade
        {
          Itch::Trade *trp = reinterpret_cast<Itch::Trade*>(buffer_+curOff);
          handleTrade(trp);
          break;
        }
      case 'Q': // TradeCross
        break;
      case 'B': // Bust
        break;
      case 'I': // NOII
        break;
      case 'N': // RPII
        break;
      default:
        break;
    }
    curOff += mlen;
  }
}


void ItchParser::
handleAddOrderAttrib(Itch::AddOrderAttrib* aoa_)
{
  MktData::AddOrder* ao = new MktData::AddOrder;
  memcpy(ao->_sym,aoa_->_sym,Itch::SYMLEN);
  ao->_sym[Itch::SYMLEN-1]='\0';
  ao->_ts = aoa_->_nanos.v;
  ao->_oid = aoa_->_oid; 
  ao->_buySell = aoa_->_buySell;
  ao->_shares =  aoa_->_shares;
  ao->_px = aoa_->_px;

  // keeps stats
  _allStats->_nAddAttrib++;
}

void ItchParser::
handleAddOrder(Itch::AddOrder* ao_)
{
  MktData::AddOrder* ao = new MktData::AddOrder;
  memcpy(ao->_sym,ao_->_sym,Itch::SYMLEN);
  ao->_sym[Itch::SYMLEN-1]='\0';
  ao->_ts = ao_->_nanos.v;
  ao->_oid = ao_->_oid; 
  ao->_buySell = ao_->_buySell;
  ao->_shares =  ao_->_shares;
  ao->_px = ao_->_px;
  
  // keeps stats
  _allStats->_nAdd++;
}

void ItchParser::
handleDelOrder(Itch::DelOrder* do_)
{
  MktData::DelOrder* dop = new MktData::DelOrder;
  dop->_ts = do_->_nanos.v;
  dop->_oid = do_->_oid;
  
  // keeps stats
  _allStats->_nDel++;
}

void ItchParser::
handleCancelOrder(Itch::CancelOrder* co_)
{
  
  // keeps stats
  _allStats->_nCancel++;
}

void ItchParser::
handleReplaceOrder(Itch::ReplaceOrder* co_)
{
  
  // keeps stats
  _allStats->_nReplace++;
}

void ItchParser::
handleExec(Itch::Exec* ex_)
{
  
  // keeps stats
  _allStats->_nExec++;
}

void ItchParser::
handleExecPx(Itch::ExecPx* exp_)
{
  
  // keeps stats
  _allStats->_nExecPx++;
}

void ItchParser::
handleTrade(Itch::Trade* tr_)
{
  
  // keeps stats
  _allStats->_nTrade++;
}
