#include "widget.h"
#include "ui_widget.h"

#include "addrecipedialog.h"

#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , model(new RecipesModel)
{
    ui->setupUi(this);

    ui->recipes_listView->setModel(model);
    ui->recipes_listView->show();

    ui->spinBox_1->hide();
    ui->spinBox_2->hide();
    ui->spinBox_3->hide();
    ui->spinBox_4->hide();
    ui->spinBox_5->hide();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_recipes_listView_clicked(const QModelIndex &index)
{
        ui->spinBox_1->hide();
        ui->spinBox_2->hide();
        ui->spinBox_3->hide();
        ui->spinBox_4->hide();
        ui->spinBox_5->hide();
        ui->i1->clear();
        ui->i2->clear();
        ui->i3->clear();
        ui->i4->clear();
        ui->i5->clear();

        ui->label_2->setText("            " + model->data(index, Qt::DisplayRole).toString());

        int count = model->GetSize(index.row());
   if(count <= 5){
        if(1 <= count ){
        ui->i1->setText(model->GetIngridient(0));
        ui->spinBox_1->setValue(model->GetWeight(0));
        ui->spinBox_1->show();
        }
        if(2 <= count){
        ui->i1->setText(model->GetIngridient(1));
        ui->spinBox_2->setValue(model->GetWeight(1));
        ui->spinBox_2->show();
        }
        if(3 <= count){
        ui->i1->setText(model->GetIngridient(2));
        ui->spinBox_3->setValue(model->GetWeight(2));
        ui->spinBox_3->show();
        }
        if(4 <= count){
        ui->i1->setText(model->GetIngridient(3));
        ui->spinBox_4->setValue(model->GetWeight(3));
        ui->spinBox_4->show();
        }
        if(5 <= count){
        ui->i1->setText(model->GetIngridient(4));
        ui->spinBox_5->setValue(model->GetWeight(4));
        ui->spinBox_5->show();
        }
   }

}


void Widget::on_pushButton_clicked()
{
    auto * dialog = new AddRecipeDialog();
    dialog->exec();
    model->addRecipe(dialog->getRecipe());
    ui->recipes_listView->setModel(model);
    ui->recipes_listView->show();
}

