#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
	Stack <int> test;
	for (int i = 0; i < 10; ++i)
	{
		test.push (i);
	}
	while (!test.empty())
	{
		cout << test.pip() << endl;
		test.pop();
	}
	return 0;
}
