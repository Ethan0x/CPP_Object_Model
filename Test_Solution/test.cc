#include <iostream>
using namespace std;

class Foo{
public:
	int val;
	Foo *pnext;
};
int main(int argc, const char **argv)
{
	Foo bar;
	cout << bar.val << "\t" << bar.pnext << endl;
	return 0;
}