//static成员具有全局性，即便在某一函数内部声明的变量，其初始化仍然在程序的静态存储区，这将导致static
//成员具有全局可见和全局“唯一性”，且容易出现被覆盖的问题，其主要问题就是，一但一个变量声明后，
//其内存地址将保持不变，且不会被再次初始化，内容只会被覆盖
#include <iostream>

using namespace std;

int* Add_Func(int i)
{
	static int temp = i;
	return &(++temp);
}

int main(int argc, const char ** argv[])
{
	int a = 1, b = 2;
	printf("The First number is :%d!\t The second number is :%d!\t\n", *Add_Func(a), *Add_Func(b));
	return 0;
}