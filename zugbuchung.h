#ifndef ZUGBUCHUNG_H
#define ZUGBUCHUNG_H

#include <QDialog>
#include"booking.h"
#include "trainticket.h"
#include<QDateTime>

namespace Ui {
class zugbuchung;
}

class zugbuchung : public QDialog
{
    Q_OBJECT

public:
    explicit zugbuchung(Booking* B,QWidget *parent = nullptr);
    ~zugbuchung();

private:
    Ui::zugbuchung *ui;
};

#endif // ZUGBUCHUNG_H
