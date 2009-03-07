//class definition
class Class : public BaseClass
{
	public:
		Class();
		~Class();

		void someFunction1();
		void someFunction2( int, int );

	private:
		OtherClass member1;
		OtherClass * member2;
		
		int * number;
};


//function definition
void someFunction( int a, int b ) {
	if ( true ) {
		//this
	} else {
		//that
	}

	while ( true ) {
		//this
	}

	for ( true ) {
		//this
	}
}
