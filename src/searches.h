/*
 * Copyright (C) 2008-2009 Alexei Chaloupov <alexei.chaloupov@gmail.com>
 * Copyright (C) 2013 Sergei Lopatin <magist3r@gmail.com>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA  02110-1301  USA
 */
#ifndef SEARCHES_H
#define SEARCHES_H

#include <QDialog>
#include <QSettings>
#include <QItemDelegate>
#include <QKeyEvent>
#include "ui_searches.h"

QT_BEGIN_NAMESPACE
class QSortFilterProxyModel;
QT_END_NAMESPACE

#define SEARCH_GOOGLE   QString("Google")
#define SEARCH_YAHOO    QString("Yahoo")
#define SEARCH_BING     QString("Bing")
#define SEARCH_CUIL     QString("Cuil")
#define DEFAULT_PROVIDER    SEARCH_GOOGLE

#define QUERY_GOOGLE    "http://www.google.com/search?q="
#define QUERY_YAHOO     "http://search.yahoo.com/search?p="
#define QUERY_BING      "http://www.bing.com/search?q="
#define QUERY_CUIL      "http://www.cuil.com/search?q="


class SearchesModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    SearchesModel(QObject *parent);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;
    int addRow(QString name, QString value);

public slots:
    void loadDefaultProviders();
    void save();

private:
    QList< QPair<QString,QString> > *m_searchProviders;
};

class Searches : public QDialog, public Ui_SearchesDialog
{
    Q_OBJECT

public:
    Searches(QWidget *parent);
    void keyPressEvent(QKeyEvent *event);

private slots:
    void addSearchProvider();
    void addEbay();
    void addAsk();
    void removeSelectedRows();

private:
    QSortFilterProxyModel *m_proxyModel;
    SearchesModel* m_model;
};

#endif // SEARCHES_H
