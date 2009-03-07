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

#include <KCmdLineArgs>
#include <KApplication>
#include <KAboutData>

#include "mainwindow.h"
#include "contactdatabase.h"

int main(int argc, char *argv[]) {
	KAboutData about("kcontact", 0, ki18n("KContact"), "0.1",
					 ki18n("Yet Another Contact Manager"),
					 KAboutData::License_GPL, ki18n("(C) 2009"),
					 ki18n("About..."), "http://fengshaun.wordpress.com",
					 "feng.shaun@gmail.com");
					 
	KCmdLineArgs::init(argc, argv, &about);
	KApplication app;
	
	if(!ContactDatabase::createConnection()) {
		return 1;
	}

	MainWindow *mw = new MainWindow;
	mw->show();

	return app.exec();
}