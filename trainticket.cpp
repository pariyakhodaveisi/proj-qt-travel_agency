#include "trainticket.h"


TrainTicket::TrainTicket(QString id, double price, QString fromDate, QString toDate, QString fromDestination, QString toDestination, QString departureTime, QString arrivalTime, QVector<QString> connectingStations):
    Booking(id, price, fromDate, toDate), fromDestination(fromDestination), toDestination(toDestination), departureTime(departureTime), arrivalTime(arrivalTime), connectingStations(connectingStations)
{

}

QString TrainTicket::showDetails()
{
    QString buchung_info = "Zugticket von " + fromDestination + " nach " + toDestination + " am " + fromDate + " von " + departureTime + " bis "
                     + arrivalTime + " über ";

    //mit der Hilfe von for Schleife, alle Stationen zum QString buchung_info hinzufuegen
    for(const auto& station: connectingStations){
        buchung_info += station + ", ";
    }

    buchung_info += ". Preis: " + QString::number(price) + " Euro";

    return buchung_info;
}

TrainTicket::~TrainTicket()
{

}

const QString &TrainTicket::getFromDestination() const
{
    return fromDestination;
}

const QString &TrainTicket::getToDestination() const
{
    return toDestination;
}

const QString &TrainTicket::getDepartureTime() const
{
    return departureTime;
}

const QString &TrainTicket::getArrivalTime() const
{
    return arrivalTime;
}

const QVector<QString> &TrainTicket::getConnectingStations() const
{
    return connectingStations;
}

