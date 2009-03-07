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

#include "contactdatabase.h"

#include <KMessageBox>
#include <KDebug>
#include <KLocale>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

ContactDatabase::ContactDatabase() {
}

bool ContactDatabase::createConnection(QString dbName) {
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName(dbName);
	if (!db.open()) {
		KMessageBox::error(0, i18n("KContact needs Qt SQLite support"),
							  i18n("Cannot Open database"));
		return false;
	}
	
	QSqlQuery q;
	if (!db.tables().contains("contacts")) {
		kDebug() << "creating a new database";
		if(!q.exec("CREATE TABLE contacts (firstname VARCHAR(20), lastname VARCHAR(20), phonenumber VARCHAR(20), address VARCHAR(100))"))
			kDebug() << q.lastError().text();
	}
	
	return true;
}