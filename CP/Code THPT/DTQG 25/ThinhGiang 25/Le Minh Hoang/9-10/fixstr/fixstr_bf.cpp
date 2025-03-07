// author : nhatanh_k7
#include <bits/stdc++.h>
 

 
 
 
using namespace std;
 
 
#define task "fixstr"
#define ll int
 
 
 
 
string s;
ll q;
struct query{
	char op;
	ll l, r;
}e[1000005];
ll res[1000005];

vector<int> ke[1000005];
struct Node {
    int open;
    int close;
    friend bool operator == (const Node& left, const Node& right) {
    	return (left.open == right.open);
    }
 friend Node operator + (const Node& left, const Node& right) {
    Node res;
   
    int tmp = min(left.open, right.close);

    

    res.open = left.open + right.open - tmp;
    res.close = left.close + right.close - tmp;

    return res;
}
}st[4000005], z;
struct segtre{
	
void build(int id, int l, int r) {
    if (l == r) {
        if (s[l] == '(') st[id] = {1, 0};
        else st[id] = {0, 1};
        return ;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid+1, r);

    st[id] = st[id << 1] + st[id << 1 | 1];
}
void update(int id, int l, int r,int u) {
	if (l > u || r < u) return;
    if (l == r) {
    	Node m = {1, 0};
        if (st[id] == m)
       st[id] = {0, 1};
   		else
   			st[id] = {1, 0};
        return ;
    }
    int mid = (l + r) >> 1;
   	update(id << 1, l, mid, u);
    update(id << 1 | 1, mid+1, r, u);

    st[id] = st[id << 1] + st[id << 1 | 1];
}
Node query(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        return z;
    }
    if (u <= l && r <= v) {
        return st[id];
    }

    int mid = (l + r) >> 1;
    return query(id << 1, l, mid, u, v) + query(id << 1 | 1, mid+1, r, u, v);
}
}it;
void dfs(ll u){
	if (e[u].op == 'C'){
		it.update(1, 0, s.size() - 1, e[u].l - 1);
	}	

	if (e[u].op == 'Q'){
		Node h = it.query(1, 0, s.size() - 1, e[u].l - 1, e[u].r - 1);
		res[u] = h.open + h.close;
	}

	for (ll x : ke[u]){
		dfs(x);
	}
	if (e[u].op == 'C'){
		it.update(1, 0, s.size() - 1, e[u].l - 1);
	}	
}
 
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
      freopen(task".inp","r",stdin);
      freopen(task".ans","w",stdout);
 
    
 
   	cin >> s;
   	cin >> q;
   	for (int i = 1;i <= q;++i){
   		cin >> e[i].op >> e[i].l;
   		if (e[i].op == 'Q')
   			cin >> e[i].r;
   		if (e[i].op == 'U'){
   			ke[e[i].l - 1].push_back(i);
   		}
   		else
   			ke[i - 1].push_back(i);
  	
   	}

   	it.build(1, 0, s.size() - 1);
 	dfs(0);
 	for (int i = 1;i <= q;++i){
 		if (e[i].op == 'Q'){
 			cout << res[i] << '\n';
 		}
 	}
 
 
 
    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
   return 0;
}