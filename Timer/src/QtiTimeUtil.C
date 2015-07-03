#include <cstring>
#include "QtiTimeUtil.H"

// Time is specified in HH:MM:SS.xxxxxx (upto micros)
bool QtiTmStr2TimePt(std::string& tm_, QtiTimePoint_t& tp_)
{
  char* stm = tm_.c_string();
  char* mm=0;
  char* ss=0;
  char* us=0;

  int ihh=0;
  int imm=0;
  int iss=0;
  int ius=0;

  if ((mm = strpbrk(stm, ":")) == null)
      return false;

  if ((ss = strpbrk((char*)(mm+1), ":")) == null)
      return false;

  if ((us = strpbrk((char*)(ss+1), ".")) == null)
      return false;

  *mm = '\0'; mm++;
  *ss = '\0'; ss++;

  ihh = atoi((char*) stm);
  imm = atoi((char*)mm);
  iss = atoi((char*)ss);
  ius = atoi((char*)us);

  std::tm tm = {0};
  tm.tm_hour = ihh;
  tm.tm_min = imm;
  tm.tm_sec = iss;

  std::time_t tt = timegm(&tm);

  tp = std::chrono::system_clock::from_time_t(tt);
  tp += std::chrono::microseconds(ius);

  return true;
}

  
