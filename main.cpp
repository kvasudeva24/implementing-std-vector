#include "vector.hpp"
#include <iostream>







int main(){

    tik::vector<int> a;
    tik::vector<int> b;  
    // tik::vector<int> b(std::move(a));
    // b = std::move(a);  

    // std::cout << b.capacity() << std::endl;
    // std::cout << a.capacity() << std::endl;

    // a.push_back(4);
    // std::cout << a.front() << std::endl;
    // std::cout << a[0] << std::endl;
    // a.pop_back();
    // std::cout << a.capacity() << std::endl;
    // std::cout << a.size() << std::endl;

    a.reserve(100);
    a.push_back(1);
    std::cout << a.back() << std::endl;
    a.shrink_to_fit();
    std::cout << a.capacity() << std::endl;

    // a[11] = 100;
    // std::cout << a.back() << std::endl;





    return 0;
}