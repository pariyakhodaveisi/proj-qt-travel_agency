#ifndef FLUGBUCHUNG_H
#define FLUGBUCHUNG_H

#include <QDialog>
#include "booking.h"
#include "flightbooking.h"
#include <QDate>

namespace Ui {
class flugbuchung;
}

class flugbuchung : public QDialog
{
    Q_OBJECT

public:
    explicit flugbuchung(Booking* B,QWidget *parent = nullptr);
    ~flugbuchung();

private:
    Ui::flugbuchung *ui;
};

#endif // FLUGBUCHUNG_H
