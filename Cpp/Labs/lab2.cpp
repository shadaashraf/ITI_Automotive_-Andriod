#include<iostream>
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
    cout << "size = " << Size << endl;
    vec * My_Vec = (vec *)malloc(sizeof(vec)); 
    My_Vec->PtrToData = (int *)malloc(Size * sizeof(int)); 
    My_Vec->size = Size;
    My_Vec->Capacity = Size; // Correct initialization
    return My_Vec;
}

void Vector_Free(vec * My_Vec)
{
    if(NULL == My_Vec)
    {
        return;
    }
    free(My_Vec->PtrToData);
    free(My_Vec);
}

void Vector_PrintAllElements(vec * My_Vec)
{
    if(NULL == My_Vec)
    {
        return;
    }
    cout << "Your Vector Data Collection: " << endl;
    for(int i = 0; i < My_Vec->size; i++)
    {
        cout << My_Vec->PtrToData[i] << " ";
    }
    cout << endl;
}

void Vector_PrintOneElement(vec * My_Vec, int Index)
{
    if(Index >= My_Vec->size)
    {
        cout << "Out Of Boundary!!" << endl;
    }
    else
    {
        cout << "The " << Index << " Element is: " << My_Vec->PtrToData[Index] << endl;
    }
}

void Vector_InsertOneElement(vec * My_Vec, int Index, int value)
{
    if(Index < 0 || Index >= My_Vec->size)
    {
        cout << "Out of Boundaries" << endl;
    }
    else
    {
        if(My_Vec->size >= My_Vec->Capacity)
        {
            My_Vec->Capacity *= 2;
            My_Vec->PtrToData = (int *)realloc(My_Vec->PtrToData, My_Vec->Capacity * sizeof(int));
        }

        for(int i = My_Vec->size - 1; i >= Index; i--)
        {
            My_Vec->PtrToData[i + 1] = My_Vec->PtrToData[i];
        }

        My_Vec->PtrToData[Index] = value;
        My_Vec->size++;
    }
}

void Vector_DeleteOneElement(vec * My_Vec, int Index)
{
    if (My_Vec->size == 0)
    {
        std::cout << "No Elements to delete" << std::endl;
    }
    else if (Index < 0 || Index >= My_Vec->size)
    {
        std::cout << "Out of Boundaries" << std::endl;
    }
    else
    {
        for (int i = Index; i < My_Vec->size - 1; i++)
        {
            My_Vec->PtrToData[i] = My_Vec->PtrToData[i + 1];
        }

        // Set the last element to 0 (or any appropriate default value)
        My_Vec->PtrToData[My_Vec->size - 1] = 0;

        My_Vec->size--;
    }
}

int main()
{
    vec * My_Vector = Vector_Create(3);
    Vector_InsertOneElement(My_Vector, 0, 10);
    Vector_InsertOneElement(My_Vector, 1, 20);
    Vector_InsertOneElement(My_Vector, 2, 30);

    Vector_PrintAllElements(My_Vector);

    Vector_DeleteOneElement(My_Vector, 1);

    Vector_PrintAllElements(My_Vector);

    Vector_Free(My_Vector);

    return 0;
}
