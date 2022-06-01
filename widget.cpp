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
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_recipes_listView_clicked(const QModelIndex &index)
{
    ui->recipe_name->setText(model->data(index, Qt::DisplayRole).toString());
    ui->recipe_name->show();
    std::vector<Recipe> recipes = model->Get();
    for (auto i = 0; i < recipes[index.row()].ingredients.size(); i++){
    switch (i){
    case 0:{
    ui->in1->setText(recipes[index.row()].ingredients[0].first);
    ui->spin1->show();
    ui->spin1->setValue(recipes[index.row()].ingredients[0].second);
    break;
    }
    case 1:{
        ui->in2->setText(recipes[index.row()].ingredients[1].first);
        ui->spin2->show();
        ui->spin2->setValue(recipes[index.row()].ingredients[1].second);
        break;
    }
    case 2:{
        ui->in3->setText(recipes[index.row()].ingredients[2].first);
        ui->spin3->show();
        ui->spin3->setValue(recipes[index.row()].ingredients[2].second);
        break;
    }
    case 3:{
        ui->in4->setText(recipes[index.row()].ingredients[3].first);
        ui->spin4->show();
        ui->spin4->setValue(recipes[index.row()].ingredients[3].second);
        break;
    }
    case 4:{
        ui->in5->setText(recipes[index.row()].ingredients[4].first);
        ui->spin1->show();
        ui->spin5->setValue(recipes[index.row()].ingredients[4].second);
        break;
    }
    }
    }
        switch (recipes[index.row()].ingredients.size()){
        case 1:{
            ui->in2->clear();
            ui->spin2->hide();
        }
        case 2:{
            ui->in3->clear();
            ui->spin3->hide();
            }
        case 3:{
            ui->in4->clear();
            ui->spin4->hide();
            }
        case 4:{
            ui->in5->clear();
            ui->spin5->hide();
        }
        default:
            break;
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

