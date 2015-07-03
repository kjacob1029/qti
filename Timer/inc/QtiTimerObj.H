#ifndef QtiTIMEROBJ_H
#define QtiTIMEROBJ_H

#include "QtiTimeTypes.H"
#include <string>

enum class QtiTimerType {
  Interval=10,
  Calendar=20
};


//////////////////////////////////////////////
// Qti Timer Obj - a generic timer object
// //////////////////////////////////////////
class QtiTimerObj
{
 public:
  QtiTimerObj(std::string& name_, QtiTimerType timerType_)
      : _name(name_), _timerType(timerType_), _isExpired(false)
  {}

  virtual ~QtiTimerObj()
  {}

  std::string name(void) const      { return _name; }
  bool isExpired(void) const        { return _isExpired; }
  QtiTimerType timeType(void) const { return _timerType; }

  // Specifies the number of millisecs to next timer
  virtual Millsec_t nextInterval(QtiTimePoint_t currTm_)
  {
    MicroSec_t diff = (nextTimePt() - currTm_);
    if (diff<=0)
      return 0;
    else
      return diff;
  }

  // The default is to expire the time, when reset
  virtual void reset(QtiTimePoint_t currTm_) { _isExpired = true; }

 protected:
  MillSec_t nextTimePt(void) const { return _nextTimePt; }

 private:
  std::string     _name;        // Timer Name
  QtiTimerType    _timerType;   // Timer Type
  bool            _isExpired;  // Is the timer expired?
  QtiTimePoint_t  _nextTimePt;  // calculate value of when the timer should fire next
};



/////////////////////////////////////
// Interval Timer Object
// /////////////////////////////////
class QtiTimerObjInterval : public QtiTimerObj
{
 public:

  // nReps- is the number of times the timer should fire
  // if nReps==0, keeps firing
  QtiTimerObjInterval(std::string& name_, MicroSec_t interval_, uint32_t nReps_=0)
      : QtiTimerObj(name_, QtiTimerType::Interval), _interval(interval_), _nReps(nReps_)
  {
    if (_nReps==0)
      _evergreen = true;
    else
      _evergreen = false;
  }

  ~QtiTimerObjInterval()
  {}

  Microsec_t interval(void) const { return _interval; }
  uint32_t nReps(void) const { return _nReps; }

  void reset(QtiTimePoint_t currTm_) 
  {
    _nextTimePt = currTm_ + _interval;
    if (!_evergreen)
    {
      _nReps--;
      if (_nReps==0)
        _isExpired = true;
    }
  }

 private:
  MicroSec_t      _interval;    // interval between timer
  uint32_t        _nReps;       // how many times should timer fire
  bool            _evergreen;  // does this timer terminate
};

//////////////////////////////////////////////
// Calendar Timer Object
// Timer that goes off at a specified time
// ///////////////////////////////////////////

class QtiTimerObjCalendar
{
 public:
  QtiTimerObjCalendar(std::string name_, QtiTimePoint_t timerTimePt_)
      : QtiTimerObj (name_, QtiTimerType::Calendar),
      _nextTimePt(timerTimePt_)
  {}

  ~QtiTimerObjCalendar()
  {}
};

#endif
