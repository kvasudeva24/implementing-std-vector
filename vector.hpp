#include <cstddef>


#pragma once




namespace tik {


template <typename T>
    class vector{
    private:
        T* data_ = nullptr;
        size_t capacity_ = 0;
        size_t size_ = 0;


        void destructor_helper();


    public:
        vector();
        ~vector();
        vector(const vector& rhs);
        // vector& operator=(const vector& rhs);
        // vector(vector&& rhs);
        // vector& operator=(const vector&& rhs);

        // T& operator[](size_t index);

        // void reserve(int n);
        // void shrink_to_fit();

        // void push_back(T data);
        // T pop_back();
        // T& front();
        // T& back();


        // bool empty() { return size_ == 0; } ;
        // size_t capacity() { return capacity_; };
        // size_t size() { return size_; };
    };





};