#ifndef QTICLOCK_H
#define QTICLOCK_H

// ///////////////////////
// QtiClock - global clock for the platform
// Runs in 2 modes
// 1. in simulation. It updates its clock based on time from market data
// 2. in prod. uses system clock
// 
// Any resource can register callbacks to be fired at specified time
// Time is specified in elapsed time from midnight of current day
//
// ////////////////////////////////////////////////////////
//

class QtiClock
{
 public:
  QtiClock();
  ~QtiClock();

  void registerTimerCB(uint32_t tmSec_, uint32_t tmUSec_, )
#endif
