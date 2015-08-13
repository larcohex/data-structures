#ifndef HASH
#define HASH
#include <list>
#include <string>

using namespace std;

class HashTable
{


	private:



		int s;
		list <string> *table;



	public:



		HashTable()
		{
			this->s = 151;
			this->table = new list <string> [151];
		}



		HashTable (int size)
		{
			this->s = size;
			this->table = new list <string> [size];
		}



		~HashTable()
		{
			this->s = 0;
			delete [] this->table;
		}




		HashTable (const HashTable &ht)
		{
			this->s = ht.size();
			this->table = new list <string> [ht.size()];
			for (int i = 0; i < ht.size(); ++i)
			{
				(this->table)[i] = (ht.table)[i];
			}
		}



		unsigned int hash (string word)
		{
			const unsigned int prime = 709607;
			unsigned int hash = 2166136261;
			const char *str = word.c_str();
			unsigned int len = word.size();
			while (len >= 2 * sizeof (unsigned int))
			{
				hash = prime * (hash ^ (((*(unsigned int *)(str) << 5) | (*(unsigned int *)(str) >> 27)) ^ (*(unsigned int *)(str + 4))));
				len = len - 2 * sizeof (unsigned int);
				str = str + 2 * sizeof (unsigned int);
			}
			if (len & sizeof (unsigned int))
			{
				hash = prime * (hash ^ (*(unsigned short *)(str)));
				str = str + sizeof (unsigned short);
				hash = prime * (hash ^ (*(unsigned short *)(str)));
				str = str + sizeof (unsigned short);
			}
			if (len & sizeof (unsigned short))
			{
				hash = prime * (hash ^ (*(unsigned short *)(str)));
				str = str + sizeof (unsigned short);
			}
			if (len & 1)
			{ 
				hash = prime * (hash ^ *str);
			}
			return hash ^ (hash >> 16);
		}





		unsigned int search (string &word)
		{
			unsigned int key = (this->hash (word)) % (this->s);
			for (list <string> :: iterator itr = ((this->table)[key]).begin(); itr != ((this->table)[key]).end(); ++itr)
			{
				if (*itr == word)
				{
					return key;
				}
			}
			throw 0;
		}



		
		void insert (string &word)
		{
			try
			{
				this->search (word);
			}
			catch (int e)
			{
				unsigned int key = (this->hash(word)) % (this->s);
				((this->table)[key]).push_back (word);
			}
		}






		void remove (string &word)
		{
			unsigned int key = (this->hash (word)) % (this->s);
			for (list <string> :: iterator itr = ((this->table)[key]).begin(); itr != ((this->table)[key]).end(); ++itr)
			{
				if (*itr == word)
				{
					((this->table)[key]).erase (itr);
					break;
				}
			}
		}





		int size() const
		{
			return this->s;
		}




		HashTable &operator= (const HashTable &rhs)
		{
			this->s = rhs.size();
			delete [] this->table;
			this->table = new list <string> [rhs.size()];
			for (int i = 0; i < this->s; ++i)
			{
				(this->table)[i] = (rhs.table)[i];
			}
			return *this;
		}



};
#endif
