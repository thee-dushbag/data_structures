#ifndef SLinkedList
#define SLinkedList 1

#include <iostream>
#include <vector>

namespace data_structures
{
	namespace linked_list
	{
		namespace singly_linked_list
		{
			template <typename Type>
			struct Node
			{
				Type data;
				Node<Type> *next;
			};
			template <typename Type>
			class SinglyLinkedList
			{
			private:
				Node<Type> *head = nullptr;
				int counter = 0;

			public:
				~SinglyLinkedList()
				{
					Node<Type> *temp;
					while (this->head)
					{
						temp = this->head;
						this->head = temp->next;
						delete temp;
					}
				}

				void deleteNodeAtPosition(int position)
				{
					if (position <= this->counter)
					{
						Node<Type> *node = this->getNodeAtPosition(position);
						Node<Type> *pnode = this->getNodeAtPosition(position - 1);
						if (pnode != nullptr)
							pnode->next = node->next;
						if (node == this->head)
							this->head = node->next;
						delete node;
						this->counter--;
					}
				}

				Node<Type> *createNode(Type data)
				{
					Node<Type> *node = new Node<Type>;
					node->data = data;
					node->next = nullptr;
					return node;
				}

				void addNodeFront(Node<Type> *node)
				{
					node->next = this->head;
					this->head = node;
					this->counter++;
				}

				void addNodeBack(Node<Type> *node)
				{
					if (this->head)
					{
						Node<Type> *lnode = this->getNodeAtPosition(counter);
						lnode->next = node;
						node->next = nullptr;
					}
					else
						this->head = node;
					this->counter++;
				}

				Node<Type> *getNodeAtPosition(int position)
				{
					if ((position <= counter) and (position > 0))
					{
						int c = 1;
						Node<Type> *temp = this->head;
						while (c < position)
						{
							c++;
							temp = temp->next;
						}
						return temp;
					}
					return nullptr;
				}

				bool insertNodeAtPosition(int position, Node<Type> *node)
				{
					if (this->counter >= position and position > 0)
					{
						int prev = ((position - 1) == 0) ? 1 : (position - 1);
						Node<Type> *nb4 = this->getNodeAtPosition(prev);
						node->next = nb4->next;
						nb4->next = node;
						counter++;
						return true;
					}
					return false;
				}

				std::vector<Node<Type> *> find(Type data)
				{
					std::vector<Node<Type> *> found;
					Node<Type> *temp = this->head;
					while (temp)
					{
						if (temp->data == data)
							found.push_back(temp);
						temp = temp->next;
					}
					return found;
				}

				int getSize()
				{
					return this->counter;
				}

				void printData(void)
				{
					if (this->head)
					{
						Node<Type> *temp = this->head;
						while (temp != nullptr)
						{
							std::cout << temp->data << ", ";
							temp = temp->next;
						}
						std::cout << '\n';
					}
				}
			};
		}
	}
}

#endif
