#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include <QPushButton>
#include <QWidget>
#include <QListWidget>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class addContact;   // Forward declaration

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onContactDataAdded(const QString& fName, const QString& lName, const QString& tID, const QString& uName);

    void on_pushButton_delete_clicked();

    void on_pushButton_edit_clicked();

private:
    Ui::MainWindow *ui;
    addContact *pAddContact;
};
#endif // MAINWINDOW_H
