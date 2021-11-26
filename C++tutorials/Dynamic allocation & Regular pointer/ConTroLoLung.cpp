#include <iostream>

int main()
{
    int *ptr = new int;
    *ptr = 10;

    std::cout << "Gia Tri Cua Con Tro: "<< *ptr << std:: endl;
    delete ptr;
    std::cout << "Gia Tri Cua Con Tro: "<< *ptr << std:: endl;

    ptr = nullptr;

    if (!ptr){
        ptr = new int;
        std::cout <<"Hello" << std::endl;
    }
		

    *ptr = 20;
    std::cout << "Gia Tri Cua Con Tro: "<< *ptr << std:: endl;
    delete ptr;
    std::cout << "Gia Tri Cua Con Tro: "<< *ptr << std:: endl;

    return 0;
}