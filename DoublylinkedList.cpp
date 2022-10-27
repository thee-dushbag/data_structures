#ifndef DLinkedList
#define DLinkedList 1

#include <iostream>
#include <vector>
#include <string>

namespace data_structures
{
	namespace linked_list
	{
		namespace doubly_linked_list
		{
			template <typename Type>
			struct Node
			{
				Type data;
				Node<Type> *next;
				Node<Type> *prev;
			};

			template <typename Type>
			class DoublyLinkedList
			{
			private:
				Node<Type> *head = nullptr;
				int counter = 0;

			public:
				~DoublyLinkedList()
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
					if (position <= this->counter and position > 0)
					{
						Node<Type> *temp = this->getNodeAtPosition(position);
						if (temp->prev)
							temp->prev->next = temp->next;
						if (temp->next)
							temp->next->prev = temp->prev;
						if (temp == this->head)
							this->head = temp->next;
						delete temp;
						this->counter--;
					}
				}

				Node<Type> *createNode(Type data)
				{
					Node<Type> *node = new Node<Type>;
					node->data = data;
					node->next = nullptr;
					node->prev = nullptr;
					return node;
				}

				void addNodeFront(Node<Type> *node)
				{
					if (this->head)
						this->head->prev = node;
					node->next = this->head;
					this->head = node;
					node->prev = nullptr;
					this->counter++;
				}

				void addNodeBack(Node<Type> *node)
				{
					if (this->head)
					{
						Node<Type> *lnode = this->getNodeAtPosition(counter);
						lnode->next = node;
						node->prev = lnode;
						node->next = nullptr;
					}
					else
					{
						this->head = node;
						node->prev = nullptr;
						node->next = nullptr;
					}
					this->counter++;
				}

				Node<Type> *getNodeAtPosition(int position)
				{
					if (position <= counter and position > 0)
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
						node->prev = nb4;
						nb4->next->prev = node;
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

				int getSize() const
				{
					return this->counter;
				}

				template <typename T>
				std::string format(T data)
				{
					std::string sdata = std::to_string(data);
					while (sdata.length() < 10)
						sdata.push_back(' ');
					return sdata;
				}

				void printData(void)
				{
					if (this->head)
					{
						Node<Type> *temp = this->head;
						std::cout << "+--------------------[ LIST DATA ]------------------------+\n";
						while (temp != nullptr)
						{
							std::cout << " | "
									  << temp
									  << " | "
									  << temp->prev
									  << " | "
									  << this->format(temp->data)
									  << " | "
									  << temp->next
									  << " | " << '\n';
							temp = temp->next;
						}
						std::cout << "+---------------------------------------------------------+\n";
					}
				}
			};

		}
	}
}
#endif
