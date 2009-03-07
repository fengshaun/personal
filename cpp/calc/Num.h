class Num
{
	public:
		Num();
		~Num();

		int add();
		int subtract();
		int multiply();
		int divide();

		void setNum1( int );
		void setNum2( int );

	private:
		int num1;
		int num2;
};
