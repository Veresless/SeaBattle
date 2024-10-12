#ifndef ISERVER_H
#define ISERVER_H
class IServer
{
public:
    IServer() = default;
    virtual void run() = 0;
    virtual ~IServer() = default;
};
#endif // ISERVER_H
