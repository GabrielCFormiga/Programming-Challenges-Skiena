/**
* @file 10050.cpp
* "Hartals"
*
* Created on 2024-09-11 at 17:12:18
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
    int tt, n, p, h;
    cin >> tt;

    while (tt--) {
        cin >> n >> p;
        vector<int> days(n + 1);

        int cnt = 0;
        while (p--) {
            cin >> h;
            for (int i = h; i <= n; i += h) {
                if (days[i] == 0 && i % 7 != 6 && i % 7 != 0) {
                    days[i] = 1;
                    cnt++;
                }
            }
        }

        cout << cnt << endl;
    } 
    
    return 0;
}