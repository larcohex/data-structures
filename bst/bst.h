#ifndef BST_H
#define BST_H
#include <list>
#include <cstddef>

using namespace std;

template <typename Comparable>
class BST
{

	public:

		struct Node
		{
			Node()
			{
				this->left = NULL;
				this->right = NULL;
			}


			Node *left, *right;
			Comparable obj;
		};


	private:

		/***********************************/

		Node *root;
		bool delLeftSwap, delRightSwap;

		/***********************************/


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
					}

					else
						this->insertHelper (node->right, obj);
				}
			}
		}


		Node *searchHelper (Node *node, Comparable obj)
		{
			if (node)
			{
				if ((node->left && node->left->obj == obj) || (node->right && node->right->obj == obj))
					return node;

				if (obj < node->obj)
					return searchHelper (node->left, obj);

				else
					return searchHelper (node->right, obj);
			}
			else
				return NULL;
		}


		Node *rightSuccPar (Node *node)
		{
			if (node->right->right)
				return rightSuccPar (node->right);

			else
				return node;
		}


		Node *leftSuccPar (Node *node)
		{
			if (node->left->left)
				return leftSuccPar (node->left);

			else
				return node;
		}


	public:

		BST()
		{
			this->root = NULL;
			this->delLeftSwap = this->delRightSwap = true;
		}


		~BST()
		{
			this->clear();
		}


		BST (const BST &tr)
		{
			this->root = NULL;
			this->copy (&(this->root), tr.root);
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
				this->insertHelper (this->root, obj);

			else
			{
				this->root = new Node;
				this->root->obj = obj;
			}
		}


		void erase (Comparable obj)
		{
			if (this->root->obj == obj)
			{
				if (!this->root->left && !this->root->right)
				{
					delete this->root;
					this->root = NULL;
				}
				else if (this->root->left && !this->root->right)
				{
					Node *temp = this->root;
					this->root = temp->left;
					temp->left = NULL;
					delete temp;
					temp = NULL;
				}
				else if (!this->root->left && this->root->right)
				{
					Node *temp = this->root;
					this->root = temp->right;
					temp->right = NULL;
					delete temp;
					temp = NULL;
				}
				else
				{
					if (this->delLeftSwap)
					{
						Node *temp = rightSuccPar (this->root->left);
						Node *temp2 = temp->right;
						this->root->obj = temp2->obj;
						temp->right = temp2->left;
						temp2->left = NULL;
						delete temp2;
						temp2 = NULL;
						this->delLeftSwap = false;
					}
					else
					{
						Node *temp = leftSuccPar (this->root->right);
						Node *temp2 = temp->right;
						this->root->obj = temp2->obj;
						temp->right = temp2->left;
						temp2->left = NULL;
						delete temp2;
						temp2 = NULL;
						this->delLeftSwap = true;
					}
				}
			}
			else
			{
				Node *parent = this->searchHelper (this->root, obj);
				if (parent)
				{
					if (parent->left->obj == obj)
					{
						if (!parent->left->left && !parent->left->right)
						{
							delete parent->left;
							parent->left = NULL;
						}
						else if (parent->left->left && !parent->left->right)
						{
							Node *temp = parent->left;
							parent->left = temp->left;
							temp->left = NULL;
							delete temp;
							temp = NULL;
						}
						else if (!parent->left->left && parent->left->right)
						{
							Node *temp = parent->left;
							parent->left = temp->right;
							temp->right = NULL;
							delete temp;
							temp = NULL;
						}
						else
						{
							if (this->delLeftSwap)
							{
								Node *temp = rightSuccPar (parent->left->left);
								Node *temp2 = temp->right;
								parent->left->obj = temp2->obj;
								temp->right = temp2->left;
								temp2->left = NULL;
								delete temp2;
								temp2 = NULL;
								this->delLeftSwap = false;
							}
							else
							{
								Node *temp = leftSuccPar (parent->left->right);
								Node *temp2 = temp->right;
								parent->left->obj = temp2->obj;
								temp->right = temp2->left;
								temp2->left = NULL;
								delete temp2;
								temp2 = NULL;
								this->delLeftSwap = true;
							}
						}
					}

					else if (parent->right->obj == obj)
					{
						if (!parent->right->left && !parent->right->right)
						{
							delete parent->right;
							parent->right = NULL;
						}
						else if (parent->right->left && !parent->right->right)
						{
							Node *temp = parent->right;
							parent->right = temp->left;
							temp->left = NULL;
							delete temp;
							temp = NULL;
						}
						else if (!parent->right->left && parent->right->right)
						{
							Node *temp = parent->right;
							parent->right = temp->right;
							temp->right = NULL;
							delete temp;
							temp = NULL;
						}
						else
						{
							if (this->delRightSwap)
							{
								Node *temp = rightSuccPar (parent->right->left);
								Node *temp2 = temp->right;
								parent->right->obj = temp2->obj;
								temp->right = temp2->left;
								temp2->left = NULL;
								delete temp2;
								temp2 = NULL;
								this->delRightSwap = false;
							}
							else
							{
								Node *temp = leftSuccPar (parent->right->right);
								Node *temp2 = temp->right;
								parent->right->obj = temp2->obj;
								temp->right = temp2->left;
								temp2->left = NULL;
								delete temp2;
								temp2 = NULL;
								this->delRightSwap = true;
							}
						}
					}
				}
			}
		}


		Node *search (Comparable obj)
		{
			if (this->root->obj == obj)
				return this->root;

			else
			{
				Node *parent = this->searchHelper (this->root, obj);
				if (parent)
				{
					if (parent->left->obj == obj)
						return parent->left;
					else
						return parent->right;
				}

				else
					return NULL;
			}
		}


		bool operator== (const BST &rhs)
		{
			return equal (this->root, rhs.root);
		}


		bool operator!= (const BST &rhs)
		{
			return notEqual (this->root, rhs.root);
		}


		BST &operator= (const BST &rhs)
		{
			this->clear();
			copy (&(this->root), rhs.root);
		}

};

#endif
