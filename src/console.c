#include "printb.h"
#include "console.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern const int N, M;
int walking = 1;
int flag = 0;

int check_place_r_q_p_k(char a[][M], int i, int j, int k, int l)
{
    while (i < k - 1) {
        if (a[++i][j] != ' ')
            return 1;
    }
    while (i > k + 1) {
        if (a[--i][j] != ' ')
            return 1;
    }
    while (j < l - 1) {
        if (a[i][++j] != ' ')
            return 1;
    }
    while (j > l + 1) {
        if (a[i][--j] != ' ')
            return 1;
    }
    return 0;
}

int check_place_b_q_k_p(char a[][M], int i, int j, int k, int l)
{
    while (i < k - 1 && j < l - 1) {
        if (a[++i][++j] != ' ')
            return 1;
    }
    while (i < k - 1 && j > l + 1) {
        if (a[++i][--j] != ' ')
            return 1;
    }
    while (i > k + 1 && j < l - 1) {
        if (a[--i][++j] != ' ')
            return 1;
    }
    while (i > k + 1 && j > l + 1) {
        if (a[--i][--j] != ' ')
            return 1;
    }

    return 0;
}

void swap(char* a, char* b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
    flag = 1;
}

void eat(char* a, char* b)
{
    if ((walking == 1
            && (*b == 'P' || *b == 'R' || *b == 'N' || *b == 'B' || *b == 'Q'
                   || *b == 'K'))
        || (walking == 0
               && (*b == 'p' || *b == 'r' || *b == 'n' || *b == 'b' || *b == 'q'
                      || *b == 'k'))) {
        char tmp = *a;
        *a = ' ';
        *b = tmp;
        flag = 1;
    }
}

int f(char char_number)
{
    int int_number;
    switch (char_number) {
    case '1':
        int_number = 0;
        return int_number;
    case '2':
        int_number = 1;
        return int_number;
    case '3':
        int_number = 2;
        return int_number;
    case '4':
        int_number = 3;
        return int_number;
    case '5':
        int_number = 4;
        return int_number;
    case '6':
        int_number = 5;
        return int_number;
    case '7':
        int_number = 6;
        return int_number;
    case '8':
        int_number = 7;
        return int_number;
    case 'a':
        int_number = 0;
        return int_number;
    case 'b':
        int_number = 1;
        return int_number;
    case 'c':
        int_number = 2;
        return int_number;
    case 'd':
        int_number = 3;
        return int_number;
    case 'e':
        int_number = 4;
        return int_number;
    case 'f':
        int_number = 5;
        return int_number;
    case 'g':
        int_number = 6;
        return int_number;
    case 'h':
        int_number = 7;
        return int_number;
    default: {
        return -1;
    }
    }
}
int check_move(char a[][M], char* move)
{
    if ((strlen(move) > 7) || (f(move[1]) == -1) || (f(move[4]) == -1)
        || (move[2] < '0') || (move[2] > '8') || (move[5] < '0')
        || (move[5] > '8')) {
        return 0;
    }
    return 1;
}
int move_p_w(char a[][M], char move[3], int i, int j, int k, int l)
{
    if (a[i][j] == 'p') {
        if (i == 1) {
            if ((i + 1 == k || i + 2 == k) && (j == l)) {
                if (move[3] == '-' && a[k][l] == ' ') {
                    if (check_place_r_q_p_k(a, i, j, k, l) == 0) {
                        swap(&a[i][j], &a[k][l]);
                        return 0;
                    }
                }
            }
        } else {
            if (i + 1 == k && j == l) {
                if (move[3] == '-' && a[k][l] == ' ') {
                    swap(&a[i][j], &a[k][l]);
                    return 0;
                }
            }
        }
        if (move[3] == 'x' && a[k][l] != ' ') {
            eat(&a[i][j], &a[k][l]);
            return 0;
        }
    }
    return 1;
}
int move_p_b(char a[][M], char move[3], int i, int j, int k, int l)
{
    if (a[i][j] == 'P') {
        if (i == 6) {
            if ((i - 1 == k || i - 2 == k) && (j == l)) {
                if (move[3] == '-' && a[k][l] == ' ') {
                    if (check_place_r_q_p_k(a, i, j, k, l) == 0) {
                        swap(&a[i][j], &a[k][l]);
                        return 0;
                    }
                }
            }
        } else {
            if (i - 1 == k && j == l) // если ход на 1 шаг вперед
            {
                if (move[3] == '-' && a[k][l] == ' ') {
                    swap(&a[i][j], &a[k][l]);
                    return 0;
                }
            }
        }
        if (move[3] == 'x' && a[k][l] != ' ') {
            eat(&a[i][j], &a[k][l]);
            return 0;
        }
    }
    return 1;
}

int move_r_w(char a[N][M], char move[3], int i, int j, int k, int l)
{
    //ладья
    if (a[i][j] == 'r') {
        if (i == k || j == l) {
            if (move[3] == '-' && a[k][l] == ' ') {
                if (check_place_r_q_p_k(a, i, j, k, l) == 0) {
                    swap(&a[i][j], &a[k][l]);
                    return 0;
                }
            }
            if (move[3] == 'x') {
                if (a[k][l] != ' ' && check_place_r_q_p_k(a, i, j, k, l) == 0) {
                    eat(&a[i][j], &a[k][l]);
                    return 0;
                }
            }
        }
    }
    return 1;
}
int move_r_b(char a[N][M], char move[3], int i, int j, int k, int l)
{
    //ладья
    if (a[i][j] == 'R') {
        if (i == k || j == l) {
            if (move[3] == '-' && a[k][l] == ' ') {
                if (check_place_r_q_p_k(a, i, j, k, l) == 0) {
                    swap(&a[i][j], &a[k][l]);
                    return 0;
                }
            }
            if (move[3] == 'x') {
                if (a[k][l] != ' ' && check_place_r_q_p_k(a, i, j, k, l) == 0) {
                    eat(&a[i][j], &a[k][l]);
                    return 0;
                }
            }
        }
    }
    return 1;
}
int move_n_w(char a[N][M], char move[3], int i, int j, int k, int l)
{
    //конь
    if (a[i][j] == 'n') {
        if ((i + 2 == k && j + 1 == l) || (i + 2 == k && j - 1 == l)
            || (i - 2 == k && j + 1 == l) || (i - 2 == k && j - 1 == l)
            || (i + 1 == k && j + 2 == l) || (i - 1 == k && j + 2 == l)
            || (i + 1 == k && j - 2 == l) || (i - 1 == k && j - 2 == l)) {
            if (move[3] == '-' && a[k][l] == ' ') {
                swap(&a[i][j], &a[k][l]);
                return 0;
            }
            if (move[3] == 'x') {
                if (a[k][l] != ' ') {
                    eat(&a[i][j], &a[k][l]);
                    return 0;
                }
            }
        }
    }
    return 1;
}

int move_n_b(char a[N][M], char move[3], int i, int j, int k, int l)
{
    //конь
    if (a[i][j] == 'N') {
        if ((i + 2 == k && j + 1 == l) || (i + 2 == k && j - 1 == l)
            || (i - 2 == k && j + 1 == l) || (i - 2 == k && j - 1 == l)
            || (i + 1 == k && j + 2 == l) || (i - 1 == k && j + 2 == l)
            || (i + 1 == k && j - 2 == l) || (i - 1 == k && j - 2 == l)) {
            if (move[3] == '-' && a[k][l] == ' ') {
                swap(&a[i][j], &a[k][l]);
                return 0;
            }
            if (move[3] == 'x') {
                if (a[k][l] != ' ') {
                    eat(&a[i][j], &a[k][l]);
                    return 0;
                }
            }
        }
    }
    return 1;
}

int move_b_w(char a[N][M], char move[3], int i, int j, int k, int l)
{
    if (a[i][j] == 'b') {
        if (abs(i - k) == abs(j - l)) {
            if (move[3] == '-' && a[k][l] == ' ') {
                if (check_place_b_q_k_p(a, i, j, k, l) == 0) {
                    swap(&a[i][j], &a[k][l]);
                    return 0;
                }
            }
            if (move[3] == 'x') {
                if (a[k][l] != ' ' && check_place_b_q_k_p(a, i, j, k, l) == 0) {
                    eat(&a[i][j], &a[k][l]);
                    return 0;
                }
            }
        }
    }
    return 1;
}

int move_b_b(char a[N][M], char move[3], int i, int j, int k, int l)
{
    if (a[i][j] == 'B') {
        if (abs(i - k) == abs(j - l)) {
            if (move[3] == '-' && a[k][l] == ' ') {
                if (check_place_b_q_k_p(a, i, j, k, l) == 0) {
                    swap(&a[i][j], &a[k][l]);
                    return 0;
                }
            }
            if (move[3] == 'x') {
                if (a[k][l] != ' ' && check_place_b_q_k_p(a, i, j, k, l) == 0) {
                    eat(&a[i][j], &a[k][l]);
                    return 0;
                }
            }
        }
    }
    return 1;
}

int move_q_w(char a[N][M], char move[3], int i, int j, int k, int l)
{
    if (a[i][j] == 'q') {
        if (abs(i - k) == abs(j - l) || i == k || j == l) {
            if (move[3] == '-' && a[k][l] == ' ') {
                if (((i == k || j == l)
                        && check_place_r_q_p_k(a, i, j, k, l) == 0)
                    || (i != k && j != l
                           && check_place_b_q_k_p(a, i, j, k, l) == 0)) {
                    swap(&a[i][j], &a[k][l]);
                    return 0;
                }
            }
            if (move[3] == 'x') {
                if (a[k][l] != ' '
                    && (((i == k || j == l)
                            && check_place_r_q_p_k(a, i, j, k, l) == 0)
                           || (i != k && j != l
                                  && check_place_b_q_k_p(a, i, j, k, l) == 0))) {
                    eat(&a[i][j], &a[k][l]);
                    return 0;
                }
            }
        }
    }
    return 1;
}

int move_q_b(char a[N][M], char move[3], int i, int j, int k, int l)
{
    if (a[i][j] == 'Q') {
        if (abs(i - k) == abs(j - l) || i == k || j == l) {
            if (move[3] == '-' && a[k][l] == ' ') {
                if (((i == k || j == l)
                        && check_place_r_q_p_k(a, i, j, k, l) == 0)
                    || (i != k && j != l
                           && check_place_b_q_k_p(a, i, j, k, l) == 0)) {
                    swap(&a[i][j], &a[k][l]);
                    return 0;
                }
            }
            if (move[3] == 'x') {
                if (a[k][l] != ' '
                    && (((i == k || j == l)
                            && check_place_r_q_p_k(a, i, j, k, l) == 0)
                           || (i != k && j != l && check_place_b_q_k_p(a, i, j, k, l) == 0))) {
                    eat(&a[i][j], &a[k][l]);
                    return 0;
                }
            }
        }
    }
    return 1;
}

int move_k_w(char a[N][M], char move[3], int i, int j, int k, int l)
{
    if (a[i][j] == 'k') {
        if (i + 1 == k || i - 1 == k || j + 1 == l || j - 1 == l) {
            if (move[3] == '-' && a[k][l] == ' ') {
                if (((i == k || j == l)
                        && check_place_r_q_p_k(a, i, j, k, l) == 0)
                    || (i != k && j != l
                           && check_place_b_q_k_p(a, i, j, k, l) == 0)) {
                    swap(&a[i][j], &a[k][l]);
                    return 0;
                }
            }
            if (move[3] == 'x') {
                if (a[k][l] != ' '
                    && (((i == k || j == l)
                            && check_place_r_q_p_k(a, i, j, k, l) == 0)
                           || (i != k && j != l
                                  && check_place_b_q_k_p(a, i, j, k, l) == 0))) {
                    eat(&a[i][j], &a[k][l]);
                    return 0;
                }
            }
        }
    }
    return 1;
}

int move_k_b(char a[N][M], char move[3], int i, int j, int k, int l)
{
    if (a[i][j] == 'K') {
        if (i + 1 == k || i - 1 == k || j + 1 == l || j - 1 == l) {
            if (move[3] == '-' && a[k][l] == ' ') {
                if (((i == k || j == l)
                        && check_place_r_q_p_k(a, i, j, k, l) == 0)
                    || (i != k && j != l
                           && check_place_b_q_k_p(a, i, j, k, l) == 0)) {
                    swap(&a[i][j], &a[k][l]);
                    return 0;
                }
            }
            if (move[3] == 'x') {
                if (a[k][l] != ' '
                    && (((i == k || j == l)
                            && check_place_r_q_p_k(a, i, j, k, l) == 0)
                           || (i != k && j != l && check_place_b_q_k_p(a, i, j, k, l) == 0))) {
                    eat(&a[i][j], &a[k][l]);
                    return 0;
                }
            }
        }
    }
    return 1;
}

int console(char a[][M], int N, int M)
{
    char move[7];

    strcpy(move, "move");
    printb(a);
    while (strncmp(move, "exit", 4) != 0) {
        if (walking) {
            printf("Ход Белого: ");
        } else
            printf("Ход Черного: ");
        scanf("%s", move);
        if (strncmp(move, "exit", 4) == 0)
            break;
        if (check_move(a, move) == 0)
            printf("ERROR_COMMAND\n");
        if (check_move(a, move)) {
            int i = f(move[2]), j = f(move[1]);
            int k = f(move[5]), l = f(move[4]);
            if (walking) {
                if (move[3] == '-' || move[3] == 'x') {
                    switch (move[0]) {
                    case 'p':
                        move_p_w(a, move, i, j, k, l);
                        break;
                    case 'r':
                        move_r_w(a, move, i, j, k, l);
                        break;
                    case 'n':
                        move_n_w(a, move, i, j, k, l);
                        break;
                    case 'b':
                        move_b_w(a, move, i, j, k, l);
                        break;
                    case 'q':
                        move_q_w(a, move, i, j, k, l);
                        break;
                    case 'k':
                        move_k_w(a, move, i, j, k, l);
                        break;
                    }
                }

            } else {
                switch (move[0]) {
                case 'p':
                    move_p_b(a, move, i, j, k, l);
                    break;
                case 'r':
                    move_r_b(a, move, i, j, k, l);
                    break;
                case 'n':
                    move_n_b(a, move, i, j, k, l);
                    break;
                case 'b':
                    move_b_b(a, move, i, j, k, l);
                    break;
                case 'q':
                    move_q_b(a, move, i, j, k, l);
                    break;
                case 'k':
                    move_k_b(a, move, i, j, k, l);
                    break;
                }
            }
            // printf("\E[H\E[J");
            if (flag == 1) {
                printb(a);
                walking = 1 - walking;
                flag = 0;
            } else
                printf("ERROR_COMMAND\n");
        }
    }
    return 0;
}
