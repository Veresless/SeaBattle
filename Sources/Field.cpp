#include "Field.h"
#define FIELD_ELEMENT_SIZE 30
#define EMPTY_ICON_PATH "://Empty.png"
#define SHIP_ICON_PATH "://Ship.png"

Field::Field(QObject *parent):
    QObject(parent),
    m_FieldState(FieldState::PREPARING_GAME),
    m_IsShipsPlasing(false)
{
    for (int i = 0; i < FIELD_SIZE; i ++)
    {
           for (int j = 0; j < FIELD_SIZE; j ++)
           {
                m_EnemyFild[i][j] = new PushButton(i, j);
                m_EnemyFild[i][j]->setIcon(QIcon(EMPTY_ICON_PATH));
                m_EnemyFild[i][j]->setTag(PushButton::Tag::EMPTY);
                m_EnemyFild[i][j]->setIconSize(QSize(FIELD_ELEMENT_SIZE , FIELD_ELEMENT_SIZE ));
                m_EnemyFild[i][j]->setMaximumSize(FIELD_ELEMENT_SIZE , FIELD_ELEMENT_SIZE );
                m_EnemyFild[i][j]->setMinimumSize(FIELD_ELEMENT_SIZE , FIELD_ELEMENT_SIZE );
           }
    }
    for (int i = 0; i < FIELD_SIZE; i++)
    {
           for (int j = 0; j < FIELD_SIZE; j ++)
           {
                m_PlayerFild[i][j] = new PushButton(i, j);
                m_PlayerFild[i][j]->setIcon(QIcon(EMPTY_ICON_PATH));
                m_PlayerFild[i][j]->setTag(PushButton::Tag::EMPTY);
                m_PlayerFild[i][j]->setIconSize(QSize(FIELD_ELEMENT_SIZE , FIELD_ELEMENT_SIZE ));
                m_PlayerFild[i][j]->setMaximumSize(FIELD_ELEMENT_SIZE , FIELD_ELEMENT_SIZE );
                m_PlayerFild[i][j]->setMinimumSize(FIELD_ELEMENT_SIZE , FIELD_ELEMENT_SIZE );
           }
    }
}

void Field::init(const Ui::MainWindow* ui)
{
    m_ui = ui;
    m_ui->Info->setText(QString("Please connect to Host."));
    for (int i = 0; i < FIELD_SIZE; i ++)
    {
        for (int j = 0; j < FIELD_SIZE; j ++)
        {
            ui->Enemy->addWidget(m_EnemyFild[i][j], i, j);
            ui->Player->addWidget(m_PlayerFild[i][j], i, j);
            QWidget::connect(m_EnemyFild[i][j], SIGNAL(clicked(int, int)), this, SLOT(enemyButtonSlot(int, int)));
            QWidget::connect(m_PlayerFild[i][j], SIGNAL(clicked(int, int)), this, SLOT(playerButtonSlot(int, int)));
            m_EnemyFild[i][j]->setEnabled(false);
            m_PlayerFild[i][j]->setEnabled(false);
        }
    }
}

void Field::startPlaseShips()
{
    m_IsShipsPlasing = true;
    m_ui->Info->setText(QString("Please, drow ships."));
    m_Accept = new QPushButton(QString("OK"));
    if (nullptr != m_ui)
    m_ui->Central->addWidget(m_Accept);
    changeState(FieldState::PREPARING_GAME);
    QWidget::connect(m_Accept, SIGNAL(clicked()), this, SLOT(stopPlaseShips()));

}
void Field::stopPlaseShips()
{
    if (true)
    {
        m_IsShipsPlasing = false;
        QWidget::disconnect(m_Accept, SIGNAL(clicked()), this, SLOT(stopPlaseShips()));
        if (nullptr != m_ui)
        m_ui->Central->removeWidget(m_Accept);
        delete m_Accept;
        changeState(FieldState::OPPONENT_SHOOT);
        m_ui->Info->setText(QString(""));
    }
    else
    {
        m_ui->Info->setText(QString("Wrong! Try Again."));
    }
}
void Field::playerButtonSlot(int i, int j)
{
    if (m_PlayerFild[i][j]->getTag() == PushButton::Tag::EMPTY)
    {
        m_PlayerFild[i][j]->setIcon(QIcon(SHIP_ICON_PATH));
        m_PlayerFild[i][j]->setTag(PushButton::Tag::SHIP);
    }
    else
    {
        m_PlayerFild[i][j]->setIcon(QIcon(EMPTY_ICON_PATH));
        m_PlayerFild[i][j]->setTag(PushButton::Tag::EMPTY);
    }
}
void Field::enemyButtonSlot(int i, int j)
{

}
void Field::changeState(const FieldState state)
{
    switch (state) {
        case FieldState::PREPARING_GAME:
        {
            for (int i = 0; i < FIELD_SIZE; i++)
            {
                for (int j = 0; j < FIELD_SIZE; j++)
                {
                    m_EnemyFild[i][j]->setEnabled(false);
                    m_PlayerFild[i][j]->setEnabled(true);
                }
            }
            m_FieldState = state;
            break;
        }
        case FieldState::SHOOT:
        {
            for (int i = 0; i < FIELD_SIZE; i++)
            {
                for (int j = 0; j < FIELD_SIZE; j++)
                {
                    m_EnemyFild[i][j]->setEnabled(true);
                    m_PlayerFild[i][j]->setEnabled(false);
                }
            }
            m_FieldState = state;
            break;
        }
        case FieldState::OPPONENT_SHOOT:
        {
            for (int i = 0; i < FIELD_SIZE; i++)
            {
                for (int j = 0; j < FIELD_SIZE; j++)
                {
                    m_EnemyFild[i][j]->setEnabled(false);
                    m_PlayerFild[i][j]->setEnabled(false);
                }
            }
            m_FieldState = state;
            break;
        }
        default:
        {
            break;
        }
    }
}
void Field::changeIconOn(const FieldOwner player, const int x, const int y, const char* icon)
{
    switch (player) {
    case FieldOwner::PLAYER:
    {
        m_PlayerFild[y][x]->setIcon(QIcon(icon));
        break;
    }
    case FieldOwner::ENEMY:
    {
        m_EnemyFild[y][x]->setIcon(QIcon(icon));
        break;
    }
    default:
        break;
    }
}
void Field::clear()
{
    for (int i = 0; i < FIELD_SIZE; i++)
    {
        for (int j = 0; j < FIELD_SIZE; j++)
        {
            m_PlayerFild[i][j]->setIcon(QIcon(EMPTY_ICON_PATH));
            m_EnemyFild[i][j]->setIcon(QIcon(EMPTY_ICON_PATH));
        }
    }
}
Field::~Field()
{
    for (int i = 0; i < FIELD_SIZE; i ++)
    {
        for (int j = 0; j < FIELD_SIZE; j ++)
        {
            if (nullptr != m_EnemyFild[i][j])
            {
                delete m_EnemyFild[i][j];
            }
        }
    }
    for (int i = 0; i < FIELD_SIZE; i ++)
    {
        for (int j = 0; j < FIELD_SIZE; j ++)
        {
            if (nullptr != m_PlayerFild[i][j])
            {
                delete m_PlayerFild[i][j];
            }
        }
    }
    if (nullptr != m_Accept)
    {
        delete m_Accept;
    }
}
