#ifndef BUTTONCOMMON_H
#define BUTTONCOMMON_H
#include <QPushButton>
#include <QPainter>
#include <QMouseEvent>

class ButtonCommon : public QPushButton
{
    Q_OBJECT

public:
    explicit ButtonCommon(QWidget *parent = nullptr);
    ~ButtonCommon();

    void setIconMainPath(QString iconPath);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *);

private:
    enum ButtonStatus{NORMAL, HOVER, PRESS};
    ButtonStatus m_status;
    QString m_iconMain;
    bool m_mousePress;

};

#endif // BUTTONCOMMON_H
