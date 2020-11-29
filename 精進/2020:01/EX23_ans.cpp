#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"
#if defined(_MSC_VER) || defined(ONLINE_JUDGE)
#define getchar_unlocked _getchar_nolock
#define putchar_unlocked _putchar_nolock
#endif
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define FOR(i, m, n) for(int i=(m); i<(n); ++i)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define dump(x) cerr << #x << " = " << (x) << endl;
using LL=long long;
using VS=vector<string>;   using VD=vector<double>;
using VI=vector<int>;      using VL=vector<LL>;
using VVI=vector<VI>;      using VVL=vector<VL>;
using PII=pair<int, int>;  using PLL=pair<LL, LL>;
const int inf = (int)1e9;  const double pi = acos(-1.0);
const LL MOD = 1000000007; const string Snum = "0123456789";
const int dx[] = { -1,0,1,0,-1,-1,1,1 }, dy[] = { 0,1,0,-1,-1,1,-1,1 };
template<class T>void Sort(T& a) { sort(a.begin(), a.end()); }
template<class T>void ReSort(T& a) { sort(a.rbegin(), a.rend()); }
template<class T>void Reverse(T& a) { reverse(a.begin(), a.end()); }
template<class T>void Unique(T& a) { a.erase(unique(a.begin(), a.end()), a.end()); }
template<class T>auto Max(const T& a) { return *max_element(a.begin(), a.end()); }
template<class T>auto Min(const T& a) { return *min_element(a.begin(), a.end()); }
template<class T, class U>int Count(const T& a, U c) { return count(a.begin(), a.end(), c); }
template<class T, class U>U Sum(const T& a, U init = 0) { return accumulate(a.begin(), a.end(), init); }
template<class T, class U>int Lower(const T& a, U s) { return lower_bound(a.begin(), a.end(), s) - a.begin(); }
template<class T, class U>int Upper(const T& a, U s) { return upper_bound(a.begin(), a.end(), s) - a.begin(); }
template<class T>T Age(T a, T b) { return (a + b - 1) / b; }
template<class T>T Gcd(T n, T m) { return m == 0 ? n : Gcd(m, n % m); }
template<class T>T Lcm(T n, T m) { return n / Gcd(n, m) * m; }

/* INPUT */
template<class T>T GetInput() { return 0; }
template<> char GetInput() {
	char ret = '\0', c = getchar_unlocked();
	while (c != '\0' && c != '\n' && c != '\t' && c != ' ') { ret = c; c = getchar_unlocked(); }
	return ret;
}
template<> string GetInput() {
	string ret; char c = getchar_unlocked();
	while (c != '\0' && c != '\n' && c != '\t' && c != ' ') { ret.push_back(c); c = getchar_unlocked(); }
	return ret;
}
template<> int GetInput() {
	int ret = 0; bool neg = false; char c = getchar_unlocked();
	if (c == '-') { neg = true; c = getchar_unlocked(); }
	while ('0' <= c && c <= '9') { ret = ret * 10 + (c - '0'); c = getchar_unlocked(); }
	return neg ? -ret : ret;
}
template<> LL GetInput() {
	LL ret = 0; bool neg = false; char c = getchar_unlocked();
	if (c == '-') { neg = true; c = getchar_unlocked(); }
	while ('0' <= c && c <= '9') { ret = ret * 10LL + (LL(c) - LL('0')); c = getchar_unlocked(); }
	return neg ? -ret : ret;
}
template<> double GetInput() {
	double ret = 0, dp = 1; bool neg = false, adp = false; char c = getchar_unlocked();
	if (c == '-') { neg = true; c = getchar_unlocked(); }
	while (('0' <= c && c <= '9') || c == '.') {
		if (c == '.') { adp = true; }
		else if (adp) { dp *= 0.1; ret += (c - '0') * dp; }
		else { ret = ret * 10.0 + (c - '0'); }
		c = getchar_unlocked();
	}
	return neg ? -ret : ret;
}

template<class T>T StoT(string s) { return s; }
template<> char StoT(string s) { return s.front(); }
template<> string StoT(string s) { return s; }
template<> int StoT(string s) { return stoi(s); }
template<> LL StoT(string s) { return stoll(s); }
template<> double StoT(string s) { return stod(s); }

string GetLine() {
	string ret; char c = getchar_unlocked();
	while (c != '\0' && c != '\n') { ret.push_back(c); c = getchar_unlocked(); }
	return ret;
}

VS InputBuffer;
template<class T>struct Input {
	operator T() {
		return GetInput<T>();
	}
	vector<T> operator[](int n) {
		vector<T> ret(n);
		for (auto& a : ret)a = GetInput<T>();
		return ret;
	}
	vector<vector<T>> operator[](PII p) {
		int n, m; tie(n, m) = p;
		vector<vector<T>> ret(n, vector<T>(m));
		for (auto& a : ret)for (auto& b : a)b = GetInput<T>();
		return ret;
	}
	T at(int n) {
		while ((int)InputBuffer.size() <= n)InputBuffer.pb(GetInput<string>());
		return StoT<T>(InputBuffer[n]);
	}
	vector<T> at(int n, int h) {
		vector<T> ret(h);
		rep(i, n)ret[i] = Input::at(i + n);
		return ret;
	}
	vector<vector<T>> at(int n, int h, int w) {
		vector<vector<T>> ret(h, vector<T>(w));
		rep(i, h)rep(j, w)ret[i][j] = Input::at(n + i * w + j);
		return ret;
	}
};
Input<char> inc; Input<string> ins; Input<int> ini; Input<LL> inl; Input<double> ind;

/* ANSWER */
struct Answer {
	int mini = INT_MAX, maxi = INT_MIN, sumi = 0;
	LL minl = LLONG_MAX, maxl = LLONG_MIN, suml = 0LL;
	double mind = DBL_MAX, maxd = DBL_MIN, sumd = 0.;
	bool flag = false, flagt = true, lastb = false; int sumb = 0;
	int count = 0;
	void operator =(int n) { mini = min(mini, n); maxi = max(maxi, n); sumi += n; count++; }
	void operator =(LL n) { minl = min(minl, n); maxl = max(maxl, n); suml += n; count++; }
	void operator =(double n) { mind = min(mind, n); maxd = max(maxd, n); sumd += n; count++; }
	void operator =(bool n) { flag = flag | n; flagt = n ? flagt : false; lastb = n;  sumb += n; count++; }
}ans;


int main() {
	int n = ini;
	VI a = ini[n];

	map<int, int> ma;
	rep(i, n) {
		ma[a[i]]++;
	}

	int N, M = 0;
	for (auto p : ma) {
		if (M < p.second) { M = p.second; N = p.first; }
	}
	cout << N << " " << M << endl;
}
