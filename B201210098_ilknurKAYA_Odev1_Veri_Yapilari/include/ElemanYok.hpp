#ifndef ELEMANYOK_HPP
#define ELEMANYOK_HPP
#include "Exception.hpp"
class ElemanYok : public Exception
{
public:
    ElemanYok(const string &msg) : Exception(msg)
    {
    }
};
#endif
