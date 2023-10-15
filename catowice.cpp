
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfenv>
#include <cfloat>
#include <chrono>
#include <cinttypes>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <immintrin.h>
#include <initializer_list>
#include <iomanip>
#include <ios>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <streambuf>
#include <string>
#include <tuple>
#include <type_traits>
#include <variant>
using namespace std;

//numbers
using ll=long long;
#define int ll
using ld=long double;
//pairs
#define P pair
#define pi P<int,int>
#define ff first
#define ss second
#define mp make_pair
//std data structure
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
//vectors
#define V vector
#define vi V<int>
#define v2i V<vi>
#define v3i V<v2i>
#define vpi V<pi>
#define vsi V<si>
#define vb V<bool>
#define pb push_back
//sets
#define S set
#define MS multiset
#define US unordered_set
#define si S<int>
#define msi MS<int>
#define usi US<int>
#define ins insert
#define era erase
//maps
#define M map
#define UM unordered_map
#define mii M<int,int>
#define mivi UM<int,vi>
#define misi UM<int,si>
#define umii UM<int,int>
#define umivi UM<int,vi>
#define umisi UM<int,si>
//queues
#define Q queue
#define PQ priority_queue
#define qi Q<int>
#define qpi Q<pi>
#define pqi PQ<int>
#define rpqi PQ<int,vi,greater<int> >
#define pqpi PQ<pi>
#define rpqpi PQ<pi,vpi,greater<pi> >
//constants
const int MOD=998244353;
const int INF=922337203685477580;

struct strongly {
	int n; v2i adj; v2i radj;
	vb vis; vi ord; v2i scc;
	vi ccin; vsi cadj;
	strongly(v2i ad) {
		adj=ad; n=sz(ad); radj=v2i(n); scc=v2i(1); ccin=vi(n);
		for (int i=0; i<n; i++) {for (auto j:adj[i]) radj[j].pb(i);}
		vis=vb(n,0); for (int i=0; i<n; i++) {dfs(i);}
		vis=vb(n,0); for (int i=0; i<n; i++) {
		if (sz(scc[sz(scc)-1])>0) {vi v; scc.pb(v);}
		dfs(ord[n-i-1]);}
		if (sz(scc[sz(scc)-1])==0) scc.pop_back();
		for (int i=0; i<sz(scc); i++) {
			for (auto j:scc[i]) {ccin[j]=i;}}
		cadj=vsi(sz(scc));
		for (auto i:ccin) cout<<i<<" ";
		cout<<endl;
		cout<<117<<endl;
		for (int i=0; i<n; i++) {
			for (auto j:adj[i]) {
				if (ccin[i]!=ccin[j]) cadj[ccin[i]].ins(ccin[j]);
			}
		}
	}
	void dfs(int p) {
		if (vis[p]) {return;} vis[p]=1;
		for (auto i:adj[p]) {dfs(i);} ord.pb(p);}
	void rdfs(int p) {
		if (vis[p]) {return;} vis[p]=1;
		scc[sz(scc)-1].pb(p); for (auto i:radj[p]) {rdfs(i);}}
	v2i cc() {return scc;}
	vi in() {return ccin;}
	vsi cdj() {return cadj;}
};

void solve() {
	int n,m; cin>>n>>m;
	v2i adj(n);
	while (m--) {
		int a,b; cin>>a>>b; a--; b--;
		adj[a].pb(b);
	}
	strongly ss(adj);
	v2i cc=ss.cc();
	if (sz(cc)==1) {
		cout<<"No\n";
	} else {
		cout<<"Yes\n";
		vi a=cc[0]; si b;
		cout<<sz(a)<<" "<<n-sz(a)<<"\n";
		for (auto i:a) {cout<<i+1<<" "; b.ins(i);}
		cout<<"\n";
		for (int i=0; i<n; i++) {
			if (!b.count(i)) cout<<i+1<<" ";
		}
		cout<<"\n";
	}
	cout<<endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin>>t;
	while (t--) solve();
	return 0;
}