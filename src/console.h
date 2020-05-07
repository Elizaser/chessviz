#ifndef ADD_H
#define ADD_H 	
extern  const int N, M;
int console(char a[N][M], int N, int M);
int swap( char *a, char *b );
int eat( char *a, char *b );
int f(char char_number);
int check_hod(char a[][M], int N, int M, char *hod);
int hod_p( char a[][M], int i, int j, int k, int l, int f);
int figurs (char a[N][M], int i, int j, int k, int l, int f);
 #endif
