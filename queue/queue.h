#ifndef QUEUE_H
#define QUEUE_H
#include <list>

using namespace std;

template <typename Object>
class Queue
{

	private:

		list <Object> q;


	public:

		Queue()
		{
		}


		~Queue()
		{
		}


		Queue (const Queue &q)
		{
			this->q = q.q;
		}


		int size()
		{
			return this->q.size();
		}


		bool empty()
		{
			return this->q.empty();
		}


		void enqueue (Object &obj)
		{
			this->q.push_back (obj);
		}


		void dequeue()
		{
			this->q.pop_front();
		}


		Object &queue()
		{
			return this->q.front();
		}


		bool operator== (const Queue &rhs)
		{
			return (this->q == rhs.q);
		}


		bool operator!= (const Queue &rhs)
		{
			return (this->q != rhs.q);
		}


		Queue &operator= (const Queue &rhs)
		{
			this->q = rhs.q;
			return *this;
		}

};

#endif
