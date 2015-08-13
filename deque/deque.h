#ifndef DEQUE_H
#define DEQUE_H
#include <list>

using namespace std;

template <typename Object>
class Deque
{

	private:

		list <Object> deque;


	public:

		Deque()
		{
		}


		~Deque()
		{
		}


		Deque (const Deque &d)
		{
			this->deque = d.deque;
		}


		int size()
		{
			return this->deque.size();
		}


		bool empty()
		{
			return this->deque.empty();
		}


		void push (Object &obj)
		{
			this->deque.push_front (obj);
		}


		void enqueue (Object &obj)
		{
			this->deque.push_front (obj);
		}


		void pop()
		{
			this->deque.pop_front();
		}


		void inject (Object &obj)
		{
			this->deque.push_back (obj);
		}


		void dequeue()
		{
			this->deque.pop_back();
		}


		void eject()
		{
			this->deque.pop_back();
		}


		Object &front()
		{
			return this->deque.front();
		}


		Object &back()
		{
			return this->deque.back();
		}


		bool operator== (const Deque &rhs)
		{
			return this->deque == rhs.deque;
		}


		bool operator!= (const Deque &rhs)
		{
			return this->deque != rhs.deque;
		}


		Deque &operator= (const Deque &rhs)
		{
			this->deque = rhs.deque;
			return *this;
		}

};

#endif
