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
            // 上界小优化，s表示最大可能和（重量
            // 不过转移最值时可能有个注意事项（详见lastStoneWeightII）
            s = min(s + x, target);
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
    int findMaxForm(vector<string>& strs, int m, int n) {
        // https://leetcode.cn/problems/ones-and-zeroes/
        // 二维01背包（二维费用背包）
        int len=strs.size();
        vector<pair<int,int>> w;
        for(auto s:strs){
            int a=0,b=0;
            for(auto c:s){
                if(c=='1'){
                    b++;
                }
                else{
                    a++;
                }
            }
            w.push_back({a,b});
        }
        int s1=0,s2=0;
        int ans=0;
        vector<vector<int>> f(m+1,vector<int>(n+1));
        for(auto p:w){
            int a=p.first,b=p.second;
            s1=min(s1+a,m);
            s2=min(s2+b,n);
            for(int i=s1;i>=a;i--){
                for(int j=s2;j>=b;j--){
                    f[i][j]=max(f[i][j],f[i-a][j-b]+1);
                    ans=max(ans,f[i][j]);
                }
            }
        }
        return ans;
    }
    int lastStoneWeightII(vector<int>& stones) {
        // https://leetcode.cn/problems/last-stone-weight-ii/
        // 思维+维护最大值
        // 要注意的是上界优化后不会复制最优值到target，需要维护ans最值
        
        // 因为无论如何最多只会剩下一个石头，所以我们可视为有两堆石头，一堆用于+，一堆用于-
        // 设为a和b，显然我们想让a-b最小，则有ans=a-b;sum=a+b(此时与numberOfWays很相似了)
        // 那么则有ans=sum-2*b,然后求b最大即可
        int ss=0;
        for(auto i:stones)ss+=i;
        int target=ss/2;
        int s=0;
        vector<int> f(target+1);
        int ans=0;
        for(auto w:stones){
            s=min(s+w,target);
            for(int j=s;j>=w;j--){
                f[j]=max(f[j],f[j-w]+w);
                ans=max(ans,f[j]);
            }
        }
        return ss-ans*2;
    }
};