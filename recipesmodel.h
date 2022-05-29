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

    QString GetIngridient(const size_t& ind){
         return m_recipes[ind].ingredients[ind].first;
     }
     int GetWeight(const size_t& ind){
         return m_recipes[ind].ingredients[ind].second;
     }

     int GetSize(const size_t& ind){
         return m_recipes[ind].ingredients.size();
     }


private:
    std::vector<Recipe> m_recipes;
};

#endif // RECIPESMODEL_H
