#ifndef QTITIMERMANAGER_H
#define QTITIMERMANAGER_H

#include <map>
#include <string>
#include <thread>

#include "QtiTimerObj.H"

// 
// QtiTimerManager has its own thread and manages all timers
// When a timer is fired, it inserts an event into the specified EventQ
//
class QtiTimerManager
{
  typedef std::map<std::string, QtiTimerObj*> NameObjMap_t;

 public:
  QtiTimerManager()
      : _stopRequest(false), _hasStarted(false)
  {}

  ~QtiTimerManager()
  {}

  // add a timer obj
  bool addTimer(QtiTimerObj* timerObj_);

  // remove a timer obj by name
  bool delTimer(std::string& name_);

  // method checks timers that need to fire.
  void checkTimers(QtiTimePoint_t now_);

  QtiTimePoint_t nextTimePt(void) const;

  void start();
  void stop();

 private:
  std::mutex      _mapLock;
  NameObjMap_t    _nameMap;
};
#endif
