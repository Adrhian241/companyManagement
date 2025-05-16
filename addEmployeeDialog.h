#ifndef ADDEMPLOYEEDIALOG_H
#define ADDEMPLOYEEDIALOG_H


#include <QDialog>
QT_BEGIN_NAMESPACE
namespace Ui {
class dialogAdd;
}
QT_END_NAMESPACE

class AddEmployeeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddEmployeeDialog(QWidget *parent = nullptr);
    ~AddEmployeeDialog();

    QString getName() const;
    QString getSurname() const;
    int getAge()const;
    QString getPosition()const;
private slots:


private:
    Ui::dialogAdd *ui;
};

#endif // ADDEMPLOYEEDIALOG_H
