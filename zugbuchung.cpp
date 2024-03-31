#include "zugbuchung.h"
#include "ui_zugbuchung.h"

zugbuchung::zugbuchung(Booking* B,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::zugbuchung)
{
    ui->setupUi(this);
    TrainTicket *t = dynamic_cast<TrainTicket*> (B);

    QString dateTime = t->getFromDate() + " " + t->getDepartureTime();
    QDateTime departureDateTime = QDateTime::fromString(dateTime, "yyyyMMdd hh:mm");

    QString dateTimeTwo = t->getToDate() + " " + t->getArrivalTime();
    QDateTime arrivalDateTime = QDateTime::fromString(dateTimeTwo, "yyyyMMdd hh:mm");

    ui->idLineEdit->setText(t->getId());
    ui->vonDateTimeEdit->setDateTime(departureDateTime);
    ui->bisDateTimeEdit->setDateTime(arrivalDateTime);
    ui->preisDoubleSpinBox->setValue(t->getPrice());
    ui->abfahrtLineEdit->setText(t->getFromDestination());
    ui->ankunftLineEdit->setText(t->getToDestination());
    const QVector <QString> bvector = t->getConnectingStations();
    QString ausgeben = " ";
    for(auto e: bvector){
        ausgeben = ausgeben + e + "\n";
    }
    ui->uberTextBrowser->setText(ausgeben);
}

zugbuchung::~zugbuchung()
{
    delete ui;
}
