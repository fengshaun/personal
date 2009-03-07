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

#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <QTableWidget>

class Cell;
class SpreadsheetCompare;

class Spreadsheet : public QTableWidget
{
	Q_OBJECT

	public:
		Spreadsheet(QWidget *parent = 0);

		bool autoRecalculate() const;
		QString currentLocation() const;
		QString currentFormula() const;
		QTableWidgetSelectionRange selectedRange() const;
		void clear();
		bool readFile(const QString &);
		bool writeFile(const QString &);
		void sort(const SpreadsheetCompare &);

	public slots:
		void cut();
		void copy();
		void paste();
		void del();
		void selectCurrentRow();
		void selectCurrentColumn();
		void recalculate();
		void setAutoRecalculate(bool);
		void findNext(const QString &, Qt::CaseSensitivity);
		void findPrevious(const QString &, Qt::CaseSensitivity);

	signals:
		void modified();

	private:
		enum { MagicNumber = 0x7F51C883, RowCount = 999, ColumnCount = 26 };

		Cell *cell(int, int) const;
		QString text(int, int) const;
		QString formula(int, int) const;
		void setFormula(int, int, const QString &);

		bool autoRecalc;

	private slots:
		void somethingChanged();
};

class SpreadsheetCompare
{
	public:
		bool operator()(const QStringList &, const QStringList &) const;
		enum { KeyCount = 3 };
		int keys[KeyCount];
		bool ascending[KeyCount];
};

#endif //SPREADSHEET_H