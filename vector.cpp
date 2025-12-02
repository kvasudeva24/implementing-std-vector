#include "vector.hpp"
#include <stdexcept>


template <typename T>
tik::vector<T>::vector(){
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

template <typename T>
void tik::vector<T>::push_back(T value){
    if(capacity_ == size_) {
        //need to grow

        size_t new_cap = (capacity_ == 0) ? 1 : capacity_ * 2;
        T* new_arr = new T[new_cap];
    
        for(size_t i = 0; i<size_; i++){
            new_arr[i] = data_[i];
        }

        capacity_ = new_cap;
        delete[] data_;
        data_ = new_arr;
    }

    data_[size_++] = value;

}

template <typename T>
T tik::vector<T>::pop_back(){
    if(size_ == 0){
        throw std::out_of_range("Cannot pop back on empty vector");
        return;
    }
    T value = data_[size_ - 1];
    size_--;
    return value;
}

template <typename T>
T& tik::vector<T>::front(){
    if(size_ == 0){
        throw std::logic_error("Cannot get front element of empty vector");
    }
    return data_[0];
}

template <typename T>
T& tik::vector<T>::back(){
    if(size_ == 0){
        throw std::logic_error("Cannot get back element of empty vector");
    }

    return data_[size_-1];
}

template <typename T>
tik::vector<T>& tik::vector<T>::operator=(const tik::vector<T>& rhs){
    if(*this != rhs){
        capacity_ = rhs.capacity_;
        data_ = new T[capacity_];

        for(; size_<rhs.size_; size_++){
            data_[size_] = rhs[size_];
            size_++;
        }
    }
    return *this;
}

template<typename T>
tik::vector<T>::vector(vector<T>&& rhs){
    data_ = rhs.data_;
    capacity_ = rhs.capacity_;
    size_ = rhs.size_;

    rhs.size_ = 0;
    rhs.capacity_ = 0;
    rhs.data_ = nullptr;
}

template <typename T>
tik::vector<T>& tik::vector<T>::operator=(vector<T>&& rhs){
    if(*this != rhs){
        delete[] data_;
        
        data_ = rhs.data_;
        capacity_ = rhs.capacity_;
        size_ = rhs.size_;

        rhs.size_ = 0;
        rhs.capacity_ = 0;
        rhs.data_ = nullptr;

    }
    return *this;
}

template<typename T>
T& tik::vector<T>::operator[](size_t index){
    if(index >= size_){
        throw std::out_of_range("Index invalid");
    }
    return data_[index];
}

template <typename T>
void tik::vector<T>::reserve(size_t new_cap){
    if(new_cap > size_){
        T* new_arr = new T[new_cap];
        for(size_t i = 0; i<size_; i++){
            new_arr[i] = data_[i];
        }
        delete[] data_;
        capacity_ = new_cap;
        data_ = new_arr;
    }
}

template <typename T>
void tik::vector<T>::shrink_to_fit(){
    if(size_ < capacity_){
        T* new_arr = new T[size_];
        for(size_t i = 0; i<size_; i++){
            new_arr[i] = data_[i];
        }
        delete[] data_;
        capacity_ = size_;
        data_ = new_arr;
    } 
}



// #include <vector>
// #include <iostream>

// int main(){
//     std::vector<int> v;
//     std::cout << v.capacity() << std::endl;


//     return 0;
// }