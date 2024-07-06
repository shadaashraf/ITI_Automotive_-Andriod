#include "calculate.h" 
int sum(int x,int y){
	return x+y;
}
int sub(int x,int y){
	return y-x;
}
int multi(int x,int y){
	return x*y;
}
float divided(float x,float y){
	if(y!=0){
		return x/y;
	}
	else{
	 return 0;
	}
}
