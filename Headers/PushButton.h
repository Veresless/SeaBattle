#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <QPushButton>
#include <iostream>

class PushButton : public QPushButton
{
    Q_OBJECT
public:
    enum Tag
    {
        EMPTY,
        SHIP,
        MISS,
        DAMAGED
    };
    PushButton(int x, int y, QWidget *parent = nullptr):
        QPushButton(parent),
        m_X(x),
        m_Y(y)
    {
        QWidget::connect(this, SIGNAL(clicked()), this, SLOT(clickedSlot()));
    }
    inline Tag getTag();
    void setTag(const Tag tag)
    {
        m_Tag = tag;
    }
    ~PushButton()
    {
        QWidget::disconnect(this, SIGNAL(clicked()), this, SLOT(clickedSlot()));
    }
public slots:
    void clickedSlot()
    {
        emit clicked(m_X, m_Y);
    }
signals:
    void clicked(int x, int y);
private:
    Tag m_Tag;
    int m_X;
    int m_Y;
};
inline PushButton::Tag PushButton::getTag()
{
    return m_Tag;
}
#endif // PUSHBUTTON_H
