/***************************************************************************
 * General Ledger, Copyright (C) 2008 Armin Moradi <feng.shaun@gmail.com>  *
 * http://fengshaun.wordpress.com                                          *
 *                                                                         *
 * This program is free software; you can redistribute it and/or modify    *
 * it under the terms of the GNU General Public License as published by    *
 * the Free Software Foundation; either version 3 of the License, or       *
 * (at your option) any later version.                                     *
 *                                                                         *
 * This program is distributed in the hope that it will be useful,         *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the            *
 * GNU General Public License for more details.                            *
 *                                                                         *
 * You should have received a copy of the GNU General Public License       *
 * along with this program; if not, write to the Free Software             *
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 US  *
 ***************************************************************************/

#include <QPushButton>
#include <QCheckBox>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "finddialog.h"

FindDialog::FindDialog(QWidget * parent)
	: QDialog(parent)
{
	label = new QLabel(tr("Find &what:"));
	lineEdit = new QLineEdit;
	label->setBuddy(lineEdit);

	caseCheckBox = new QCheckBox(tr("Match &case"));
	backwardCheckBox = new QCheckBox(tr("Search &backward"));

	findButton = new QPushButton(tr("&Find"));
	findButton->setDefault(true);
	findButton->setEnabled(false);

	closeButton = new QPushButton(tr("Close"));

	connect(lineEdit, SIGNAL(textChanged(const QString &)),
			this, SLOT(enableFindButton(const QString &)));
	connect(findButton, SIGNAL(clicked()), this, SLOT(findClicked()));
	connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

	QHBoxLayout * topLeftLayout = new QHBoxLayout;
	topLeftLayout->addWidget(label);
	topLeftLayout->addWidget(lineEdit);

	QVBoxLayout * leftLayout = new QVBoxLayout;
	leftLayout->addLayout(topLeftLayout);
	leftLayout->addWidget(caseCheckBox);
	leftLayout->addWidget(backwardCheckBox);

	QVBoxLayout * rightLayout = new QVBoxLayout;
	rightLayout->addWidget(findButton);
	rightLayout->addWidget(closeButton);
	rightLayout->addStretch();

	QHBoxLayout * mainLayout = new QHBoxLayout;
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);

	setLayout(mainLayout);
	setWindowTitle(tr("Find"));
	setFixedHeight(sizeHint().height());
}

FindDialog::~FindDialog() {}

void FindDialog::findClicked() {
	QString text = lineEdit->text();
	Qt::CaseSensitivity cs = caseCheckBox->isChecked() ? Qt::CaseSensitive
													   : Qt::CaseInsensitive;

	if (backwardCheckBox->isChecked()) {
		emit findPrevious(text, cs);
	} else {
		emit findNext(text, cs);
	}
}

void FindDialog::enableFindButton(const QString & text) {
	findButton->setEnabled(!text.isEmpty());
}