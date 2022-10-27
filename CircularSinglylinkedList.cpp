#ifndef CirSinglyLinkedList
#define CirSinglyLinkedList 1

#include <vector>
#include <iostream>

namespace data_structures
{
	namespace linked_list
	{
		namespace circular_singly_linked_list
		{
			template <typename Type>
			struct Node
			{
				Type data;
				Node<Type> *next;
			};
			template <typename Type>
			class CircularSinglyLinkedList
			{
			private:
				Node<Type> *head = nullptr;
				int counter = 0;

			public:
				~CircularSinglyLinkedList()
				{
					this->clearAllNodes();
				}

				void clearAllNodes()
				{
					if (this->head)
					{
						Node<Type> *temp = this->head->next;
						this->head->next = nullptr;
						while (temp)
						{
							this->head = temp;
							temp = temp->next;
							delete this->head;
						}
						this->head = nullptr;
					}
				}

				void deleteNodeAtPosition(int position)
				{
					if (this->head and (position >= 0))
					{
						Node<Type> *temp = this->head, *node;
						if (this->counter == 1 and position == 0)
						{
							node = this->head;
							temp = nullptr;
						}
						else
						{
							if (position == 0)
							{
								position = counter;
								temp = this->head->next;
							}
							this->moveToNode(position - 1);
							node = this->head->next;
							this->head->next = this->head->next->next;
						}
						this->head = temp;
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
					if (this->head)
					{
						node->next = this->head->next;
						this->head->next = node;
					}
					else
					{
						node->next = node;
						this->head = node;
					}
					this->counter++;
				}

				void addNodeBack(Node<Type> *node)
				{
					if (this->head)
					{
						node->next = this->head;
						this->moveToNode(counter - 1);
						this->head->next = node;
						this->head = node->next;
						this->counter++;
					}
					else
						addNodeFront(node);
				}

				void moveToNode(int position)
				{
					if (position > 0)
					{
						if (position >= counter)
							position = (int)(position % counter);
						for (int c = 0; c < position; c++)
							this->head = this->head->next;
					}
				}

				Node<Type> *getCurNodeData()
				{
					return this->head;
				}

				void setCurNodeData(Type data)
				{
					this->head->data = data;
				}

				void insertNodeAtPosition(int position, Node<Type> *node)
				{
					if (position > 0)
					{
						Node<Type> *temp = this->head;
						this->moveToNode(position - 1);
						addNodeFront(node);
						this->head = temp;
					}
				}

				std::vector<Node<Type> *> find(Type data)
				{
					std::vector<Node<Type> *> found;
					for (int c = 0; c < this->counter; c++)
					{
						if (this->head->data == data)
							found.push_back(this->head);
						this->head = this->head->next;
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
						std::cout << "List Data : \x1b[33;1m[ \x1b[93;1m";
						std::cout << this->head->data << "\x1b[33;1m, ";
						this->head = this->head->next;
						for (int c = 1; c < counter; c++)
						{
							std::cout << this->head->data << ", ";
							this->head = this->head->next;
						}
						std::cout << "]\x1b[0m\n";
					}
				}
			};
		}
	}
}

#endif