#include <iostream>
enum class Error
{
    ERROR_400,
    ERROR_404,
    ERROR_500,
    ERROR_504
};
void PrintError(Error e)
{
    if (e == Error::ERROR_400)
    {
        std::cout << "Bad Reuest";
    }
    else if (e == Error::ERROR_404)
    {
        std::cout << "Not Found";
    }
    else if (e == Error::ERROR_500)
    {
        std::cout << "Server Error";
    }
    else if (e == Error::ERROR_400)
    {
        std::cout << "Getway Timeout";
    }
}
int main()
{
    Error e = Error::ERROR_404;
    PrintError(e);
}