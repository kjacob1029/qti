#ifndef ITCHMSGTYPE_H
#define ITCHMSGTYPE_H
// Msg Types in ITCH V5.0
//

#include <cstdint>


namespace Itch 
{

const int SYMLEN=8;

struct uint48_t
{
  int64_t v:48;
} __attribute__((packed));

// System codes:
// O - start of messages
// S - start of system hours
// Q - start of market hours
// M - end of market hours
// E - end of system hours
// C - end of message
struct SysEvent
{
  char      _msgType;     // S
  uint16_t  _locate;
  uint16_t  _tracking;
  uint48_t  _nanos;
  char      _eventCode;
} __attribute__((packed));


// Stock Directory

struct StkDir
{
  char      _msgType; // R
  uint16_t  _locate;
  uint16_t  _tracking;
  uint48_t  _nanos;
  char      _sym[SYMLEN];
  char      _mktCat; // Q, G, S, N, A, P, Z, space
  char      _finStatus; // D, E, Q, S, G, H, J, K, C, N, space
  uint32_t  _lotSize;
  char      _rndLotsOnly; // Y, N
  char      _issueClass;
  char      _issueSubType[2];
  char      _auth;
  char      _shortSaleThreshold;
  char      _IPOFlag;
  char      _luldRefTier;
  char      _etpFlag;     // Instrument is ETP
  uint32_t  _levFactor;   // ETP Leverage Factor
  char      _inverseInd;  // Inverse ETP
} __attribute__((packed));


// Stock Trading Action
struct StkTradeAct
{
  char     _msgType; // H
  uint16_t _locateCode;
  uint16_t _tracking;
  uint48_t _nanos;
  char     _sym[SYMLEN];
  char     _tradeState;
  char     _reserved;
  char     _reason[4];
} __attribute__((packed));

// RegSHO
struct RegSHO
{
  char      _msgType;     // Y
  uint16_t  _locateCode;
  uint16_t  _tracking;
  uint48_t  _nanos;
  char      _sym[SYMLEN];
  char      _regSHOAction; // 0- No Price test, 1- ShortSale Price Test, 2 - Price Test remains
} __attribute__((packed));

// Market Participant Pos
struct MktPartPos
{
  char      _msgType;   // L
  uint16_t  _locateCode;
  uint16_t  _tracking;
  uint48_t  _nanos;
  char      _mpid[4];
  char      _sym[SYMLEN];
  char      _pmm;
  char      _mmMode;  // N - Normal, P-Passive, S-Syndicate, R-pre-syndicate, L-penalty
  char      _mpState; // A-Active, E-Excused,W-Withdrawn,S-Suspended,D-Deleted
} __attribute__((packed));

// Market Wide Circuit Breaker Levels
struct MWCBLevels
{
  char      _msgType; // V
  uint16_t  _locateCode;
  uint16_t  _tracking;
  uint48_t  _timestamp;
  uint64_t  _pxLvl1;
  uint64_t  _pxLvl2;
  uint64_t  _pxLvl3;
} __attribute__((packed));

// MWCB Breach
struct MWCBBreach
{
  char      _msgType;  // W 
  uint16_t  _locateCode;
  uint16_t  _tracking;
  uint48_t  _timestamp;
  char      _breachLvl; // 1, 2 or 3
} __attribute__((packed));

// IPO Quoting Period Update
struct IPOQuote
{
  char      _msgType; // K - IPO Quoting Period Update
  uint16_t  _locateCode;
  uint16_t  _tracking;
  uint48_t  _timestamp;
  char      _sym[SYMLEN];
  uint32_t  _releaseTime;
  char      _releaseQual;
  uint32_t  _ipoPx;
} __attribute__((packed));

// Add Order
struct AddOrder
{
  char      _msgType; // A
  uint16_t  _locateCode;
  uint16_t  _tracking;
  uint48_t  _nanos;
  uint64_t  _oid;
  char      _buySell; // B-Buy, S-Sell
  uint32_t  _shares;
  char      _sym[SYMLEN];
  uint32_t  _px;
} __attribute__((packed));


// Add Order with Attrib
struct AddOrderAttrib
{
  char      _msgType; // F
  uint16_t  _locateCode;
  uint16_t  _tracking;
  uint48_t  _nanos;
  uint64_t  _oid;
  char      _buySell; // B-Buy, S-Sell
  uint32_t  _shares;
  char      _sym[SYMLEN];
  uint32_t  _px;
  char      _attrib[4];
} __attribute__((packed));


// Execution
struct Exec
{
  char      _msgType; // E
  uint16_t  _locateCode;
  uint16_t  _tracking;
  uint48_t  _nanos;
  uint64_t  _oid;
  uint32_t  _shares;
  uint64_t  _execID;
} __attribute__((packed));

// Execution with Price
// For executions where the execution price is different from the display price
struct ExecPx
{
  char      _msgType; // C
  uint16_t  _locateCode;
  uint16_t  _tracking;
  uint48_t  _nanos;
  uint64_t  _oid;
  uint32_t  _shares;
  uint64_t  _execID;
  char      _printable;
  uint32_t  _px;
} __attribute__((packed));


// Cancel Order
// Message sent when an order is partially cancelled
struct CancelOrder
{
  char      _msgType; // X
  uint16_t  _locateCode;
  uint16_t  _tracking;
  uint48_t  _nanos;
  uint64_t  _oid;
  uint32_t  _shares;
} __attribute__((packed));

// Delete Order
struct DelOrder
{
  char      _msgType; // D
  uint16_t  _locateCode;
  uint16_t  _tracking;
  uint48_t  _nanos;
  uint64_t  _oid;
} __attribute__((packed));

// Replace Order
struct ReplaceOrder
{
  char      _msgType; // U
  uint16_t  _locateCode;
  uint16_t  _tracking;
  uint48_t  _nanos;
  uint64_t  _origOid;
  uint64_t  _newOid;
  uint32_t  _shares;
  uint32_t  _px;
} __attribute__((packed));


// Trade (Non Cross)
// For executions where the order was non-displayed
struct Trade
{
  char      _msgType; // P
  uint16_t  _locateCode;
  uint16_t  _tracking;
  uint48_t  _nanos;
  uint64_t  _oid;   // null field
  char      _buySell;
  uint32_t  _shares;
  char      _sym[SYMLEN];
  uint32_t  _px;
  uint64_t  _execID;
} __attribute__((packed));

// Trade (Cross)
struct TradeCross
{
  char      _msgType; // Q
  uint16_t  _locateCode;
  uint16_t  _tracking;
  uint48_t  _nanos;
  uint64_t  _shares;
  char      _sym[SYMLEN];
  uint32_t  _px;
  uint64_t  _execID;
  char      _crossType; // O - Open, C - Close, H - IPO, I -
} __attribute__((packed));

// Bust
struct Bust
{
  char      _msgType; // B
  uint16_t  _locateCode;
  uint16_t  _tracking;
  uint48_t  _nanos;
  uint64_t  _execID;
} __attribute__((packed));

// NOII
struct NOII
{
  char      _msgType;   // I
  uint16_t  _locateCode;
  uint16_t  _tracking;
  uint48_t  _nanos;
  uint64_t  _pairShares;
  uint64_t  _imbShares;
  char      _imbDir;  // B- Buy, S - Sell, N - No Imbalance, O- Insufficient
  char      _sym[SYMLEN];
  uint32_t  _farPx;   // Auction Px for cross orders only
  uint32_t  _nearPx;  // Auction Px for cross & continuous orders
  uint32_t  _refPx;   // Ref px for current imb calc
  char      _crossType; // O-Open, C-Close, H - IPO/Halted
  char      _pxVarInd; 
} __attribute__((packed));

// RPII
struct RPII
{
  char      _msgType;   // N
  uint16_t  _locateCode;
  uint16_t  _tracking;
  uint48_t  _nanos;
  char      _sym[SYMLEN];
  char      _intFlag;   // B - RPI on bid, S - RPI on Offer, A - Both, N - None
} __attribute__((packed));

} // end of namespace Itch
#endif
