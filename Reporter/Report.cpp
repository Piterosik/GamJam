#include "Report.hpp"

Logger::Logger()
{

}

void Logger::report(const std::string &_log)
{
    std::cout << _log << std::endl;
}
