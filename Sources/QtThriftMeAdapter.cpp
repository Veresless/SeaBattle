#include "QtThriftMeAdapter.h"

QtThriftMeAdapter::QtThriftMeAdapter(MainWindow* &ui, ThriftMeClient* &client):
    m_ui(ui),
    m_client(client)
{

}
void QtThriftMeAdapter::checkField(Collections::Vector<bool>& field)
{

}
void QtThriftMeAdapter::fieldChecked(bool rezult)
{

}
void QtThriftMeAdapter::gameOver(bool rezult)
{

}
void QtThriftMeAdapter::makeStep()
{

}
void QtThriftMeAdapter::setAt(Point point, Rezult rezult)
{

}
void QtThriftMeAdapter::shoot(Point point)
{

}
void QtThriftMeAdapter::createServer(IServer &server)
{
    server.run();
}
QtThriftMeAdapter::~QtThriftMeAdapter()
{

}
