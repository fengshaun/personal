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

#ifndef CONTACTDATABASE_H
#define CONTACTDATABASE_H

#include <QString>

class ContactDatabase
{
	public:
		ContactDatabase();
		
		enum Field {FirstName = 0,
					LastName = 1,
					PhoneNumber = 2,
					Address = 3};
		
		static bool createConnection(QString dbName = QString("/home/armin/contacts.db"));
};

#endif // CONTACTDATABASE_H
