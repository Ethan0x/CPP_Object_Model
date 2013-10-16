//单一继承 a-b-c
//在这个继承关系中，父类，子类，孙子类都有自己的一个成员变量。
//而子类覆盖了父类的f()方法，孙子类覆盖了子类的g_child()及其超类的f()。
//在本例中我们使用的方法：
//使用了一个int** pVtab 来作为遍历对象内存布局的指针，像使用数组一样来遍历所有的成员包括其虚函数表
/////////////////////////////////////////////////////////////////////////////////////////
//Result:
//1）虚函数表在最前面的位置。
//2）成员变量根据其继承和声明顺序依次放在后面。
//3）在单一的继承中，被overwrite的虚函数在虚函数表中得到了更新。
#include <iostream>
using namespace std;

class Parent{
public:
	int iparent;
	Parent():iparent(10){}
	virtual void f(){cout << "Parent:f()!" << endl;}
	virtual void g(){cout << "Parent:g()!" << endl;}
	virtual void h(){cout << "Parent:h()!" << endl;}
};

class Child:public Parent{
public:
	int ichild;
	Child():ichild(100){}
	virtual void f(){cout << "Child:f()!" << endl;}
	virtual void g_child(){cout << "Child:g_child()!" << endl;}
	virtual void h_child(){cout << "child:h_child()!" << endl;}
};

class GrandChild:public Child{
public:
	int igrandchild;
	GrandChild():igrandchild(1000){}
	virtual void f(){cout << "GrandChild:f()!" << endl;}
	virtual void g_child(){cout << "GrandChild:g_child()!" <<endl;}
	virtual void h_grandchild(){cout << "FrandChild:h_grandchild()!" << endl;}

};

typedef void(*Fun)(void);

int main(int argc, const char** argv)
{
	GrandChild gc;
	int** pVtable = (int**)&gc;

	cout << "[0] GrandChild:v_ptr->" <<endl;

	for (int i = 0; (Fun)pVtable[0][i] != NULL; ++i)
	{
		Fun pFun;
		pFun = (Fun)pVtable[0][i];
		cout << " [" << i << "] ";
		pFun();
	}

	cout << "[1] Parent.iparent = " << (int)pVtable[1] << endl;
	cout << "[2] Child.ichild = " << (int)pVtable[2] <<endl;
	cout << "[3] Grandchild.igrandchild = " << (int)pVtable[3] << endl;

	return 0;
}