#include "printb.h"
#include "console.h"
#include <string.h>
#include <stdio.h> 
extern const int N, M;
int swap( char *a, char *b )
{
	char  tmp = *a;
	*a = *b;  
	*b = tmp;
	return 0;
}
int f(char char_number)
{  
	int int_number;
	switch (char_number)
	{
		case '1':
			int_number=0;
			return int_number;
		case '2':
			int_number=1;
			return int_number;
		case '3':
			int_number=2;
			return int_number;
		case '4':
			int_number=3;
			return int_number;
		case '5':
			int_number=4;
			return int_number;
		case '6':
			int_number=5;
			return int_number;
		case '7':
			int_number=6;
			return int_number;
		case 'a':
			int_number=0;
			return int_number;
		case 'b':
			int_number=1;
			return int_number;
		case 'c':
			int_number=2;
			return int_number;
		case 'd':
			int_number=3;
			return int_number;
		case 'e':
			int_number=4;
			return int_number;
		case 'f':
			int_number=5;
			return int_number;
		case 'g':
			int_number=6;
			return int_number;
		case 'h':
			int_number=7;
			return int_number;
		default: 
		{
			return -1;	
		}
	}  
} 
int check_hod(char a[][M], int N, int M, char *hod)
{  
	if( (strlen(hod)>7) || (f(hod[1]) == -1) || (f(hod[4]) == -1)||
		 (hod[2]<'0') || (hod[2]>'7') || ( hod[5]<'0') || (hod[5]>'7')  ) 
	{

		return 0;
	}	

	return 1;

}
int hod_p( char a[][M], int i, int j, int k, int l)
{
	if(a[i][j] == 'p')
	{
		if (i==1)
		{
			if( ( (i+1 == k)||(i+2 == k) )&&(j==l) ) // если ход на 1 шаг вперед 
			{	
				swap( &a[i][j],&a[k][l] );
			}	
		}
		else 
		{
			if( (i+1 == k)&&(j==l) ) // если ход на 1 шаг вперед 
			 {	
				swap( &a[i][j],&a[k][l] );
			 } 
		}
		return 0;
	}
	else
	{
		return 1;
	} 
} 

int console(char a[][M], int N, int M)
{
	char hod[7];
	strcpy(hod, "hod");
	printb(a, N, M);
	int p =0;
	while(strncmp(hod, "exit", 4) != 0)
	{
		scanf("%s", hod);
		if (strncmp(hod, "exit", 4) == 0) break;
		if(check_hod(a, N, M, hod) == 0) printf("ERROR_COMMAND\n");
		if(check_hod(a, N, M, hod)==1)
		{          
			int i=f(hod[2]), j=f(hod[1]);    
			int k=f(hod[5]), l=f(hod[4]);
	        switch (hod[0])
			{
				case 'p':
					hod_p( a, i, j, k, l);
					printf("\np = %d\n", p);
					break;
			}
			printf("\E[H\E[J");
			printb(a, N, M);
		} 
	}
	return 0;	
}
