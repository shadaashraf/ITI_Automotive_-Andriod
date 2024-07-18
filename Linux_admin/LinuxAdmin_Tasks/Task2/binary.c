
#include <stdio.h>

int main(){

int arr[]={1,2,3,4,5,6}; 

int high=4;
int low=0;


int mid,result=-1;
while(low<=high){

mid = low  +(high -low)/2;
if (arr[mid] == 5){
result=mid;
break;}
else if(arr[mid]<5){
low=mid+1;
}
else{
high=mid-1;
}
}
if(result != -1)
{
printf("element found at index :%d",result);
}
else{
printf("not found");
}
return 0;


}















