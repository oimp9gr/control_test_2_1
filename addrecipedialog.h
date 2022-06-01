#ifndef ADDRECIPEDIALOG_H
#define ADDRECIPEDIALOG_H

#include <QDialog>
#include "recipesmodel.h"

namespace Ui {
class AddRecipeDialog;
}

class AddRecipeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddRecipeDialog(QWidget *parent = nullptr);
    ~AddRecipeDialog();
    Recipe getRecipe();

private slots:
    void on_recipename_lineEdit_textChanged(const QString &arg1);

    void on_add_pushButton_clicked();

    void updateRecipeIngredient(int index, const QString & ingredient);

    void updateRecipeWeight(int index, int weight);

    void on_ok_pushButton_clicked();

    void on_cancel_pushButton_clicked();

private:
    Ui::AddRecipeDialog *ui;

    Recipe recipe;
};

#endif // ADDRECIPEDIALOG_H
