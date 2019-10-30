#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

void Menu();
void CreateFile(char *);
void WriteFile(char*,char*);
void ReadFile(char*);
void Mode(int mode,char *str);
void ReadMode(char *str);
void Chmode(char *,char*);
