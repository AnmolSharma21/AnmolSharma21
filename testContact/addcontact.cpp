#include "addcontact.h"
#include "ui_addcontact.h"

addContact::addContact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addContact)
{
    ui->setupUi(this);
}

addContact::~addContact()
{
    delete ui;
}

void addContact::on_pushButton_save_clicked()
{
    QString fName = ui->lineEdit_firstname->text();
    QString lName = ui->lineEdit_lastname->text();
    QString tID = ui->lineEdit_terminalid->text();
    QString uName = ui->lineEdit_unitname->text();

    // Validate if any of the QLineEdit fields are empty
    if (fName.isEmpty() || lName.isEmpty() || tID.isEmpty() || uName.isEmpty()) {
        QMessageBox::warning(this, "Empty Fields", "Please fill in all fields before saving.");
        return;
    }

    // Emit the signal with the entered data
    emit contactDataAdded(fName, lName, tID, uName);

    ui->lineEdit_firstname->clear();
    ui->lineEdit_lastname->clear();
    ui->lineEdit_terminalid->clear();
    ui->lineEdit_unitname->clear();
    QMessageBox::information(this,tr("Add Contact"), tr("Saved"));

    accept();   // Accept the dialog (close it)
}
