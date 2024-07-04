#include<iostream>
#include<string.h>
using namespace std;
int main() {
    int n,arr_len;
    char str[100];
    cout<<"tell me how many row do you want"<<endl;
    cin>>n;
    
    char **arr=(char **)malloc(sizeof(char*)*n);
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the length of string"<<endl; 
        cin>>arr_len;
        arr[i]=(char*)malloc(sizeof(char)*arr_len);
        cout<<"Enter the  string"<<endl; 
        cin>>str;
        strncpy(arr[i], str, arr_len);
    }
    cout << "You entered:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);

}
