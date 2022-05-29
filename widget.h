#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "recipesmodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_recepies_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;

    RecipesModel * model;
    std::vector<QWidget*>shownIngredients;
};
#endif // WIDGET_H
