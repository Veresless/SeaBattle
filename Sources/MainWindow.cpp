#include "MainWindow.h"
MainWindow::MainWindow(IAdapter* &adapter, IServer* &server, QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow),
    m_field(new Field(this)),
    m_server(server),
    m_adapter(adapter)
{
    m_ui->setupUi(this);
    m_field->init(m_ui);
}
MainWindow::~MainWindow()
{
    if (nullptr != m_ui)
    {
        delete m_ui;
    }
    if (nullptr != m_field)
    {
        delete m_field;
    }
}

void MainWindow::on_actionMake_Host_triggered()
{
    if (m_field->isShipsPlasing())
    {
        m_field->stopPlaseShips();
    }
    m_field->clear();
    m_field->startPlaseShips();
    m_adapter->createServer(*m_server);
}

void MainWindow::on_actionFound_triggered()
{
    if (m_field->isShipsPlasing()) m_field->stopPlaseShips();
    m_field->clear();
    m_field->startPlaseShips();
    m_server->run();
}

void MainWindow::on_actionEnter_IP_triggered()
{

    if (m_field->isShipsPlasing()) m_field->stopPlaseShips();
    m_field->clear();
    m_field->startPlaseShips();
    m_server->run();
}

void MainWindow::on_actionSave_triggered()
{

}

void MainWindow::on_actionLoad_triggered()
{

}
