#include "OrderBook.H"

OrderBook::
OrderBook(std::string& sym_):
    _sym(sym_)
{}

OrderBook::
~OrderBook()
{}

void OrderBook::
handleAddOrder(uint64_t ts_, MDOrder* op_)
{
}

void OrderBook::
handleDelOrder(uint64_t ts_, MDOrder* op_)
{
}

void OrderBook::
handleCancelOrder(uint64_t ts_, MDOrder* op_, Qty_t qty_)
{
}

void OrderBook::
handleExec(uint64_t ts_, MDOrder* op_, Qty_t qty_)
{
}

void OrderBook::
handleTrade(MktData::MDTrade* tr_)
{
}
