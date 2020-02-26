#include "buttontest.h"
#include <QMessageBox>

ButtonTest::ButtonTest(QWidget *parent)
    :ButtonCommon(parent)
{
    m_iconType = "";
    m_iconLockOpen = "";
    m_iconLockClose = "";
    m_iconPointPink = "";
    m_iconPointGreen = "";

    m_lockStatus = true;
    m_pointStatus = false;

    m_typeCode = 0;
    m_actionCode = 0;

    m_actionEnable = false;
}
ButtonTest::~ButtonTest()
{
}
void ButtonTest::setTypeCode(ushort code)
{
    m_typeCode = code;
}
void ButtonTest::setLockStatus(bool status)
{
    m_lockStatus = status;
}
void ButtonTest::setPointStatus(bool status)
{
    m_pointStatus = status;
}
void ButtonTest::setTypeIconPath(QString iconPath)
{
    m_iconType = iconPath;
}
void ButtonTest::setLockOpenIconPath(QString iconPath)
{
    m_iconLockOpen = iconPath;
}
void ButtonTest::setLockCloseIconPath(QString iconPath)
{
    m_iconLockClose = iconPath;
}
void ButtonTest::setPointPinkIconPath(QString iconPath)
{
    m_iconPointPink = iconPath;
}
void ButtonTest::setPointGreenIconPath(QString iconPath)
{
    m_iconPointGreen = iconPath;
}
void ButtonTest::setActionEnable(bool status)
{
    m_actionEnable = status;
}
void ButtonTest::paintEvent(QPaintEvent *event)
{
    ButtonCommon::paintEvent(event);

    QPainter painter(this);
    QPixmap pixmap;
    if (!m_iconType.isEmpty())
    {
        pixmap.load(m_iconType);
        painter.drawPixmap(rect().x()+rect().width()/2 - pixmap.width()/2,rect().y()+rect().height()/2 - pixmap.height(),pixmap.width(),pixmap.height(),pixmap);
    }

    if (m_lockStatus)
        pixmap.load(m_iconLockClose);
    else
        pixmap.load(m_iconLockOpen);
    painter.drawPixmap(rect().x()+rect().width()/2 - pixmap.width()/2,rect().y()+rect().height()/2,pixmap.width(),pixmap.height(),pixmap);

    if (m_pointStatus)
        pixmap.load(m_iconPointGreen);
    else
        pixmap.load(m_iconPointPink);
    painter.drawPixmap(rect().x()+rect().width()/2 - pixmap.width()/2,rect().y()+rect().height()/7 - pixmap.height(),pixmap.width(),pixmap.height(),pixmap);

    if (!this->text().isEmpty())
    {
        painter.setPen(Qt::white);
        painter.drawText(rect().x(),rect().y() - rect().height()/4,rect().width(),rect().height(), Qt::AlignCenter, this->text());
    }
}
void ButtonTest::mousePressEvent(QMouseEvent *event)
{
    ButtonCommon::mousePressEvent(event);

    if(event->button() == Qt::LeftButton)
    {
        m_actionCode = m_lockStatus?open:close;
        if(m_actionEnable)
        {
            emit sendDataSignal(m_typeCode,m_actionCode);
        }
        m_lockStatus = m_lockStatus?false:true;
    }
}
