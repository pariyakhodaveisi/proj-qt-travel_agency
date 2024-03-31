#include "rentalcarreservation.h"


RentalCarReservation::RentalCarReservation(QString id, double price, QString fromDate, QString toDate, QString pickupLocation, QString returnLocation, QString company):
   Booking(id, price, fromDate, toDate),pickupLocation(pickupLocation), returnLocation(returnLocation), company(company)
{

}

RentalCarReservation::~RentalCarReservation()
{

}

QString RentalCarReservation::showDetails()
{
    QString buchung_info = "Miewagenreservierung mit "+ company + ". Abholung am " +  fromDate + " in " + pickupLocation +". "
            +" Rückgabe am " + toDate + " in " + returnLocation + ". " +" Price: " + QString::number(price)  + " Euro.";

    return buchung_info;
}

const QString &RentalCarReservation::getPickupLocation() const
{
    return pickupLocation;
}

const QString &RentalCarReservation::getReturnLocation() const
{
    return returnLocation;
}

const QString &RentalCarReservation::getCompany() const
{
    return company;
}
