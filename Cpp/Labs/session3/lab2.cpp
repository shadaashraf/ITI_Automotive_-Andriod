#include <iostream>
template <typename T>
class Pair
{
private:
    T first;
    T secound;

public:
    Pair()
    {
        first = "";
        secound = "";
    }
    Pair(T f, T sec)
    {
        first = f;
        secound = sec;
    }
    T getfirst()
    {
        return first;
    }
    T getsecoud()
    {
        return secound;
    }
    void setfirst(T f)
    {
        f = first;
    }
    void setsecoud(T s)
    {
        s = secound;
    }
    void setpair(T f, T s)
    {
        f = first;
        s = secound;
    }

    void printPair()
    {
        std::cout << first << "\n";
        std::cout << secound << "\n";
    }
};

int main()
{
    std::string f = "10";
    std::string s = "20";
    Pair p(f, s);
    p.printPair();
    int fi = 5;
    int se = 10;
    Pair p2(fi, se);
    p2.printPair();
}