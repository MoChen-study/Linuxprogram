#include "head.h"
void  ReadFile(char* path)
{
	
	FILE* fd;
	char buf[10000];
	int len;
	if((fd=fopen(path,"r"))==NULL)
	{
		perror("Open fail!\n");
		exit(1);
	}else{
		while((fgets(buf,10000,fd))!=NULL){
			len=strlen(buf);
 			buf[len] = '\0';  /*去掉换行符*/
			printf("%s\n",buf);
		}
			
	}
	fclose(fd);

	/*
	int n;
	char buf[10000];
	int fd=open(path,O_RDONLY);
	if(fd==-1){
		perror("Open fail!\n");
		exit(1);
	}else{
		while((read(fd,buf,sizeof(buf)-1))!=0){
		
		n=strlen(buf);
 		buf[n] = '\0';  /*去掉换行符*/
		/*puts(buf);
		}

	}
	close(fd);
*/
}

void Mode(int mode,char *str)
{
	/*-------这个函数用来把模式值转化为字符串------*/
	str[0]='-'; /*------这里的S_*****都是宏定义，用来判断模式属性-*/

	if(S_ISDIR(mode)) str[0]='d';/*-文件夹-*/
	if(S_ISCHR(mode)) str[0]='c';/*-字符设备-*/
	if(S_ISBLK(mode)) str[0]='b';/*-块设备-*/

	if(mode & S_IRUSR) str[1]='r';/*--用户的三个属性-*/
	else str[1]='-';
	if(mode & S_IWUSR) str[2]='w';
	else str[2]='-';
	if(mode & S_IXUSR) str[3]='x';
	else str[3]='-';

	if(mode & S_IRGRP) str[4]='r';/*--组的三个属性-*/
	else str[4]='-';
	if(mode & S_IWGRP) str[5]='w';
	else str[5]='-';
	if(mode & S_IXGRP) str[6]='x';
	else str[6]='-';

	if(mode & S_IROTH) str[7]='r';/*-其他人的三个属性-*/
	else str[7]='-';
	if(mode & S_IWOTH) str[8]='w';
	else str[8]='-';
	if(mode & S_IXOTH) str[9]='x';
	else str[9]='-';

	str[10]='\0';
	


}


void ReadMode(char *str)
{
	struct stat sb;			/*- 定义stat结构--*/
	if((stat(str,&sb))==-1)
	{
		perror("stat\n");
		exit(1);
	}
	printf("Mode:%lo(octal)\n",(unsigned long)sb.st_mode);
	Mode(sb.st_mode,str);
	printf("Mode:%s\n",str);
}
 






void Chmode(char *s,char* path)
{
 	int mode;
    int mode_u;//所有者权限
    int mode_g;//所属组权限
    int mode_o;//其他人权限
    mode=(atoi(s));//将要设置的权限字符串转换成整数,如"777"转换成777
    if(mode>777||mode<0){//验证要设置的权限是否合法
        printf("Error mode!\n"); 
        exit(0);
    }
    mode_u=mode/100; 
    mode_g=mode/10%10;
    mode_o=mode%10;
    mode=mode_u*8*8+mode_g*8+mode_o;//八进制转换

    if(chmod(path,mode)==-1){//调用chmod函数进行权限修改
        perror("Error mode!\n");
        exit(1);
    }
	else{
		printf("Change Mode successfully!\n");
	}


}
