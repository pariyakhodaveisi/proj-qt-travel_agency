#include "travelagency.h"

TravelAgency::TravelAgency() {}

QString TravelAgency::readFile(const QString &filePath)
{
    QString summary;

    QString type, id, fromDate, toDate;
    double price;
    //Flug
    QString airline, fromDestination, toDestination;
    //Auto
    QString pickupLocation, returnLocation, company;
    //Hotel
    QString hotel, town;
    //Train
    QString departureTime, arrivalTime, fromStation, toStation;
    QVector<QString> connectingStations;

    int flightCounter = 0, flightPrice = 0;
    int hotelCounter = 0, hotelPrice = 0;
    int carCounter = 0, carPrice = 0;
    int trainCounter = 0, trainPrice = 0;
    int zeilenCounter = 0;

    QFile dateiFile(filePath);

    if(!dateiFile.open(QIODevice::ReadOnly)){
        qDebug() << filePath << " could not be opened";
        return QString("File could not be opened");
    }else {
        qDebug() << filePath << "opened successfully";
    }

    QByteArray json_byte = dateiFile.readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(json_byte);

    QJsonArray json_array = json_doc.array();

    for(const QJsonValue &json_value: json_array){
        zeilenCounter++;
        QJsonObject json_obj = json_value.toObject();

        type = json_obj["type"].toString();
        id = json_obj["id"].toString();
        fromDate = json_obj["fromDate"].toString();
        toDate = json_obj["toDate"].toString();
        price = json_obj["price"].toDouble();

        //check for empty values

        if(type.isEmpty()|| id.isEmpty() || fromDate.isEmpty() || toDate.isEmpty()){
            throw std::runtime_error("Leeres oder ungültiges Feld in Objekt " + std::to_string(zeilenCounter) + "/n" +"Das Einlesen der Buchungen wurde in der betroffenen Zeile gestoppt.Die vorangehenden Buchungen wurden erfolgreich angelegt.");
        }
        if(!json_obj["price"].isDouble()){
            throw runtime_error(" Keinen numerischen Wert im Array " +  std::to_string(zeilenCounter));
        }

        if(type == "Flight"){
            airline = json_obj["airline"].toString();
            fromDestination = json_obj["fromDest"].toString();
            toDestination = json_obj["toDest"].toString();

            bookings.push_back(new FlightBooking(id, price, fromDate, toDate, fromDestination, toDestination, airline));
            flightCounter++;
            flightPrice += price;
        }

        else if(type == "RentalCar"){
            pickupLocation = json_obj["pickupLocation"].toString();
            returnLocation = json_obj["returnLocation"].toString();
            company = json_obj["company"].toString();

            bookings.push_back(new RentalCarReservation(id, price, fromDate, toDate, pickupLocation, returnLocation, company));
            carCounter++;
            carPrice += price;
        }
        else if(type == "Hotel"){
            hotel = json_obj["hotel"].toString();
            town = json_obj["town"].toString();

            bookings.push_back(new HotelBooking(id, price, fromDate, toDate, hotel, town));
            hotelCounter++;
            hotelPrice += price;
        }
        else if(type == "Train"){
            departureTime = json_obj["departureTime"].toString();
            arrivalTime = json_obj["arrivalTime"].toString();
            fromStation = json_obj["fromStation"].toString();
            toStation = json_obj["toStation"].toString();
            QJsonArray connectingStationsArray = json_obj["connectingStations"].toArray();
            for(const QJsonValue &stations : connectingStationsArray){
                connectingStations.push_back(stations.toString());
            }

            bookings.push_back(new TrainTicket(id, price, fromDate, toDate, fromStation, toStation, departureTime, arrivalTime, connectingStations));
            trainCounter++;
            trainPrice += price;
        }
    }

    summary += "Zusammenfassung der Buchungen der JsonFile\n";
    summary += "Es wurden " + QString::number(flightCounter) + "Flugbuchungen gemacht. Preis: " + QString::number(flightPrice) + "\n";
    summary += "Es wurden " + QString::number(hotelCounter) + " Hotelbuchungen gemacht. Preis: " + QString::number(hotelPrice) + "\n";
    summary += "Es wurden " + QString::number(carCounter) + " Autobuchungen gemacht. Preis: " + QString::number(carPrice) + "\n";
    summary += "Es wurden " + QString::number(trainCounter) + " Zugbuchungen gemacht. Preis: " + QString::number(trainPrice) + "\n";

    return summary;

}

vector<Booking *> TravelAgency::getBookings() const
{
    return bookings;
}

TravelAgency::~TravelAgency(){
    for(Booking* Buchungen:bookings){
        delete Buchungen;
    }
}
