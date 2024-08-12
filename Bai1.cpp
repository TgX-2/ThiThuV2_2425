/*-----------------------------
        Author : TgX.2
       11Ti - K28 - CHV
-----------------------------*/

#include <bits/stdc++.h>

#define FOR(i, a, b)       for (int i = (a), _b = (b); i <= _b; i += 1)
#define FORD(i, a, b)      for (int i = (a), _b = (b); i >= _b; i -= 1)
#define FORC(i, a, b, c)   for (int i = (a), _b = (b), _c = (c); i <= _b; i += _c)

#define fi                 first
#define se                 second
#define pb                 push_back
#define len(x)             (int)((x).size())
#define all(x)             (x).begin(), (x).end()

#define _                  << " " <<
#define __                 << "\n"
#define ___                << " "

#define ______________TgX______________ main()
#define int                long long
#define intmax             1e9
#define intmin            -1e9
#define llongmax           1e18
#define llongmin          -1e18
#define memo(a, val)       memset((a), (val), sizeof((a)))

using   namespace std;
typedef long long          ll;
typedef pair<int, int>     pii;

template<typename T1, typename T2> 
bool mini(T1 &a, T2 b)
    {if (a > b) a = b; else return 0; return 1;}

template<typename T1, typename T2> 
bool maxi(T1 &a, T2 b)
    {if (a < b) a = b; else return 0; return 1;}
    
/*-----------------------------*/

const int maxn = 1e5 + 7;
const int loga = 23;
int n, k, a[maxn];
int arr[loga][maxn];

void build() {
    memcpy(arr[0], a, maxn * sizeof(int));
    for(int j = 1; (1 << j) <= n; j++)
        for(int i = 1; i + (1 << j) - 1 <= n; i++)
            arr[j][i] = __gcd(arr[j - 1][i], arr[j - 1][i + (1 << (j - 1))]);
}

int get(int l, int r) { 
    int k = __lg(r - l + 1);
    return __gcd(arr[k][l], arr[k][r - (1 << k) + 1]);
}

void process() {
	cin >> n >> k;
	FOR(i, 1, n) cin >> a[i];

	build();
	int ans = 0;
	FOR(i, 1, n - k + 1)
		maxi(ans, get(i, i + k - 1));
	cout << ans;
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    if (fopen("gcd.inp", "r")) {
        freopen("gcd.inp", "r", stdin);
        freopen("gcd.out", "w", stdout);
    }
    process();
}


/*==============================+
|INPUT                          |
--------------------------------|

================================+
|OUTPUT                         |
--------------------------------|

===============================*/
