#include "head.h"

void Menu()
{
	int choice;
	char path[50],contain[100000];
	while(1){
		printf("********************************\n");
		printf("0. 退出\n");
		printf("1. 创建新文件\n");
		printf("2. 写文件\n");
		printf("3. 读文件\n");
		printf("4. 修改文件权限\n");
		printf("5. 查看当前文件的权限\n");
		printf("********************************\n");
		printf("Please input your choice(0-5):");
		scanf("%d",&choice);
		switch(choice){

		case 0:
			printf("Exit successfully!\n");
			exit(0);
			break;

		case 1:
			printf("Please input file name:");
			scanf("%s",path);
			CreateFile(path);
			break;
		case 2:
			printf("Please input file name:");
			scanf("%s",path);
			printf("Please input contain:");
			scanf("%s",contain);
			WriteFile(path,contain);
			break;
		case 3:
			printf("Please input file name:");
			scanf("%s",path);
			ReadFile(path);
			break;
		case 4:
			printf("Please input file name:");
			scanf("%s",path);
			printf("Please input mode number:");
			scanf("%s",contain);
			Chmode(contain,path);
			break;

		case 5:
			printf("Please input file name:");
			scanf("%s",path);
			ReadMode(path);
			break;
		default:
			printf("Invalid input!Please input valuable number again!\n");
			while(getchar()!='\n');
			break;



		}
	}
	
}
void CreateFile(char *path)
{
	/*	
	FILE* fd2 = fopen(path, "a");
	if(fd2==NULL)
	{
		perror("Create file error\n");
		exit(1);	
	}
	else
		printf("Create sucessfully!\n");
	fclose(fd2);
	*/

	int fd=open(path,O_CREAT,0777);
	if(fd==-1)
	{
		perror(" file error\n");
		exit(1);
	}else
		printf("Creat sucessfully!\n");
	close(fd);
}

void WriteFile(char* path,char* contain)
{
	
	FILE* fd2 = fopen(path,"a+");
	if(fd2==NULL)
	{
		perror("Open file error\n");
		exit(1);	
	}
	fprintf(fd2,"%s",contain);
	printf("Write successfully!\n");
	fclose(fd2);
	
	/*
	int n;
	int fd=open(path,O_RDWR|O_APPEND);
	if(fd==-1)
	{
		perror("file error\n");
		exit(1);
	}else
	{
	lseek(fd,0,SEEK_SET);
	n=write(fd,contain,sizeof(contain));
	if(n==-1)
	{
		perror("Write error!\n");
		exit(2);
	}else{
		printf("Write successfully!\n");
	}
	}
	close(fd);
	*/
}
