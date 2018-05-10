#define CTEST_MAIN
#include <stdio.h>
#include "board.h"
#include "board_read.h"
#include "board_print_html.h"
#include "board_test.c"
#include <ctest.h>
CTEST(Step_P, Correct) {
    int board[8][8]={{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};
    FILE *f;
    Spis1 SpisP;
    f = fopen("../input.txt","w");
    fprintf(f,"e2-e3 a9-a2\n");
    fclose(f);
    borders(board,10);
    Read(&SpisP,0);
    int real=CheckStep(SpisP.Run1)*CheckPosition(SpisP.Run1,board);
    int exp = 1;
    ASSERT_EQUAL(exp, real);
}
CTEST(Step_P, Inorrect) {
    int board[8][8]={{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};
    FILE *f;
    Spis1 SpisP;
    f = fopen("../input.txt","w");
    fprintf(f,"e2-d4 a9-a2\n");
    fclose(f);
    borders(board,10);
    Read(&SpisP,0);
    int real = CheckStep(SpisP.Run1)*CheckPosition(SpisP.Run1,board);
    int exp = 0;
    ASSERT_EQUAL(exp, real);
}
CTEST(Step_N, Correct) {
    int board[8][8]={{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};
    FILE *f;
    Spis1 SpisP;
    f = fopen("../input.txt","w");
    fprintf(f,"Ne2-f4 a9-a2\n");
    fclose(f);
    borders(board,12);
    Read(&SpisP,0);
    int real=CheckStep(SpisP.Run1)*CheckPosition(SpisP.Run1,board);
    int exp = 1;
    ASSERT_EQUAL(exp, real);
}
CTEST(Step_N, Inorrect) {
    int board[8][8]={0};
    FILE *f;
    Spis1 SpisP;
    f = fopen("../input.txt","w");
    fprintf(f,"Ne2-e3 a9-a2\n");
    fclose(f);
    borders(board,12);
    Read(&SpisP,0);
    int real = CheckStep(SpisP.Run1)*CheckPosition(SpisP.Run1,board);
    int exp = 0;
    ASSERT_EQUAL(exp, real);
}
CTEST(Kill_P, Correct) {
    int board[8][8]={{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};
    FILE *f;
    Spis1 SpisP;
    f = fopen("../input.txt","w");
    fprintf(f,"e2xd3 a9-a2\n");
    fclose(f);
    borders(board,20);
    Read(&SpisP,0);
    int real = CheckStep(SpisP.Run1)*CheckEnemy(SpisP.Run1,board);
    int exp = 1;
    ASSERT_EQUAL(exp, real);
}
CTEST(Kill_P, Inorrect) {
    int board[8][8]={{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};
    FILE *f;
    Spis1 SpisP;
    f = fopen("../input.txt","w");
    fprintf(f,"e2xd4 a9-a2\n");
    fclose(f);
    borders(board,20);
    Read(&SpisP,0);
    int real = CheckStep(SpisP.Run1)*CheckEnemy(SpisP.Run1,board);
    int exp = 0;
    ASSERT_EQUAL(exp, real);
}
CTEST(Kill_B, Correct) {
    int board[8][8]={{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};
    FILE *f;
    Spis1 SpisP;
    f = fopen("../input.txt","w");
    fprintf(f,"Be2xh5 a9-a2\n");
    fclose(f);
    borders(board,23);
    Read(&SpisP,0);
    int real = CheckStep(SpisP.Run1)*CheckEnemy(SpisP.Run1,board);
    int exp = 1;
    ASSERT_EQUAL(exp, real);
}
CTEST(Kill_B, Inorrect) {
    int board[8][8]={0};
    FILE *f;
    Spis1 SpisP;
    f = fopen("../input.txt","w");
    fprintf(f,"Be2xg4 a9-a2\n");
    fclose(f);
    borders(board,23);
    Read(&SpisP,0);
    int real = CheckStep(SpisP.Run1)*CheckEnemy(SpisP.Run1,board);
    int exp = 0;
    ASSERT_EQUAL(exp, real);
}
CTEST(Block_B, Correct) {
    int board[8][8]={{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};
    FILE *f;
    Spis1 SpisP;
    f = fopen("../input.txt","w");
    fprintf(f,"Re2-e5 a9-a2\n");
    fclose(f);
    borders(board,21);
    Read(&SpisP,0);
    int real = CheckStep(SpisP.Run1)*CheckBlock(SpisP.Run1,board);
    int exp = 1;
    ASSERT_EQUAL(exp, real);
}
CTEST(Block_B, Inorrect) {
    int board[8][8]={{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};
    FILE *f;
    Spis1 SpisP;
    f = fopen("../input.txt","w");
    fprintf(f,"Re2-e7 a9-a2\n");
    fclose(f);
    borders(board,21);
    Read(&SpisP,0);
    int real = CheckStep(SpisP.Run1)*CheckBlock(SpisP.Run1,board);
    int exp = 0;
    ASSERT_EQUAL(exp, real);
}
int main(int argc, const char** argv) {
    return ctest_main(argc, argv);
}
