#include<iostream>
#include <string.h>
#include <cmath>
#include <cctype>
#include <algorithm>
namespace MathFunctions{
    void print(double x){
       std::cout<<"the squre is:"<< sqrt(x)<<std::endl;
    }
}
namespace StringFunctions{
    void print(char x[]){
        char str[strlen(x)];
        for(int i=0;i<strlen(x);i++)
        {
            str[i]=toupper(x[i]); 
        }
          for(int i=0;i<strlen(x);i++)
        {
            std::cout<<str[i];
        }
        std::cout<<std::endl;
        
    }
}
namespace ArrayFunctions{
    void print(int x[],int length){
        
        
            std::reverse(x,x+length);
        for(int i=0;i<length;i++){
            std::cout<<"element:"<<x[i]<<std::endl;
        }
    }
}
int main() {
    double x=25;
    int arr[5]={1,2,3,4,5};
    char str[6]="shada";
    int length=sizeof(arr)/sizeof(arr[0]);
    MathFunctions::print(x);
    StringFunctions::print(str);
    ArrayFunctions::print(arr,length);
}