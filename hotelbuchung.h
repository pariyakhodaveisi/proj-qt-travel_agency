#ifndef HOTELBUCHUNG_H
#define HOTELBUCHUNG_H

#include <QDialog>
#include "booking.h"
#include "hotelbooking.h"
#include <QDate>

namespace Ui {
class hotelbuchung;
}

class hotelbuchung : public QDialog
{
    Q_OBJECT

public:
    explicit hotelbuchung(Booking* B,QWidget *parent = nullptr);
    ~hotelbuchung();

private:
    Ui::hotelbuchung *ui;
};

#endif // HOTELBUCHUNG_H
