#include "addrecipedialog.h"
#include "ui_addrecipedialog.h"

#include <QTimer>
#include <QSpinBox>

AddRecipeDialog::AddRecipeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRecipeDialog),
    recipe({"", {{"", 0}}})
{
    ui->setupUi(this);
    ui->error_label->hide();

    connect(ui->i1_lineEdit, &QLineEdit::textChanged, [=] (const QString & value) { updateRecipeIngredient(1, value); });
    //connect(ui->i1_spinBox, &QSpinBox::valueChanged, [=] (int value) { updateRecipeWeight(1, value); });
}

AddRecipeDialog::~AddRecipeDialog()
{
    delete ui;
}

void AddRecipeDialog::on_recipename_lineEdit_textChanged(const QString &arg1)
{
    recipe.name = arg1;
}

void AddRecipeDialog::on_add_pushButton_clicked()
{
    recipe.ingredients.push_back({"", 0});
    int number = recipe.ingredients.size();

    auto * i_n_lineEdit = new QLineEdit(ui->i1_lineEdit);
    auto * i_n_spinBox = new QSpinBox(ui->i1_spinBox);
    i_n_spinBox->setMaximum(100000);

    auto * i_n_label = new QLabel(ui->i1_label);
    i_n_label->setText(QString::number(number));
    i_n_label->setAlignment(ui->i1_label->alignment());
    i_n_label->setMinimumHeight(ui->i1_label->minimumHeight());

    ui->numbers_verticalLayout->addWidget(i_n_label);
    ui->ingredients_verticalLayout->addWidget(i_n_lineEdit);
    ui->weights_verticalLayout->addWidget(i_n_spinBox);

    connect(i_n_lineEdit, &QLineEdit::textChanged, [=] (const QString & value) { updateRecipeIngredient(number, value); });
    //connect(i_n_spinBox, SIGNAL(valueChanged()), [=] (int value) { updateRecipeWeight(number, value); });
}

void AddRecipeDialog::updateRecipeIngredient(int index, const QString &ingredient)
{
    recipe.ingredients[index - 1].first = ingredient;
}

void AddRecipeDialog::updateRecipeWeight(int index, int weight)
{
    recipe.ingredients[index - 1].second = weight;
}

void AddRecipeDialog::on_ok_pushButton_clicked()
{
    for (auto & [ing, weight] : recipe.ingredients) {
        if (ing.isEmpty() || ui->recipename_lineEdit->text().isEmpty()) {
            ui->error_label->show();
            QTimer * timer = new QTimer(this);
            connect(timer, &QTimer::timeout, [=](){ui->error_label->hide();});
            timer->start(3000);
            return;
        }
    }
    accept();
}

void AddRecipeDialog::on_cancel_pushButton_clicked()
{
    reject();
}

Recipe AddRecipeDialog::getRecipe()
{
    return recipe;
}

