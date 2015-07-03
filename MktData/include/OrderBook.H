#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include <string>
#include "MktDataMsgType.H"
#include "PxLevel.H"

class OrderBook
{
  typedef std::map<Px_t, PxLevel*> PxLevels;
 public:
  OrderBook(std::string& sym_);
  ~OrderBook();

  void handleAddOrder     (uint64_t ts_, MDOrder* op_);
  void handleDelOrder     (uint64_t ts_, MDOrder* op_);
  void handleCancelOrder  (uint64_t ts_, MDOrder* op_, Qty_t qty_);
  void handleExec         (uint64_t ts_, MDOrder* op_, Qty_t qty_);

  inline std::string& sym() const { return _sym; }

 private:
  std::string _sym;
  PxLevels    _levels;
};

#endif
