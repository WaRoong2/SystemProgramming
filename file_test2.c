/**
* file_test2.c : read and print data from a file
* @author : SeJun Lim
* @email : lsj1137@naver.com
* @version : 1.0
* @date : 2022.10.21
**/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#define MAX_BUF 16

char fname[]="alphabet.txt";
int main(){
	int fd, read_size, write_size;
	char buf[MAX_BUF];

	fd = open(fname,O_RDONLY);
	if (fd<0){
		printf("Can't open %s file with errno %d\n", fname, errno);
		exit(-1);
	}
	read_size = read(fd, buf, MAX_BUF);
	if (read_size<0){
		printf("Can't read from file %s, read_size = %d\n", fname, read_size);
		exit(-1);
	} else 
		printf("size of read data is %d\n", read_size);
	
	write_size = write(STDOUT_FILENO, buf, MAX_BUF);

	close(fd);

	return 0;
}
