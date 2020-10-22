#pragma once

#include <cassert>
#include <iostream>
#include <fstream>

//#define BOOST_LOG_DYN_LINK 1
namespace ott
{

namespace util
{

// Here we define our application severity levels.
enum severity_level
{
    normal,
    notification,
    warning,
    error,
    critical
};

// The formatting logic for the severity level
template< typename CharT, typename TraitsT >
inline std::basic_ostream< CharT, TraitsT >& operator<< (std::basic_ostream< CharT, TraitsT >& strm, severity_level lvl);

void initLogging( std::string logFileName = std::string("sample.log") );

} // util namespace
} // ott namespace


