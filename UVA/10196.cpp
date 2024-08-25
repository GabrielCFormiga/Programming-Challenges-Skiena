/**
* @file 10196.cpp
* "Check The Check"
*
* Created on 2024-08-24 at 21:34:15
* @author GabrielCampelo
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

char board[8][8];
bool vis[8][8];
bool bcheck, wcheck;
int bx, by, wx, wy;

void clearVis() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            vis[i][j] = false;
        }
    }
}

void handlePawn() {
    if (bx + 1 < 8) {
        if ((by + 1 < 8 && board[bx + 1][by + 1] == 'P') || 
            (by - 1 >= 0 && board[bx + 1][by - 1] == 'P')) {
            bcheck = true;
        }
    }
}

void whandlePawn() {
    if (wx -1 >= 0) {
        if ((wy + 1 < 8 && board[wx - 1][wy + 1] == 'p') || 
            (wy - 1 >= 0 && board[wx - 1][wy - 1] == 'p')) {
            wcheck = true;
        }
    }
}

void handleDiagonalR(int i, int j) {
    if (i < 0 || i >= 8 || j < 0 || j >= 8) return;
    if (vis[i][j]) return;
    vis[i][j] = true;

    if (board[i][j] == 'Q' || board[i][j] == 'B') {
        bcheck = true;
        return;
    } else if (board[i][j] == '.' || board[i][j] == 'k') {
        handleDiagonalR(i + 1, j + 1); 
        handleDiagonalR(i - 1, j - 1); 
    } else {
        return;
    }
}

void whandleDiagonalR(int i, int j) {
    if (i < 0 || i >= 8 || j < 0 || j >= 8) return;
    if (vis[i][j]) return;
    vis[i][j] = true;

    if (board[i][j] == 'q' || board[i][j] == 'b') {
        wcheck = true;
        return;
    } else if (board[i][j] == '.' || board[i][j] == 'K') {
        whandleDiagonalR(i + 1, j + 1); 
        whandleDiagonalR(i - 1, j - 1); 
    } else {
        return;
    }
}

void handleDiagonalL(int i, int j) {
    if (i < 0 || i >= 8 || j < 0 || j >= 8) return;
    if (vis[i][j]) return;
    vis[i][j] = true;

    if (board[i][j] == 'Q' || board[i][j] == 'B') {
        bcheck = true;
        return;
    } else if (board[i][j] == '.' || board[i][j] == 'k') {
        handleDiagonalL(i - 1, j + 1); 
        handleDiagonalL(i + 1, j - 1); 
    } else {
        return;
    }
}

void whandleDiagonalL(int i, int j) {
    if (i < 0 || i >= 8 || j < 0 || j >= 8) return;
    if (vis[i][j]) return;
    vis[i][j] = true;

    if (board[i][j] == 'q' || board[i][j] == 'b') {
        wcheck = true;
        return;
    } else if (board[i][j] == '.' || board[i][j] == 'K') {
        whandleDiagonalL(i - 1, j + 1); 
        whandleDiagonalL(i + 1, j - 1); 
    } else {
        return;
    }
}

void handleVertical(int i, int j) {
    if (i < 0 || i >= 8 || j < 0 || j >= 8) return;
    if (vis[i][j]) return;
    vis[i][j] = true;

    if (board[i][j] == 'Q' || board[i][j] == 'R') {
        bcheck = true;
        return;
    } else if (board[i][j] == '.' || board[i][j] == 'k') {
        handleVertical(i - 1, j);
        handleVertical(i + 1, j);
    } else {
        return;
    }
}

void whandleVertical(int i, int j) {
    if (i < 0 || i >= 8 || j < 0 || j >= 8) return;
    if (vis[i][j]) return;
    vis[i][j] = true;

    if (board[i][j] == 'q' || board[i][j] == 'r') {
        wcheck = true;
        return;
    } else if (board[i][j] == '.' || board[i][j] == 'K') {
        whandleVertical(i - 1, j);
        whandleVertical(i + 1, j);
    } else {
        return;
    }
}

void handleHorizontal(int i, int j) {
    if (i < 0 || i >= 8 || j < 0 || j >= 8) return;
    if (vis[i][j]) return;
    vis[i][j] = true;

    if (board[i][j] == 'Q' || board[i][j] == 'R') {
        bcheck = true;
        return;
    } else if (board[i][j] == '.' || board[i][j] == 'k') {
        handleHorizontal(i, j + 1);
        handleHorizontal(i, j - 1);
    } else {
        return;
    }
}

void whandleHorizontal(int i, int j) {
    if (i < 0 || i >= 8 || j < 0 || j >= 8) return;
    if (vis[i][j]) return;
    vis[i][j] = true;

    if (board[i][j] == 'q' || board[i][j] == 'r') {
        wcheck = true;
        return;
    } else if (board[i][j] == '.' || board[i][j] == 'K') {
        whandleHorizontal(i, j + 1);
        whandleHorizontal(i, j - 1);
    } else {
        return;
    }
}

void handleKnight() {
    int knightMoves[8][2] = {{-2, 1}, {-2, -1}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {1, 2}, {1, -2}};
    for (int i = 0; i < 8; i++) {
        int nx = bx + knightMoves[i][0];
        int ny = by + knightMoves[i][1];
        if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && board[nx][ny] == 'N') {
            bcheck = true;
            return;
        }
    }
}

void whandleKnight() {
    int knightMoves[8][2] = {{-2, 1}, {-2, -1}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {1, 2}, {1, -2}};
    for (int i = 0; i < 8; i++) {
        int nx = wx + knightMoves[i][0];
        int ny = wy + knightMoves[i][1];
        if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && board[nx][ny] == 'n') {
            wcheck = true;
            return;
        }
    }
}

void bsolve() {
    handlePawn();
    if (bcheck) return;
    
    handleDiagonalR(bx, by);
    if (bcheck) return;
    clearVis();
    handleDiagonalL(bx, by);
    if (bcheck) return;
    clearVis();
    handleVertical(bx, by);
    if (bcheck) return;
    clearVis();
    handleHorizontal(bx, by);
    if (bcheck) return;
    
    handleKnight();
}

void wsolve() {
    whandlePawn();
    if (wcheck) return;

    whandleDiagonalR(wx, wy);
    if (wcheck) return;
    clearVis();  
    whandleDiagonalL(wx, wy);
    if (wcheck) return;
    clearVis();
    whandleVertical(wx, wy);
    if (wcheck) return;
    clearVis();
    whandleHorizontal(wx, wy);
    if (wcheck) return;
    
    whandleKnight();
}

int main() {
    int game = 1; _
    while (true) {
        bx = -1;
        by = -1;
        wx = -1;
        wy = -1;

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                scanf(" %c", &board[i][j]);
                vis[i][j] = false;
                
                if (board[i][j] == 'k') {
                    bx = i;
                    by = j;
                } else if (board[i][j] == 'K') {
                    wx = i;
                    wy = j;
                }
            }
        }

        if (bx == -1 && wx == -1) break;

        bcheck = false;
        wcheck = false;
        
        if (bx != -1) {
            bsolve();
            if (wx != -1) {
                clearVis();
            }
        }
        if (wx != -1) wsolve();

        printf("Game #%d: ", game);
        game++;

        if (bcheck) {
            printf("black king is in check.\n");
        } else if (wcheck) {
            printf("white king is in check.\n");
        } else {
            printf("no king is in check.\n");
        }
    }
    
    return 0;
}

