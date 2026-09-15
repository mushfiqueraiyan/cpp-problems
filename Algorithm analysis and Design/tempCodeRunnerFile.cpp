#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void LCS(const  string& s1, const string& s2){
    int m = s1.length();
    int n = s2.length();

    vector<vector<int>> dp(m+1, vector<int>(n+1,0));

    for(int i = 1; i<= m ; i++){
        for(int j = 1; j <= n;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j-1]);
            }
        }
    }

    // Backtrack to find the LCS string 
    int i = m;
    int j = n;
    string lcs = "";

    while(i >0 && j > 0){
        if(s1[i - 1] == s2[j-1]){
            lcs.push_back(s1[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else {
            j--;
        }
    }

    reverse(lcs.begin(),lcs.end());

    cout << "Length of LCS: " << dp[m][n] <<endl;
    cout << "LCS String: " << lcs << endl;

}

int main(){

    string s1 = "Helloworld";
    string s2 = "Helloworlds";

    LCS(s1, s2);

    return 0;
}