#include "autobuchung.h"
#include "rentalcarreservation.h"
#include "ui_autobuchung.h"

autobuchung::autobuchung(Booking* B,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::autobuchung)
{
    ui->setupUi(this);
    RentalCarReservation *c = dynamic_cast<RentalCarReservation*> (B);

    QString dateTime = c->getFromDate();
    QDate vonDate = QDate::fromString(dateTime, "yyyyMMdd");

    QString dateTime2 = c->getToDate();
    QDate bisDate = QDate::fromString(dateTime2, "yyyyMMdd");

    ui->IDlineEdit->setText(c->getId());
    ui->VondateEdit->setDate(vonDate);
    ui->BisdateEdit->setDate(bisDate);
    ui->PreisdoubleSpinBox->setValue(c->getPrice());
    ui->PickUplineEdit->setText(c->getPickupLocation());
    ui->ReturnlineEdit->setText(c->getReturnLocation());



}

autobuchung::~autobuchung()
{
    delete ui;
}
