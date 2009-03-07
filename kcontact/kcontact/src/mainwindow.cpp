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

#include "mainwindow.h"

#include <KDebug>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlError>
#include <QListWidgetItem>

#include "contactdatabase.h"
#include "contactdialog.h"

MainWindow::MainWindow() : KXmlGuiWindow(0) {
	kDebug() << "";
	ui = new MainWidget;
	setCentralWidget(ui);
	
	initializeList();
	setupConnections();
	setupGUI();
}

MainWindow::~MainWindow() {
	kDebug() << "";
	delete ui;
	ui = 0;
}

void MainWindow::initializeList() {
	kDebug() << "";
	
	QSqlTableModel model;
	
	model.setTable("contacts");
	model.select();
	
	for (int i = 0; i < model.rowCount(); i++) {
		QSqlRecord rec = model.record(i);
		QString name = rec.value(ContactDatabase::FirstName).toString();
		addContactToList(name);
	}
}

void MainWindow::setupConnections() {
	kDebug() << "";
	
	connect(ui->searchButton, SIGNAL(clicked()), this, SLOT(searchForContact()));
	connect(ui->addButton, SIGNAL(clicked()), this, SLOT(addContact()));
	connect(ui->removeButton, SIGNAL(clicked()), this, SLOT(removeContact()));
	connect(ui->editButton, SIGNAL(clicked()), this, SLOT(editContact()));
	connect(ui->closeButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(ui->nameEdit, SIGNAL(returnPressed()), this, SLOT(searchForContact()));
}

void MainWindow::searchForContact() {
	kDebug() << "";
	
	QString name = ui->nameEdit->text().toLower();
	
	for (int i = 0; i < ui->nameList->count(); i++) {
		if (ui->nameList->item(i)->text().toLower() == name) {
			ui->nameList->setCurrentRow(i);
			break;
		}
	}
}

void MainWindow::addContact() {
	QString name = ui->nameEdit->text();
	
	addContactToDatabase(name);
	addContactToList(name);
}

void MainWindow::addContactToDatabase(QString name) {
	kDebug() << name;
	
	QSqlDatabase::database().transaction();
	QSqlTableModel model;
	model.setTable("contacts");
	int row = model.rowCount();
	
	model.insertRows(row, 1);
	model.setData(model.index(row, ContactDatabase::FirstName), name);
	model.setData(model.index(row, ContactDatabase::LastName), "");
	model.setData(model.index(row, ContactDatabase::PhoneNumber), "");
	model.setData(model.index(row, ContactDatabase::Address), "");
	model.submitAll();
	
	QSqlDatabase::database().commit();
}

void MainWindow::addContactToList(QString name) {
	kDebug() << name;
	
	ui->nameList->addItem(name);
	ui->nameList->sortItems(Qt::AscendingOrder);
	ui->nameEdit->clear();
	
	if(!ui->nameEdit->hasFocus()) {
		ui->nameEdit->setFocus(Qt::OtherFocusReason);
	}
}

void MainWindow::editContact() {
	kDebug() << "";
	
	QString first;
	QString last;
	QString phone;
	QString address;
	
	QString fn = ui->nameList->item(ui->nameList->currentRow())->text();
	QSqlTableModel model;
	model.setTable("contacts");
	model.setFilter("firstname = '" + fn + "'");
	model.select();
	if (model.rowCount() > 0) {
		QSqlRecord rec = model.record(0);
		first = rec.value(ContactDatabase::FirstName).toString();
		last = rec.value(ContactDatabase::LastName).toString();
		phone = rec.value(ContactDatabase::PhoneNumber).toString();
		address = rec.value(ContactDatabase::Address).toString();
	} else {
		kDebug() << "Contact " << fn << " cannot be edited";
		return;
	}
	
	ContactDialog dialog(this);
	dialog.setFirstName(first);
	dialog.setLastName(last);
	dialog.setPhoneNumber(phone);
	dialog.setAddress(address);
	dialog.exec();
	
	ui->nameList->clear();
	initializeList();
}

void MainWindow::removeContact() {
	kDebug() << "";
	
	QListWidgetItem *item = ui->nameList->takeItem(ui->nameList->currentRow());
	
	QSqlTableModel model;
	model.setTable("contacts");
	model.setFilter("firstname = '" + item->text() + "'");
	model.select();
	if (model.rowCount() > 0) {
		model.removeRows(0, model.rowCount());
	}
	
	delete item;
}