#include<bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int> &a, vector<int> &b, int k) {
    int n=a.size(),m=b.size();
    sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	vector<int> ans;
	set<pair<int,int>> st;
	priority_queue<pair<int,pair<int,int>>> pq;
	pq.push(make_pair(a[n-1]+b[m-1],make_pair(n-1,m-1)));
	st.insert(make_pair(n-1,m-1));
	while(k--){
		auto top=pq.top();
		pq.pop();
		ans.push_back(top.first);
		int L=top.second.first;
		int R=top.second.second;
		if(L>0 && R>0 && st.find(make_pair(L-1,R))==st.end()){
			pq.push(make_pair(a[L-1]+b[R],make_pair(L-1,R)));
			st.insert(make_pair(L-1,R));
		}
		if(L>0 && R>0 && st.find(make_pair(L,R-1))==st.end()){
			pq.push(make_pair(a[L]+b[R-1],make_pair(L,R-1)));
			st.insert(make_pair(L,R-1));
		}
	}
	return ans;
}
