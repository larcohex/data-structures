#ifndef ARRAY
#define ARRAY
#include <cstddef>


using namespace std;


template <typename Object>
class Array
{
	private:
	

			int s;
			Object *array;



	public:


			Array()
			{
				this->array = NULL;
				this->s = 0;
			}




			~Array()
			{
				this->clear();
			}





			Array (const Array <Object> &arr)
			{
				this->array = NULL;
				this->s = 0;
				for (int i = 0; i < arr.size(); ++i)
				{
					this->push_back (arr.array[i]);
				}
			}




			class const_iterator
			{



				protected:


					Object *parent;




				public:



					const_iterator()
					{
					}




					const_iterator (Object *a)
					{
						this->parent = a;
					}




					const_iterator (const const_iterator &itr)
					{
						this->parent = itr.parent;
					}




					const Object operator*() const
					{
						if (this->parent)
						{
							return *(this->parent);
						}
						throw 0;
					}




					const_iterator &operator++()
					{
						if (this->parent && this->parent + 1)
						{
							++this->parent;
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
						if (this->parent && this->parent - 1)
						{
							--this->parent;
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
						return this->parent == rhs.parent;
					}




					bool operator!= (const const_iterator &rhs) const
					{
						return this->parent != rhs.parent;
					}





					const_iterator &operator= (const const_iterator &rhs)
					{
						this->parent = rhs.parent;
						return *this;
					}


					friend class Array <Object>;

			};




			class iterator : public const_iterator
			{





				protected:


					Object *parent;




				public:



					iterator()
					{
					}




					iterator (Object *a)
					{
						this->parent = a;
					}




					iterator (const iterator &itr)
					{
						this->parent = itr.parent;
					}




					const Object &operator*() const
					{
						if (this->parent)
						{
							const Object result = *this->parent;
							return result;
						}
						throw 0;
					}




					Object &operator*()
					{
						if (this->parent)
						{
							return *this->parent;
						}
						throw 0;
					}




					iterator &operator++()
					{
						if (this->parent && this->parent + 1)
						{
							++this->parent;
						}
						return *this;
					}






					iterator operator++ (int)
					{
						const_iterator old = *this;
						++(*this);
						return old;
					}






					iterator &operator--()
					{
						if (this->parent && this->parent - 1)
						{
							--this->parent;
						}
						return *this;
					}





					iterator operator-- (int)
					{
						const_iterator old = *this;
						--(*this);
						return old;
					}





					bool operator== (const iterator &rhs) const
					{
						return this->parent == rhs.parent;
					}




					bool operator!= (const iterator &rhs) const
					{
						return this->parent != rhs.parent;
					}





					iterator &operator= (const iterator &rhs)
					{
						this->parent = rhs.parent;
						return *this;
					}


					friend class Array <Object>;

			};






			iterator begin()
			{
				return iterator (this->array);
			}




			const_iterator begin() const
			{
				return const_iterator (this->array);
			}




			iterator end()
			{
				return iterator (this->array + this->s);
			}




			const_iterator end() const
			{
				return const_iterator (this->array + this->s);
			}




			int size() const
			{
				return this->s;
			}





			Object &front()
			{
				if (this->array)
				{
					return *this->array;
				}
				throw 1;
			}




			const Object front() const
			{
				if (this->array)
				{
					const Object result = *(this->array);
					return result;
				}
			}




			Object &back()
			{
				if (this->array)
				{
					return *(this->array + this->s - 1);
				}
			}





			const Object back() const
			{
				if (this->array)
				{
					const Object result = *(this->array + this->s - 1);
					return result;
				}
			}





			void push_back (Object &o)
			{
				if (this->s)
					this->insert (iterator (this->array + this->s - 1), o);
				else
					this->insert (iterator (this->array), o);
			}




			void pop_back()
			{
				if (this->array)
				{
					this->erase (iterator (this->array + this->s - 1));
				}
			}




			iterator insert (iterator itr, Object &obj)
			{
				Object *destination = itr.parent;
				if (destination)
				{
					++this->s;
					Object *newArray = new Object [this->s];
					int i;
					Object *temp = this->array;
					for (i = 0; temp != destination; ++i, ++temp)
					{
						newArray[i] = *temp;
					}
					newArray[i] = *temp;
					++i;
					++temp;
					newArray[i] = obj;
					iterator result (newArray + i);
					++i;
					while (i < this->s)
					{
						newArray[i] = *temp;
						++i;
						++temp;
					}
					delete [] this->array;
					this->array = newArray;
					return result;
				}
				else if (!this->s)
				{
					++this->s;
					this->array = new Object;
					*(this->array) = obj;
					return iterator (this->array);
				}
				else
				{
					return iterator (NULL);
				}
			}




			iterator erase (iterator itr)
			{
				Object *destination = itr.parent;
				if (destination)
				{
					--this->s;
					Object *newArray = new Object [this->s];
					int i;
					Object *temp = this->array;
					for (i = 0; temp != destination; ++i, ++temp)
					{
						newArray[i] = *temp;
					}
					++temp;
					iterator result (newArray+i);
					if (*temp < this->s + 1)
					{
						newArray[i] = *temp;					
						++i;
						++temp;
						while (i < this->s)
						{
							newArray[i] = *temp;
							++i;
							++temp;
						}
					}
					delete [] this->array;
					this->array = newArray;
					return result;
				}
				else
				{
					return iterator (NULL);
				}
			}




			void clear()
			{
				if (this->array)
				{
					delete [] this->array;
					this->s = 0;
				}
			}




			bool operator== (const Array <Object> &rhs)
			{
				if (this->s != rhs.size())
				{
					return false;
				}
				else
				{
					for (int i = 0; i < this->s; ++i)
					{
						if (this->array[i] != rhs.array[i])
						{
							return false;
						}
					}
					return true;
				}
			}





			bool operator != (const Array <Object> &rhs)
			{
				if (this->s != rhs.size())
				{
					return true;
				}
				else
				{
					for (int i = 0; i < this->s; ++i)
					{
						if (this->array[i] != rhs.array[i])
						{
							return true;
						}
					}
					return false;
				}
			}






			Array &operator= (const Array <Object> &rhs)
			{
				if (this->size)
				{
					delete [] this->array;
					this->size = 0;
				}
				for (int i = 0; i < rhs.size(); ++i)
				{
					this->push_back (rhs.array[i]);
				}
				return *this;
			}






			Object &operator[] (const int index)
			{
				return this->array[index];
			}



};

#endif
