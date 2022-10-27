#ifndef CirQUEUE
#define CirQUEUE 1

namespace data_structures
{
    namespace circular_queue
    {
        template <typename QTYPE, int blocks>
        class CirQueue
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

            CirQueue()
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
            bool enQueue(QTYPE item)
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
            // remove the last item from the queue and store its value to the specified location
            bool deQueue(QTYPE &item)
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
            ~CirQueue()
            {
                delete[] this->container;
            }
        };
    }
}

#endif