#include <iostream>
#include <string>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();

    bool can_increase = false; 
    bool can_decrease = false; 

    //string can be compressed by merging 000s to 0 and 111s to 1. adjacent indices checked, if same, flipping increases. ist and last cant be changed condition stays true since middle ones always flipped
    for (int i = 1; i < n - 1; i++) {
        if (s[i - 1] == s[i] && s[i] == s[i + 1]) {
            can_increase = true;
        }
        //if adjacent different, then flipping middle one, merging can be done
        if (s[i - 1] != s[i] && s[i] != s[i + 1]) {
            can_decrease = true;
        }
    }
    //for each case of being able to merge or expand, since only 1 operation can be done, for each case possible string num increase
    int ans = 1; 
    if (can_increase) ans++;
    if (can_decrease) ans++;

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}