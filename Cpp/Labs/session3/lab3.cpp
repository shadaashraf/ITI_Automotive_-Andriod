#include <iostream>
template <typename F, typename S>

class KeyValuePair
{
private:
    F key;
    S value;

public:
    KeyValuePair()
    {
    }
    KeyValuePair(F K, S V)
    {
        key = K;
        value = V;
    }
    S getter(F key)
    {
        return value;
    }
    void setter(F K, S V)
    {
        key = K;
        value = V;
    }
    void print(F K)
    {
        std::cout << value;
    }
};

int main()
{
    int key = 1;
    std::string value = "shada";
    KeyValuePair Dic(key, value);
    Dic.print(key);
}
