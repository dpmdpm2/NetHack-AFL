#include <stdio.h>
#include <string.h>

void main()
{
	char buf[256];
	int i, j;
	for (i = 0; fgets(buf, sizeof buf, stdin) == buf; i++) {
		int len = strlen(buf) - 1;
		buf[len] = 0;
		for (j = 0; j < len; j++) {
			if (buf[j] == '\\') {
				memmove(buf+j+4,buf+j+1,len-j);
				buf[j+1] = 'x';
				buf[j+2] = '5';
				buf[j+3] = 'c';
				len += 3;
			}
		}
		printf("a%d=\"%s\"\n", i, buf);
	}
}
