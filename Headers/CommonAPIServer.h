#ifndef COMMONAPISERVER_H
#define COMMONAPISERVER_H
#include <iostream>
#include "IServer.h"
class CommonAPIServer : public IServer
{
public:
    CommonAPIServer() = default;
    virtual void run() override
    {
        std::cout << "Hello, I`m Server!!!\n";
    }
    virtual ~CommonAPIServer() = default;
};

#endif // COMMONAPISERVER_H
