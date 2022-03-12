class Solution {
public:
    
    int dp[1005][1005];
    int LCS(string &s1, string &s2, int i, int j){
        if(i==s1.size() or j==s2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s1[i]==s2[j]) return dp[i][j] = 1+LCS(s1,s2,i+1,j+1);
        else return dp[i][j] = max(LCS(s1,s2,i+1,j),LCS(s1,s2,i,j+1));
    }
    
    int minDistance(string word1, string word2) {
        
          int i=0,j=0;
        memset(dp,-1,sizeof(dp));
        return word1.size()+word2.size()-2*LCS(word1,word2,i,j);
    }
};