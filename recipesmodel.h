#ifndef RECIPESMODEL_H
#define RECIPESMODEL_H

#include <QAbstractListModel>
#include <vector>

struct Recipe {
    QString name;
    std::vector<std::pair<QString, int>> ingredients;
};

class RecipesModel : public QAbstractListModel
{
public:
    explicit RecipesModel(QObject *parent = nullptr);

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;

public:
    void addRecipe(const Recipe & recipe);

private:
    std::vector<Recipe> m_recipes;
};

#endif // RECIPESMODEL_H
