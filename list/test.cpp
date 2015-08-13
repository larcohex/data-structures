#include "list.h"
#include <iostream>
#include <string>

using namespace std;


int main()
{
	SinglyLinkedList <int> test0;
	SinglyLinkedList <char> test1;
	SinglyLinkedList <string> test2;


	cout << "TESTING LISTS" << endl;
	cout << "Integers:" << endl;
	test0.push_front (0);
	test0.push_front (1);
	test0.push_front (2);
	test0.push_front (3);
	test0.pop_front();
	SinglyLinkedList <int> test3 (test0);
	SinglyLinkedList <int> test4;
	test4 = test3;
	test0.clear();
	SinglyLinkedList <int>::iterator itr;
	cout << "test0 - ";
	for (itr = (test0.begin()); itr != (test0.end()); ++itr)
	{
		cout << *itr;
	}
	cout << endl;
	cout << "size of test0 - " << test0.size() << endl;
	cout << "test3 - ";
	for (itr = (test3.begin()); itr != (test3.end()); ++itr)
	{
		cout << *itr;
	}
	cout << *itr;
	cout << endl;
	cout << "size of test3 - " << test3.size() << endl;
	cout << "1st element in test3 - " << test3.front() << endl;
	cout << "test4 - ";
	for (itr = (test4.begin()); itr != (test4.end()); ++itr)
	{
		cout << *itr;
	}
	cout << *itr;
	cout << endl;
	cout << "size of test4 - " << test4.size() << endl;
	cout << "1st element in test4 - " << test4.front() << endl;
	cout << "COPY CONSTRUCTORS: COMPLETE" << endl;
	cout << "BEGIN(): COMPLETE" << endl;
	cout << "END(): COMPLETE" << endl;
	cout << "CLEAR(): COMPLETE" << endl;
	SinglyLinkedList <int> test5 = test0;
	if (test5.empty())
	{
		cout << "EMPTY(): COMPLETE" << endl;
	}
	cout << "SIZE(): COMPLETE" << endl;
	test3.insert (++test3.begin(), 42);
	if (*(++(++test3.begin())) == 42)
	{
		cout << "42 is the third element" << endl;
	}
	cout << "INSERT(): COMPLETE" << endl;
	test3.erase (test3.begin());
	if (test3.front() == 42)
	{
		cout << "42 is now at the beginning" << endl;
	}
	cout << "ERASE(): COMPLETE" << endl;
	if (test0 == test5)
	{
		cout << "test0 and test5 are equal" << endl;
		if (test3 != test4)
		{
			cout << "test3 and test4 are not equal" << endl;
			cout << "COMPARIZON: COMPLETE" << endl;
		}
	}
	


	cout << "\n\n\n\n\n" << endl;


	cout << "TESTING LISTS" << endl;
	cout << "Characters:" << endl;
	test1.push_front ('a');
	test1.push_front ('b');
	test1.push_front ('c');
	test1.push_front ('d');
	test1.pop_front();
	SinglyLinkedList <char> test6 (test1);
	SinglyLinkedList <char> test7;
	test7 = test6;
	test1.clear();
	SinglyLinkedList <char>::iterator itr1;
	cout << "test1 - ";
	for (itr1 = (test1.begin()); itr1 != (test1.end()); ++itr1)
	{
		cout << *itr1;
	}
	cout << endl;
	cout << "size of test1 - " << test1.size() << endl;
	cout << "test6 - ";
	for (itr1 = (test6.begin()); itr1 != (test6.end()); ++itr1)
	{
		cout << *itr1;
	}
	cout << *itr1;
	cout << endl;
	cout << "size of test6 - " << test6.size() << endl;
	cout << "1st element in test6 - " << test6.front() << endl;
	cout << "test7 - ";
	for (itr1 = (test7.begin()); itr1 != (test7.end()); ++itr1)
	{
		cout << *itr1;
	}
	cout << *itr1;
	cout << endl;
	cout << "size of test7 - " << test7.size() << endl;
	cout << "1st element in test7 - " << test7.front() << endl;
	cout << "COPY CONSTRUCTORS: COMPLETE" << endl;
	cout << "BEGIN(): COMPLETE" << endl;
	cout << "END(): COMPLETE" << endl;
	cout << "CLEAR(): COMPLETE" << endl;
	SinglyLinkedList <char> test8 = test1;
	if (test8.empty())
	{
		cout << "EMPTY(): COMPLETE" << endl;
	}
	cout << "SIZE(): COMPLETE" << endl;
	test6.insert (++test6.begin(), 'z');
	if (*(++(++test6.begin())) == 'z')
	{
		cout << "z is the third element" << endl;
	}
	cout << "INSERT(): COMPLETE" << endl;
	test3.erase (test3.begin());
	if (test3.front() == 'z')
	{
		cout << "z is now at the beginning" << endl;
	}
	cout << "ERASE(): COMPLETE" << endl;
	if (test1 == test8)
	{
		cout << "test1 and test8 are equal" << endl;
		if (test6 != test7)
		{
			cout << "test6 and test7 are not equal" << endl;
			cout << "COMPARIZON: COMPLETE" << endl;
		}
	}



	cout << "\n\n\n\n\n" << endl;



	cout << "TESTING LISTS" << endl;
	cout << "Strings:" << endl;
	test2.push_front ("Hello ");
	test2.push_front ("I ");
	test2.push_front ("am ");
	test2.push_front ("alive");
	test2.pop_front();
	SinglyLinkedList <string> test9 (test2);
	SinglyLinkedList <string> test10;
	test10 = test9;
	test2.clear();
	SinglyLinkedList <string>::iterator itr2;
	cout << "test2 - ";
	for (itr2 = (test2.begin()); itr2 != (test2.end()); ++itr2)
	{
		cout << *itr2;
	}
	cout << endl;
	cout << "size of test2 - " << test2.size() << endl;
	cout << "test9 - ";
	for (itr2 = (test9.begin()); itr2 != (test9.end()); ++itr2)
	{
		cout << *itr2;
	}
	cout << *itr2;
	cout << endl;
	cout << "size of test9 - " << test9.size() << endl;
	cout << "1st element in test9 - " << test9.front() << endl;
	cout << "test10 - ";
	for (itr2 = (test10.begin()); itr2 != (test10.end()); ++itr2)
	{
		cout << *itr2;
	}
	cout << *itr2;
	cout << endl;
	cout << "size of test10 - " << test10.size() << endl;
	cout << "1st element in test10 - " << test10.front() << endl;
	cout << "COPY CONSTRUCTORS: COMPLETE" << endl;
	cout << "BEGIN(): COMPLETE" << endl;
	cout << "END(): COMPLETE" << endl;
	cout << "CLEAR(): COMPLETE" << endl;
	SinglyLinkedList <string> test11 = test2;
	if (test11.empty())
	{
		cout << "EMPTY(): COMPLETE" << endl;
	}
	cout << "SIZE(): COMPLETE" << endl;
	test9.insert (++test9.begin(), "am not ");
	if (*(++(++test9.begin())) == "am not ")
	{
		cout << "\"am not \" is the third element" << endl;
	}
	cout << "INSERT(): COMPLETE" << endl;
	test9.erase (test9.begin());
	if (test9.front() == "am not ")
	{
		cout << "\"am not \" is now at the beginning" << endl;
	}
	cout << "ERASE(): COMPLETE" << endl;
	if (test2 == test11)
	{
		cout << "test2 and test11 are equal" << endl;
		if (test9 != test10)
		{
			cout << "test9 and test10 are not equal" << endl;
			cout << "COMPARIZON: COMPLETE" << endl;
		}
	}


	return 0;
}
