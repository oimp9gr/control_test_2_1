#include "recipesmodel.h"

RecipesModel::RecipesModel(QObject *parent)
    : QAbstractListModel{parent}
{

}

int RecipesModel::rowCount(const QModelIndex &parent) const
{
    return m_recipes.size();
}

QVariant RecipesModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole && index.isValid() && index.row() < m_recipes.size()) {
        return m_recipes[index.row()].name;
    }
    return QVariant();
}

void RecipesModel::addRecipe(const Recipe &recipe)
{
    m_recipes.push_back(recipe);

    emit dataChanged(index(0), index(m_recipes.size()), {Qt::DisplayRole});
}
