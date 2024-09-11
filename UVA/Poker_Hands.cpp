/**
* @file 10315.cpp
* "Poker Hands"
*
* Created on 2024-09-11 at 14:43:30
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
    map<char, int> mp;
    for (int i = 2; i <= 9; i++) {
        mp[(char)('0' + i)] = i - 2;
    }
    mp['T'] = 8;
    mp['J'] = 9;
    mp['Q'] = 10;
    mp['K'] = 11;
    mp['A'] = 12;

    vector<string> black(5);
    vector<string> white(5);

    while (cin >> black[0]) {
        vector<vector<char>> dp_blk(13); // cartas de 0 ('2') até 12 ('A')
        vector<vector<char>> dp_wht(13); 

        // primeira carta preta
        dp_blk[mp[black[0][0]]].pb(black[0][1]);

        for (int i = 1; i < 5; i++) {
            cin >> black[i];
            dp_blk[mp[black[i][0]]].pb(black[i][1]);
        }
        
        for (int i = 0; i < 5; i++) {
            cin >> white[i];
            dp_wht[mp[white[i][0]]].pb(white[i][1]);
        }

        int mx_blk = -1, par1_blk = -1, par2_blk = -1, trinca_blk = -1, quadra_blk = -1, c_blk = 0, d_blk = 0, h_blk = 0, s_blk = 0;
        int mx_wht = -1, par1_wht = -1, par2_wht = -1, trinca_wht = -1, quadra_wht = -1, c_wht = 0, d_wht = 0, h_wht = 0, s_wht = 0;
        
        for (int i = 0; i <= 12; i++) {
            if (dp_blk[i].size() == 4) quadra_blk = i;
            if (dp_blk[i].size() == 3) trinca_blk = i;
            if (dp_blk[i].size() == 2) {
                if (par1_blk == -1) par1_blk = i;
                else par2_blk = i;
            }
            if (dp_blk[i].size() == 1) mx_blk = i; 
            
            for (int j = 0; j < dp_blk[i].size(); j++) {
                if (dp_blk[i][j] == 'C') c_blk++;
                if (dp_blk[i][j] == 'D') d_blk++;
                if (dp_blk[i][j] == 'H') h_blk++;
                if (dp_blk[i][j] == 'S') s_blk++;
            }

            if (dp_wht[i].size() == 4) quadra_wht = i;
            if (dp_wht[i].size() == 3) trinca_wht = i;
            if (dp_wht[i].size() == 2) {
                if (par1_wht == -1) par1_wht = i;
                else par2_wht = i;
            }
            if (dp_wht[i].size() == 1) mx_wht = i; 

            for (int j = 0; j < dp_wht[i].size(); j++) {
                if (dp_wht[i][j] == 'C') c_wht++;
                if (dp_wht[i][j] == 'D') d_wht++;
                if (dp_wht[i][j] == 'H') h_wht++;
                if (dp_wht[i][j] == 'S') s_wht++;
            }
        }

        if (par1_blk < par2_blk) swap(par1_blk, par2_blk);
        if (par1_wht < par2_wht) swap(par1_wht, par2_wht);

        bool straight_blk = false;
        bool straight_wht = false; 

        for (int i = 0; i < 9; i++) {
            if (dp_blk[i].size() && dp_blk[i + 1].size() && dp_blk[i + 2].size() && dp_blk[i + 3].size() && dp_blk[i + 4].size()) straight_blk = true;
            if (dp_wht[i].size() && dp_wht[i + 1].size() && dp_wht[i + 2].size() && dp_wht[i + 3].size() && dp_wht[i + 4].size()) straight_wht = true;
        }

        bool flush_blk = (c_blk == 5 || d_blk == 5 || h_blk == 5 || s_blk == 5);
        bool flush_wht = (c_wht == 5 || d_wht == 5 || h_wht == 5 || s_wht == 5);
        
        // straight flush
        if (straight_blk && flush_blk && straight_wht && flush_wht) {
            if (mx_blk == mx_wht) cout << "Tie." << endl;
            else if (mx_blk > mx_wht) cout << "Black wins." << endl;
            else cout << "White wins." << endl;
        } else if (straight_blk && flush_blk) {
            cout << "Black wins." << endl;
        } else if (straight_wht && flush_wht) {
            cout << "White wins." << endl;
        } else {
            // four of a kind
            if (quadra_blk != -1 && quadra_wht != -1) {
                if (quadra_blk > quadra_wht) cout << "Black wins." << endl;
                else cout << "White wins." << endl;
            } else if (quadra_blk != -1) {
                cout << "Black wins." << endl;
            } else if (quadra_wht != -1) {
                cout << "White wins." << endl;
            } else {
                // full house
                if (trinca_blk != -1 && par1_blk != -1 && trinca_wht != -1 && par1_wht != -1) {
                    if (trinca_blk == trinca_wht) {
                        cout << "Tie." << endl;
                    } else if (trinca_blk > trinca_wht) {
                        cout << "Black wins." << endl;
                    } else {
                        cout << "White wins." << endl;
                    }
                } else if (trinca_blk != -1 && par1_blk != -1) {
                    cout << "Black wins." << endl;
                } else if (trinca_wht != -1 && par1_wht != -1) {
                    cout << "White wins." << endl;
                } else {
                    // flush
                    if (flush_blk && flush_wht) {
                        if (mx_blk == mx_wht) {
                            // desempate
                            vector<int> pretas;
                            vector<int> brancas;

                            for (int i = 0; i <= 12; i++) {
                                for (int j = 0; j < dp_blk[i].size(); j++) pretas.pb(i);
                                for (int j = 0; j < dp_wht[i].size(); j++) brancas.pb(i);
                            }

                            sort(all(pretas));
                            sort(all(brancas));

                            bool foi_exibido = false;
                            for (int i = 4; i >= 0; i--) {
                                if (pretas[i] > brancas[i]) {
                                    cout << "Black wins." << endl;
                                    foi_exibido = true;
                                    break;
                                } else if (pretas[i] < brancas[i]) {
                                    cout << "White wins." << endl;
                                    foi_exibido = true;
                                    break;
                                }
                            }

                            if (!foi_exibido) cout << "Tie." << endl;
                        }
                        else if (mx_blk > mx_wht) cout << "Black wins." << endl;
                        else cout << "White wins." << endl;
                    } else if (flush_blk) {
                        cout << "Black wins." << endl;
                    } else if (flush_wht) {
                        cout << "White wins." << endl;
                    } else {
                        // straight
                        if (straight_blk && straight_wht) {
                            if (mx_blk == mx_wht) cout << "Tie." << endl;
                            else if (mx_blk > mx_wht) cout << "Black wins." << endl;
                            else cout << "White wins." << endl;
                        } else if (straight_blk) {
                            cout << "Black wins." << endl;
                        } else if (straight_wht) {
                            cout << "White wins." << endl;
                        } else {
                            // three of a kind
                            if (trinca_blk != -1 && trinca_wht != -1) {
                                if (trinca_blk == trinca_wht) cout << "Tie." << endl;
                                else if (trinca_blk > trinca_wht) cout << "Black wins." << endl;
                                else cout << "White wins." << endl;
                            } else if (trinca_blk != -1) {
                                cout << "Black wins." << endl;
                            } else if (trinca_wht != -1) {
                                cout << "White wins." << endl;
                            } else {
                                // two pair
                                if (par1_blk != -1 && par2_blk != -1 && par1_wht != -1 && par2_wht != -1) {
                                    if (par1_blk == par1_wht) {
                                        // desempate pelo segundo par
                                        if (par2_blk == par2_wht) {
                                            // desempate pela maior carta restante
                                            int r_blk;
                                            int r_wht;

                                            for (int i = 0; i <= 12; i++) {
                                                if (dp_blk[i].size() && i != par1_blk && i != par2_blk) r_blk = i;
                                                if (dp_wht[i].size() && i != par1_wht && i != par2_wht) r_wht = i;
                                            }

                                            if (r_blk == r_wht) cout << "Tie." << endl;
                                            else if (r_blk > r_wht) cout << "Black wins." << endl;
                                            else cout << "White wins." << endl;
                                        } else if (par2_blk > par2_wht) {
                                            cout << "Black wins." << endl;
                                        } else {
                                            cout << "White wins." << endl;
                                        }
                                    } else if (par1_blk > par1_wht) {
                                        cout << "Black wins." << endl;
                                    } else {
                                        cout << "White wins." << endl;
                                    }
                                } else if (par1_blk != -1 && par2_blk != -1) {
                                    cout << "Black wins." << endl;
                                } else if(par1_wht != -1 && par2_wht != -1) {
                                    cout << "White wins." << endl;
                                } else {
                                    // one pair
                                    if (par1_blk != -1 && par1_wht != -1) {
                                        if (par1_blk == par1_wht) {
                                            // desempate
                                            vector<int> pretas;
                                            vector<int> brancas;

                                            for (int i = 0; i <= 12; i++) {
                                                for (int j = 0; j < dp_blk[i].size(); j++) pretas.pb(i);
                                                for (int j = 0; j < dp_wht[i].size(); j++) brancas.pb(i);
                                            }

                                            sort(all(pretas));
                                            sort(all(brancas));

                                            bool foi_exibido = false;
                                            for (int i = 4; i >= 0; i--) {
                                                if (pretas[i] > brancas[i]) {
                                                    cout << "Black wins." << endl;
                                                    foi_exibido = true;
                                                    break;
                                                } else if (pretas[i] < brancas[i]) {
                                                    cout << "White wins." << endl;
                                                    foi_exibido = true;
                                                    break;
                                                }
                                            }

                                            if (!foi_exibido) cout << "Tie." << endl;
                                        }

                                        else if (par1_blk > par1_wht) cout << "Black wins." << endl;
                                        else cout << "White wins." << endl;
                                    } else if (par1_blk != -1) {
                                        cout << "Black wins." << endl;
                                    } else if (par1_wht != -1) {
                                        cout << "White wins." << endl;
                                    } else {
                                        // high card
                                        if (mx_blk > mx_wht) cout << "Black wins." << endl;
                                        else if (mx_wht > mx_blk) cout << "White wins." << endl;
                                        else {
                                            // desempate
                                            vector<int> pretas;
                                            vector<int> brancas;

                                            for (int i = 0; i <= 12; i++) {
                                                for (int j = 0; j < dp_blk[i].size(); j++) pretas.pb(i);
                                                for (int j = 0; j < dp_wht[i].size(); j++) brancas.pb(i);
                                            }

                                            sort(all(pretas));
                                            sort(all(brancas));

                                            bool foi_exibido = false;
                                            for (int i = 4; i >= 0; i--) {
                                                if (pretas[i] > brancas[i]) {
                                                    cout << "Black wins." << endl;
                                                    foi_exibido = true;
                                                    break;
                                                } else if (pretas[i] < brancas[i]) {
                                                    cout << "White wins." << endl;
                                                    foi_exibido = true;
                                                    break;
                                                }
                                            }

                                            if (!foi_exibido) cout << "Tie." << endl;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } 
    
    return 0;
}