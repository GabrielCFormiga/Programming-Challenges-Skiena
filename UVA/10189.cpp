/**
* @file 10189.cpp
* "Minesweeper"
*
* Created on 2024-08-24 at 16:04:55
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

#define MAX_N 100
#define MAX_M 100

int n, m;
char field[MAX_N][MAX_M];

int is_bomb(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m) return 0;
    if (field[i][j] == '*') return 1;
    else return 0;
}


int calculate(int i, int j) {
    int sum = 0;    

    sum += is_bomb(i + 1, j);
    sum += is_bomb(i + 1, j + 1);
    sum += is_bomb(i + 1, j - 1);     
    sum += is_bomb(i, j - 1);
    sum += is_bomb(i, j + 1);
    sum += is_bomb(i - 1, j);
    sum += is_bomb(i - 1, j - 1);    
    sum += is_bomb(i - 1, j + 1);

    return sum;
}

int main() { _
    int cnt = 1;
    while (cin >> n >> m && n != 0) {
        if (cnt > 1) cout << endl;
        cout << "Field #" << cnt << ':' << endl;
        cnt++;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> field[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (field[i][j] == '*') cout << '*';
                else cout << calculate(i, j); 
            }
            cout << endl;
        }
    }
    
    return 0;
}