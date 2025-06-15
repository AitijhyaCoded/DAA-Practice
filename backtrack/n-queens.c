#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int count = 0;

int isSafe(char board[MAX][MAX], int n, int row, int col){
    for(int i = 0; i < n; i++){
        if(board[i][col] == 'Q') //column
            return 0;
    }
    for(int i = 0; i < n; i++){
        if(board[row][i] == 'Q') //row
            return 0;
    }
    for(int i = row, j = col; i >= 0, j >= 0; i--, j--){
        if(board[i][j] == 'Q') //left diagonal
            return 0;
    }
    for(int i = row, j = col; i >= 0, j < n; i--, j++){
        if(board[i][j] == 'Q') //right diagonal
            return 0;
    }
    return 1;
}

void nQueensB(char board[MAX][MAX], int n, int r){
    if(r == n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        count++;
        return;
    }
    else{
        for(int c = 0; c < n; c++){
            if(isSafe(board, n, r, c) && board[r][c] == '.'){
                board[r][c]='Q';
                nQueensB(board, n, r+1);
                board[r][c]='.'; // backtrack
            }
        }
    }
}

int main(){
    char board[MAX][MAX], n, i, j;
    printf("Enter n: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            board[i][j]='.';
        }
    }
    printf("Boards:\n");
    nQueensB(board, n, 0);
    printf("Total solutions: %d\n", count);
    return 0;
}
