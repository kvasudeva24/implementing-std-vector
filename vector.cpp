#include "vector.hpp"


template <typename T>
tik::vector<T>::vector(){
    data_ = new T[1];
    capacity_ = 0;
}

template <typename T>
void tik::vector<T>::destructor_helper(){
    delete data_;
    capacity_ = 0;
    size_ = 0;
}

template <typename T>
tik::vector<T>::~vector(){
    destructor_helper();
}

template<typename T>
tik::vector<T>::vector(const vector& rhs){
    capacity_ = rhs.capacity_;
    data_ = new T[capacity_];

    for(; size_<rhs.size_; size_++){
        data_[size_] = rhs[size_];
        size_++;
    }
}

