#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
struct vec
{
    int size;
    int Capacity;
    int * PtrToData;
};
vec * Vector_Create(int Size)
{
    vec * My_Vec = (vec *)malloc(sizeof(vec)); 
    My_Vec->PtrToData =(int *)malloc(Size * sizeof(int)); 
    My_Vec->size = Size;
    My_Vec->size = My_Vec->Capacity;
    return My_Vec;
}
void Vector_Free(vec * My_Vec)
{
    if(NULL == My_Vec)
    {

    }
    else
    {
        free(My_Vec->PtrToData);
        free(My_Vec);
    }
    
}
void Vector_PrintAllElements(vec * My_Vec)
{
      if(NULL == My_Vec)
    {

    }
    else
    {
        std::cout<<"Your Vector Data Collection : \n"<<std::endl;
        for(int i=0;i<(My_Vec->size);i++)
        {
            printf("%d ",(My_Vec->PtrToData[i]));
        }
    }
}
void Vector_PrintOneElement(vec * My_Vec,int Index)
{
    if(Index >= My_Vec->size)
    {
        std::cout<<"Out Of Boundry!!"<<std::endl;
    }
    else
    {
        printf("The %d Element is : %d\n",Index,My_Vec->PtrToData[Index]);
    }
}
void Vector_InsertOneElement(vec * My_Vec,int Index,int value)
{
    if(My_Vec->Capacity > My_Vec->size && Index == My_Vec->size) 
    {
        My_Vec->PtrToData[Index] = value;
    }
    else
    {
        if(Index < 0 || Index > My_Vec->size)
        {
            std::cout<<"Out of Boundries"<<std::endl;
        }
        else
        {
              
                My_Vec->Capacity *=2;
                My_Vec->PtrToData =(int *)realloc(My_Vec->PtrToData, My_Vec->Capacity * sizeof(int));
               
                for(int i=My_Vec->size -1;i > Index;i--)
                {
                    My_Vec->PtrToData[i] = My_Vec->PtrToData[i-1] ;
                }
              
                 My_Vec->PtrToData[Index] = value;
                 My_Vec->size++;
        }
    }
}
void Vector_DeleteOneElement(vec * My_Vec,int Index)
{
    if(My_Vec->size == 0)
    {
        std::cout<<"No Elements to delete"<<std::endl;
    }
    else
    {
        if(Index == My_Vec->size -1)
        {
            My_Vec->PtrToData[Index] = 0;
        }
        else
        {
          
            for(int i=Index;i<My_Vec->size-1;i++)
            {
                My_Vec->PtrToData[i] = My_Vec->PtrToData[i+1] ;
            }
        }
    }
    My_Vec->size--;
}
int main()
{
    



    return 0;
}