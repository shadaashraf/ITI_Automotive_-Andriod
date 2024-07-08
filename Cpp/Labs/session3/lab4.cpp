#include <iostream>
class VPointerArray
{
private:
    void **arr = nullptr;

public:
    VPointerArray() {}
    VPointerArray(int size)
    {
        arr = new void *[size];
    }
    ~VPointerArray()
    {
        delete[] arr;
    }
    void setelement(int index, void *ptr, const std::type_info &type)
    {
        if (type == typeid(int))
        {
            int *intptr = static_cast<int *>(ptr);
            arr[index] = intptr;
        }
        else if (type == typeid(char))
        {
            char *intptr = static_cast<char *>(ptr);
            arr[index] = intptr;
        }
        else if (type == typeid(double))
        {
            double *intptr = static_cast<double *>(ptr);
            arr[index] = intptr;
        }
    }
    void *getelement(int index)
    {
        return arr[index];
    }
};
int main()
{
    void *ptr2;
    int ptr = 10;
    VPointerArray p(3);
    p.setelement(0, &ptr, typeid(ptr));
    ptr2 = p.getelement(0);
    if (typeid(ptr2) == typeid(int))
        std::cout << *static_cast<int *>(ptr2);
    else if (typeid(ptr2) == typeid(char))
        std::cout << *static_cast<char *>(ptr2);
    else if (typeid(ptr2) == typeid(double))
        std::cout << *static_cast<double *>(ptr2);
}