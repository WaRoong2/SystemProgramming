/**
* mycat.c : read and print data from a file
* @author : SeJun Lim
* @student ID : 32193767
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
	int fd, read_size, write_size; 
	//파일디스크립터, read사이즈, write사이즈 저장용 변수 생성
	char buf[MAX_BUF];
	//읽어온 내용 담아둘 스트링버퍼 생성

	if (argc != 2){ //argument 수가 2개가 아닌경우 == 사용방법이 틀린 경우
		printf("USAGE : %s file_name\n", argv[0]);
		//사용방법 출력
		exit(-1);
		//프로그램 종료
	}
	fd = open(argv[1],O_RDONLY);
	//argv[1]의 이름을 가진 파일명의 파일 오픈
	if (fd<0){ //제대로 오픈되지 않은 경우
		printf("Can't open %s file with errno %d\n", argv[1], errno);
		//에러넘버 출력
		exit(-1);
		//프로그램 종료
	}
	while (1) {
		read_size = read(fd, buf, MAX_BUF);
		//버퍼에 최대 MAX_BUF만큼 읽어오기 
		if(read_size==0)       //읽어온게 없는 경우
			break;         //반복 종료
		write_size = write(STDOUT_FILENO,buf,read_size);
		//표준출력에 버퍼 내용 쓰기
	}

	close(fd); //파일 닫기

	return 0;
}
