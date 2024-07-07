#include<iostream>
namespace DynamicAlloc{
    int **create2Darray(int size){
            int **myArr= new int*[size];
            for(int i=0;i<size;i++){
                myArr[i]=new int[2];
            }
             for(int i=0;i<size;i++){
                myArr[i][0]=5;
                myArr[i][1]=25;
                
            }
        return myArr;
    }
    void display(int **arr,int size){
         for(int i=0;i<size;i++){
                std::cout<<arr[i][0]<<"  ";
                std::cout<<arr[i][1]<<std::endl;
            }
    }
    void delete2Darray(int **arr,int size){
         for(int i=0;i<size;i++){
                delete[] arr[i];
            }
            delete[] arr;
    }
}

int main(){
    int **ptr;
   ptr= DynamicAlloc::create2Darray(5);
   DynamicAlloc::display(ptr,5);
  
   DynamicAlloc::delete2Darray(ptr,5);

   }