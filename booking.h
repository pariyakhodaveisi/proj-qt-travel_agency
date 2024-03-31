#ifndef BOOKING_H
#define BOOKING_H
#include <QString>

using namespace std;


class Booking
{
public:
    Booking(QString id, double price, QString fromDate, QString toDate);
    virtual QString showDetails() = 0;
    virtual ~Booking();

    const QString getId() const;

    double getPrice() const;

    const QString &getFromDate() const;

    const QString &getToDate() const;

protected:
    QString id;
    double price;
    QString fromDate;
    QString toDate;
};

#endif // BOOKING_H
