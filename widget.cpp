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

    ui->recepies->setModel(model);
    ui->recepies->show();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_recepies_clicked(const QModelIndex &index)
{
//    ui->name_of->setText(model->data(index, Qt::DisplayRole).toString());
//
//    ui->name_of->show();
    for (auto the_pair: model->m_recipes) {
        ui->name_of_ingredient->setText(model->m_recipes[index.row()].ingredients[0].first);
        ui->mass->setValue(model->m_recipes[index.row()].ingredients[1].second);
    }


}


void Widget::on_pushButton_clicked()
{
    auto * dialog = new AddRecipeDialog();

    dialog->exec();
    model->addRecipe(dialog->getRecipe());
    ui->recepies->setModel(model);
    ui->recepies->show();
}

