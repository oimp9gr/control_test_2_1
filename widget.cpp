#include "widget.h"
#include "ui_widget.h"

#include "addrecipedialog.h"

#include <QMessageBox>

QFont Font_1("Arial Black", 14);
QFont Font_2("Tempus Sans ITC", 10);
QFont Font_3("Tempus Sans ITC", 14);

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , model(new RecipesModel)
{
    ui->setupUi(this);

    ui->recipes_listView->setModel(model);
    ui->recipes_listView->show();
    ui->label->setFont(Font_3);
    ui->wei_1->hide();
    ui->wei_2->hide();
    ui->wei_3->hide();
    ui->wei_4->hide();
    ui->wei_5->hide();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_recipes_listView_clicked(const QModelIndex &index)
{
    ui->wei_1->hide();
    ui->wei_2->hide();
    ui->wei_3->hide();
    ui->wei_4->hide();
    ui->wei_5->hide();
    ui->ingr_1->clear();
    ui->ingr_2->clear();
    ui->ingr_3->clear();
    ui->ingr_4->clear();
    ui->ingr_5->clear();
    ui->recipe_name->setText(model->data(index, Qt::DisplayRole).toString());
    ui->recipe_name->setGeometry(640,50,150,30);
    ui->recipe_name->setFont(Font_1);
    ui->recipe_name->show();
    QLabel* ings = new QLabel(this);
    ings->setText("Ingredients:");
    ings->setFont(Font_2);
    ings->setGeometry(620,100,100,30);
    ings->show();
    int s_ = model->m_recipes[index.row()].ingredients.size();
    ui->ingr_1->setText(model->m_recipes[index.row()].ingredients[0].first);
    ui->wei_1->setValue(model->m_recipes[index.row()].ingredients[0].second);
    ui->wei_1->show();
    if(s_ > 1){
        ui->ingr_2->setText(model->m_recipes[index.row()].ingredients[1].first);
        ui->wei_2->setValue(model->m_recipes[index.row()].ingredients[1].second);
        ui->wei_2->show();
    }
    if(s_ > 2){
        ui->ingr_3->setText(model->m_recipes[index.row()].ingredients[2].first);
        ui->wei_3->setValue(model->m_recipes[index.row()].ingredients[2].second);
        ui->wei_3->show();
    }
    if(s_ > 3){
        ui->ingr_4->setText(model->m_recipes[index.row()].ingredients[3].first);
        ui->wei_4->setValue(model->m_recipes[index.row()].ingredients[3].second);
        ui->wei_4->show();
    }
    if(s_ > 4){
        ui->ingr_5->setText(model->m_recipes[index.row()].ingredients[4].first);
        ui->wei_5->setValue(model->m_recipes[index.row()].ingredients[4].second);
        ui->wei_5->show();
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

