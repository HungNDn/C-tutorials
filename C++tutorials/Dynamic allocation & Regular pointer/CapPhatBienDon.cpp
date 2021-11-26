#include <iostream>

int main()
{
    // int *ptr = new int;
    // *ptr = 10;
    // or int *ptr = new int(10);
    int *ptr = new int(10);
    std::cout << "Dia chi o nho = " << ptr << " va no chua gia tri la = " << *ptr << std::endl;

    // Xoa cac Bien Don 

    delete ptr;
    ptr = nullptr;
    return 0;
}