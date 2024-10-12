#ifndef FIELD_H
#define FIELD_H

#include <QImage>

#include "PushButton.h"
#include "ui_MainWindow.h"

#define FIELD_SIZE 10

class Field: public QObject
{
    Q_OBJECT
    struct Point;
public:
    enum FieldState
    {
        PREPARING_GAME,
        SHOOT,
        OPPONENT_SHOOT
    };
    enum FieldOwner
    {
        PLAYER,
        ENEMY
    };
public:
    explicit Field(QObject *parent = nullptr);
    void init(const Ui::MainWindow *ui);
    void startPlaseShips();
    inline bool isShipsPlasing();
    void changeState(const FieldState state);
    void changeIconOn(const FieldOwner player, const int x, const int y, const char* icon);
    void clear();
    ~Field();
public slots:
    void stopPlaseShips();
private:
    PushButton *m_EnemyFild[FIELD_SIZE][FIELD_SIZE];
    PushButton *m_PlayerFild[FIELD_SIZE][FIELD_SIZE];
    FieldState m_FieldState;
    QPushButton* m_Accept;
    const Ui::MainWindow * m_ui;
    bool m_IsShipsPlasing;
private slots:
    void playerButtonSlot(int i, int j);
    void enemyButtonSlot(int i, int j);
};
inline bool Field::isShipsPlasing()
{
    return m_IsShipsPlasing;
}
#endif // FIELD_H
