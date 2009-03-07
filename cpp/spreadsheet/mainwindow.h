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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QStringList>

class QAction;
class QLabel;
class QMenu;
class QToolBar;
class QLabel;

class FindDialog;
class Spreadsheet;

class MainWindow : public QMainWindow
{
	Q_OBJECT
	
	public:
		MainWindow();
		~MainWindow();

	protected:
		virtual void closeEvent(QCloseEvent *);

	private:
		void createActions();
		void createMenues();
		void createContextMenu();
		void createToolBars();
		void createStatusBar();
		void readSettings();
		void writeSettings();
		bool okToContinue();
		bool loadFile(const QString &);
		bool saveFile(const QString &);
		void setCurrentFile(const QString &);
		void updateRecentFileActions();
		QString strippedName(const QString &);

		Spreadsheet * spreadsheet;
		FindDialog * findDialog;
		QLabel * locationLabel;
		QLabel * formulaLabel;
		QStringList recentFiles;
		QString currentFile;

		enum { MaxRecentFiles = 5 };
		static QAction * recentFilesActions[MaxRecentFiles];
		QAction * separatorAction;

		QMenu * fileMenu;
		QMenu * editMenu;
		QMenu * selectSubMenu;
		QMenu * toolsMenu;
		QMenu * optionsMenu;
		QMenu * helpMenu;

		QToolBar * fileToolBar;
		QToolBar * editToolBar;

		//file menu
		QAction * newAction;
		QAction * openAction;
		QAction * saveAction;
		QAction * saveAsAction;
		QAction * closeAction;
		QAction * exitAction;

		//edit menu
		QAction * cutAction;
		QAction * copyAction;
		QAction * pasteAction;
		QAction * deleteAction;
		QAction * findAction;
		QAction * goToCellAction;
		QAction * selectRowAction;
		QAction * selectColumnAction;
		QAction * selectAllAction;

		//tools menu
		QAction * recalcAction;
		QAction * sortAction;

		//options menu
		QAction * showGridAction;
		QAction * autoRecalcAction;

		//help menu
		QAction * aboutAction;
		QAction * aboutQtAction;
		
	private slots:
		void newFile();
		void open();
		bool save();
		bool saveAs();
		void find();
		void goToCell();
		void sort();
		void about();
		void openRecentFile();
		void updateStatusBar();
		void spreadsheetModified();
};

#endif //MAINWINDOW_H