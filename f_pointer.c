/**
* f_pointer.c : function pointer example program
* @author : SeJun Lim
* @email : lsj1137@naver.com
* @version : 1.0
* date : 2022.10.21
**/
#include <stdio.h>

int a = 10;
int func1(int arg1) {
	printf("In func1 : arg1 = %d\n", arg1);
}

int main(){
	int *pa;
	int (*func_ptr)(int);

	pa = &a;
	printf("pa = %p, *pa = %d\n",pa,*pa);
	func1(3);

	func_ptr = func1;
	func_ptr(5);
	
	printf("bye..\n");
}

