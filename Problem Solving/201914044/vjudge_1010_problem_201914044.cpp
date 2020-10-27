/*
auther : Abdullah Al Masum
MIST_roll : 201914044
problem Link : https://vjudge.net/problem/LightOJ-1010
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
    ll row, col, test, t = 1;

    cin>>test;

    while (test--) {
        cin>>row>>col;

        cout << "Case " << t++ << ": " ;

        ll ans = row * col;

        if(row == 1 || col == 1) {
            cout << max(row, col) << endl;
        } else if(row == 2 || col == 2) {
            ll largerBox = max(row, col);
            ans = largerBox;
            if(largerBox % 4 == 1 || largerBox % 4 == 3) {
                ans++;
            }
            if(largerBox % 4 == 2 ) {
                ans+=2;
            }
            cout << ans << endl;
        } else if(ans %2 == 1) {
            cout << ans/2 + 1 << endl;
        } else
            cout << ans/2 << endl;
    }
}
