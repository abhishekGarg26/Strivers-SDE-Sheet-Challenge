#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(15, vector<int>(1, 0));

void preComp()
{
    for(int i=0; 1; i++)
    {
        int cur = dp[3][i] + (i*(i+1))/2 + 1;
        dp[3].push_back(cur);
        if(cur > 10000)
        {
            break;
        }
    }
	
    for(int i=4; i <= 14; i++)
    {
        for(int j=0; 1; j++)
        {
            int cur = dp[i][j] + dp[i-1][j] + 1;
            dp[i].push_back(cur);
			
            if(cur > 10000)
            {
                break;
            }
        }
    }
}

int cutLogs(int k, int n)
{	
    if(k == 1)
    {
        return n;
    }
	    if(k == 2)
    {
        return ceil((-1.0 + sqrt(1 + 8 * n)) / 2.0);
    }

    if(dp[3].size() == 1)
    {
        preComp();
    }
	
    k = min(k, 14);
	
    int ans = lower_bound(dp[k].begin(), dp[k].end(), n) - dp[k].begin();
    return ans;
}

