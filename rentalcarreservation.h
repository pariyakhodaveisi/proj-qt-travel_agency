#ifndef RENTALCARRESERVATION_H
#define RENTALCARRESERVATION_H

#include "booking.h"


class RentalCarReservation: public Booking
{
public:
    RentalCarReservation(QString id, double price, QString fromDate, QString toDate, QString pickupLocation, QString returnLocation, QString company);
    virtual ~RentalCarReservation();
    virtual QString showDetails() override;
    const QString &getPickupLocation() const;

    const QString &getReturnLocation() const;

    const QString &getCompany() const;

private:
    QString pickupLocation;
    QString returnLocation;
    QString company;

};

#endif // RENTALCARRESERVATION_H
