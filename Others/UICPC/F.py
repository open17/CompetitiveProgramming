import sys
from math import ceil,floor,fmod,gcd,sqrt,inf
from bisect import bisect_left
from collections import defaultdict,Counter,deque
from functools import lru_cache, reduce, cmp_to_key
from itertools import accumulate, combinations, permutations
from heapq import nsmallest, nlargest, heappushpop, heapify, heappop, heappush
from copy import deepcopy

limits = [100000, 10000, 5000, 2000]
for limit in limits:
    try:
        sys.setrecursionlimit(limit)
        break
    except:
        continue 

input = lambda: sys.stdin.readline().rstrip("\r\n")

def I():
    return input()
 
def II():
    return int(input())
 
def MII():
    return map(int, input().split())
 
def LI():
    return list(input().split())
 
def LII():
    return list(map(int, input().split()))

s=I()
k=II()

@lru_cache(maxsize=None)
def f(i,l,r):
    global k
    if i>=len(s):
        return 0
    ans=f(i+1,l,i)
    if i>r and s[i]=="f" and s[r]=="o":
        for j in range(k+1):
            if i+j+1>len(s): break
            if r-1>=l:
                ans=max(ans,f(i+j+1,l,r-1)+2+j)
            else:
                ans=max(ans,f(i+j+1,i+j+1,i+j+1)+2+j)
        # print(1,i,l,r,ans)
    if i>r and r-l+1>=2 and s[r]=="f" and s[r-1]=="o":
        for j in range(k+1):
            if i+j>len(s): break
            if r-2>=l:
                ans=max(ans,f(i+j,l,r-2)+2+j)
            else:
                ans=max(ans,f(i+j,i+j,i+j)+2+j)
        # print(2,i,l,r,ans)
    return ans

print(len(s),f(0,0,0))



















































# # @lru_cache(maxsize=None)
# # def f(i,lst,lft):
# #     global k
# #     if i>=len(s):
# #         return 0
# #     if lst==-1:
# #         lft=i
# #     ans=f(i+1,i,lft)
# #     if s[i]=="f" and lst>=lft and lst>=0 and s[lst]=="o":
# #         new_lst=lst-1
# #         new_lft=lft
# #         for j in range(k+1):
# #             if i+j+1>len(s):
# #                 break
# #             if new_lst<lft:
# #                 new_lft=i+j+1
# #                 new_lst=-1
# #             ans=max(ans,f(i+j+1,new_lst,new_lft)+2+j)
# #         # print(111,i,lst,lft,ans)
# #     if lst>=1 and lst-1>=lft and s[lst]=="f" and s[lst-1]=="o":
# #         new_lst=lst-2
# #         new_lft=lft
# #         for j in range(k+1):
# #             if i+j>len(s):
# #                 break
# #             if new_lst<lft:
# #                 new_lft=i+j
# #                 new_lst=-1
# #             ans=max(ans,f(i+j,new_lst,new_lft)+2+j)
# #         # print(222,i,lst,lft,ans)
# #     return ans
# # print(len(s)-f(1,0,0))


