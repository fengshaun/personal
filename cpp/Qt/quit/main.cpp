#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <QLabel>

int main( int argc, char *argv[] ) {
	QApplication app( argc, argv );

	QPushButton quit( "Quit" );
	quit.resize( 300, 200 );
	quit.setFont( QFont( "Times", 18, QFont::Bold ) );
	QPushButton hello( "Hello" );
	hello.resize( 100, 300 );
	hello.show();

	QLabel hellol( "hello world" );
	hellol.resize( 300, 500 );

	QObject::connect( &quit, SIGNAL( clicked() ), &app, SLOT( quit() ) );
	QObject::connect( &hello, SIGNAL( clicked() ), &app, SLOT( quit() ) );

	quit.show();
	return app.exec();
}
