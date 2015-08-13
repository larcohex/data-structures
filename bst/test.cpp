#include <iostream>
#include "bst.h"

using namespace std;


int main()
{
	list <int> testPre;
	list <int> testIn;
	list <int> testPost;
	list <int> testBre;
	BST <int> test, test2;
	for (int i = 0; i < 10; ++i)
	{
		if (i % 2)
			test.insert (i);
		else
			test.insert (10 - i);
	}
	BST <int> test3 (test);
	testPre = test.pre_order();
	testIn = test.in_order();
	testPost = test.post_order();
	testBre = test.breadth_first();
	for (list <int> :: iterator itr = testPre.begin(); itr != testPre.end(); ++itr)
	{
		cout << *itr << " ";
	}
	cout << endl;
	for (list <int> :: iterator itr = testIn.begin(); itr != testIn.end(); ++itr)
	{
		cout << *itr << " ";
	}
	cout << endl;
	for (list <int> :: iterator itr = testPost.begin(); itr != testPost.end(); ++itr)
	{
		cout << *itr << " ";
	}
	cout << endl;
	for (list <int> :: iterator itr = testBre.begin(); itr != testBre.end(); ++itr)
	{
		cout << *itr << " ";
	}
	cout << endl;
	cout << (test3 == test) << endl;
	test.erase (10);
	cout << (test3 == test) << endl;
	testPre = test.pre_order();
	testIn = test.in_order();
	testPost = test.post_order();
	testBre = test.breadth_first();
	for (list <int> :: iterator itr = testPre.begin(); itr != testPre.end(); ++itr)
	{
		cout << *itr << " ";
	}
	cout << endl;
	for (list <int> :: iterator itr = testIn.begin(); itr != testIn.end(); ++itr)
	{
		cout << *itr << " ";
	}
	cout << endl;
	for (list <int> :: iterator itr = testPost.begin(); itr != testPost.end(); ++itr)
	{
		cout << *itr << " ";
	}
	cout << endl;
	for (list <int> :: iterator itr = testBre.begin(); itr != testBre.end(); ++itr)
	{
		cout << *itr << " ";
	}
	cout << endl;
	BST <int> :: Node *searchTest = searchTest = test.search (4);
	cout << searchTest->obj << endl;
	test2 = test;
	cout << (test2 == test) << endl;
	test.clear();
	cout << (test2 == test) << endl;
	testPre = test.pre_order();
	testIn = test.in_order();
	testPost = test.post_order();
	testBre = test.breadth_first();
	for (list <int> :: iterator itr = testPre.begin(); itr != testPre.end(); ++itr)
	{
		cout << *itr << " ";
	}
	cout << endl;
	for (list <int> :: iterator itr = testIn.begin(); itr != testIn.end(); ++itr)
	{
		cout << *itr << " ";
	}
	cout << endl;
	for (list <int> :: iterator itr = testPost.begin(); itr != testPost.end(); ++itr)
	{
		cout << *itr << " ";
	}
	cout << endl;
	for (list <int> :: iterator itr = testBre.begin(); itr != testBre.end(); ++itr)
	{
		cout << *itr << " ";
	}
	cout << endl;
	return 0;
}
