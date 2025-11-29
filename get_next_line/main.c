#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(){
	int fd = open("text.txt", O_RDONLY);
	static char *buff;
	buff  = malloc(13);
	if (!buff)
		return 1;
	int i = read(fd, buff, 13);
	buff[i] = '\0';
	printf("%d\n", i);
	printf("%s", buff);
	free(buff);
	buff = malloc(12);
	i = read(fd, buff, 12);
	printf("%d\n", i);
	printf("%s\n", buff);
	free(buff);
	buff = malloc(3);
	i = read(fd, buff, 3);
	printf("%d\n", i);
	free(buff);
}