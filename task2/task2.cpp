#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>
//??????? 10
// ??????????????
int** create_arr(const int ROW, const int COL);
void del_arr(int** arr, const int ROW, const int COL);
void fill_arr(int** arr, const int ROW, const int COL);
void print(int** arr, const int ROW, const int COL);
void del_row(int** arr, int& ROW, const int COL, const int number);
int** del_column(int** arr, int N, int& M, int numOfEresing);
void GetPositionOfMinimalElement(int** arr, int N, int M, int& iOut, int& jOut);
// ??????????? ???????
int main() {
    int ROW = 5;
    int COL = 5;
    int** arr = create_arr(ROW, COL);
    fill_arr(arr, ROW, COL);
    print(arr, ROW, COL);
    int i, j;
    GetPositionOfMinimalElement(arr, ROW, COL, i, j);

    del_row(arr, ROW, COL, i);
    arr = del_column(arr, ROW, COL, j);
    print(arr, ROW, COL);

    del_arr(arr, ROW, COL);

}
// ???????? ?????????? ????????????? ??????
int** create_arr(const int ROW, const int COL) {
    int** A = (int**)malloc(ROW * sizeof(int*));
    for (int i = 0; i < COL; i++) {
        A[i] = (int*)malloc(COL * sizeof(int));
    }
    return A;
}
// ???????? ??????
void del_arr(int** arr, const int ROW, const int COL) {
    for (int i = 0; i < ROW; i++) delete[]arr[i];
    delete[]arr;
}
//?????????? ??????
void fill_arr(int** arr, const int ROW, const int COL) {
    srand(time(nullptr));
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            arr[i][j] = rand() % (-512 - 512) + -512;
        }
    }
}
//????? ??????
void print(int** arr, const int ROW, const int COL) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/*??????? ???????? ?????? ?????????? ???????*/
void del_row(int** arr, int& ROW, const int COL, const int number) {

    if (number < 1 || number > ROW) {
        printf("error string number %d: erase ignore\n", number);
        return;
    }

    delete[]arr[number - 1];
    ROW--;
    for (int i = number - 1; i < ROW; i++) arr[i] = arr[i + 1];
    printf("row %d was deleted\n", number);
}
//??????? ???????? ??????? ?????????? ????????????? ??????
int** del_column(int** arr, int N, int& M, int numOfEresing) {
    int i, j, k;
    int** arr1 = create_arr(N, M - 1);
    int anotherInterator = 0;
    for (int i = 0; i < N; i++) {
        anotherInterator = 0;
        for (int j = 0; j < M; j++) {
            if (j < numOfEresing - 1) {
                arr1[i][j] = arr[i][j];
                anotherInterator++;
            }
            else if(j==numOfEresing)
            {
                continue;
            }
            else
            {
                arr1[i][anotherInterator] = arr[i][j];
                anotherInterator++;
            }
        }
    }
    free(arr);
    M--;
    printf("col %d was deleted\n", numOfEresing);
    return arr1;
   
}
//????? ???????????? ???????? ? ???????
void GetPositionOfMinimalElement(int** arr, int N, int M, int& iOut, int& jOut) {
    int min = INT_MAX;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] < min) {
                min = arr[i][j];
                iOut = i+1;
                jOut = j+1;
            }
        }
    }
    printf("INFO: Min Element is equal to %d, Row position is %d, Col position is %d\n", min, iOut, jOut);
}