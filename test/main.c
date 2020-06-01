#define CTEST_MAIN
#include "console.h"
#include <ctest.h>
const int N = 8, M = 9;

CTEST(B_Peshka, Correct_p_forward)
{
    char move[6], a[N][M];
    move[0] = 'P';
    move[1] = 'e';
    move[2] = '7';
    move[3] = '-';
    move[4] = 'e';
    move[5] = '6';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = ' ';
        }
    }
    a[6][4] = 'P';
    a[5][4] = ' ';
    int result = move_p_b(a, move, 6, 4, 5, 4);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

int main(int argc, const char** argv)
{
    int test_result = ctest_main(argc, argv);
    return test_result;
}
