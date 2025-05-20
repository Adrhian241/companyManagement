#include "attendanceDialog.h"
#include "ui_attendanceDialog.h"
#include <QSpinBox>
#include <QMessageBox>

attendanceDialog::attendanceDialog(const std::vector<Employee>& employees,std::vector<std::array<int, 7>>& workHours,std::vector<double>& hourlyRate, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::attendanceDialog)
    , workHours(workHours)
    , hourlyRate(hourlyRate)
    , workHoursCopy(workHours)
    , hourlyRateCopy(hourlyRate)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(9);
    ui->tableWidget->setHorizontalHeaderLabels({"Pn", "Wt", "Śr", "Czw", "Pt", "Sb", "Nd","Stawka","Pensja"});
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    setupTable(employees);
}

attendanceDialog::~attendanceDialog()
{
    delete ui;

}

QString attendanceDialog::getEmployee(const Employee& emp) const{
    return emp.getName() + " " +emp.getSurname();
}



void attendanceDialog::setupTable(const std::vector<Employee>& employees){


    ui->tableWidget->setRowCount(static_cast<int>(employees.size()));
    for(int row=0;row<static_cast<int>(employees.size());++row){
        const Employee& emp = employees[row];
        QString person = getEmployee(emp);

        ui->tableWidget->setVerticalHeaderItem(row, new QTableWidgetItem(person));      //Dopisanie danych osoby do tabeli

        for(int col=0;col<7;++col){
            QSpinBox *spinBox = new QSpinBox;
            spinBox->setRange(0,12);
            spinBox->setValue(workHoursCopy[row][col]); //Wartość wczytana z vectora

            connect(spinBox, QOverload<int>::of(&QSpinBox::valueChanged), [=](int val){                //[=] = wszystkie zmienne przekazywane są przez wartość
                workHoursCopy[row][col]=val;
                updateSalary(row);
            });

            ui->tableWidget->setCellWidget(row,col,spinBox);
        }
        QDoubleSpinBox *dSpinBox = new QDoubleSpinBox;
        dSpinBox->setRange(0.0,1000.0);
        dSpinBox->setSuffix(" zł");
        //dSpinBox->setDecimals(2);
        dSpinBox->setValue(hourlyRateCopy[row]);
        connect(dSpinBox, QOverload<double>::of(&QDoubleSpinBox::valueChanged), [=](double val){
            hourlyRateCopy[row]=val;
            updateSalary(row);
        });
        ui->tableWidget->setCellWidget(row,7,dSpinBox);

        QTableWidgetItem *salary = new QTableWidgetItem;
        salary->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row,8,salary);   // Wypisanie 'salary' do tabelki
        updateSalary(row);

    }
}

void attendanceDialog::updateSalary(int row){
    int allHours = 0;
    for (int i = 0; i < 7; ++i)
        allHours += workHoursCopy[row][i];     // Sumowanie ilosci przepracowanych godzin

    double salary = allHours * hourlyRateCopy[row];
    QTableWidgetItem *item = ui->tableWidget->item(row,8);
    if(item){
        item->setText(QString::number(salary,'f',2)+" zł");
    }
}

void attendanceDialog::accept(){
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        for (int col = 0; col < 7; ++col) {
            QSpinBox *spinBox = qobject_cast<QSpinBox*>(ui->tableWidget->cellWidget(row,col));
            if(spinBox){
                workHours[row][col] = spinBox->value();
            }}
        QDoubleSpinBox *dSpinBox = qobject_cast<QDoubleSpinBox*>(ui->tableWidget->cellWidget(row,7));
        if(dSpinBox){
            hourlyRate[row]=dSpinBox->value();
        }

    }

    QDialog::accept();
    QMessageBox::information(this,"Sukces!","Dane zostały pomyślnie zapisane");
}
void attendanceDialog::reject() {
    QDialog::reject();
    QMessageBox::information(this,"Odrzucono","Zmiany nie zostały zapisane");
}
