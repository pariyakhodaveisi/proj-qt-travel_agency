#ifndef HOTELBOOKING_H
#define HOTELBOOKING_H
#include "booking.h"

class HotelBooking : public Booking
{
public:
    HotelBooking(QString id, double price, QString fromDate, QString toDate, QString hotel, QString town);
    virtual QString showDetails() override;
    virtual ~HotelBooking();
    const QString &getHotel() const;

    const QString &getTown() const;

private:
    QString hotel{};
    QString town{};
};

#endif // HOTELBOOKING_H
