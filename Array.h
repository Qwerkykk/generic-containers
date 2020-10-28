#ifndef ARRAY_ARRAY_H
#define ARRAY_ARRAY_H


#include <cstddef>

template<class Array_>
class ArrayIterator{
public:
        using ValueType = typename Array_::ValueType;
        using ReferenceType = ValueType&;
public:

        explicit ArrayIterator(ValueType* ptr): ptr_(ptr){}

    ArrayIterator& operator++() {
        ptr_++;
        return *this;
    }

    ArrayIterator operator++(int) {
        ArrayIterator iterator = *this;
        ptr_++;
        return iterator;
    }


    ArrayIterator& operator--() {
        ptr_--;
        return *this;
    }

    ArrayIterator operator--(int) {
        ArrayIterator iterator = *this;
        ptr_--;
        return iterator;
    }

    ValueType* operator->() {
        return ptr_;
    }

    ReferenceType operator*() {
        return *ptr_;
    }

    bool operator==(const ArrayIterator& other) const {
        return ptr_ == other.ptr_;
    }

    bool operator!=(const ArrayIterator& other) const {
        return !(*this == other);
    }


private:
    ValueType* ptr_;
};

template<typename T,size_t S>
class Array {

public:
    using ValueType = T;
    using Iterator = ArrayIterator<Array<T,S>>;

public:
    constexpr size_t Size() const { return S;}

    ValueType& operator[](size_t index)  { return data_[index];}
    const ValueType& operator[](size_t index) const  { return data_[index];}

    Iterator begin() {
        return Iterator(&data_[0]);
    }

    Iterator end() {
        return Iterator(&data_[S]);
    }

private:
    ValueType data_[S];
};


#endif
