cmake_minimum_required (VERSION 2.6)

project (MDParse)

set (CMAKE_CXX_FLAGS "-std=c++11 -g -pthread")
set (CMAKE_VERBOSE_MAKEFILE ON)

set (MDParse_VERSION_MAJOR 1)
set (MDParse_VERSION_MINOR 0)

set (INCDIR /home/kjacob1029/dev/MktData/include)
set (GOOGDIR /home/kjacob1029/3rd/sparsehash-2.0.2/src)

set (SRCDIR /home/kjacob1029/dev/MktData/src)

include_directories(${INCDIR} ${GOOGDIR})

set (INCFILES ${INCDIR}/ItchMsgType.H
  ${INCDIR}/ItchParser.H
  ${INCDIR}/MktDataMsgType.H
  ${INCDIR}/PcapReader.H)

set (SRCFILES ${SRCDIR}/main.C
  ${SRCDIR}/PcapReader.C
  ${SRCDIR}/ItchParser.C
  ${SRCDIR}/main.C)
        
add_executable (mdparse ${INCDIR} ${SRCFILES})

