#include "widget.h"
#include "ui_widget.h"

#include "addrecipedialog.h"

#include <QSpinBox>
#include <QMessageBox>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , model(new RecipesModel)
{
    ui->setupUi(this);

    ui->recipes_listView->setModel(model);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_recipes_listView_clicked(const QModelIndex &index)
{
    ui->label->clear();
    ui->label_3->clear();
    ui->label_4->clear();
    ui->label_5->clear();
    ui->label_6->clear();
    ui->label_name->clear();
    ui->spinBox->clear();
    ui->spinBox_3->clear();
    ui->spinBox_4->clear();
    ui->spinBox_5->clear();
    ui->spinBox_6->clear();
    ui->label_name->setText(model->data(index, Qt::DisplayRole).toString());
    for(auto i : model->m_recipes){
        if(model->data(index, Qt::DisplayRole).toString() == i.name){
            int size = i.ingredients.size();
            if(size > 0){
                ui->label->setText(i.ingredients[0].first);
                ui->spinBox->setValue(i.ingredients[0].second);
            }
            if(size > 1){
                ui->label_3->setText(i.ingredients[1].first);
                ui->spinBox_3->setValue(i.ingredients[1].second);
            }
            if(size > 2){
                ui->label_4->setText(i.ingredients[2].first);
                ui->spinBox_4->setValue(i.ingredients[2].second);
            }
            if(size > 3){
                ui->label_6->setText(i.ingredients[3].first);
                ui->spinBox_6->setValue(i.ingredients[3].second);
            }
            if(size > 4){
                ui->label_5->setText(i.ingredients[4].first);
                ui->spinBox_5->setValue(i.ingredients[4].second);
            }
            if(size > 5){
                QMessageBox::warning(this,
                                         tr("Too big recipe. "),
                                         tr("You will not cook this dish , be sure !")
                                         );
            }
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

