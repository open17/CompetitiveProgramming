/**
 * @title: ..
 * @desc: ..
 * @tag: IO
 * @url:
 */

#include <bits/stdc++.h>

/*
 *
 *   宏定义模板常量:
 *
 *          使用STD
 *          重复数据读入
 *          int强制转ll
 *          重载工具函数
 *          启用debug输出
 *          关闭输入同步流
 *          使用文件输入流
 *          使用文件输出流
 *
 */

// 常开
#define USE_STD
#define USE_TOOL

// 可能关闭
#define USE_LL
// #define REAP_READ
#define USE_PD

// 基本关闭
// #define USE_DEBUG
// #define USE_IOS
// #define IN_FILE "data.in"
// #define OUT_FILE "solve.out"

#ifdef USE_PD
#include <ext/pb_ds/assoc_container.hpp> //容器库
#include <ext/pb_ds/tree_policy.hpp>     //各种树
#include <ext/pb_ds/hash_policy.hpp>     //哈希表
using namespace __gnu_pbds;
#endif

#ifdef USE_STD
using namespace std;
#endif

#ifdef USE_LL
#define int long long
#endif

// 辅助宏
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define _rep(i, l, r) for (int i = (l); i >= (r); i--)
#define all(x) (x).begin(), x.end()
#define endl '\n' // 避免刷新缓冲区
#define inf32 0x3f3f3f3f
#define inf64 1LL << 60
#define max32 INT_MAX

// 类型别名
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using pii = std::pair<int, int>;

// 常规输出
template <typename T>
void print(const T &t) { std::cout << t << endl; }
template <typename T, typename... Args>
void print(const T &t, const Args... args)
{
    std::cout << t << ' ';
    print(args...);
}

// USE_DEBUG 模式下的输出
template <typename T>
void debug(const T &t)
{
#ifdef USE_DEBUG
    std::cout << t << "\n\n";
#endif
}
template <typename T, typename... Args>
void debug(const T &t, const Args... args)
{
#ifdef USE_DEBUG
    std::cout << t << ' ';
    debug(args...);
#endif
}

#ifdef USE_TOOL
i64 ceilDiv(i64 n, i64 m)
{
    if (n >= 0)
    {
        return (n + m - 1) / m;
    }
    else
    {
        return n / m;
    }
}

i64 floorDiv(i64 n, i64 m)
{
    if (n >= 0)
    {
        return n / m;
    }
    else
    {
        return (n - m + 1) / m;
    }
}

template <class T>
void chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
    }
}

template <class T>
void chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
    }
}

template <class T>
T gcd(T a, T b)
{
    return b ? gcd(b, a % b) : a;
}
#endif

// 快读快写
int read();
void write(int);

const int N = 5e5 + 5;
const int MOD = 1e9 + 7;

void solve()
{

    tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> p;
    int n = read(), mm = read();
    int px = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        string opt;
        cin >> opt;
        int x = read();
        if (opt == "I")
        {
            if (x >= mm)
                p.insert(x - px);
        }
        if (opt == "A")
        {
            px += x;
        }
        if (opt == "S")
        {
            px -= x;
            vector<int> idx;
            auto i = p.upper_bound(mm - px);
            while (i != p.begin())
            {
                p.erase(--i);
                i = p.upper_bound(mm - px);
                ans++;
            }
        }
        if (opt == "F")
        {
            int tarIdx = p.size() - x;
            if (tarIdx < 0)
                print(-1);
            else
                print(*(p.find_by_order(tarIdx)) + px);
        }
    }
    print(ans);
}

signed main()
{
    int T = 1;
    debug("hello world");
#ifdef IN_FILE
    freopen(IN_FILE, "r", stdin);
#endif

#ifdef OUT_FILE
    freopen(OUT_FILE, "w", stdout);
#endif

#ifdef REAP_READ
    std::cin >> T;
#endif

#ifdef USE_IOS
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
#endif

    while (T--)
    {
        solve();
    }
    return 0;
}

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
inline void write(int x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}