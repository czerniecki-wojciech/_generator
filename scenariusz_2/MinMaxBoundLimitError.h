#ifndef MINMAXBOUNDLIMITERROR_H
#define MINMAXBOUNDLIMITERROR_H

#include <exception>
#include <stdexcept>
#include <sstream>

class MinMaxBoundLimitError : public std::runtime_error
{
public:
    MinMaxBoundLimitError()
        : std::runtime_error("Minimal value was equal or greater then maximum value")
        {}

        virtual const char* what() const throw()
        {
            std::ostringstream cnvt("");
            cnvt << std::runtime_error::what();
            return cnvt.str().c_str();
        }
};

#endif // MINMAXBOUNDLIMITERROR_H
