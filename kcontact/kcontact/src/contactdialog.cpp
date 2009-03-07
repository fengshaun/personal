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

#include "contactdialog.h"

#include <KDebug>

#include <QItemDelegate>

#include "contactdatabase.h"

ContactDialogWidget::ContactDialogWidget() {
	firstNameEdit = new KLineEdit;
	lastNameEdit = new KLineEdit;
	phoneEdit = new KLineEdit;
	addressEdit = new KTextEdit;
	
	firstNameLabel = new QLabel("First name:");
	lastNameLabel = new QLabel("Last name:");
	phoneLabel = new QLabel("Phone number:");
	addressLabel = new QLabel("Address:");
	
	addressLayout = new QVBoxLayout;
	addressLayout->addWidget(addressLabel);
	addressLayout->addStretch();
	
	layout = new QGridLayout;
	layout->addWidget(firstNameLabel, 0, 0);
	layout->addWidget(firstNameEdit, 0, 1);
	layout->addWidget(lastNameLabel, 1, 0);
	layout->addWidget(lastNameEdit, 1, 1);
	layout->addWidget(phoneLabel, 2, 0);
	layout->addWidget(phoneEdit, 2, 1);
	layout->addLayout(addressLayout, 3, 0);
	layout->addWidget(addressEdit, 3, 1, 2, 1);
	
	setLayout(layout);
}

ContactDialog::ContactDialog(QWidget *parent) : KDialog(parent) {
	m_widget = new ContactDialogWidget;
	m_widget->firstNameEdit->setText(m_firstName);
	m_widget->lastNameEdit->setText(m_lastName);
	
	populateWidgets();
	
	connect(this, SIGNAL(accepted()), m_mapper, SLOT(submit()));
	
	setMainWidget(m_widget);
	setButtons(KDialog::Ok | KDialog::Cancel);
}

ContactDialog::~ContactDialog() {
	kDebug() << "";
}

void ContactDialog::setFirstName(QString firstName) {
	m_firstName = firstName;
}

void ContactDialog::setLastName(QString lastName) {
	m_lastName = lastName;
}

void ContactDialog::setPhoneNumber(QString phone) {
	m_phone = phone;
}

void ContactDialog::setAddress(QString address) {
	m_address = address;
}

void ContactDialog::populateWidgets() {
	kDebug() << "";

	m_model = new QSqlTableModel(this);
	m_model->setTable("contacts");
	m_model->setFilter("firstname = '" + m_firstName + "'");
	m_model->select();
	
	m_mapper = new QDataWidgetMapper(this);
	m_mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
	m_mapper->setModel(m_model);
	m_mapper->addMapping(m_widget->firstNameEdit, ContactDatabase::FirstName);
	m_mapper->addMapping(m_widget->lastNameEdit, ContactDatabase::LastName);
	m_mapper->addMapping(m_widget->phoneEdit, ContactDatabase::PhoneNumber);
	m_mapper->addMapping(m_widget->addressEdit, ContactDatabase::Address);
	m_mapper->toFirst();
}

