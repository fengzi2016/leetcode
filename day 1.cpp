/*复数结构体加减运算符重载*/
#include"iostream.h"
struct complex{
	int real;
	int imag;
	complex &operator + (complex &s)
	{
		complex c;
		c.real=real+s.real;
		c.imag=imag+s.imag;
		return c;
	}
	complex &operator += (complex &s);
	friend ostream &operator<<(ostream &output, complex &s);
	};
	complex &complex::operator += (complex &s)
	{
		real+=s.real;
		imag+=s.imag;
		return *this;
	}
	ostream&operator<<(ostream &output,complex &s)
	{
		output << "a.real ="<<s.real<<"a.imag="<<s.imag<<endl;
		return output;
	}
int  main(){
		complex c={0,0},a,b={1,5};
		a=b+b;
		c+=b;
		cout<<a;
		cout<<"c.real ="<<c.real<<"c.imag ="<<c.imag<<endl;
		cout<<"b.real ="<<b.real<<"b.imag ="<<b.imag<<endl;
}

	
