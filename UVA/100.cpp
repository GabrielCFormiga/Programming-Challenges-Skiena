/**
* @file 100.cpp
* "The 3n + 1 Problem" 
*
* Created on 2024-08-24 at 13:32:10
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

int main() { _
    ll l, r, mx, cnt, aux;
    while (cin >> l >> r) {
        cout << l << ' ' << r << ' ';

        mx = 1;
        if (l >= r) swap(l, r);

        for (ll i = l; i <= r; i++) {
            cnt = 1;
            aux = i;

            while (aux > 1) {
                if (aux % 2 == 0) aux /= 2;
                else aux = 3 * aux + 1;
                cnt++;
            }    

            mx = max(mx, cnt);
        }

        cout << mx << endl;
    }
    
    return 0;
}