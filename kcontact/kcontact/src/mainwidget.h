/*
    This file is part of KContact.

    KContact is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    KContact is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with KCantact.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <KPushButton>
#include <KLineEdit>
#include <KListWidget>

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>

class MainWidget : public QWidget
{
	public:
		MainWidget();
		
		KPushButton *searchButton;
		KPushButton *addButton;
		KPushButton *removeButton;
		KPushButton *editButton;
		KPushButton *closeButton;
		
		KLineEdit *nameEdit;
		KListWidget *nameList;
		
	private:
		QVBoxLayout *leftLayout;
		QVBoxLayout *rightLayout;
		QHBoxLayout *mainLayout;
};

#endif // MAINWIDGET_H