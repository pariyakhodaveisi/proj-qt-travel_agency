#include "travelagencyui.h"
#include "ui_travelagencyui.h"

//TravelAgencyUi::TravelAgencyUi(TravelAgency* agency ,QWidget *parent)
TravelAgencyUi::TravelAgencyUi(std::unique_ptr<TravelAgency> agency ,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TravelAgencyUi)
    //,_agency(agency)
    ,_agency(std::move(agency))  //ubernahme den Besitz
{
    ui->setupUi(this);
    ui->listWidget->setVisible(0);
}

TravelAgencyUi::~TravelAgencyUi()
{
    delete ui;
}

void TravelAgencyUi::showMessageBox(const QString &title, const QString &text, QMessageBox::Icon icon, bool showError)
{
    QMessageBox msgBox;
    msgBox.setIcon(icon);
    msgBox.setWindowTitle(title);
    msgBox.setText(text);

    if(showError){
        msgBox.setDetailedText(tr("Wenn Sie die Datei bereits korrigiert haben, wählen Sie 'Retry'. Wählen Sie 'Discard', um alle Buchungen zu löschen und 'Cancel', um die vorhandenen Buchungen stehen zu lassen und diesen Dialog zu verlassen."));
        auto *retryButton = msgBox.addButton(tr("&Retry"), QMessageBox::AcceptRole);
        auto *discardButton = msgBox.addButton(tr("&Discard"), QMessageBox::DestructiveRole);
        auto *cancelButton = msgBox.addButton(tr("&Cancel"), QMessageBox::RejectRole);

        msgBox.exec();

        if(static_cast<QAbstractButton*>(msgBox.clickedButton()) == retryButton){
            on_actionEinlesen_triggered();
        }else if(static_cast<QAbstractButton*> (msgBox.clickedButton()) == discardButton){
            //deleteAllBookings();
        }else if(static_cast<QAbstractButton*> (msgBox.clickedButton()) == cancelButton){

        }
    }else {
        // Für den Fall, dass showError false ist, wird nur eine OK-Schaltfläche benötigt.
        msgBox.addButton(QMessageBox::Ok);
        msgBox.exec();
    }
}



void TravelAgencyUi::on_actionEinlesen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open Booking File"), "",tr("JSON Files(*.json);; All Files(*)"));

    if(!filename.isEmpty()){
        try{
            QString summary = _agency->readFile(filename);
            showMessageBox(tr("File loaded"), tr("The booking file has been loaded successfully.\n\n") + summary, QMessageBox::NoIcon, false);
            loadAndDisplayBookings();
        }catch(const std::runtime_error &e){
            showMessageBox(tr("Error"), e.what(), QMessageBox::NoIcon, true);
        }
    }else {
        // Show message for no file selected
        showMessageBox(tr("No File Selected"), tr("No file was selected."), QMessageBox::NoIcon, false);
    }
}


void TravelAgencyUi::loadAndDisplayBookings() {
    QString loadResult = _agency->readFile("path/to/your/bookings/file");

    if (!loadResult.isEmpty()) {
        displayBookings();
        ui->listWidget->setVisible(true); // Zeigt das QListWidget an
    } else {
        QMessageBox::warning(this, "Ladefehler", "Die Buchungen konnten nicht geladen werden.");
    }
}
void TravelAgencyUi::displayBookings() {
    ui->listWidget->clear(); // Löscht bestehende Einträge im QListWidget
    for (const auto &booking : _agency->getBookings()) {
        QString details = booking->showDetails();
        ui->listWidget->addItem(details);
    }
}










void TravelAgencyUi::on_listWidget_doubleClicked(const QModelIndex &index)
{
    int zahlen = index.row();

    vector<Booking*> bookingV = _agency->getBookings();
    FlightBooking *f = dynamic_cast<FlightBooking*>(bookingV[zahlen]);
    TrainTicket *t = dynamic_cast<TrainTicket*>(bookingV[zahlen]);
    HotelBooking *h = dynamic_cast<HotelBooking*>(bookingV[zahlen]);
    RentalCarReservation *c = dynamic_cast<RentalCarReservation*>(bookingV[zahlen]);

    if(t != nullptr){
        zugbuchung *zug = new zugbuchung(bookingV[zahlen], nullptr);
        zug->setWindowModality(Qt::NonModal);
        zug->show();
    }

    if(f != nullptr){
        flugbuchung *flug = new flugbuchung(bookingV[zahlen], nullptr);
        flug->setWindowModality(Qt::NonModal);
        flug->show();
    }

    if(h != nullptr){
        hotelbuchung *hotel = new hotelbuchung(bookingV[zahlen], nullptr);
        hotel->setWindowModality(Qt::NonModal);
        hotel->show();
    }
    if(c != nullptr){
        autobuchung *car = new autobuchung(bookingV[zahlen], nullptr);
        car->setWindowModality(Qt::NonModal);
        car->show();
    }
}

