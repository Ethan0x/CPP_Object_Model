//多重继承 (a,b,c)-d  中的V-able
//三个父类虚函数表中的f()的位置被替换成了子类的函数指针。这样任一静态类型的父类来指向子类，并调用子类的f()了。
#include <iostream>
using namespace std;

class Base1{
public:
	int ibase1;
	Base1():ibase1(10){}
	virtual void f(){cout << "Base1:f()!" << endl;}
	virtual void g(){cout << "Base1:g()!" << endl;}
	virtual void h(){cout << "Base1:h()!" << endl;}
};

class Base2{
public:
	int ibase2;
	Base2():ibase2(20){}
	virtual void f(){cout << "Base2:f()!" << endl;}
	virtual void g(){cout << "Base2:g()!" << endl;}
	virtual void h(){cout << "Base2:h()!" << endl;}
};

class Base3{
public:
	int ibase3;
	Base3():ibase3(30){}
	virtual void f(){cout << "Base3:f()!" << endl;}
	virtual void g(){cout << "Base3:g()!" << endl;}
	virtual void h(){cout << "Base3:h()!" << endl;}
};

class Derive:public Base1, public Base2, public Base3{
public:
	int iderive;
	Derive():iderive(100){}
	virtual void f(){cout << "Derive:f()!" <<endl;}
	virtual void g1(){cout << "Derive:g1()!" <<endl;}
};

typedef void(*Fun)(void);

int main(int argc, const char** argv)
{
	Derive d;
	int** pVtable = (int**)&d;
	Fun pFun;

	cout << "[0]Base::_vptr->" << endl;

	pFun = (Fun)pVtable[0][0];
	cout << "	[0]";
	pFun();

	pFun = (Fun)pVtable[0][1];
	cout << "	[1]";
	pFun();

	pFun = (Fun)pVtable[0][2];
	cout << "	[2]";
	pFun();

	pFun = (Fun)pVtable[0][3];
	cout << "	[3]";
	pFun();

	pFun = (Fun)pVtable[0][4];
	cout << "	[4]";
	cout << pFun <<endl;

	cout << "[1]Base1.ibase1 = " << (int)pVtable[1] << endl;

	int s = sizeof(Base1)/4;

	cout << "[" << s << "] Base2::_vptr->"<<endl;
	pFun = (Fun)pVtable[s][0];
	cout << "     [0] "; 
	pFun();

	pFun = (Fun)pVtable[s][1];
	cout << "     [1] "; 
	pFun();

	pFun = (Fun)pVtable[s][2];
	cout << "     [2] "; 
	pFun();

	pFun = (Fun)pVtable[s][3];
	cout << "     [3] ";
	cout << pFun << endl;

	cout << "["<< s+1 <<"] Base2.ibase2 = " << (int)pVtable[s+1] << endl;

	s = s + sizeof(Base2)/4;

	cout << "[" << s << "] Base3::_vptr->" << endl;
	pFun = (Fun)pVtable[s][0];
	cout << "     [0] "; 
	pFun();

	pFun = (Fun)pVtable[s][1];
	cout << "     [1] "; 
	pFun();

	pFun = (Fun)pVtable[s][2];
	cout << "     [2] "; 
	pFun();

	pFun = (Fun)pVtable[s][3];
	cout << "     [3] ";
	cout << pFun << endl;

	s++;
	cout << "["<< s <<"] Base3.ibase3 = " << (int)pVtable[s] << endl;
	s++;
	cout << "["<< s <<"] Derive.iderive = " << (int)pVtable[s] << endl;

	return 0;
}
