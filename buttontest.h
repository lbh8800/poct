#ifndef BUTTONTEST_H
#define BUTTONTEST_H
#include "buttoncommon.h"

class ButtonTest : public ButtonCommon
{
    Q_OBJECT

public:
    enum actionCode
    {
        open = 0x0002,
        close = 0x0003,
    };

    explicit ButtonTest(QWidget *parent = nullptr);
    ~ButtonTest();

    void setTypeIconPath(QString iconPath);
    void setLockOpenIconPath(QString iconPath);
    void setLockCloseIconPath(QString iconPath);
    void setPointPinkIconPath(QString iconPath);
    void setPointGreenIconPath(QString iconPath);

    void setLockStatus(bool status);
    void setPointStatus(bool status);
    void setTypeCode(ushort code);

    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

    void setActionEnable(bool status);

signals:
    void sendDataSignal(ushort typeCode, ushort actionCode);

private:
    QString m_iconType;
    QString m_iconLockOpen;
    QString m_iconLockClose;
    QString m_iconPointPink;
    QString m_iconPointGreen;

    bool m_lockStatus;
    bool m_pointStatus;
    ushort m_typeCode;
    ushort m_actionCode;

    bool m_actionEnable;
};

#endif // BUTTONTEST_H
