#include <iostream>
using namespace std;

class Foo{
public:
	Foo(int ival = 0):_val(ival), pnext(NULL){}
	int _val;
	Foo *pnext;
};
int main(int argc, const char **argv)
{
	Foo bar;
	cout << bar._val << "\t" << bar.pnext << endl;
	return 0;
}