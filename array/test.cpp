#include "array.h"
#include <iostream>

int main()
{
	Array <int> test;
	for (int i = 0; i < 10; ++i)
	{
		test.push_back (i);
	}
	for (int i = 0; i < test.size(); ++i)
	{
		cout << test[i] << " ";
	}
	cout << endl;
	Array <int> test1 (test);
	for (int i = 0; i < test1.size(); ++i)
	{
		cout << test1[i] << " ";
	}
	cout << endl;
	Array <int> test2 = test1;
	for (int i = 0; i < test2.size(); ++i)
	{
		cout << test2[i] << " ";
	}
	cout << endl;
	test.pop_back();
	for (int i = 0; i < test.size(); ++i)
	{
		cout << test[i] << " ";
	}
	cout << endl;
	cout << test.front() << " " << test.back() << endl;
	cout << (test1 == test2) << " " << (test == test1) << endl;
}
