#include <bits/stdc++.h>
using namespace std;

void arrange(vector<int> &wt, vector<int> &val) {
    map<int, int > mp;
    
    for(int i=0;i<wt.size();i++) {
        mp.insert(pair<int, int> (wt[i], val[i]));
    }
    map<int, int > :: iterator it;
    wt.clear();
    val.clear();
    for(it=mp.begin();it!=mp.end();it++) {
        wt.push_back(it->first);
        val.push_back(it->second);
    }
}

int knapsack(int w, vector<int> wt, vector<int> val) {
    int n = wt.size();
    arrange(wt, val);
    int A[n+1][w+1];
    
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=w;j++) {
            if(i==0 || j==0)
                A[i][j] = 0;
            else if(wt[i-1]<=w)
                A[i][j] = max(A[i-1][j], val[i-1]+A[i-1][j-wt[i-1]]);
            else
                A[i][j] = A[i-1][j];
        }
    }
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=w;j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
    
    return A[n][w];
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n, W;
	    cin >> n >> W;
	    vector<int> wt(n);
	    vector<int> val(n);
	    for(int i=0;i<n;i++)
	        cin >> wt[i];
	        
	   for(int j=0;j<n;j++)
	        cin >> val[j];
	   cout << knapsack(W, wt, val) << endl;
	}
	return 0;
}

