#include "editcontact.h"
#include "ui_editcontact.h"

EditContact::EditContact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditContact)
{
    ui->setupUi(this);
}

EditContact::~EditContact()
{
    delete ui;
}

void EditContact::setContactData(const QString& fName, const QString& lName, const QString& tID, const QString& uName)
{
    ui->lineEdit_firstname->setText(fName);
    ui->lineEdit_lastname->setText(lName);
    ui->lineEdit_terminalid->setText(tID);
    ui->lineEdit_unitname->setText(uName);
}
QString EditContact::getEditedfName() const
{
    return ui->lineEdit_firstname->text();
}

QString EditContact::getEditedlName() const
{
    return ui->lineEdit_lastname->text();
}

QString EditContact::getEditedtID() const
{
    return ui->lineEdit_terminalid->text();
}

QString EditContact::getEditeduName() const
{
    return ui->lineEdit_unitname->text();
}

void EditContact::on_pushButton_save_clicked()
{
    editedfName = ui->lineEdit_firstname->text();
    editedlName = ui->lineEdit_lastname->text();
    editedtID = ui->lineEdit_terminalid->text();
    editeduName = ui->lineEdit_unitname->text();

    // Validate if any of the QLineEdit fields are empty
    if (editedfName.isEmpty() || editedlName.isEmpty() || editedtID.isEmpty() || editeduName.isEmpty()) {
        QMessageBox::warning(this, "Empty Fields", "Please fill in all fields before saving.");
        return;
    }

    QMessageBox::information(this,tr("Edit Contact"), tr("Edited"));

    accept(); // Accept the dialog (close it)
}
