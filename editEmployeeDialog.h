#ifndef EDITEMPLOYEEDIALOG_H
#define EDITEMPLOYEEDIALOG_H

#include <QDialog>
QT_BEGIN_NAMESPACE
namespace Ui {
class dialogEdit;
}
QT_END_NAMESPACE

class EditEmployeeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditEmployeeDialog(QWidget *parent = nullptr);
    ~EditEmployeeDialog();
    void setCurrentValues(const QString &name,const QString &surname,int age,const QString &position);

    bool isNameChanged()const;
    bool isSurnameChanged()const;
    bool isAgeChanged()const;
    bool isPositionChanged()const;

    QString getNewName() const;
    QString getNewSurname() const;
    int getNewAge() const;
    QString getNewPosition() const;

private:
    Ui::dialogEdit *ui;
};

#endif // EDITEMPLOYEEDIALOG_H
