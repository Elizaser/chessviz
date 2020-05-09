#ifndef ADD_H
#define ADD_H 	
extern  const int N, M;
int swap( char *a, char *b );
int f(char char_number);
int eat( char *a, char *b );
int check_hod(char a[][M], int N, int M, char *hod);
int hod_pw(char a[][M], int i, int j, int k, int l);
int hod_pb(char a[][M], int i, int j, int k, int l); 
int hod_l(char a[N][M], int i, int j, int k, int l);
int console(char a[N][M], int N, int M);
 #endif
