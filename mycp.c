/**
 * * mycp.c : copy contents and attributes of a file
 * * @author : SeJun Lim
 * * @student ID : 32193767
 * * @email : lsj1137@naver.com
 * * @version : 1.0
 * * @date : 2022.11.02
 * **/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#define MAX_BUF 64

int main(int argc, char *argv[]){
	int fd1, fd2, read_size, write_size, mode;
	//파일 디스크립터, read사이즈, write사이즈, 모드 저장용 변수 생성
	char buf[MAX_BUF];
	//읽어온 내용 저장할 스트링버퍼 생성
	struct stat fst;
	//파일 모드 저장용 stat 구조체 변수 생성
 	
	if (argc != 3){ //argument 수가 3개가 아닌경우 == 사용방법이 틀린 경우
		printf("USAGE: %s original_file_name copy_file_name\n",argv[0]);
		//사용방법 출력
		exit(-1);
	       	//프로그램 종료
	}
	fd1 = open(argv[1], O_RDONLY); //argv[1]의 이름을 가진 파일명의 파일 오픈
	if (fd1<0){		       //제대로 오픈되지 않은 경우
		printf("Can't open %s file with errno %d\n", argv[1], errno);
		//에러넘버 출력
		exit(-1);
		//프로그램 종료
	}
	if (fstat(fd1,&fst)==-1) {     //fd1 사용해서 파일 stat 불러오기 + 실패한 경우
		printf("Can't inquire %s file statistics with errno %d\n", argv[1], errno);
		//에러넘버 출력
		exit(-1);
		//프로그램 종료
	}
	fd2 = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, fst.st_mode);
	//argv[2]의 이름을 가진 파일 생성, 이미 있는 경우 생성x, argv[1]의 mode와 일치시킴
	if (fd2<0) {		        //파일 오픈이 안된 경우
		printf("Can't open %s file with errno %d\n", argv[2], errno);
		//에러넘버 출력
		exit(-1);
		//프로그램 종료
	}
	while(1) {
		read_size = read(fd1,buf,MAX_BUF); //버퍼에 최대 MAX_BUF만큼 읽어오기
		if (read_size == 0) //읽어온게 없는 경우
			break;      //반복 종료
		write_size = write(fd2,buf,read_size); //argv[2] 파일에 버퍼 내용 입력
	}
	close(fd1); //파일 닫기
	close(fd2);
	return 0;
}
