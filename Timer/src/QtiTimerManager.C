#include <thread>
#include "QtiTimerManager.H"

// Adding a timer
bool QtiTimerManager::
addTimer(QtiTimerObj* timerObj_)
{
  std::lock_guard grd(_mapLock);

  std::string name = timerObj_->name();

  // this timer name already exists
  if (_nameMap.find(name) != _nameMap.end())
   return false;

  std::cout << "QtiTimerManager::addTimer" << std::endl;

  // otherwise: insert this timer
  _nameMap.insert(NameObjMap_t::value_type(name, timerObj_));

  return true;
}

// remove a timer
bool QtiTimerManager::
delTimer(std::string& name_)
{
  std::lock_guard grd(_mapLock);

  NameObjMap_t::iterator it = _nameMap.find(name_);

  if (it == _nameMap.end())
    return false;

  _nameMap.erase(it);

  return true;
}


void QtiTimerManager::
start()
{
  std::cout << "QtiTimerManager::start" << std::endl;
  if (!_inSimulation)
  {
    std::thread thr(&QtiTimerManager::run, this);
    thr.join();
  }
}

void QtiTimerManager::
stop()
{
  std::cout << "QtiTimerManager::stop" << std::endl;
  _stopRequest = true;
}

void QtiTimerManager::
run()
{
  _hasStarted = true;
  while (!_stopRequest)
  {
    QtiTimePoint_t tmNow = std::chrono::system_clock::now();
    checkTimers(tmNow);

    MicroSec_t dur = durNextTimer(); // Time to the next timer
    if (dur > std::chrono::second(1))
      dur = std::chrono::second(1)
   std::thread::sleep_for(dur);
  }
}



