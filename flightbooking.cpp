#include "flightbooking.h"


FlightBooking::FlightBooking(QString id, double price, QString fromDate, QString toDate, QString fromDestination, QString toDestination, QString airline):
    Booking(id, price, fromDate, toDate), fromDestination(fromDestination), toDestination(toDestination), airline(airline)
{

}

QString FlightBooking::showDetails()
{
    QString buchung_info = "Flugbuchung von " + fromDestination + " nach " + toDestination + " mit " + airline +
            " am " + fromDate + ".Preis: " + QString::number(price) + " Euro.";

    return buchung_info;
}

FlightBooking::~FlightBooking()
{

}

const QString &FlightBooking::getFromDestination() const
{
    return fromDestination;
}

const QString &FlightBooking::getToDestination() const
{
    return toDestination;
}

const QString &FlightBooking::getAirline() const
{
    return airline;
}
