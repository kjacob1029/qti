#ifndef PXLEVELSIDE_H
#define PXLEVELSIDE_H

#include <vector>
#include "MktDataMsgType.H"

// keeps tracks of all orders at 
// px level and side
// The summary info is kept separately
// Orders are not deleted until px level is removed
class PxLevelSide
{
  typedef std::vector<MDOrder*> OrderVector;

 public:
  PxLevelSide(Px_t px_, char side_):
      _side(side_), _px(px_)
  {}

  ~PxLevelSide();

  void addOrder(MDOrder* op_);

  void delQty   (Qty_t qty_);
  void fillQty  (Qty_t qty_);
  void bustQty  (Qty_t qty_);


 private:
  Px_t _px;
  char _side;

  OrderVector _orderList;

  Qty_t _addQty;
  Qty_t _delQty;
  Qty_t _exeQty;
  Qty_t _tradeQty;

}
#endif
