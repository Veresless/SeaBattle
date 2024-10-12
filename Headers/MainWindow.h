#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_MainWindow.h"
#include "IAdapter.h"
#include "Field.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(IAdapter* &adapter, IServer* &server, QWidget *parent = 0);
    bool isShipsPlasedCorrect();
    ~MainWindow();
private slots:
    void on_actionMake_Host_triggered();

    void on_actionFound_triggered();

    void on_actionEnter_IP_triggered();

    void on_actionSave_triggered();

    void on_actionLoad_triggered();

private:

    Ui::MainWindow *m_ui;
    Field* m_field;
    IServer* &m_server;
    IAdapter* &m_adapter;
};

#endif // MAINWINDOW_H
