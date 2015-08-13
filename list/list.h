#ifndef LIST
#define LIST


#include <cstddef>



/*             SINGLY LINKED LIST             */


template <typename Object>
class SinglyLinkedList
{



	private:


		int listSize;									// size of list
		struct Node									// node implementation
		{
			Node ()
			{
				this->next = NULL;
			}
			Object obj;
			Node *next;
		};
		Node *head;									// pointer to dummy node



	public:



		/*         Basic members           */


		SinglyLinkedList ()								// constructor
		{
			this->head = new Node;
			this->listSize = 0;
		}


		~SinglyLinkedList()								// destructor
		{
			this->clear();
			delete this->head;
			this->listSize = 0;
		}


		SinglyLinkedList (const SinglyLinkedList &list)				// copy constructor
		{
			this->head = new Node;
			this->listSize = 0;
			if (!list.empty())
			{
				for (Node *temp = list.head; temp->next; temp = temp->next)
				{
					this->insert (this->end(), temp->next->obj);
				}
			}
		}



		class const_iterator								// constant iterator
		{



			public:

				const_iterator()
					: current (NULL)
				{
				}


				~const_iterator()
				{
					this->current = NULL;
				}


				const_iterator (const const_iterator &itr)
				{
					this->current = itr.current;
				}


				const Object &operator*() const				// * - returns object
				{
					if (this->current)
					{
						return this->current->obj;
					}
				}


				const_iterator &operator++()					// prefix increment
				{
					if (this-> current && this->current->next)
					{
						this->current = this->current->next;
					}
					return *this;
				}


				const_iterator operator++ (int)				// postfix increment
				{
					const_iterator old = *this;
					++(*this);
					return old;
				}


				bool operator== (const const_iterator &rhs) const			// == operator
				{
					return (this->current == rhs.current);
				}


				bool operator!= (const const_iterator &rhs) const			// != operator
				{
					return (this->current != rhs.current);
				}


				const_iterator &operator= (const const_iterator &source)	// assignment operator
				{
					this->current = source.current;
					return *this;
				}


			protected:


				Node *current;
				const_iterator (Node *node)
					: current (node)
				{
				}
				friend class SinglyLinkedList <Object>;


		};




		class iterator : public const_iterator					// iterator
		{


			public:


				iterator()
					:current (NULL)
				{
				}


				~iterator()
				{
					this->current = NULL;
				}


				iterator (const iterator &itr)
				{
					this->current = itr.current;
				}


				Object &operator* ()
				{
					if (this->current)
					{
						return this->current->obj;
					}
				}


				const Object &operator* () const
				{
					if (this->current)
					{
						const Object result = this->current->obj;
						return result;
					}
				}


				iterator &operator++ ()
				{
					if (this->current && this->current->next)
					{
						this->current = this->current->next;
					}
					return *this;
				}


				iterator operator++ (int)
				{
					iterator old = *this;
					++(*this);
					return old;
				}


				bool operator== (const iterator &rhs) const			// == operator
				{
					return (this->current == rhs.current);
				}


				bool operator!= (const iterator &rhs) const			// != operator
				{
					return (this->current != rhs.current);
				}


				iterator &operator= (const iterator &source)
				{
					this->current = source.current;
					return *this;
				}


			protected:
				Node *current;
				iterator (Node *node)
					: current (node)
				{
				}
				friend class SinglyLinkedList <Object>;


		};


		/*           Accessors             */


		iterator begin()								// iterator to 1st node
		{
			return iterator (this->head->next);
		}


		const_iterator begin() const							// constant iterator to 1st node
		{
			return const_iterator (this->head->next);
		}


		iterator end()									// iterator to last node
		{
			Node *temp;
			for (temp = this->head; temp->next; temp = temp->next)
			{
			}
			if (temp == this->head)
			{
				temp = temp->next;
			}
			return iterator (temp);
		}


		const_iterator end() const							// constant iterator to last node
		{
			Node *temp;
			for (temp = this->head; temp->next; temp = temp->next)
			{
			}
			if (temp == this->head)
			{
				temp = temp->next;
			}
			return const_iterator (temp);
		}


                int size() const								// size of list
		{
			return this->listSize;
		}


                bool empty() const								// checks if empty list
		{
			if (this->head->next)
			{
				return false;
			}
			else
			{
				return true;
			}
		}


		Object &front()									// first element of list
		{
			if (this->head->next)
			{
				return this->head->next->obj;
			}
		}


		const Object &front() const							// first element of constant list
		{
			if (this->head->next)
			{
				return this->head->next->obj;
			}
		}



		
		/*	      Mutators		   */


		void clear()
		{
			while (!(this->empty()))
			{
				this->pop_front();
			}
			this->listSize = 0;
		}


		void push_front(const Object &o)						// insert to begin
		{
			insert (iterator (this->head), o);
		}


		void pop_front()								// delete from begin
		{
			erase (this->begin());
		}


		iterator insert (iterator itr, const Object &o)				// insert obj after itr
		{
			Node *newNode = new Node;
			newNode->obj = o;
			Node *destination = itr.current;
			if (destination)
			{
				Node *temp = destination->next;
				destination->next = newNode;
				newNode->next = temp;
				++(this->listSize);
				return iterator (newNode);
			}
			else if (itr == this->end())
			{
				this->head->next = newNode;
				newNode->next = NULL;
				++(this->listSize);
				return iterator (newNode);
			}
		}


		iterator erase (iterator itr)							// erase obj in itr, return after itr or to end
		{
			Node *toDelete = itr.current;
			iterator result (toDelete->next);
			Node *prev = NULL;
			Node *next = toDelete->next;
			for (Node *temp = this->head; temp->next != NULL; temp = temp->next)
			{
				if (temp->next == toDelete)
				{
					prev = temp;
					break;
				}
			}
			if (prev)
			{
				prev->next = next;
				delete toDelete;
				--(this->listSize);
				return result;
			}
		}
		

		bool operator== (const SinglyLinkedList &rhs)
		{
			Node *temp1, *temp2;
			for (temp1 = this->head, temp2 = rhs.head; temp1->next, temp2->next; temp1 = temp1->next, temp2 = temp2->next)
			{
				if (temp1->next->obj != temp2->next->obj)
				{
					return false;
				}
			}
			return true;
		}


		bool operator!= (const SinglyLinkedList &rhs)
		{
			Node *temp1, *temp2;
			for (temp1 = this->head, temp2 = rhs.head; temp1->next, temp2->next; temp1 = temp1->next, temp2 = temp2->next)
			{
				if (temp1->next->obj != temp2->next->obj)
				{
					return true;
				}
			}
			return false;
		}


		SinglyLinkedList &operator= (const SinglyLinkedList &source)
		{
			this->clear();
			this->head = new Node;
			if (!source.empty())
			{
				for (Node *temp = source.head; temp->next; temp = temp->next)
				{
					this->insert (this->end(), temp->next->obj);
				}
			}
			return *this;
		}
};



/*		DOUBLY LINKED LIST		*/


template <typename Object>
class DoublyLinkedList
{



	private:


		int listSize;
		struct Node
		{
			Node ()
			{
				this->next = NULL;
				this->prev = NULL;
			}
			Object obj;
			Node *next;
			Node *prev;
		};
		Node *head;
		Node *tail;



	public:



		/*         Basic members           */


		DoublyLinkedList ()								// constructor
		{
			this->head = new Node;
			this->tail = new Node;
			head->next = tail;
			tail->prev = head;
			this->listSize = 0;
		}


		~DoublyLinkedList()								// destructor
		{
			this->clear();
			delete this->head;
			delete this->tail;
			this->listSize = 0;
		}


		DoublyLinkedList (const DoublyLinkedList &list)				// copy constructor
		{
			this->head = new Node;
			this->tail = new Node;
			this->listSize = 0;
			this->head->next = tail;
			this->tail->prev = head;
			if (!list.empty())
			{
				for (Node *temp = list.head; temp->next != list.tail; temp = temp->next)
				{
					this->push_back (temp->next->obj);
				}
			}
		}



		class const_iterator								// constant iterator
		{



			public:

				const_iterator()
					: current (NULL)
				{
				}


				~const_iterator()
				{
					this->current = NULL;
				}


				const_iterator (const const_iterator &itr)
				{
					this->current = itr.current;
				}


				const Object &operator*() const
				{
					if (this->current)
					{
						return this->current->obj;
					}
				}


				const_iterator &operator++()
				{
					if (this->current && this->current->next)
					{
						this->current = this->current->next;
					}
					return *this;
				}


				const_iterator operator++ (int)
				{
					const_iterator old = *this;
					++(*this);
					return old;
				}


				const_iterator &operator--()
				{
					if (this->current && this->current->prev)
					{
						this->current = this->current->prev;
					}
					return *this;
				}


				const_iterator operator-- (int)
				{
					const_iterator old = *this;
					--(*this);
					return old;
				}


				bool operator== (const const_iterator &rhs) const
				{
					return (this->current == rhs->current);
				}


				bool operator!= (const const_iterator &rhs) const
				{
					return (this->current != rhs->current);
				}


				const_iterator &operator= (const const_iterator &source)
				{
					this->current = source.current;
					return *this;
				}


			protected:


				Node *current;
				const_iterator (Node *node)
					: current (node)
				{
				}
				friend class DoublyLinkedList <Object>;


		};




		class iterator : public const_iterator					// iterator
		{


			public:


				iterator()
					:current (NULL)
				{
				}


				~iterator()
				{
					this->current = NULL;
				}


				iterator (const iterator &itr)
				{
					this->current = itr.current;
				}


				Object &operator* ()
				{
					if (this->current)
					{
						return this->current->obj;
					}
				}


				const Object &operator* () const
				{
					return const_iterator::operator* ();
				}


				iterator &operator++ ()
				{
					if (this->current && this->current->next)
					{
						this->current = this->current->next;
					}
					return *this;
				}


				iterator operator++ (int)
				{
					iterator old = *this;
					++(*this);
					return old;
				}


				iterator &operator-- ()
				{
					if (this->current && this->current->prev)
					{
						this->current = this->current->prev;
					}
					return *this;
				}


				iterator operator-- (int)
				{
					iterator old = *this;
					--(*this);
					return old;
				}


				bool operator== (const iterator &rhs) const
				{
					return (this->current == rhs.current);
				}


				bool operator!= (const iterator &rhs) const
				{
					return (this->current != rhs.current);
				}


				iterator &operator= (const iterator &source)
				{
					this->current = source.current;
					return *this;
				}


			protected:
				Node *current;
				iterator (Node *node)
					: current (node)
				{
				}
				friend class DoublyLinkedList <Object>;


		};


		/*           Accessors             */


		iterator begin()								// iterator to 1st node
		{
			if (this->empty())
			{
				return iterator (this->head);
			}
			else
			{
				return iterator (this->head->next);
			}
		}


		const_iterator begin() const							// constant iterator to 1st node
		{
			if (this->empty())
			{
				return const_iterator (this->head);
			}
			else
			{
				return const_iterator (this->head->next);
			}
		}


		iterator end()									// iterator to last node
		{
			if (this->empty())
			{
				return iterator (this->tail);
			}
			else
			{
				return iterator (this->tail->prev);
			}
		}


		const_iterator end() const							// constant iterator to last node
		{
			if (this->empty)
			{
				return const_iterator (this->tail);
			}
			else
			{
				return const_iterator (this->tail->prev);
			}
		}


                int size() const								// size of list
		{
			return this->listSize;
		}


                bool empty() const								// checks if empty list
		{
			if (this->head->next == this->tail)
			{
				return true;
			}
			else
			{
				return false;
			}
		}


		Object &front()									// first element of list
		{
			if (this->head->next != this->tail)
			{
				return this->head->next->obj;
			}
		}


		const Object &front() const							// first element of constant list
		{
			if (this->head->next != this->tail)
			{
				return this->head->next->obj;
			}
		}


		Object &back()
		{
			if (this->tail->prev != this->head)
			{
				return this->tail->prev->obj;
			}
		}


		const Object &back() const
		{
			if (this->tail->prev != this->head)
			{
				return this->tail->prev->obj;
			}
		}


		
		/*	      Mutators		   */


		void clear()
		{
			while (!(this->empty()))
			{
				this->pop_front();
			}
			this->listSize = 0;
		}


		void push_front (const Object &o)						// insert to begin
		{
			insert (iterator (this->head), o);
		}


		void pop_front()								// delete from begin
		{
			erase (this->begin());
		}


		void push_back (const Object &o)
		{
			insert (iterator (this->tail->prev), o);
		}


		void pop_back()
		{
			erase (this->end());
		}


		iterator insert (iterator itr, const Object &o)				// insert obj after itr
		{
			Node *newNode = new Node;
			newNode->obj = o;
			Node *destination = itr.current;
			Node *temp = destination->next;
			destination->next = newNode;
			newNode->next = temp;
			newNode->prev = destination;
			temp->prev = newNode;
			++(this->listSize);
			return iterator (newNode);
		}


		iterator erase (iterator itr)							// erase obj in itr, return after itr or to end
		{
			Node *toDelete = itr.current;
			if (toDelete != this->head && toDelete != this->tail)
			{
				iterator result (toDelete->next);
				Node *prev = toDelete->prev;
				Node *next = toDelete->next;
				prev->next = next;
				next->prev = prev;
				delete toDelete;
				--(this->listSize);
				return result;
			}
		}


		bool operator== (const DoublyLinkedList &rhs)
		{
			Node *temp1, *temp2;
			for (temp1 = this->head, temp2 = rhs.head; temp1->next != this->tail, temp2->next != rhs.tail; temp1 = temp1->next, temp2 = temp2->next)
			{
				if (temp1->next->obj != temp2->next->obj)
				{
					return false;
				}
			}
			return true;
		}


		bool operator!= (const DoublyLinkedList &rhs)
		{
			Node *temp1, *temp2;
			for (temp1 = this->head, temp2 = rhs.head; temp1->next != this->tail, temp2->next != rhs.tail; temp1 = temp1->next, temp2 = temp2->next)
			{
				if (temp1->next->obj != temp2->next->obj)
				{
					return true;
				}
			}
			return false;
		}


		DoublyLinkedList &operator= (DoublyLinkedList &source)
		{
			this->clear();
			if (!source.empty())
			{
				for (Node *temp = source.head; temp->next != source.tail; temp = temp->next)
				{
					this->push_back (temp->next->obj);
				}
			}
			return *this;
		}
};




#endif
