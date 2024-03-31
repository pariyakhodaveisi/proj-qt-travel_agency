#ifndef TRAVELAGENCYUI_H
#define TRAVELAGENCYUI_H
#include "travelagency.h"

#include "ui_travelagencyui.h"
#include "autobuchung.h"
#include "flugbuchung.h"
#include "hotelbuchung.h"
#include "zugbuchung.h"


#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QPushButton>
#include <QAbstractButton>
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui {
class TravelAgencyUi;
}
QT_END_NAMESPACE

class TravelAgencyUi : public QMainWindow
{
    Q_OBJECT

public:
    //TravelAgencyUi(TravelAgency* agency,QWidget *parent = nullptr);
    explicit TravelAgencyUi(std::unique_ptr<TravelAgency> agency,QWidget *parent = nullptr);
    ~TravelAgencyUi();

private:
    void showMessageBox(const QString &title, const QString &text, QMessageBox::Icon icon, bool showError);
    void loadAndDisplayBookings();
    void displayBookings();
private slots:
    void on_actionEinlesen_triggered();
    void on_listWidget_doubleClicked(const QModelIndex &index);

private:
    Ui::TravelAgencyUi *ui;
    //TravelAgency* _agency = nullptr;
    std::unique_ptr<TravelAgency> _agency;


};
#endif // TRAVELAGENCYUI_H
