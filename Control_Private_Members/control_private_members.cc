//使用trick对Base class的private属性进行操纵，利用的就是virtual Tables
#include <iostream>

using namespace std;

class Base{
private:
	virtual void f()
	{
		cout << "Base:: f()" << endl;
	}
};

class Derive:public Base{

};

typedef void(*Fun)(void);

int main(int argc, const char **argv)
{
	Derive d;
	//d.f();正常情况下编译器讲阻止该行为
	Fun pFun = (Fun)*((int*)*(int*)(&d)+0);
	pFun();

	return 0;
}