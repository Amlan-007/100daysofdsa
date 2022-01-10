#include <bits/stdc++.h>
using namespace std;

bool isMatch(string s, string p){
    int n = s.size(), m = p.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;
    for(int i=1; i<n; i++){
        if(char *p[i-1]=="*"){
            dp[0][i]=dp[0][i-2];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(p[j - 1] == '*'){
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            }
            else if(p[j - 1] == '.' || s[i - 1] == p[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }
    return dp[n][m];
}

int main(){
    string s = "aab";
    string p = "c*a*b";
    cout << isMatch(s, p) << endl;
    return 0;
}