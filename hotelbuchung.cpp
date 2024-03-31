#include "hotelbuchung.h"
#include "ui_hotelbuchung.h"

hotelbuchung::hotelbuchung(Booking* B,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::hotelbuchung)
{
    ui->setupUi(this);
    HotelBooking* h = dynamic_cast<HotelBooking*> (B);

    QString dateTime = h->getFromDate();
    QDate vonDate = QDate::fromString(dateTime, "yyyyMMdd");

    QString dateTimeTwo = h->getToDate();
    QDate bisDate = QDate::fromString(dateTimeTwo, "yyyyMMdd");

    ui->idLineEdit->setText(h->getId());
    ui->vonDateEdit->setDate(vonDate);
    ui->bisDateEdit->setDate(bisDate);
    ui->hotelLineEdit->setText(h->getHotel());
    ui->townLineEdit->setText(h->getTown());
}

hotelbuchung::~hotelbuchung()
{
    delete ui;
}
