/* 

    ॐ हौं जूं सः ॐ भूर्भुवः स्वः 
    ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय मामृतात् 
    ॐ स्वः भुवः भूः ॐ सः जूं हौं ॐ

   @Author  : Akshat Madhavan
   @Country : INDIA 
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define all(x) x.begin(), x.end()


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
// void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 

template<typename T> void chmin (T &a, T &b) {if (a > b) swap(a, b);}
template<typename T> void chmax (T &a, T &b) {if (a < b) swap(a, b);}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif


void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &x : a) {
        cin >> x;
    }
    for (auto &x : b) {
        cin >> x;
    }
    sort(all(a));
    sort(all(b));
    int i = 0, j = n - 1, lo = 0, hi = m - 1, ans = 0;
    while (i <= j) {
        int ilo = abs(a[i] - b[lo]);
        int ihi = abs(a[i] - b[hi]);
        int jlo = abs(a[j] - b[lo]);
        int jhi = abs(a[j] - b[hi]);

        int mx = max({ilo, ihi, jlo, jhi});
        if (ilo >= max({ihi, jlo, jhi})) {
            ++i, ++lo;
        } else if (ihi >= max({ilo, jlo, jhi})) {
            ++i, --hi;
        } else if (jlo >= max({ilo, ihi, jhi})) {
            --j, ++lo;
        } else {
            --j, --hi;
        }
        ans += max({ilo, ihi, jlo, jhi});
    }
    cout << ans << endl;
} 

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE   
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);  
    #endif  
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
        // cout << (solve() ? "Yes\n" : "No\n");
    } 

    #ifndef ONLINE_JUDGE
        double timeTaken = 1000.0 * clock() / CLOCKS_PER_SEC;
        cout << "\n[Finished in " << timeTaken << "ms]";
        cerr << "\n[Finished in " << timeTaken << "ms]";
    #endif

    return 0;
}

//JAI SHREE RAM !!!!