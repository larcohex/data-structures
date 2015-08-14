#ifndef STACK_H
#define STACK_H
#include <list>

using namespace std;

template <typename Object>
class Stack
{

	private:

		list <Object> stack;


	public:

		Stack()
		{
		}

		~Stack()
		{
		}

		Stack (const Stack &st)
		{
			this->stack = st.stack;
		}


		int size()
		{
			return this->stack.size();
		}


		bool empty()
		{
			return this->stack.empty();
		}


		void push (Object &obj)
		{
			this->stack.push_back (obj);
		}


		void pop()
		{
			this->stack.pop_back();
		}


		Object &pip()
		{
			return this->stack.back();
		}


		bool operator== (const Stack &rhs)
		{
			return this->stack == rhs.stack;
		}


		bool operator!= (const Stack &rhs)
		{
			return this->stack != rhs.stack;
		}


		Stack &operator= (const Stack &rhs)
		{
			this->stack = rhs.stack;
			return *this;
		}

};

#endif
