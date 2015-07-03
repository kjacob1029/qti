#include "OrderBookManager.H"

OrderBookManager::
OrderBookManager(std::string& bookName_)
  :_bookName(bookName_)
{}

OrderBookManager::
~OrderBookManager()
{}

void OrderBookManager::
handleAddOrder(uint64_t ts_,
               uint64_t oid_,
               uint32_t shares_,
               uint32_t px_,
               char     buySell_,
               std::string& sym_)
{
  MktData::AddOrder* ao = new MktData::AddOrder;
  ao->_ts = ts_;
  ao->_oid = oid_;
  ao->_orderQty = shares_;
  ao->_fillQty = 0;
  ao->_delQty = 0;
  ao->_px = px_;
  ao->_buySell = buySell_;
  ao->_sym = sym_;

  // insert the order
  if (_oidMap.find(oid_) == _oidMap.end())
    _oidMap[oid_] = ao;
  else
    std::cerr << "OrderBookManager::handleAddOrder. Duplicate Oid: " << ao->_oid << std::endl;

  // Find the order book and insert the order
  OrderBookMap::iterator it = _orderBookMap.find(sym_);
  OrderBook* ob;
  if (it == _orderBookMap.end()) {
    std::cout << "OBManager::handleAddOrder. Adding order book for sym: " << ao->_sym << std::endl;
    ob = new OrderBook(sym_);
    _orderBookMap[sym_] = ob;
  }
  else {
    ob = (*it).second;
  }
  ob->addOrder(ao);
}

void OrderBookManager::
handleDelOrder(uint64_t ts_,
               uint64_t oid_)
{
  
}

void OrderBookManager::
handleReplaceOrder(uint64_t ts_,
                   uint64_t origOid_,
                   uint64_t newOid_,
                   uint32_t shares,
                   uint32_t px_)
{
}

void OrderBookManager::
handleCancelOrder(uint64_t ts_,
                  uint64_t oid_,
                  uint32_t shares_)
{
}

void OrderBookManager::
handleExec(uint64_t ts_,
           uint64_t oid_,
           uint32_t shares_,
           uint64_t execId_)
{
}

void OrderBookManager::
handleExecPx(uint64_t ts_,
             uint64_t oid_
             uint32_t shares_,
             uint32_t px_,
             uint64_t execId_)
{
}

void OrderBookManager::
handleTrade(uint64_t ts_,
            uint64_t oid_
            uint32_t shares_,
            uint32_t px_,
            char*    sym_,
            char     buySell_,
            uint64_t execId_)
{
}

void OrderBookManager::
handleBust(uint64_t ts_,
           uint64_t execId_)
{
}

