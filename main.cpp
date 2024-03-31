#include "travelagencyui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //TravelAgency* travelagency = new TravelAgency;
     //TravelAgencyUi w(travelagency);
    auto agency = std::make_unique<TravelAgency>();
    TravelAgencyUi w(std::move(agency));
    w.show();
    return a.exec();
}
