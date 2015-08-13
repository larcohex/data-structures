#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
	Queue <int> test;
	for (int i = 0; i < 10; ++i)
	{
		test.enqueue (i);
	}
	while (!test.empty())
	{
		cout << test.queue() << endl;
		test.dequeue();
	}
	return 0;
}
