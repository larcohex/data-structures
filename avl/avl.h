#ifndef AVL_H
#define AVL_H
#include <list>
#include <cstddef>

using namespace std;

template <typename Comparable>
class AVL
{

	public:

		struct Node
		{
			Node()
			{
				this->left = NULL;
				this->right = NULL;
				this->balance = 0;
			}
			
			Comparable obj;
			Node *left, *right;
			int balance;
		};


	private:

		/******************************************/

		Node *root;

		/******************************************/


		void copy (Node **dest, Node *src)
		{
			if (src)
			{
				(*dest) = new Node;
				(*dest)->obj = src->obj;
				copy (&((*dest)->left), src->left);
				copy (&((*dest)->right), src->right);
			}
		}


		void destroy (Node *node)
		{
			if (node)
			{
				destroy (node->left);
				destroy (node->right);
				delete node;
			}
		}


		list <Comparable> preOrder (Node *node)
		{
			list <Comparable> result;
			if (node)
			{
				result.push_back (node->obj);
				list <Comparable> left = preOrder (node->left);
				result.splice (result.end(), left);
				list <Comparable> right = preOrder (node->right);
				result.splice (result.end(), right);
			}
			return result;
		}


		list <Comparable> inOrder (Node *node)
		{
			list <Comparable> result;
			if (node)
			{
				list <Comparable> left = inOrder (node->left);
				result.splice (result.end(), left);
				result.push_back (node->obj);
				list <Comparable> right = inOrder (node->right);
				result.splice (result.end(), right);
			}
			return result;
		}


		list <Comparable> postOrder (Node *node)
		{
			list <Comparable> result;
			if (node)
			{
				list <Comparable> left = postOrder (node->left);
				result.splice (result.end(), left);
				list <Comparable> right = postOrder (node->right);
				result.splice (result.end(), right);
				result.push_back (node->obj);
			}
			return result;
		}


		bool equal (Node *tr1, Node *tr2)
		{
			if (tr1 == tr2)
				return true;

			if (tr1 == NULL || tr2 == NULL)
				return false;

			return ((tr1->obj == tr2->obj) && (equal (tr1->left, tr2->left)) && (equal (tr2->right, tr2->right)));
		}


		bool notEqual (Node *tr1, Node *tr2)
		{
			if (tr1 == tr2)
				return false;

			if (tr1 == NULL || tr2 == NULL)
				return true;

			return ((tr1->obj != tr2->obj) || (notEqual (tr1->left, tr2->left)) || (notEqual (tr1->right, tr2->right)));
		}


		void insertHelper (Node *node, Comparable obj)
		{
			if (node->obj != obj)
			{
				if (node->obj > obj)
				{
					if (!node->left)
					{
						Node *newNode = new Node;
						newNode->obj = obj;
						node->left = newNode;
						updateBalances (this->root);
					}

					else
						this->insertHelper (node->left, obj);

				}

				else if (node->obj < obj)
				{
					if (!node->right)
					{
						Node *newNode = new Node;
						newNode->obj = obj;
						node->right = newNode;
						updateBalances (this->root);
					}

					else
						this->insertHelper (node->right, obj);
				}
			}
		}


		int getBalance (Node *node)
		{
			if (node)
				return node->balance;
			else
				return 0;
		}


		void updateBalances (Node *node)
		{
			if (node)
			{
				updateBalances (node->left);
				updateBalances (node->right);
				node->balance = getBalance (node->left) - getBalance (node->right);
			}
		}


		int abs (int n)
		{
			int mask = n >> 31;
			return (n ^ mask) - mask;
		}


		void balance (Node *node)
		{
			if (node->balance > 0)
			{
				if (node->left->balance > 0)
				{
					l2bleRotation


	public:

		AVL()
		{
			this->root = NULL;
		}


		~AVL()
		{
			this->clear();
		}


		AVL (const AVL &tr)
		{
			this->root = NULL;
			this->copy (&this->root, tr.root);
		}


				list <Comparable> pre_order()
		{
			return this->preOrder (this->root);
		}


		list <Comparable> in_order()
		{
			return this->inOrder (this->root);
		}


		list <Comparable> post_order()
		{
			return this->postOrder (this->root);
		}


		list <Comparable> breadth_first()
		{
			list <Comparable> result;
			if (this->root)
			{
				list <Node *> queue;
				queue.push_back (this->root);
				while (!queue.empty())
				{
					result.push_back (queue.front()->obj);

					if (queue.front()->left)
						queue.push_back (queue.front()->left);

					if (queue.front()->right)
						queue.push_back (queue.front()->right);

					queue.pop_front();
				}
			}
			return result;
		}


		void clear()
		{
			this->destroy (this->root);
			this->root = NULL;
		}


		void insert (Comparable obj)
		{
			if (this->root)
			{
				this->insertHelper (this->root, obj);
				if (abs (this->root->balance) > 1)
					balance (this->root);
			}
			else
			{
				this->root = new Node;
				this->root->obj = obj;
			}
		}

};

#endif
