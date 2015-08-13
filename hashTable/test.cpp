#include <iostream>
#include "hashTable.h"
#include <fstream>
#include <ctime>
#include <vector>


int main()
{
	HashTable test1;
	HashTable test2 (1999);
	fstream file;
	file.open ("test.txt");
	while (!file.eof())
	{
		string temp;
		getline (file, temp);
		test1.insert (temp);
		test2.insert (temp);
	}
	file.close();
	file.open ("search.txt");
	ofstream output1 ("output1.txt");
	ofstream output2 ("output2.txt");
	vector <string> input;
	while (!file.eof())
	{
		string temp;
		getline (file, temp);
		input.push_back (temp);
	}
	time_t start, finish;
	time (&start);
	for (int i = 0; i < 30000; ++i)
	{
		for (int j = 0; j < input.size(); ++j)
		{
			try
			{
				test1.search (input[j]);
			}
			catch (int e)
			{
			}
		}
	}
	time (&finish);
	int result = (int) difftime (finish, start);
	output1 << result << "\n" << endl;
	for (int i = 0; i < input.size(); ++i)
	{
		try
		{
			output1 << test1.search (input[i]) << endl;
		}
		catch (int e)
		{
			output1 << "NOT FOUND" << endl;
		}
	}
	time (&start);
	for (int i = 0; i < 30000; ++i)
	{
		for (int j = 0; j < input.size(); ++j)
		{
			try
			{
				test2.search (input[j]);
			}
			catch (int e)
			{
			}
		}
	}
	time (&finish);
	result = (int) difftime (finish, start);
	output2 << result << "\n" << endl;
	for (int i = 0; i < input.size(); ++i)
	{
		try
		{
			output2 << test2.search (input[i]) << endl;
		}
		catch (int e)
		{
			output2 << "NOT FOUND" << endl;
		}
	}
	output1.close();
	output2.close();
	file.close();
	return 0;
}
