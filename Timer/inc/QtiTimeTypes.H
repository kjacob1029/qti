#ifndef QTITIMETYPES_H
#define QTITIMETYPES_H

#include <chrono>

using Clock = std::chrono::high_resolution_clock;
typedef std::chrono::time_point<Clock> QtiTimePoint_t;
typedef std::chrono::microseconds Microsec_t;


#endif
