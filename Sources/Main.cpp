#include "MainWindow.h"
#include "QtThriftMeAdapter.h"
#include "CommonAPIServer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    IAdapter * adapter = nullptr;
    IServer *server = new CommonAPIServer();
    MainWindow *window = new MainWindow(adapter, server);
    ThriftMeClient *client = new ThriftMeClient(adapter);
    adapter = new QtThriftMeAdapter(window, client);
    window->show();
    return application.exec();;
}
