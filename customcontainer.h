#ifndef CUSTOMCONTAINER_H
#define CUSTOMCONTAINER_H

#include <iterator>


template <typename T>
class CustomContainer
{
private:
    T* mArray;
    int mSize;

    class CustomIterator: public std::iterator<std::input_iterator_tag, T>
    {
    private:

        T* mPointer;

    public:

        CustomIterator(T* p):
        mPointer(p)
        {}

        CustomIterator(const CustomIterator & ci):
        mPointer(ci.mPointer)
        {}

        bool operator!=(const CustomIterator & other) const
        {
            return mPointer != other.mPointer;
        }

        bool operator==(const CustomIterator & other) const
        {
            return mPointer == other.mPointer;
        }

        CustomIterator& operator++()
        {
            ++mPointer;
            return *this;
        }

        T& operator*()
        {
            return *mPointer;
        }
    };

public:

    typedef CustomIterator iterator;

    CustomContainer(int size = 10)
    {
        mArray = new T[size];
        mSize = size;
    }

    ~CustomContainer()
    {
        delete[] mArray;
    }

    T& operator[] (size_t i)
    {
        return mArray[i];
    }

    iterator begin()
    {
        return iterator(mArray);
    }

    iterator end()
    {
        return iterator(mArray + mSize);
    }
};

#endif // CUSTOMCONTAINER_H
