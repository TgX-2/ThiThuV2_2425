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

const int maxn = 20;

int n, a[maxn];

int gt[maxn];
void precal() { 
	gt[0] = 1;
	FOR(i, 1, 15)
		gt[i] = gt[i - 1] * i;
}


int f_even(int n) {
	int k = n / 2;
	k--;
	return gt[k] * (k + 1) * 2 * gt[k + 1];
}

int f_odd(int n) {
	int x = n / 2;
	int y = (n + 1) / 2;
	return gt[x] * gt[y];
}

int f_s(int n) {
	return 1 + 1 + n + n;
}


void process() {
	precal();
	cin >> n;

	int sum = 0;

	FOR(i, 1, n) {
		cin >> a[i];
		sum += f_s(a[i]);
	}

	sort(a + 1, a + 1 + n);

	if (n & 1) {
		FOR(i, 1, n / 2)
			sum -= a[i] * 4;
	} else {
		FOR(i, 1, n / 2 - 1)
			sum -= a[i] * 4;
		sum -= a[(n + 1) / 2] * 2;
	}

	cout << sum << " ";
	if (n & 1) cout << f_odd(n);
	else cout << f_even(n);
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    if (fopen("cvmax.inp", "r")) {
        freopen("cvmax.inp", "r", stdin);
        freopen("cvmax.out", "w", stdout);
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
