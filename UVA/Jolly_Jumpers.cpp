/**
* @file 10038.cpp
* "Jolly Jumpers"
*
* Created on 2024-09-11 at 14:31:13
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

#define MAX_N 3000

int main() { _
    int n;

    while (cin >> n) {
        vector<int> vec(n);
        vector<bool> vis(n);
        bool jolly = true;
        
        cin >> vec[0];
        for (int i = 1; i < n; i++) {
            cin >> vec[i];
            vis[abs(vec[i] - vec[i - 1])] = true;
        }

        for (int i = 1; i <= n - 1; i++) {
            if (!vis[i]) {
                jolly = false;
                break;
            }
        }

        cout << (jolly ? "Jolly" : "Not jolly") << endl;
    }
    
    return 0;
}