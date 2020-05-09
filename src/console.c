#include "console.h"
#include "printb.h"
#include <stdio.h>
#include <string.h>
extern const int N, M;

int swap(char* a, char* b)
{
    printf("*a = %c\n", *a);
    char tmp = *a;
    *a = ' ';
    *b = tmp;
    return 0;
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
int check_hod(char a[][M], int N, int M, char* hod)
{
    if ((strlen(hod) > 7) || (f(hod[1]) == -1) || (f(hod[4]) == -1)
        || (hod[2] < '0') || (hod[2] > '8') || (hod[5] < '0')
        || (hod[5] > '8')) {
        return 0;
    }

    return 1;
}
int hod_pw(char a[][M], int i, int j, int k, int l)
{
    if (i == 1) {
        if ((i + 1 == k || i + 2 == k) && (j == l)) // если ход на 1 шаг вперед
        {
            swap(&a[i][j], &a[k][l]);
            return 0;
        }
    } else {
        if (i + 1 == k && j == l) // если ход на 1 шаг вперед
        {
            swap(&a[i][j], &a[k][l]);
            return 0;
        }
    }
    return 1;
}
int hod_pb(char a[][M], int i, int j, int k, int l)
{
    printf("i = %d", i);
    if (i == 6) {
        if ((i - 1 == k || i - 2 == k) && (j == l)) // если ход на 1 шаг вперед
        {
            printf("i-2 = %d", i - 2);
            swap(&a[i][j], &a[k][l]);
            return 0;
        }
    } else {
        if (i - 1 == k && j == l) // если ход на 1 шаг вперед
        {
            swap(&a[i][j], &a[k][l]);
            return 0;
        }
    }
    return 1;
}

int hod_l(char a[N][M], int i, int j, int k, int l)
{
    //ладья
    int i1 = i, j1 = j;
    if (j == l || i == k) {
        if (i == k) {
            for (i1 = i; i1 < k; i1++) {
                if (a[i1][j1] != ' ') {
                    return 1;
                }
            }
            return 0;
        }
        if (j == l) {
            for (j1 = i; j1 < l; j1++) {
                if (a[i1][j1] != ' ') {
                    return 1;
                }
            }
        }
        swap(&a[i][j], &a[k][l]);
    }
    return 1;
}

int console(char a[][M], int N, int M)
{
    char hod[7];
    int flag = 1;
    strcpy(hod, "hod");
    printb(a, N, M);
    while (strncmp(hod, "exit", 4) != 0) {
        if (flag) {
            printf("Ход Белого: ");
        } else
            printf("Ход Черного: ");
        scanf("%s", hod);
        if (strncmp(hod, "exit", 4) == 0)
            break;
        if (check_hod(a, N, M, hod) == 0)
            printf("ERROR_COMMAND\n");
        if (check_hod(a, N, M, hod) == 1) {
            int i = f(hod[2]), j = f(hod[1]);
            int k = f(hod[5]), l = f(hod[4]);
            if (flag) {
                if (hod[3] == '-') {
                    switch (hod[0]) {
                    case 'p':
                        hod_pw(a, i, j, k, l);
                        break;
                    case 'r':
                        hod_l(a, i, j, k, l);
                        break;
                    }
                }
                // else if (hod[3] == 'x'){
                //      switch (hod[0]) {
                //        case 'p':
                //        hod_pw(a, i, j, k, l);
                //        break;
                //        case 'r':
                //        hod_l(a, i, j, k, l);
                //        break;
                //      }
                // }

            } else {
                switch (hod[0]) {
                case 'p':
                    hod_pb(a, i, j, k, l);
                    break;
                case 'r':
                    hod_l(a, i, j, k, l);
                    break;
                }
            }
            // printf("\E[H\E[J");
            printb(a, N, M);
            printf(" \nhod_pb(a, i, j, k, l) = %d\n", hod_pb(a, i, j, k, l));
            printf(" hod_pw(a, i, j, k, l) = %d\n", hod_pw(a, i, j, k, l));
            printf(" hod_l(a, i, j, k, l) = %d\n", hod_l(a, i, j, k, l));

            if (hod_pb(a, i, j, k, l) == 0 || hod_pw(a, i, j, k, l) == 0
                || hod_l(a, i, j, k, l) == 0) {
                flag = 1 - flag;
            }
        }
    }
    return 0;
}
