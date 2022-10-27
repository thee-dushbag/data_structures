#ifndef MyARRAY
#define MyARRAY 1
#include <iostream>
namespace data_structures
{
    namespace array
    {
        template <typename Type>
        class Array
        {
        private:
            int size = 5;
            int lsize = 5;
            int count = 0;
            Type store;
            Type *Store = new Type[size];
            void resize(int n)
            {
                lsize = size;
                size = n;
                std::cout << "New array size -> " << size << '\n';
                static Type *NewStore = new Type[n];
                for (int i = 0; i < n; i++)
                    NewStore[i] = Store[i];
                Store = NewStore;
            }

        public:
            ~Array()
            {
                std::cout << "Store freed\n";
                delete[] Store;
            }
            void push_back(Type item)
            {
                if (isFull())
                    resize(size + 5);
                Store[count] = item;
                count++;
            }
            bool isFull(void)
            {
                return (count == size) ? true : false;
            }
            bool isEmpty(void)
            {
                return (count == 0) ? true : false;
            }
            Type pop_back(void)
            {
                if ((size - lsize) == 5)
                    resize(size - 5);
                if (!isEmpty())
                {
                    store = Store[count];
                    count--;
                    return store;
                }
            }
            int getSize(void)
            {
                return count;
            }
        };
    }
}

#endif
