#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H
#include "booking.h"
#include "flightbooking.h"
#include "rentalcarreservation.h"
#include "hotelbooking.h"
#include "trainticket.h"
#include <iostream>
#include <vector>
#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QVector>



class TravelAgency
{
public:
    TravelAgency();
    QString readFile(const QString &filePath);
    void readBinaryFile();
    void printBooking();
    void menue();


    ~TravelAgency();
    vector<Booking *> getBookings() const;

private:
    vector<Booking*> bookings;
};

#endif // TRAVELAGENCY_H
