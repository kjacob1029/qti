#ifndef ORDERBOOKMANAGER_H
#define ORDERBOOKMANAGER_H

#include <string>
#include <sparsehash/dense_hash_map>

#include "MktDataMsgType.H"
#include "OrderBook.H"

class OrderBookManager
{
  typedef google::dense_hash_map<std::string,OrderBook*>  OrderBookMap; 
  typedef std::pair<MDOrder*, OrderBook*>                 OrderOBPair;
  typedef google::dense_hash_map<Oid_t,OrderOBPair>       OidOrderMap; 

 public:
  OrderBookManager(std::string& bookName_);
  ~OrderBookManager();

  void handleAddOrder(uint64_t ts_,
                      Oid_t oid_,
                      Qty_t shares_,
                      Px_t  px_,
                      char  buySell_,
                      std::string& sym_);

  void handleDelOrder(uint64_t ts_,
                      Oid_t oid_);

  void handleReplaceOrder(uint64_t ts_,
                          Oid_t origOid_,
                          Oid_t newOid_,
                          Qty_t shares,
                          Px_t  px_);

  void handleCancelOrder(uint64_t ts_,
                         Oid_t oid_,
                         Qty_t shares_);

  void handleExec(uint64_t ts_,
                  Oid_t oid_,
                  Qty_t shares_,
                  uint64_t execId_);

  void handleExecPx(uint64_t ts_,
                    Oid_t oid_
                    Qty_t shares_,
                    Px_t  px_,
                    uint64_t execId_);

  void handleTrade(uint64_t ts_,
                   Oid_t  oid_
                   Qty_t  shares_,
                   Px_t   px_,
                   std::string& sym_,
                   char     buySell_,
                   uint64_t execId_);

  void handleBust(uint64_t ts_,
                  uint64_t execId_);

 private:
  OidOrderMap  _oidMap;       // Maps orderIds to pair<MDOrder*,OrderBook*>
  OrderBookMap _orderBookMap; // Maps sym strings to OrderBook*
};

#endif
