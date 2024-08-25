/**
* @file 10142.cpp
*
* Created on 2024-08-24 at 22:11:24
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
    int tt, n;
    cin >> tt;

    while (tt--) {
        cin >> n;
        vector<string> candidatos(n);
        
        cin.ignore();
        for (int i = 0; i < n; i++) {
            getline(cin, candidatos[i]);
        }

        
    } 
    
    return 0;
}