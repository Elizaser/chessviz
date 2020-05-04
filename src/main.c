// #include "f.h"
// #include "swap.h"
// #include "printb.h"
// #include "check_hod.h"
// #include "hod_p.h"
#include "console.h"
#include <string.h>
#include <stdio.h>
#include <string.h>
const int N=8, M=9;

int main(int argc, char* argv[]) 
{
	FILE *file;

	if (!(file = fopen(argv[1], "r"))) 
	{
		printf("ERROR INPUT FILE\n");
		return -1;
	}

	char a[N][M];
	char buffer[12];
	int i = 0;
	while (fgets(buffer, 12, file)) 
	{
		strcpy(a[i], buffer);
		i++;
	}

	fclose(file);
	console(a,  N,  M);
	return 0;
}


