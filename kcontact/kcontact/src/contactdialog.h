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

#ifndef CONTACTDIALOG_H
#define CONTACTDIALOG_H

#include <KDialog>
#include <KLineEdit>
#include <KTextEdit>

#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QSqlTableModel>
#include <QDataWidgetMapper>

class ContactDialog;

class ContactDialogWidget : public QWidget
{
	private:
		ContactDialogWidget();
		
		KLineEdit *firstNameEdit;
		KLineEdit *lastNameEdit;
		KLineEdit *phoneEdit;
		KTextEdit *addressEdit;
		
		QLabel *firstNameLabel;
		QLabel *lastNameLabel;
		QLabel *phoneLabel;
		QLabel *addressLabel;
		
		QGridLayout *layout;
		QVBoxLayout *addressLayout;
		
		friend class ContactDialog;
};

class ContactDialog : public KDialog
{
	Q_OBJECT
	
	public:
		ContactDialog(QWidget *parent = 0);
		virtual ~ContactDialog();
		
		void setFirstName(QString firstName);
		void setLastName(QString lastName);
		void setPhoneNumber(QString phone);
		void setAddress(QString address);
		
	protected:
		void populateWidgets();
		
	private:
		QSqlTableModel *m_model;
		QDataWidgetMapper *m_mapper;
		
		ContactDialogWidget *m_widget;
		
		QString m_firstName;
		QString m_lastName;
		QString m_phone;
		QString m_address;
};

#endif // CONTACTDIALOG_H
