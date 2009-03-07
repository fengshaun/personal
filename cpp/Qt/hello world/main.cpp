#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QWidget>

 int main(int argc, char *argv[])
{
	QApplication app( argc, argv );

	QWidget window;
	window.resize( 100, 200 );

	QLabel hello( "Hello World...!", &window );
	hello.resize( 200, 300 );
	hello.setFont( QFont( "Times", 15, QFont::Bold ) );
	
	QPushButton helloB( "Hello", &window );
	helloB.setGeometry( 0, 51, 30, 48 );
	
	QPushButton no( "No", &window );
	no.setGeometry( 35, 51, 30, 48 );

	QPushButton quit( "Quit", &window );
	quit.setGeometry( 70, 51, 30, 48 );

	window.show();
	return app.exec();

}
