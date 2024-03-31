#ifndef AUTOBUCHUNG_H
#define AUTOBUCHUNG_H

#include <QDialog>
#include <QDate>
#include "booking.h"

namespace Ui {
class autobuchung;
}

class autobuchung : public QDialog
{
    Q_OBJECT

public:
    explicit autobuchung(Booking* B,QWidget *parent = nullptr);
    ~autobuchung();

private:
    Ui::autobuchung *ui;
};

#endif // AUTOBUCHUNG_H
