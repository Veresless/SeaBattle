#ifndef IADAPTER_H
#define IADAPTER_H
#include "Collections/Vector.hpp"
#include "IServer.h"

struct Point
{
  int X, Y;
};
enum Rezult
{
    Miss,
    Hit,
    Kill
};
enum ConfigMode
{
    Client,
    Server
};
class IAdapter
{
public:
    IAdapter() = default;
    virtual void checkField(Collections::Vector<bool>& field) = 0;
    virtual void fieldChecked(bool rezult) = 0;
    virtual void shoot(Point point) = 0;
    virtual void setAt(Point point, Rezult rezult) = 0;
    virtual void makeStep() = 0;
    virtual void gameOver(bool rezult = false) = 0;
    virtual void createServer(IServer& server)= 0;
    virtual ~IAdapter() = default;
};
#endif // IADAPTER_H
