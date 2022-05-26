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
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_recipes_listView_clicked(const QModelIndex &index)
{
    QMessageBox::warning(this,
                         tr("\"on_recipes_listView_clicked\" method is not implemented."),
                         tr("It is one of the methods you need to implement\n"
                            "to complete the assignment.")
                         );
}


void Widget::on_pushButton_clicked()
{
    auto * dialog = new AddRecipeDialog();
    QMessageBox::warning(this,
                         tr("\"on_pushButton_clicked\" method is partly implemented."),
                         tr("You need to fully implement the method\n"
                            "to complete the assignment.")
                         );
}

