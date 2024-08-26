#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    bool isLocal(){
        return true;
    }
    int longestCommonSubsequence(string text1, string text2) {
        // https://leetcode.cn/problems/longest-common-subsequence/
        int n=text1.size(),m=text2.size();
        vector<vector<int>> f(n+1,vector<int>(m+1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(text1[i]==text2[j])f[i+1][j+1]=f[i][j]+1;
                else f[i+1][j+1]=max(f[i][j+1],f[i+1][j]);
            }
        }
        return f[n][m];
    }
    int minDistance(string text1, string text2) {
        // https://leetcode.cn/problems/delete-operation-for-two-strings/
        int n=text1.size(),m=text2.size();
        vector<vector<int>> f(n+1,vector<int>(m+1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(text1[i]==text2[j])f[i+1][j+1]=f[i][j]+1;
                else f[i+1][j+1]=max(f[i][j+1],f[i+1][j]);
            }
        }
        return n+m-f[n][m]*2;
    }
    int minimumDeleteSum(string text1, string text2) {
        // https://leetcode.cn/problems/minimum-ascii-delete-sum-for-two-strings/
        int n=text1.size(),m=text2.size();
        vector<vector<int>> f(n+1,vector<int>(m+1));
        for(int i=0;i<n;i++){
            f[i+1][0]=int(text1[i])+f[i][0];
        }
        for(int j=0;j<m;j++){
            f[0][j+1]=int(text2[j])+f[0][j];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(text1[i]==text2[j])f[i+1][j+1]=f[i][j];
                else f[i+1][j+1]=min(f[i][j+1]+int(text1[i]),f[i+1][j]+int(text2[j]));
            }
        }
        return f[n][m];
    }
    int minDistance(string text1, string text2) {
        // https://leetcode.cn/problems/edit-distance/description/
        // 编辑距离
        // 思维，思考哪些操作是等价的，如何化简情况？
        int n=text1.size(),m=text2.size();
        vector<vector<int>> f(n+1,vector<int>(m+1));
        for(int i=0;i<n;i++)f[i+1][0]=f[i][0]+1;
        for(int j=0;j<m;j++)f[0][j+1]=f[0][j]+1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(text1[i]==text2[j])f[i+1][j+1]=f[i][j];
                else{
                    f[i+1][j+1]=min(f[i][j+1]+1,f[i+1][j]+1);
                    f[i+1][j+1]=min(f[i+1][j+1],f[i][j]+1);
                } 
            }
        }
        return f[n][m];
    }
    int numDistinct(string text1, string text2) {
        // https://leetcode.cn/problems/distinct-subsequences/description/
        int MOD=1e9+7;
        int n=text1.size(),m=text2.size();
        vector<vector<int>> f(n+1,vector<int>(m+1));
        for(int i=0;i<n;i++)f[i][0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                f[i+1][j+1]=f[i][j+1];
                if(text1[i]==text2[j])f[i+1][j+1]=(f[i+1][j+1]+f[i][j])%MOD;
            }
        }
        return f[n][m];
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        // https://leetcode.cn/problems/uncrossed-lines/
        int n=nums1.size(),m=nums2.size();
        vector<vector<int>> f(n+1,vector<int>(m+1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums1[i]==nums2[j])f[i+1][j+1]=f[i][j]+1;
                else f[i+1][j+1]=max(f[i+1][j],f[i][j+1]);
            }
        }
        return f[n][m];
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        // https://leetcode.cn/problems/max-dot-product-of-two-subsequences/
        // 注意初始化细节
        int n=nums1.size(),m=nums2.size();
        vector<vector<int>> f(n+1,vector<int>(m+1,INT_MIN));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                f[i+1][j+1]=max(f[i][j],0)+nums1[i]*nums2[j];
                f[i+1][j+1]=max(f[i+1][j],f[i+1][j+1]);
                f[i+1][j+1]=max(f[i+1][j+1],f[i][j+1]);
            }
        }
        return f[n][m];
    }
};