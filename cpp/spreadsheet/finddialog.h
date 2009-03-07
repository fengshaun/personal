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

#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>

class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;

class FindDialog : public QDialog
{
	Q_OBJECT
	
	public:
		FindDialog(QWidget * parent = 0);
		~FindDialog();

	signals:
		void findNext(const QString & str, Qt::CaseSensitivity cs);
		void findPrevious(const QString & str, Qt::CaseSensitivity cs);

	private:
		QLabel * label;
		QLineEdit * lineEdit;
		QCheckBox * caseCheckBox;
		QCheckBox * backwardCheckBox;
		QPushButton * findButton;
		QPushButton * closeButton;
		
	private slots:
		void findClicked();
		void enableFindButton(const QString & text);
};

#endif //FINDDIALOG_H