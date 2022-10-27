#ifndef DeQUE
#define DeQUE 1

namespace data_structures
{
    namespace deque
    {
        template <typename QTYPE, int blocks>
        class DeQue
        {
        private:
            QTYPE *container;
            int rearI;
            int frontI;
            int usedBlocks;
            int capacity;
            int size;
            const char *name;

        public:
            int getSize() { return this->size; }
            int getUsedBlocks() { return this->usedBlocks; }

            DeQue()
            {
                this->name = "Circular Queue";
                this->capacity = blocks + 1;
                this->container = new QTYPE[this->capacity];
                this->frontI = 0;
                this->usedBlocks = 0;
                this->rearI = 0;
                this->size = this->capacity - 1;
            }
            // set name of queue
            void setName(const char *name)
            {
                this->name = name;
            }
            // returns true if queue is empty
            bool isEmpty()
            {
                if (this->usedBlocks == 0)
                    return true;
                return false;
            }
            // returns true if queue is full
            bool isFull()
            {
                if (this->usedBlocks == this->size)
                    return true;
                return false;
            }
            // add an item to the end of the queue
            bool pushBack(QTYPE item)
            {
                if (this->isFull())
                    return false;
                this->container[this->rearI] = item;
                this->usedBlocks++;
                if (this->rearI == this->size)
                    this->rearI = 0;
                else
                    this->rearI++;
                return true;
            }
            // add an item to the beginning of the queue
            bool pushFront(QTYPE item)
            {
                if (this->isFull())
                    return false;
                if (this->frontI == 0)
                    this->frontI = this->size;
                else
                    this->frontI--;
                this->container[this->frontI] = item;
                this->usedBlocks++;
                return true;
            }
            // remove the last item from the queue and store its value to the specified location
            bool popBack(QTYPE &item)
            {
                if (this->isEmpty())
                    return false;
                if (this->rearI == 0)
                    this->rearI = this->size;
                else
                    this->rearI--;
                item = this->container[this->rearI];
                this->usedBlocks--;
                return true;
            }
            // remove the first item from the queue and store its value to the specified location
            bool popFront(QTYPE &item)
            {
                if (this->isEmpty())
                    return false;
                item = this->container[this->frontI];
                if (this->frontI == this->size)
                    this->frontI = 0;
                else
                    this->frontI++;
                this->usedBlocks--;
                return true;
            }
            ~DeQue()
            {
                delete[] this->container;
            }
        };
    }
}

#endif