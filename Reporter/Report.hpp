#ifndef REPORT_HPP
#define REPORT_HPP
#include <string>
#include <iostream>
class Logger
{
public:
    Logger();
    static void report(const std::string & _log);
};
#endif // REPORT_HPP
