#ifndef CUSTOMCONTAINER_H
#define CUSTOMCONTAINER_H

#include <iterator>


template <typename T>
class CustomContainer
{
private:
    T* mArray;
    int mSize;

    template <typename X>
    class CustomIterator: public std::iterator<std::input_iterator_tag, X>
    {
    private:

        X* mPointer;

    public:

        CustomIterator(X* p):
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

        X& operator*()
        {
            return *mPointer;
        }
    };

public:

    typedef CustomIterator<T> iterator;

    typedef CustomIterator<const T> const_iterator;

    CustomContainer(size_t size = 10)
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

    T operator[] (size_t i) const
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

    const_iterator begin() const
    {
        return const_iterator(mArray);
    }

    const_iterator end() const
    {
        return const_iterator(mArray + mSize);
    }
};

#endif // CUSTOMCONTAINER_H
