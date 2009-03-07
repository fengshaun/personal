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

#include <iostream>

#include <QtGui>

#include "mainwindow.h"
#include "finddialog.h"
#include "gotocelldialog.h"
#include "sortdialog.h"
#include "spreadsheet.h"

QAction *MainWindow::recentFilesActions[5];

MainWindow::MainWindow() {
	std::cout << "constructing main window" << std::endl;
	spreadsheet = new Spreadsheet;
	setCentralWidget(spreadsheet);

	createActions();
	createMenues();
	createContextMenu();
	createToolBars();
	createStatusBar();

	setAttribute(Qt::WA_DeleteOnClose);

	readSettings();

	findDialog = 0;

	setWindowIcon(QIcon(":/images/icon.png"));
	setCurrentFile("");
	std::cout << "finished constructing main window" << std::endl;
}

MainWindow::~MainWindow() {}

void MainWindow::createActions() {
	std::cout << "creating actions" << std::endl;

	// FILE MENU
	newAction = new QAction(tr("&New"), this);
	newAction->setIcon(QIcon(":/images/new.png"));
	newAction->setShortcut(QKeySequence::New);
	newAction->setStatusTip(tr("Create a new spreadsheet file"));
	connect(newAction, SIGNAL(triggered()), this, SLOT(newFile()));

	openAction = new QAction(tr("&Open..."), this);
	openAction->setIcon(QIcon(":/images/open.png"));
	openAction->setShortcut(QKeySequence::Open);
	openAction->setStatusTip(tr("Open a spreadsheet file"));
	connect(openAction, SIGNAL(triggered()), this, SLOT(open()));

	saveAction = new QAction(tr("&Save"), this);
	saveAction->setIcon(QIcon(":/images/save.png"));
	saveAction->setShortcut(QKeySequence::Save);
	saveAction->setStatusTip(tr("Save this spreadsheet"));
	connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));

	saveAsAction = new QAction(tr("Save &As..."), this);
	saveAsAction->setIcon(QIcon(":/images/saveas.png"));
	saveAsAction->setStatusTip(tr("Save this spreadsheet as a different file"));
	connect(saveAsAction, SIGNAL(triggered()), this, SLOT(saveAs()));

	closeAction = new QAction(tr("&Close"), this);
	closeAction->setShortcut(QKeySequence::Close);
	closeAction->setStatusTip(tr("Close this window"));
	connect(closeAction, SIGNAL(triggered()), this, SLOT(close()));

	exitAction = new QAction(tr("E&xit"), this);
	exitAction->setShortcut(tr("Ctrl+Q"));
	exitAction->setStatusTip(tr("Exit the application"));
	connect(exitAction, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));

	// EDIT MENU
	cutAction = new QAction(tr("Cu&t"), this);
	cutAction->setIcon(QIcon(":/images/cut.png"));
	cutAction->setShortcut(QKeySequence::Cut);
	cutAction->setStatusTip(tr("Cut the selected cells"));
	connect(cutAction, SIGNAL(triggered()), spreadsheet, SLOT(cut()));

	copyAction = new QAction(tr("&Copy"), this);
	copyAction->setIcon(QIcon(":/images/copy.png"));
	copyAction->setShortcut(QKeySequence::Copy);
	copyAction->setStatusTip(tr("Copy the selected cells into clipboard"));
	connect(copyAction, SIGNAL(triggered()), spreadsheet, SLOT(copy()));

	pasteAction = new QAction(tr("&Paste"), this);
	pasteAction->setIcon(QIcon(":/images/paste.png"));
	pasteAction->setShortcut(QKeySequence::Paste);
	pasteAction->setStatusTip(tr("Paste the cells from clipboard"));
	connect(pasteAction, SIGNAL(triggered()), spreadsheet, SLOT(paste()));

	deleteAction = new QAction(tr("&Delete"), this);
	deleteAction->setIcon(QIcon(":/images/delete.png"));
	deleteAction->setShortcut(QKeySequence::Delete);
	deleteAction->setStatusTip(tr("Delete selected cells"));
	connect(deleteAction, SIGNAL(triggered()), spreadsheet, SLOT(del()));

	findAction = new QAction(tr("&Find..."), this);
	findAction->setShortcut(QKeySequence::Find);
	findAction->setIcon(QIcon(":/images/find.png"));
	findAction->setStatusTip(tr("Find a value in the spreadsheet"));
	connect(findAction, SIGNAL(triggered()), this, SLOT(find()));

	goToCellAction = new QAction(tr("&Go to cell..."), this);
	//goToCellAction->setShortcut("Ctrl+G");
	goToCellAction->setIcon(QIcon(":/images/rightarrow.png"));
	goToCellAction->setStatusTip(tr("Go to the specified cell"));
	connect(goToCellAction, SIGNAL(triggered()), this, SLOT(goToCell()));

	selectRowAction = new QAction(tr("&Row"), this);
	selectRowAction->setStatusTip(tr("Select current row"));
	connect(selectRowAction, SIGNAL(triggered()), spreadsheet, SLOT(selectCurrentRow()));

	selectColumnAction = new QAction(tr("&Column"), this);
	selectColumnAction->setStatusTip(tr("Select current column"));
	connect(selectColumnAction, SIGNAL(triggered()),
			spreadsheet, SLOT(selectCurrentColumn()));

	selectAllAction = new QAction(tr("&All"), this);
	selectAllAction->setShortcut(QKeySequence::SelectAll);
	selectAllAction->setStatusTip(tr("Select all cells"));
	connect(selectAllAction, SIGNAL(triggered()),
			spreadsheet, SLOT(selectAll()));

	// TOOLS MENU
	recalcAction = new QAction(tr("&Recalculate"), this);
	//recalcAction->setShortcut("F9");
	recalcAction->setStatusTip(tr("Recalculate spreadsheet cells"));
	connect(recalcAction, SIGNAL(triggered()), spreadsheet, SLOT(recalculate()));

	sortAction = new QAction(tr("&Sort..."), this);
	sortAction->setStatusTip(tr("Sort specified columns and orders"));
	connect(sortAction, SIGNAL(triggered()), this, SLOT(sort()));

	// OPTIONS MENU
	showGridAction = new QAction(tr("Show Grid"), this);
	showGridAction->setCheckable(true);
	showGridAction->setChecked(spreadsheet->showGrid());
	showGridAction->setStatusTip(tr("Show/hide grid"));
	connect(showGridAction, SIGNAL(toggled(bool)), spreadsheet, SLOT(setShowGrid(bool)));

	autoRecalcAction = new QAction(tr("Auto Recalculate"), this);
	autoRecalcAction->setCheckable(true);
	autoRecalcAction->setChecked(spreadsheet->autoRecalculate());
	autoRecalcAction->setStatusTip(tr("Set auto recalculation on/off"));
	connect(autoRecalcAction, SIGNAL(toggled(bool)), spreadsheet, SLOT(setAutoRecalculate(bool)));

	// HELP MENU
	aboutAction = new QAction(tr("About"), this);
	aboutAction->setStatusTip(tr("About this program"));
	connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));

	aboutQtAction = new QAction(tr("About Qt"), this);
	aboutQtAction->setStatusTip(tr("Learn about Qt"));
	connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
	
	for (int i = 0; i < MaxRecentFiles; i++) {
		recentFilesActions[i] = new QAction(this);
		recentFilesActions[i]->setVisible(false);
		connect(recentFilesActions[i], SIGNAL(triggered()),
				this, SLOT(openRecentFile()));
	}

}

void MainWindow::createMenues() {
	std::cout << "creating menues" << std::endl;
	
	fileMenu = menuBar()->addMenu(tr("&File"));
	fileMenu->addAction(newAction);
	fileMenu->addAction(openAction);
	fileMenu->addAction(saveAction);
	fileMenu->addAction(saveAsAction);
	separatorAction = fileMenu->addSeparator();
	for (int i = 0; i < MaxRecentFiles; i++) {
		fileMenu->addAction(recentFilesActions[i]);
	}
	fileMenu->addSeparator();
	fileMenu->addAction(exitAction);

	editMenu = menuBar()->addMenu(tr("&Edit"));
	editMenu->addAction(cutAction);
	editMenu->addAction(copyAction);
	editMenu->addAction(pasteAction);
	editMenu->addAction(deleteAction);

	selectSubMenu = editMenu->addMenu(tr("&Select"));
	selectSubMenu->addAction(selectRowAction);
	selectSubMenu->addAction(selectColumnAction);
	selectSubMenu->addAction(selectAllAction);

	editMenu->addSeparator();
	editMenu->addAction(findAction);
	editMenu->addAction(goToCellAction);

	toolsMenu = menuBar()->addMenu(tr("&Tools"));
	toolsMenu->addAction(recalcAction);
	toolsMenu->addAction(sortAction);

	optionsMenu = menuBar()->addMenu(tr("&Options"));
	optionsMenu->addAction(showGridAction);
	optionsMenu->addAction(autoRecalcAction);

	menuBar()->addSeparator();

	helpMenu = menuBar()->addMenu(tr("&Help"));
	helpMenu->addAction(aboutAction);
	helpMenu->addAction(aboutQtAction);
}

//another way of creating context menues, is to reimplement 'virtual void QWidget::contextMenuEvent()'
void MainWindow::createContextMenu() {
	std::cout << "creating context menu" << std::endl;
	
	spreadsheet->addAction(cutAction);
	spreadsheet->addAction(copyAction);
	spreadsheet->addAction(pasteAction);
	spreadsheet->setContextMenuPolicy(Qt::ActionsContextMenu);
}

void MainWindow::createToolBars() {
	std::cout << "creating toolbars" << std::endl;
	
	fileToolBar = addToolBar(tr("&File"));
	fileToolBar->addAction(newAction);
	fileToolBar->addAction(openAction);
	fileToolBar->addAction(saveAction);
	fileToolBar->addAction(saveAsAction);

	editToolBar = addToolBar(tr("&Edit"));
	editToolBar->addAction(cutAction);
	editToolBar->addAction(copyAction);
	editToolBar->addAction(pasteAction);
	editToolBar->addSeparator();
	editToolBar->addAction(findAction);
	editToolBar->addAction(goToCellAction);
}

void MainWindow::createStatusBar() {
	std::cout << "creating status bar" << std::endl;
	
	locationLabel = new QLabel(" W999 ");
	locationLabel->setAlignment(Qt::AlignHCenter);
	locationLabel->setMinimumSize(locationLabel->sizeHint());

	formulaLabel = new QLabel;
	formulaLabel->setIndent(3);

	statusBar()->addWidget(locationLabel);
	statusBar()->addWidget(formulaLabel, 1);  //(formulaLabel, 1), the 1 is the stretch factor, not position

	connect(spreadsheet, SIGNAL(currentCellChanged(int, int, int, int)),
			this, SLOT(updateStatusBar()));
	connect(spreadsheet, SIGNAL(modified()), this, SLOT(spreadsheetModified()));

	updateStatusBar();

}

void MainWindow::updateStatusBar() {
	std::cout << "updating status bar" << std::endl;
	
	locationLabel->setText(spreadsheet->currentLocation());
	formulaLabel->setText(spreadsheet->currentFormula());
}

void MainWindow::spreadsheetModified() {
	std::cout << "MainWindow::spreadsheetModified()" << std::endl;
	setWindowModified(true);
	updateStatusBar();
}

void MainWindow::newFile() {
	std::cout << "MainWindow::newFile()" << std::endl;
	MainWindow * mainWin = new MainWindow;
	mainWin->show();
}

bool MainWindow::okToContinue() {
	std::cout << "MainWindow::okToContinue()" << std::endl;
	if (isWindowModified()) {
		//QMessageBox::warning(parent, title, message, buttons);
		//QMessageBox:: information | question | warning | critical
		int r = QMessageBox::warning(this, tr("Spreadsheet"),
									 tr("The document has been modified.\n"
									    "Do you want to save your changes?"),
									 QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
		if (r == QMessageBox::Yes) {
			return save();
		} else if (r == QMessageBox::Cancel) {
			return false;
		}
	}
	return true;
}

void MainWindow::open() {
	std::cout << "MainWindow::open()" << std::endl;
	if (okToContinue()) {
		//QFileDialog::getOpenFileName(parent, title, starting dir, file filter);
		QString filename = QFileDialog::getOpenFileName(this, tr("Open Spreadsheet"),
														".", tr("Spreadsheet files (*.sp)"));
		if (!filename.isEmpty()) {
			loadFile(filename);
		}
	}
}

bool MainWindow::loadFile(const QString &filename) {
	std::cout << "MainWindow::loadFile()" << std::endl;
	if (!spreadsheet->readFile(filename)) {
		statusBar()->showMessage(tr("Loading canceled"), 3000);
		return false;
	}
	setCurrentFile(filename);
	statusBar()->showMessage(tr("File loaded"), 3000);
	return true;
}

bool MainWindow::save() {
	std::cout << "MainWindow::save()" << std::endl;
	if (currentFile.isEmpty()) {
		return saveAs();
	} else {
		return saveFile(currentFile);
	}
}

bool MainWindow::saveFile(const QString &filename) {
	std::cout << "MainWindow::saveFile()" << std::endl;
	if (!spreadsheet->writeFile(filename)) {
		statusBar()->showMessage(tr("Saving canceled"), 3000);
		return false;
	}
	setCurrentFile(filename);
	statusBar()->showMessage(tr("File saved"), 3000);
	return true;
}

bool MainWindow::saveAs() {
	std::cout << "MainWindow::saveAs()" << std::endl;
	QString filename = QFileDialog::getSaveFileName(this, tr("Save Spreadsheet"),
													".", tr("Spreadsheet files (*.sp)"));
	if (filename.isEmpty())
		return false;

	return saveFile(filename);
}

void MainWindow::closeEvent(QCloseEvent *event) {
	std::cout << "MainWindow::closeEvent()" << std::endl;
	if (okToContinue()) {
		writeSettings();
		event->accept();
	} else {
		event->ignore();
	}
}

void MainWindow::setCurrentFile(const QString &filename) {
	std::cout << "MainWindow::setCurrentFile()" << std::endl;
	currentFile = filename;
	setWindowModified(false);

	QString shownName = tr("Untitled");
	std::cout << "if (!currentFile.isEmpty())" << std::endl;
	if (!currentFile.isEmpty()) {
		shownName = strippedName(currentFile);
		std::cout << "recentFiles.removeAll(currentFile);" << std::endl;
		recentFiles.removeAll(currentFile);
		recentFiles.prepend(currentFile);
		std::cout << "updateRecentFilesActions();" << std::endl;
		updateRecentFileActions();
	}

	setWindowTitle(tr("%1[*] - %2").arg(shownName).arg(tr("Spreadsheet")));
}

QString MainWindow::strippedName(const QString &fullFileName) {
	return QFileInfo(fullFileName).fileName();
}

void MainWindow::updateRecentFileActions() {
	QMutableStringListIterator i(recentFiles);
	std::cout << "while (i.hasNext())" << std::endl;
	while (i.hasNext()) {
		std::cout << "i.hasNext() == true" << std::endl;
		if (!QFile::exists(i.next())) {
			i.remove();
		}
	}

	std::cout << "for (int j = 0; j < MaxRecentFIles; j++)" << std::endl;
	for (int j = 0; j < MaxRecentFiles; j++) {
		if (j < recentFiles.count()) {
			std::cout << "j < recentFiles.count()" << std::endl;
			QString text = tr("&%1 %2").arg(j + 1).arg(strippedName(recentFiles[j]));
			recentFilesActions[j]->setText(text);
			recentFilesActions[j]->setData(recentFiles[j]);
			recentFilesActions[j]->setVisible(true);
		} else {
			std::cout << "j > recentFiles.count()" << std::endl;
			recentFilesActions[j]->setVisible(false);
		}
	}
	std::cout << "separatorAction->setVisiable()" << std::endl;
	separatorAction->setVisible(!recentFiles.isEmpty());

	std::cout << "foreach (topLevelWidgets())" << std::endl;

	foreach (QWidget *win, QApplication::topLevelWidgets()) {
		if (MainWindow *mainWin = qobject_cast<MainWindow *>(win)) {
			std::cout << "mainWin top level found" << std::endl;
// 			mainWin->updateRecentFileActions();
		}
	}
}

void MainWindow::openRecentFile() {
	if (okToContinue()) {
		QAction *action = qobject_cast<QAction *>(sender());
		if (action) {
			loadFile(action->data().toString());
		}
	}
}

void MainWindow::find() {
	if (!findDialog) {
		findDialog = new FindDialog(this);
		connect(findDialog, SIGNAL(findNext(const QString &, Qt::CaseSensitivity)),
				spreadsheet, SLOT(findNext(const QString &, Qt::CaseSensitivity)));
		connect(findDialog, SIGNAL(findPrevious(const QString &, Qt::CaseSensitivity)),
				spreadsheet, SLOT(findPrevious(const QString &, Qt::CaseSensitivity)));
	}
	findDialog->show();
	findDialog->raise();
	findDialog->activateWindow();
}

void MainWindow::goToCell() {
	GoToCellDialog dialog(this);
	if (dialog.exec()) {
		QString str = dialog.lineEdit->text().toUpper();
		spreadsheet->setCurrentCell(str.mid(1).toInt() - 1,
									str[0].unicode() - 'A');
	}
}

void MainWindow::sort() {
	SortDialog dialog(this);
	QTableWidgetSelectionRange range = spreadsheet->selectedRange();
	dialog.setColumnRange('A' + range.leftColumn(), 'A' + range.rightColumn());

	if (dialog.exec()) {
		SpreadsheetCompare compare;
		compare.keys[0] = dialog.primaryColumnCombo->currentIndex();
		compare.keys[1] = dialog.secondaryColumnCombo->currentIndex();
		compare.keys[2] = dialog.tertiaryColumnCombo->currentIndex();
		compare.ascending[0] = (dialog.primaryOrderCombo->currentIndex() == 0);
		compare.ascending[1] = (dialog.secondaryOrderCombo->currentIndex() == 0);
		compare.ascending[2] = (dialog.tertiaryOrderCombo->currentIndex() == 0);
		spreadsheet->sort(compare);
	}
}

void MainWindow::about() {
	QMessageBox::about(this, tr("About Spreadsheet"),
					   tr("<h2>Spreadsheet 0.1</h2>"
						  "<p>Copyright &copy; 2008 Armin Moradi"
						  "<p>Spreadsheet is a small application that "
						  "is written in C++/Qt for educational purposes only."));
}

void MainWindow::writeSettings() {
	std::cout << "MainWindow::writeSettings()" << std::endl;
	QSettings settings("Armin Moradi", "Spreadsheet");

	settings.setValue("geometry", saveGeometry());
	settings.setValue("recentFiles", recentFiles);
	settings.setValue("showGrid", showGridAction->isChecked());
	settings.setValue("autoRecalc", autoRecalcAction->isChecked());
}

void MainWindow::readSettings() {
	std::cout << "MainWindow::readSettings()" << std::endl;
	QSettings settings("Armin Moradi", "Spreadsheet");
	
	restoreGeometry(settings.value("geometry").toByteArray());

	recentFiles = settings.value("recentFiles").toStringList();
	updateRecentFileActions();

	bool showGrid = settings.value("showGrid", true).toBool();
	showGridAction->setChecked(showGrid);

	bool autoRecalc = settings.value("autoRecalc", true).toBool();
	autoRecalcAction->setChecked(autoRecalc);
}