/**
* file_redirection.c : redirection example program
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

int main(int argc, char *argv[]){
	int fd, fd1, read_size, write_size;
	char buf[MAX_BUF];

	if (argc != 4){
		printf("USAGE : %s file_name \">\" output_file_name\n", argv[0]);
		exit(-1);
	}
	fd = open(argv[1],O_RDONLY);
	if (fd<0){
		printf("Can't open %s file with errno %d\n", argv[1], errno);
		exit(-1);
	}

	fd1 = open(argv[3], O_RDWR | O_CREAT, 0641);
	dup2(fd1, STDOUT_FILENO);

	while (1) {
		read_size = read(fd, buf, MAX_BUF);
		if(read_size==0)
			break;
		write_size = write(STDOUT_FILENO,buf,read_size);
	}

	close(fd);

	return 0;
}
