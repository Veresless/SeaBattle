#ifndef UICLIENTADAPTER_H
#define UICLIENTADAPTER_H
#include "IAdapter.h"
#include "ThriftMeClient.h"
#include "MainWindow.h"
class QtThriftMeAdapter : public IAdapter
{
public:
    QtThriftMeAdapter(MainWindow* &ui, ThriftMeClient* &client);
    virtual void checkField(Collections::Vector<bool>& field) override;
    virtual void fieldChecked(bool rezult) override;
    virtual void shoot(Point point) override;
    virtual void setAt(Point point, Rezult rezult) override;
    virtual void makeStep() override;
    virtual void gameOver(bool rezult) override;
    virtual void createServer(IServer &server) override;
    virtual ~QtThriftMeAdapter();
private:
    MainWindow* &m_ui;
    ThriftMeClient* &m_client;
};

#endif // UICLIENTADAPTER_H
