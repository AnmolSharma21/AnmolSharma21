#ifndef ADDCONTACT_H
#define ADDCONTACT_H

#include <QDialog>
#include <QWidget>
#include <QMessageBox>

namespace Ui {
class addContact;
}

class addContact : public QDialog
{
    Q_OBJECT

public:
    explicit addContact(QWidget *parent = nullptr);
    ~addContact();
signals:
    void contactDataAdded(const QString& fName, const QString& lName, const QString& tID, const QString& uName);

private slots:
    void on_pushButton_save_clicked();

private:
    Ui::addContact *ui;
};

#endif // ADDCONTACT_H

