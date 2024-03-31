#include "flugbuchung.h"
#include "ui_flugbuchung.h"

flugbuchung::flugbuchung(Booking* B,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::flugbuchung)
{
    ui->setupUi(this);
    FlightBooking* f = dynamic_cast<FlightBooking*>(B);

    QString dateTime = f->getFromDate();
    QDate vonDate = QDate::fromString(dateTime, "yyyyMMdd");

    QString dateTimeTwo = f->getToDate();
    QDate bisDate = QDate::fromString(dateTimeTwo, "yyyyMMdd");

    ui->idLineEdit->setText(f->getId());
    ui->vonDateEdit->setDate(vonDate);
    ui->bisDateEdit->setDate(bisDate);
    ui->preisDoubleSpinBox->setValue(f->getPrice());
    ui->abfahrtLineEdit->setText(f->getFromDestination());
    ui->ankunftLineEdit->setText(f->getToDestination());
    ui->airlineLineEdit->setText(f->getAirline());
}

flugbuchung::~flugbuchung()
{
    delete ui;
}
