#ifndef RECIPESMODEL_H
#define RECIPESMODEL_H

#include <QAbstractListModel>
#include <vector>
#include <unordered_map>

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


    std::vector<Recipe> m_recipes;
    //std::unordered_map<QString, int> my_map;
};

#endif // RECIPESMODEL_H
