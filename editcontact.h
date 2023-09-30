#ifndef EDITCONTACT_H
#define EDITCONTACT_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class EditContact;
}

class EditContact : public QDialog
{
    Q_OBJECT

public:
    explicit EditContact(QWidget *parent = nullptr);
    ~EditContact();

    void setContactData(const QString& fName, const QString& lName, const QString& tID, const QString& uName);
    QString getEditedfName() const;
    QString getEditedlName() const;
    QString getEditedtID() const;
    QString getEditeduName() const;

private slots:
    void on_pushButton_save_clicked();

private:
    Ui::EditContact *ui;
    QString editedfName;
    QString editedlName;
    QString editedtID;
    QString editeduName;
};

#endif // EDITCONTACT_H
