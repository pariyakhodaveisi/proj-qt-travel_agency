#include "booking.h"


Booking::Booking(QString id, double price, QString fromDate, QString toDate):
    id(id), price(price), fromDate(fromDate), toDate(toDate)
{

}





Booking::~Booking()
{

}

const QString Booking::getId() const
{
    return id;
}

double Booking::getPrice() const
{
    return price;
}

const QString &Booking::getFromDate() const
{
    return fromDate;
}

const QString &Booking::getToDate() const
{
    return toDate;
}
