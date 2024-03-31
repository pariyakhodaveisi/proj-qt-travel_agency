#ifndef FLIGHTBOOKING_H
#define FLIGHTBOOKING_H

#include "booking.h"

class FlightBooking: public Booking
{
public:
    FlightBooking(QString id, double price, QString fromDate, QString toDate, QString fromDestination, QString toDestinaton, QString airline);
    virtual QString showDetails() override;
    virtual ~FlightBooking();
    const QString &getFromDestination() const;

    const QString &getToDestination() const;

    const QString &getAirline() const;

private:
    QString fromDestination{};
    QString toDestination{};
    QString airline{};
};

#endif // FLIGHTBOOKING_H
