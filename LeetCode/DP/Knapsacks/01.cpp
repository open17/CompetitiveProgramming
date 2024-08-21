#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    bool isLocal(){
        return true;
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        // https://leetcode.cn/problems/length-of-the-longest-subsequence-that-sums-to-target/
        // 灵板
        // 恰好满足
        vector<int> f(target + 1, INT_MIN);
        f[0] = 0;
        int s = 0;
        for (int x : nums) {
            s = min(s + x, target);  // 上界小优化，s表示最大可能和（重量）
            for (int j = s; j >= x; j--) {
                f[j] = max(f[j], f[j - x] + 1);
            }
        }
        return f[target] > 0 ? f[target] : -1;
    }
    bool canPartition(vector<int>& nums) {
        // https://leetcode.cn/problems/partition-equal-subset-sum/description/
        // 是否存在
        int ss=0;
        for(auto x:nums)ss+=x;
        if(ss&1)return false;
        int target=ss/2;
        vector<int> f(target+1);
        f[0]=1;
        int s=0;
        for(auto x:nums){
            s=min(s+x,target);
            for (int j = s; j >= x; j--) {
                f[j] = max(f[j], f[j - x]);
            }
        }
        return f[target]==1;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // https://leetcode.cn/problems/target-sum/
        // 公式转换变为单向，注意p<0的非法情况
        // 恰好满足
        // a-b=target
        // a+b=sum
        // a=sum-b
        // sum-2*b=target
        // b=(sum-target)//2
        int ss=0;
        for(auto i:nums)ss+=i;
        int p=ss-target;
        if(p&1||p<0)return 0;
        target=p/2;
        vector<int> f(target+1);
        int s=0;
        f[0]=1;
        for(auto x:nums){
            s=min(s+x,target);
            for(int j=s;j>=x;j--){
                f[j]+=f[j-x];
            }
        }
        return f[target];
    }
    int numberOfWays(int n, int x) {
        // 方案数
        // https://leetcode.cn/problems/ways-to-express-an-integer-as-sum-of-powers/description/
        vector<int> f(n+1);
        int MOD=1e9+7;
        f[0]=1;
        int s=0;
        for(int i=1;pow(i,x)<=n;i++){
            int d=pow(i,x);
            s=min(s+d,n);
            for(int j=s;j>=d;j--){
                f[j]+=f[j-d]%MOD;
                f[j]%=MOD;
            }
        }
        return f[n];
    }
};