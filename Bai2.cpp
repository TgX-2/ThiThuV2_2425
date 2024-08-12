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

const int maxn = 1e6 + 7;
int n, k, rr;
int a[maxn], b[maxn];

namespace sub1 {
	int bs1(int u, int v, int pos) {
		int l = u, r = v, ans = pos;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if (abs(a[pos] - a[mid]) <= rr) {
				r = mid - 1;
				ans = mid;
			} else l = mid + 1;
		}
		return ans;
	}

	int bs2(int u, int v, int pos) {
		int l = u, r = v, ans = pos;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if (abs(a[pos] - a[mid]) <= rr) {
				l = mid + 1;
				ans = mid;
			} else r = mid - 1;
		}
		return ans;
	}

	void sol() {
		FOR(i, 2, n) {
			int x; cin >> x;
			a[i] = a[i - 1] + x;
		}
		FOR(i, 1, n) {
			int x; cin >> x;
			b[i] = b[i - 1] + x;
		}

		int ans = 0;
		FOR(i, 1, n) {
			int l = bs1(1, i , i);
			int r = bs2(i, n, i);
			maxi(ans, b[r] - b[l -1]);
		}

		cout << ans;
	}
};

namespace sub2 {
	bool vis[10007];

	int dq(int id, int cnt, int s) {
		// cout << id _ cnt _ s  __ ;
		if (id > n or cnt > k) return s;

		if (vis[id])
			return dq(id + 1, cnt, s);

		int sum = 0;
		if (!vis[id]) {
			sum = b[id];
			vis[id] = 1;
		}

		int l = abs(a[id] - a[id - 1]);
		FORD(i, id - 1, 1) {
			if (l > rr) break;
			l += abs(a[i] - a[i - 1]);
			if (!vis[i]) {
				sum += b[i];
				vis[i] = 1;
			}
		}

		l = abs(a[id] - a[id + 1]);
		FOR(i, id + 1, n) {
			if (l > rr) break;
			l += abs(a[i] - a[i + 1]);
			if (!vis[i]) {
				sum += b[i];
				vis[i] = 1;
			} 
		}

		return dq(id + 1, cnt + 1, s + sum);
	}


	void sol() {
		FOR(i, 2, n) {
			int x; cin >> x;
			a[i] = a[i - 1] + x;
		}
		FOR(i, 1, n) cin >> b[i];

		int ans = 0;

		FOR(i, 1, n - k + 1) {
			memo(vis, 0);
			maxi(ans, dq(i, 1, 0));
		}

		cout << ans;
	} 
};

void process() {
	cin >> n >> k >> rr;

	if (k == 1) sub1::sol();
	else sub2::sol();
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    if (fopen("space.inp", "r")) {
        freopen("space.inp", "r", stdin);
        freopen("space.out", "w", stdout);
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
