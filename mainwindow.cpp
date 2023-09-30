#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addcontact.h"
#include "editcontact.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pAddContact = new addContact();

    // Connect the signal from pAddContact to the slot in MainWindow
    connect(pAddContact, &addContact::contactDataAdded, this, &MainWindow::onContactDataAdded);

    // Connect the "Add Contact" button click to show the pAddContact
    connect(ui->pushButton_add, &QPushButton::clicked, pAddContact, &addContact::show);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete pAddContact;
}

void MainWindow::onContactDataAdded(const QString& fName, const QString& lName, const QString& tID, const QString& uName)
{
    QString contactData = QString("%1 | %2 | %3 | %4").arg(fName, lName, tID, uName);
    QListWidgetItem* item = new QListWidgetItem(contactData);
    ui->listWidget->addItem(item);
}

void MainWindow::on_pushButton_delete_clicked()
{
    // Get the selected item from the QListWidget
    QListWidgetItem* selectedItem = ui->listWidget->currentItem();
    if (!selectedItem) {
        // If no item is selected,
        QMessageBox::warning(this,tr("Delete"), tr("Please select contact"));
        return;
    }
    // Remove the selected item from the QListWidget
    delete selectedItem;
    QMessageBox::critical(this,tr("Delete"), tr("Deleted!"));
}

void MainWindow::on_pushButton_edit_clicked()
{
    QListWidgetItem* selectedItem = ui->listWidget->currentItem();
    if (!selectedItem) {
        // If no item is selected,
        QMessageBox::warning(this,tr("Edit"), tr("Please select contact"));
        return;
    }

    // Retrieve the data from the selected item
    QString contactData = selectedItem->text();
    QStringList contactDataList = contactData.split(" | ");
    QString f_Name = contactDataList.value(0);
    QString l_Name = contactDataList.value(1);
    QString t_ID = contactDataList.value(2);
    QString u_Name = contactDataList.value(3);

    // Create the edit dialog and set the data
    EditContact editDialog;
    editDialog.setContactData(f_Name, l_Name, t_ID, u_Name);

    // Show the edit dialog as a modal dialog
    if (editDialog.exec() == QDialog::Accepted) {
        // The dialog was accepted (Save button was clicked), update the edited data
        QString editedf_Name = editDialog.getEditedfName();
        QString editedl_Name = editDialog.getEditedlName();
        QString editedt_ID = editDialog.getEditedtID();
        QString editedu_Name = editDialog.getEditeduName();

        // Update the selected item in the QListWidget
        QString editedContactData = QString("%1 | %2 | %3 | %4").arg(editedf_Name, editedl_Name, editedt_ID, editedu_Name);
        selectedItem->setText(editedContactData);
    }
}
