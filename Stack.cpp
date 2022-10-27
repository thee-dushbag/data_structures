#ifndef CPPSTACK
#define CPPSTACK 1

#include "SinglylinkedList.cpp"

using data_structures::linked_list::singly_linked_list::SinglyLinkedList;
using data_structures::linked_list::singly_linked_list::Node;

namespace data_structures
{
    namespace stack
    {
        template <typename Type>
        class Stack
        {
        private:
            SinglyLinkedList<Type> container;

        public:
            Type pop()
            {
                Node<Type> *node = container.getNodeAtPosition(1);
                Type data = node->data;
                container.deleteNodeAtPosition(1);
                return data;
            }
            void push(Type data)
            {
                container.addNodeFront(container.createNode(data));
            }

            Type size() { return container.getSize(); }

            void printData()
            {
                std::cout << "Stack data : \x1b[33;1m[ ";
                for (int i = 0; i < container.getSize(); i++)
                    std::cout << container.getNodeAtPosition(i + 1)->data << ", ";
                std::cout << "]\x1b[0m\n";
            }
        };
    }
}

#endif