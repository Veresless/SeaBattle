#ifndef THRIFTMECLIENT_H
#define THRIFTMECLIENT_H
#include "IAdapter.h"
class ThriftMeClient
{
public:
    ThriftMeClient(IAdapter* &adapter);
private:
    IAdapter* &m_adapter;
};
#endif // THRIFTMECLIENT_H
