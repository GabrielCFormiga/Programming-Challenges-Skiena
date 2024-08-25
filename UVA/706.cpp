/**
* @file 706.cpp
* "LC-Display"
* não está pronto
*
* Created on 2024-08-24 at 20:59:48
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

// update dig
void get_dig(vector<string> &dig, int x, int n, int m) {
    string tmp;
    for (int i = 0; i < n; i++) {
        tmp = "";

        if (i == 0) {

        } else if (i == (n - 1) / 2) {

        } else if (i == n - 1) {

        }

    }
}

int main() { _
    string num;
    int sz;

    while (cin >> sz >> num && sz != 0) {
        int qtd_digs = num.size();
        int n = 2 * sz + 3, m = sz + 2;

        vector<string> linha(n);
        vector<string> dig(n);

        // append first digit
        get_dig(dig, num[0] - '0', n, m);
        for (int i = 0; i < n; i++) {
            linha[i] = dig[i];
        }

        // append others digits
        for (int j = 1; j < qtd_digs; j++) {
            get_dig(dig, num[j] - '0', n, m);

            for (int i = 0; i < n; i++) {
                linha[i] = linha[i] + " " + dig[i];
            }
        }

        // print
        for (int i = 0; i < n; i++) {
            cout << linha[i] << endl;
        }
        cout << endl << endl;
    }
    
    return 0;
}