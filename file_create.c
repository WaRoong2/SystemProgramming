/**
* mycat.c : read and print data from a file
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
#define MAX_BUF 64 

char fname[]="newfile.txt";
char dummy_data[]="abcdefg\n";

int main(){
	int fd, read_size, write_size;
	char buf[MAX_BUF];

	fd = open(fname,O_RDWR | O_CREAT | O_APPEND, 0664);
	if (fd<0){
		printf("Can't create %s file with errno %d\n", fname, errno);
		exit(-1);
	}
	write_size = write(fd,dummy_data,sizeof(dummy_data));
	printf("write_size = %d\n",write_size);
	close(fd);

	fd = open(fname,O_RDONLY);
	if (fd<0){
		printf("Can't open %s file with errno %d\n", fname, errno);
		exit(-1);
	}
	read_size = read(fd,buf,MAX_BUF);
	printf("read_size = %d\n",read_size);
	write_size = write(STDOUT_FILENO,buf,read_size);
	close(fd);

	return 0;
}
