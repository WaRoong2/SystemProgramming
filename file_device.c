/**
* file_device.c : device example program
* @author : SeJun Lim
* @email : lsj1137@naver.com
* @version : 1.0
* @date : 2022.10.21
**/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#define MAX_BUF 4 

char fname[]="test.txt";
char tmp_data[]="abcdefghijklmn";

int main(int argc, char *argv[]){
	int fd, size;
	char buf[MAX_BUF];

	fd = open(fname, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd<0){
		printf("Can't create %s file with errno %d\n", fname, errno);
		exit(-1);
	}
	write(fd,tmp_data,sizeof(tmp_data));
	close(fd);

	fd = open(fname,O_RDONLY);
	if (fd<0){
		printf("Can't open %s file with errno %d\n", fname, errno);
		exit(-1);
	}
	lseek(fd,5,SEEK_SET);
	size = read(fd,buf,MAX_BUF);
	close(fd);

	fd = open(argv[1],O_WRONLY);
	write(fd,buf,MAX_BUF);
	close(fd);

	return 0;
}
