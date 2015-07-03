#ifndef QTITIMEUTIL_H
#define QTITIMEUTIL_H
#include <string>

#include "QtiTimeTypes.H"

// Time is specified in HH:MM:SS.xxxxxx (upto micros)
QtiTimePoint_t QtiTmStr2TimePt(std::string& tm_);

#endif
