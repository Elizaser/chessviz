#ifndef ADD_H
#define ADD_H
extern const int N, M;
void swap(char* a, char* b);
void eat(char* a, char* b);
int f(char char_number);
int check_place_r_q_p_k(char a[][M], int i, int j, int k, int l);
int check_place_b_q_k_p(char a[][M], int i, int j, int k, int l);
int check_move(char a[][M], char* move);
int move_p_w(char a[][M], char move[3], int i, int j, int k, int l);
int move_p_b(char a[][M], char move[3], int i, int j, int k, int l);
int move_r_w(char a[N][M], char move[3], int i, int j, int k, int l);
int move_r_b(char a[N][M], char move[3], int i, int j, int k, int l);
int move_n_w(char a[N][M], char move[3], int i, int j, int k, int l);
int move_n_b(char a[N][M], char move[3], int i, int j, int k, int l);
int move_b_w(char a[N][M], char move[3], int i, int j, int k, int l);
int move_b_b(char a[N][M], char move[3], int i, int j, int k, int l);
int move_q_w(char a[N][M], char move[3], int i, int j, int k, int l);
int move_q_b(char a[N][M], char move[3], int i, int j, int k, int l);
int move_k_w(char a[N][M], char move[3], int i, int j, int k, int l);
int move_k_b(char a[N][M], char move[3], int i, int j, int k, int l);
int console(char a[N][M], int N, int M);
#endif
