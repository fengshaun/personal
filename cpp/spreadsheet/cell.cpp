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

#include <QtGui>

#include "cell.h"

Cell::Cell() {
	setDirty();
}

QTableWidgetItem *Cell::clone() const {
	return new Cell(*this);
}

void Cell::setFormula(const QString &formula) {
	setData(Qt::EditRole, formula);
}

QString Cell::formula() const {
	return data(Qt::EditRole).toString();
}

void Cell::setData(int role, const QVariant &value) {
	QTableWidgetItem::setData(role, value);

	if (role == Qt::EditRole)
		setDirty();
}

void Cell::setDirty() {
	cacheIsDirty = true;
}

QVariant Cell::data(int role) const {
	if (role == Qt::DisplayRole) {
		if (value().isValid()) {
			return value().toString();
		} else {
			return "####";
		}
	} else if (role == Qt::TextAlignmentRole) {
		if (value().type() == QVariant::String) {
			return int(Qt::AlignLeft | Qt::AlignVCenter);
		} else {
			return int(Qt::AlignRight | Qt::AlignVCenter);
		}
	} else {
		return QTableWidgetItem::data(role);
	}
}

QVariant Cell::value() const {
	if (cacheIsDirty) {
		cacheIsDirty = false;

		QString formulaStr = formula();
		if (formulaStr.startsWith('\'')) {
			cachedValue = formulaStr.mid(1);
		} else if (formulaStr.startsWith('=')) {
			cachedValue = Invalid;
			QString expr = formulaStr.mid(1);
			expr.replace(" ", "");
			expr.append(QChar::Null);

			int pos = 0;
			cachedValue = evalExpression(expr, pos);
			if (expr[pos] != QChar::Null) {
				cachedValue = Invalid;
			}
		} else {
			bool ok;
			double d = formulaStr.toDouble(&ok);

			if (ok) {
				cachedValue = d;
			} else {
				cachedValue = formulaStr;
			}
		}
	}
	return cachedValue;
}

QVariant Cell::evalExpression(const QString &str, int &pos) const {
	QVariant result = evalTerm(str, pos);
	while (str[pos] != QChar::Null) {
		QChar op = str[pos];
		
		if (op != '+' && op != '-') {
			return result;
		}
		
		pos++;
		QVariant term = evalTerm(str, pos);
		
		if (result.type() == QVariant::Double &&
			term.type() == QVariant::Double)
		{
			if (op == '+') {
				result = result.toDouble() + term.toDouble();
			} else if (op == '-') {
				result = result.toDouble() - term.toDouble();
			}
		} else {
			result = Invalid;
		}
	}

	return result;
}

QVariant Cell::evalTerm(const QString &str, int &pos) const {
	QVariant result = evalFactor(str, pos);
	while (str[pos] != QChar::Null) {
		QChar op = str[pos];
		if (op != '*' && op != '/') {
			return result;
		}

		QVariant factor = evalFactor(str, ++pos);

		if (result.type() == QVariant::Double &&
			factor.type() == QVariant::Double)
		{
			if (op == '*') {
				result = result.toDouble() * factor.toDouble();
			} else {
				result = result.toDouble() / factor.toDouble();
			}
		} else {
			result = Invalid;
		}
	}
	return result;
}

QVariant Cell::evalFactor(const QString &str, int &pos) const {
	QVariant result;
	bool negative = false;

	if (str[pos] == '-') {
		negative = true;
		pos++;
	}

	if (str[pos] == '(') {
		result = evalExpression(str, ++pos);
		if (str[pos] != ')') {
			result = Invalid;
		}
		pos++;
	} else {
		QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
		QString token;

		while (str[pos].isLetterOrNumber() || str[pos] == '.') {
			token += str[pos++];
		}

		if (regExp.exactMatch(token)) {
			int column = token[0].toUpper().unicode() - 'A';
			int row = token.mid(1).toInt() - 1;

			Cell *c = static_cast<Cell *>(tableWidget()->item(row, column));

			if (c) {
				result = c->value();
			} else {
				result = 0.0;
			}
		} else {
			bool ok;
			result = token.toDouble(&ok);
			if (!ok) {
				result = Invalid;
			}
		}
	}

	if (negative) {
		if (result.type() == QVariant::Double) {
			result = -result.toDouble();
		} else {
			result = Invalid;
		}
	}

	return result;
}