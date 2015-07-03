cmake_minimum_required (VERSION 2.6)

project (testcb)

set (CMAKE_CXX_FLAGS "-std=c++11 -g -pthread")
set (CMAKE_VERBOSE_MAKEFILE ON)

set (DataStructs_VERSION_MAJOR 1)
set (DataStructs_VERSION_MINOR 0)

set (TPINC /home/kjacob1029/3rd/include)
set (SRCDIR /home/kjacob1029/dev/tmp/DataStructs/src)
set (INCDIR /home/kjacob1029/dev/tmp/DataStructs/src)

set (TPLIB /home/kjacob1029/3rd/lib)
#set(CMAKE_LIBRARY_PATH /home/kjacob1029/3rd/lib)


include_directories(${INCDIR} ${TPINC})
link_directories(${TPLIB})

#set (INCFILES ${INCDIR}/ItchMsgType.H
# ${INCDIR}/ItchParser.H
# ${INCDIR}/MktDataMsgType.H
# ${INCDIR}/PcapReader.H)

set (SRCFILES ${SRCDIR}/logtest.cpp)
        
add_executable (logtest ${SRCFILES})

target_link_libraries(logtest glog)

