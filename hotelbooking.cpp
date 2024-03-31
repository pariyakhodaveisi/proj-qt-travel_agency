#include "hotelbooking.h"


HotelBooking::HotelBooking(QString id, double price, QString fromDate, QString toDate, QString hotel, QString town):
    Booking(id, price,fromDate, toDate), hotel(hotel), town(town)
{

}


QString HotelBooking::showDetails()
{
    QString buchung_info = "Hotelreservierung im " + hotel +" in " + town + " vom " + fromDate + " bis zum "
            + toDate +"."+ "Preis: " + QString::number(price)  + " Euro.";

    return buchung_info;
}

HotelBooking::~HotelBooking()
{

}

const QString &HotelBooking::getHotel() const
{
    return hotel;
}

const QString &HotelBooking::getTown() const
{
    return town;
}
