//初探C++ Virtual Tables内存布局，在每个derived类的最前面为其
//父类的虚函数表，每个父类按继承顺序依次排序，每一个父类的VTable就是向其
//该类所有虚函数的函数指针
//该Vtable有四种简单模式，详见笔记之中

#include <iostream>
#include <string>

using namespace std;

class Base{
public:
	virtual void f(){cout << "Base:f" << endl;};
	virtual void g(){cout << "Base:g" << endl;};
	virtual void h(){cout << "Base:h" << endl;};
};

typedef void(*Fun)(void);

int main(int argc, const char** argv[])
{
	Base b;

	Fun pFun = NULL;

	cout << "The virtual tables's address is :" << (int*)(&b) <<endl;
	cout << "The function f()'s address from the V-Table is :" << (int*)(int*)(&b) <<endl;

	//Invoke the first virtual function
	pFun = (Fun)*((int*)*(int*)(&b));
	pFun();

	return 0;
}