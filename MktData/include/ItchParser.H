#ifndef ITCHPARSER_H
#define ITCHPARSER_H

#include <cstdint>
#include <iostream>
#include <ostream>
#include <sparsehash/dense_hash_map>

#include  "ItchMsgType.H"

// MOLD packet header
struct MoldUDPHeader
{
  char      _session[10];
  uint64_t  _seqNo;
  uint16_t  _count;
} __attribute__((packed));

// Data structure to capture stats for ItchParser
// Should be in MktData?
struct OrderBookStats
{
  std::string _sym;
  uint64_t _nAdd;
  uint64_t _nAddAttrib;
  uint64_t _nDel;
  uint64_t _nCancel;
  uint64_t _nReplace;
  uint64_t _nExec;
  uint64_t _nExecPx;
  uint64_t _nTrade;

  OrderBookStats() :
      _nAdd(0), _nAddAttrib(0), _nDel(0), _nCancel(0),
      _nReplace(0), _nExec(0), _nExecPx(0), _nTrade(0)
  {}

  ~OrderBookStats() {}

  void print(std::ostream& os_) const;
};

// Parse the data and keep stats on messages
class ItchParser
{
  typedef google::dense_hash_map<std::string,OrderBookStats*> SymStatsMap; 
 public:
  ItchParser();
  ~ItchParser();

  void parseMoldPkt (char* pktBuff_, uint64_t pktLen_);
  void parseBuffer  (char* buffer_, uint64_t blen, uint64_t nmsgs_);

  void stop(); // Called when we stop the parser

 protected:
  void handleAddOrderAttrib (Itch::AddOrderAttrib* aoa_);
  void handleAddOrder       (Itch::AddOrder* ao_);
  void handleDelOrder       (Itch::DelOrder* do_);
  void handleCancelOrder    (Itch::CancelOrder* co_);
  void handleReplaceOrder   (Itch::ReplaceOrder* co_);
  void handleExec           (Itch::Exec* ex_);
  void handleExecPx         (Itch::ExecPx* exp_);
  void handleTrade          (Itch::Trade* tr_);

 private:
  uint64_t        _nPackets;
  SymStatsMap     _stats;
  OrderBookStats* _allStats;
};

#endif
