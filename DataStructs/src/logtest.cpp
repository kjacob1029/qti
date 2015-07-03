#include <iostream>
#include <iomanip>

#include <glog/logging.h>
#include <string>
#include <cstring>
#include <chrono>
#include <stdint.h>


class MyTestClass
{
 public:
  MyTestClass(int a_)
      : _a(a_)
  {}

  ~MyTestClass()
  {}

  bool f(int b_) 
  {
    return _a>b_;
  }

 private:
  int _a;
};


class MyDriverClass
{
 public:
  MyDriverClass()
  {}

  ~MyDriverClass()
  {}

  void registerCB(Function f_)
  {
    _f = f_;
  }

  void run()
  {
    for (int i=0; i<10; i++)
    {
      if (_f != nullptr)
        std::cout << "i: " << i << _f(i) << std::endl;
      else
        std::cout << "No functor registered" << std::endl;
    }
  }
}

// Time is specified in HH:MM:SS.xxxxxx (upto micros)
bool QtiTmStr2TimePt(std::string& tm_, uint32_t& tps_, uint32_t& tpusec_)
{
  char* stm = (char*)(tm_.c_str());
  char* mm=0;
  char* ss=0;
  char* us=0;

  int ihh=0;
  int imm=0;
  int iss=0;
  int ius=0;

  if ((mm = strpbrk(stm, ":")) == nullptr)
      return false;

  if ((ss = strpbrk((char*)(mm+1), ":")) == nullptr)
      return false;

  if ((us = strpbrk((char*)(ss+1), ".")) == nullptr)
      return false;

  *mm = '\0'; mm++;
  *ss = '\0'; ss++;
  us++;

  ihh = atoi((char*) stm);
  imm = atoi((char*)mm);
  iss = atoi((char*)ss);
  ius = atoi((char*)us);
  std::cout << ihh << ":" << imm << ":" << iss << "." << ius << std::endl;
  std::cout << "Size: " << sizeof(tp_) << std::endl;

  tp_ = ((ihh*60 + imm)*60 + iss) * 1000000 + ius;
  std::cout << "Micro1: " << tp_ << std::endl;

  return true;
}

  
int main(int ac, char* av[])
{
  google::InitGoogleLogging(av[0]);

  std::string ttm("15:55:00.2000");
  std::cout << "Timestr: " << ttm << std::endl;

  Microsec_t tp;

  bool rv = QtiTmStr2TimePt(ttm, tp);
  if (rv == false)
    std::cout << "QtiTmStr2TimePt failed" << std::endl;
  else  {
    std::cout << "Microsecs: " << tp << std::endl;
  }

  return 0;
}


