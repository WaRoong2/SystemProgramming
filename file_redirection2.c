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
	char Warning[]="USAGE: ./file_redirection input_file_name > output_file_name\n";
	
	if (argc != 2 || STDOUT_FILENO==1){
		printf("%d",argc);
		write(STDOUT_FILENO,Warning,sizeof(Warning));
		exit(-1);
	}
	
	fd = open(argv[1],O_RDONLY);
	
	if (fd<0){
		dup2(1,STDOUT_FILENO);
		printf("Can't open %s file with errno %d\n", argv[1], errno);
		exit(-1);
	}
	
	while (1) {
		read_size = read(fd, buf, MAX_BUF);
		if(read_size==0)
			break;
		printf("%s",buf);
	}

	close(fd);

	return 0;
}
