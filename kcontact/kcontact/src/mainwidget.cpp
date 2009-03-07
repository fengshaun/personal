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

#include "mainwidget.h"

MainWidget::MainWidget() : QWidget(0) {
	searchButton = new KPushButton("Search");
	addButton = new KPushButton("Add");
	removeButton = new KPushButton("Remove");
	editButton = new KPushButton("Edit");
	closeButton = new KPushButton("Close");
	
	nameEdit = new KLineEdit;
	nameList = new KListWidget;
	
	leftLayout = new QVBoxLayout;
	leftLayout->addWidget(nameEdit);
	leftLayout->addWidget(nameList);
	
	rightLayout = new QVBoxLayout;
	rightLayout->addWidget(searchButton);
	rightLayout->addWidget(addButton);
	rightLayout->addWidget(editButton);
	rightLayout->addWidget(removeButton);
	rightLayout->addStretch();
	rightLayout->addWidget(closeButton);
	
	mainLayout = new QHBoxLayout;
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);
	
	setLayout(mainLayout);
}