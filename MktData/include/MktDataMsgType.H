#ifndef MKTDATAMSGTYPE_H
#define MKTDATAMSGTYPE_H
// Msg Types in ITCH V5.0
//

#include <cstdint>
#include <string>

typedef uint32_t Px_t;
typedef uint64_t Qty_t;
typedef uint64_t Oid_t;

// Add Order - Also keeps order state
// Need to be locked, can be accessed from multiple threads
class MDOrder
{
  MDOrder(uint64_t ts_, Oid_t oid_, Qty_t orderQty_, Px_t px_, 
          char buySell_, std::string& sym_)
      : _ts(ts_), _oid(oid_), _orderQty(orderQty_), _fillQty(0), _delQty(0),
      _px(px_), _buySell(buySell_), _sym(sym_)
  {}

  ~MDOrder()
  {}

  inline uint64_t ts(void)       const { return _ts; }

  inline Oid_t oid(void)      const { return _oid; }
  inline Qty_t orderQty(void) const { return _orderQty; }
  inline Qty_t delQty(void)   const { return _delQty; }
  inline Qty_t fillQty(void)  const { return _fillQty; }
  inline Px_t  px(void)       const { return _px; }
  inline char buySell(void)      const { return _buySell; }
  inline std::string& sym(void)  const { return _sym; }
  
  inline uint32_t openQty(void) const { return (_orderQty-_delQty-_fillQty); }

  // the order is deleted
  void delOrder() 
  { 
    _delQty = (_orderQty-_fillQty); 
    assert ((_orderQty-_delQty-_fillQty)>=0)
  }

  // order is partially cancelled
  void cancelOrder(uint32_t qty_) 
  {
    _delQty += qty_;
    assert ((_orderQty-_delQty-_fillQty)>=0)
  }

  void addExec(uint32_t qty_)
  {
    _fillQty += qty_;
    assert ((_orderQty-_delQty-_fillQty)>=0)
  }

  void bustExec(uint32_t qty_)
  {
    _fillQty -= qty_;
    _delQty += qty_; // what happens if the bust is before order is "Terminal"?
    assert ((_orderQty-_delQty-_fillQty)>=0)
  }

 private:
  uint64_t  _ts;
  std::string _sym;

  Oid_t _oid;
  Qty_t _orderQty;
  Qty_t _delQty;
  Qty_t _fillQty;
  Px_t  _px;
  char  _buySell;
};


// Execution
// Handles: Exec and ExecPx
class MDExec
{
 public:
  MDExec(uint64_t ts_, Oid_t oid_, Qty_t shares_, uint64_t execID_):
      _ts(ts_), _oid(iod_), _shares(shares_), _execID(execID_), _px(0),
      _linkOrder(nullptr)
  {}

  ~MDExec()
  {}

  inline uint64_t ts() const { return _ts; }
  inline Oid_t  oid() const { return _oid; }
  inline Qty_t  shares() const { return _shares; }
  inline Px_t   px() const { return _px; }

  inline uint64_t execID() const { return _execID; }

  // set the execution px
  inline void px(uint32_t px_) { _px = px_; }

  inline linkOrder(MDOrder* op_) { _linkOrder = op_; }

 private:
  uint64_t  _ts;
  uint64_t  _execID;

  Oid_t  _oid;
  Qty_t  _shares;
  Qty_t  _px;


  MDOrder* _linkOrder;
};


// Cancel Order
// Message sent when an order is partially cancelled
// Handles: Cancel (partial) and Del Orders
class MDCancelOrder
{
  MDCancelOrder(uint64_t ts_, Oid_t oid_, Qty_t cancelQty_, Qty_t remainQty_):
      _ts(ts_), _oid(oid_), _cancelQty(cancelQty_), _remainQty(remainQty_),
      _linkOrder(nullptr)
  {}

  ~MDCancelOrder()
  {}

  inline uint64_t ts() const { return _ts; }
  inline Oid_t oid() const { return _oid; }
  inline Qty_t cancelQty() const { return _cancelQty; }
  inline Qty_t remainQty() const { return _remainQty; }

  inline linkOrder(MDOrder* op_) { _linkOrder = op_; }

 private:
  uint64_t  _ts;
  Oid_t  _oid;
  Qty_t  _cancelQty; // Shares cancelled
  Qty_t  _remainQty; // Shared remaining open

  MDOrder* _linkOrder;
};

// Replace Order
class MDReplaceOrder
{
 public:
  MDReplaceOrder(uint64_t ts_, Oid_t origOid_,Oid_t newOid_, Qty_t shares_, Px_t px_):
      _ts(ts_), _origOid(origOid_), _newOid(newOid_), _shares(shares_), _px(px_)
  {}

  ~MDReplaceOrder()
  {}

  inline uint64_t ts() const { return _ts; }
  inline Oid_t origOid() const { return _origOid; }
  inline Oid_t newOid() const { return _newOid; }
  inline Qty_t shares() const { return _shares; }
  inline Px_t  px() const { return _px; }
  
 private:
  uint64_t  _ts;

  Oid_t _origOid;
  Oid_t _newOid;
  Qty_t _shares;
  Px_t  _px;
};


// Trade (Non Cross)
// For executions where the order was non-displayed
class MDTrade
{
 public:
  MDTrade(uint64_t ts_, Oid_t oid_, Qty_t shares_, Px_t px_,
          std::string& sym_, char buySell_, uint64_t execID_) :
      _ts(ts_), _oid(oid_), _shares(shares_), _px(px_), _execID(execID_),
      _sym(sym_), _buySell(buySell_)
  {}

  ~MDTrade()
  {}

  inline uint64_t ts() const { return _ts; }
  inline Oid_t oid() const { return _oid; }
  inline Qty_t shares() const { return _shares; }
  inline Px_t px() const { return _px; }
  inline const std::string& sym() const { return _sym; }
  inline char buySell() const { return _buySell; }
  inline uint64_t execID() const { return _execID; }

 private:
  uint64_t    _ts;
  std::string _sym;
  uint64_t    _execID;

  Oid_t _oid;   // null field
  Qty_t _shares;
  Px_t  _px;
  char  _buySell;
};

// Bust
class MDBust
{
  MDBust(uint64_t ts_, uint64_t execID_):
      _ts(ts_), _execID(execID_), _linkOrder(nullptr)
  {}

  ~MDBust()
  {}

  inline uint64_t ts() const { return _ts; }
  inline uint64_t execID() const { return _execID; }

  inline linkOrder(MDOrder* op_) { _linkOrder = op_; }

 private:
  uint64_t  _ts;
  uint64_t  _execID;

  MDOrder*  _linkOrder;
};


#endif
