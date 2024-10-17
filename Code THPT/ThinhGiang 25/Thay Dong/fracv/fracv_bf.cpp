// author : nhatanh_k7
	#include <bits/stdc++.h>
	 

	 
	 
	 
	using namespace std;
	 
	 
	#define task "fracv"
	#define ll long long
	#define logg(x) (63 - __builtin_clzll(x))
	 
	ll n, h;

	struct ii{
		ll fi, se;
		friend ii operator +(ii x0, ii y0){
		ii tmp;
		tmp.fi = x0.fi + y0.fi;
		tmp.se = x0.se + y0.se;
		return tmp;
	}
	friend bool operator <(ii x0, ii y0){
		return x0.fi * y0.se < x0.se * y0.fi;
	}
	friend bool operator ==(ii x0, ii y0){
		return x0.fi * y0.se == x0.se * y0.fi;
	}

	};
	ii e[500005], st1, st2;
	ll num[500005], tail[500005];
	vector<ll> List;
	bool cmp(ll a,ll b){
		return num[a] < num[b];
	}
	void solve(ii s,ll pos,ii x0, ii y0,ll r){
		assert((logg(pos) + 1) <= h);
			if (s == e[r]){
			num[r] = pos;
			return;
		}
		ii cur1 = s + x0;
		ii cur2 = s + y0;
		if (e[r] < s){

			solve(cur1, pos * 2, x0, s, r);
		}
		else{
			solve(cur2, pos * 2 + 1, s, y0, r);
		}
	}
	int main()
	{
	    ios_base::sync_with_stdio(0);
	    cin.tie(0); cout.tie(0);
	   //   freopen(task".inp","r",stdin);
	   //   freopen(task".out","w",stdout);
	 
	    
	 	cin >> h >> n;
	 	st1 = {0, 1};
	 	st2 = {1, 0};

	 	for (int i = 1;i <= n;++i){
	 		cin >> e[i].fi >> e[i].se;
	 		solve({1, 1}, 1, st1, st2, i);
	 		List.push_back(num[i]);
		}
		List.push_back(1);
		deque<ll> st;
		sort(List.begin(), List.end());
		ll res = 0;


		while (List.size() + st.size() > 1){
			
			
		while (List.size() >= 2 && List[List.size() - 1]
			 == List[List.size() - 2])
			List.pop_back();
		ll h = List[List.size() - 1];
		List.pop_back();
			h /= 2;
			++res;
			st.push_back(h);


			while (st.size() >= 2){
				ll h = st.front();
				st.pop_front();
				if (h != st.front()){
					st.push_front(h);
					break;
				}
			}
			while(st.size() && (st.front() >= 
				List[List.size() - 1]
				|| List.size() == 0))
			{
				List.push_back(st.front());
				st.pop_front();
			}
			while (List.size() >= 2 && List[List.size() - 1] == 
				List[List.size() - 2])
			List.pop_back();
		}
		cout << res;
		
		
	   
	 
	 
	 
	 
	 
	    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
	   return 0;
	}