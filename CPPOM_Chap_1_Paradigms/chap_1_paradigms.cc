//使用父类操作子类的函数
//在使用pointer和reference进行赋值时，C++的语义层必须要作适当的clip
//这种父类和子类之间的赋值操作一定要知道其准确含义
#include <iostream>
#include <string>
using namespace std;

class Base{
public:
	Base(float x = 0.0f):_x(x){}
	virtual void foo(){ cout << "Base: Foo()!" <<endl; }
private:
	float _x;
};

class Derive:public Base{
public:
	Derive(float x = 1.0f, float y = 1.0f):Base(x), _y(y){}
	virtual void foo(){ cout << "Derive: Foo()!" <<endl; }
private:
	float _y;
};

int main(int argc, const char **argv)
{
	Derive d;
	//Base b;
	//b =d;
	Base &b = d;

	string s("123");
	cout << sizeof(s) << endl;
	cout << sizeof(string) << endl;  //20
	cout << sizeof(int) << endl;
	b.foo();
	return 0;
}