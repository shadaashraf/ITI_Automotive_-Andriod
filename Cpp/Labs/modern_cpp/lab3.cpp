#include<iostream>
namespace ArrayPair{
    std::pair<int,int> *createArray(int size){
        std::pair<int,int> *arr=new std::pair<int,int>[size] ;
        for(int i=0;i<size;i++){
            arr[i]={1,2};
        }
        return arr;
    }
    void deleteArray(std::pair<int,int> *Array,int size){
        delete[] Array;
    }
    void setpair(std::pair<int,int> *Array,int first,int sec, int index,int size){
       
        for(int i=0;i<size;i++){
            if(i==index){
                Array[i]={first,sec};
            }
            
        }
        
    }
    std::pair<int,int> getPair(std::pair<int,int> *Array, int index,int size){
         for(int i=0;i<size;i++){
            if(i==index){
                return Array[i];
            }
            
        }
        
    }
       void praintArray(std::pair<int,int> *Array,int size){
         for(int i=0;i<size;i++){
           std::cout<<Array[i].first <<" "<<Array[i].second<<std::endl;
        }
        
    }
}
int main(){
    std::pair<int,int> *ptr;
    std::pair<int,int> ele;
    ptr=ArrayPair::createArray(3);
    ArrayPair::deleteArray(ptr,3);
    ele=ArrayPair::getPair(ptr,1,3);
    std::cout<<ele.first<<" "<<ele.second<<std::endl;
    ArrayPair::praintArray(ptr,3);
    ArrayPair::setpair(ptr,7,8,2,3);
    ArrayPair::praintArray(ptr,3);
}