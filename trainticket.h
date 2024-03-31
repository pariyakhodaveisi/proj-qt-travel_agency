#ifndef TRAINTICKET_H
#define TRAINTICKET_H

#include <QVector>
#include "booking.h"

class TrainTicket : public Booking
{
public:
    TrainTicket(QString id, double price, QString fromDate, QString toDate, QString fromDestination, QString toDestination, QString departureTime,
                QString arrivalTime, QVector<QString> connectingStations);
    virtual QString showDetails() override;
    virtual ~TrainTicket();
    const QString &getFromDestination() const;

    const QString &getToDestination() const;

    const QString &getDepartureTime() const;

    const QString &getArrivalTime() const;

    const QVector<QString> &getConnectingStations() const;

private:
    QString fromDestination;
    QString toDestination;
    QString departureTime;
    QString arrivalTime;
    QVector<QString> connectingStations;
};

#endif // TRAINTICKET_H
