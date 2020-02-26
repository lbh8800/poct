#include "buttoncommon.h"

ButtonCommon::ButtonCommon(QWidget *parent)
    :QPushButton(parent)
{
    m_status = NORMAL;
    m_mousePress = false;
    m_iconMain = "";
}
ButtonCommon::~ButtonCommon()
{
}
void ButtonCommon::setIconMainPath(QString Icon_path)
{
    m_iconMain = Icon_path;
    setFixedSize(QPixmap(Icon_path).size());
}
void ButtonCommon::enterEvent(QEvent *)
{
    m_status = HOVER;
    update();
}
void ButtonCommon::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_mousePress = true;
        m_status = PRESS;
        update();
    }
}
void ButtonCommon::mouseReleaseEvent(QMouseEvent *event)
{
    if(m_mousePress&&rect().contains(event->pos()))
    {
        m_mousePress = false;
        m_status = HOVER;
        update();
        emit clicked();
    }
}
void ButtonCommon::leaveEvent(QEvent *)
{
    m_status = NORMAL;
    update();
}
void ButtonCommon::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pixmap;
    switch(m_status)
    {
    case NORMAL:
    {
        pixmap.load(m_iconMain);
        break;
    }
    case HOVER:
    case PRESS:
    {
        pixmap.load(m_iconMain + QString("-press"));
        break;
    }
    default:
        pixmap.load(m_iconMain);
    }

    painter.drawPixmap(rect(), pixmap);
}
