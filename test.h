#ifndef TEST_H
#define TEST_H

#include <QWidget>
#include "buttoncommon.h"
#include "buttontest.h"
#include "dataprocess.h"

namespace Ui {
class Test;
}

class Test : public QWidget
{
    Q_OBJECT

public:
    enum typeCode
    {
        typeT1 = 0x0810,
        typeT2 = 0x0910,
        typeQ1 = 0x0A10,
    };

    explicit Test(QWidget *parent = nullptr);
    ~Test();

    void resizeEvent(QResizeEvent *);
    void setBackgroundImage(QPixmap &pixmap);

signals:
    void toMainSignal();

private slots:
    void on_btToMain_clicked();

private:
    Ui::Test *ui;
    QPixmap m_pixmap;
    DataProcess *dataProcess;
};

#endif // TEST_H
