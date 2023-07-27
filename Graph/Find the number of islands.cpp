//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    // Approach -1 (Using BFS)
    void bfs(int i,int j,vector<vector<int>> &vis,vector<vector<char>> &grid){
        vis[i][j]=1;
        queue<pair<int,int>> q;
        q.push({i,j});
        int m=grid.size();
        int n=grid[0].size();
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            // can also iterate in 8 dir using two loops running from -1 to 1 
            // cuz values of row & col are ranging in this range only
            // for(int delRow=-1;delRow<=1;delRow++){
            //     for(int delCol=-1;delCol<=1;delCol++){
            int delRow[]={-1,0,1,0,-1,1,1,-1};
            int delCol[]={0,1,0,-1,1,1,-1,-1};
            for(int it=0;it<8;it++){
                    int newRow=row+delRow[it];
                    int newCol=col+delCol[it];
                    if(newRow>=0 && newRow<m && newCol>=0 && newCol<n && !vis[newRow][newCol] && grid[newRow][newCol]=='1'){
                        vis[newRow][newCol]=1;
                        q.push({newRow,newCol});
                }
            }
        }
    }
    // Approach-2 (Using DFS)
    void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<char>> &grid,int tRow,int tCol){
        vis[i][j]=1;
        int delRow[]={-1,0,1,0,-1,1,1,-1};
        int delCol[]={0,1,0,-1,1,1,-1,-1};
        for(int it=0;it<8;it++){
            int newRow=i+delRow[it];
            int newCol=j+delCol[it];
            if(newRow>=0 && newRow<tRow && newCol>=0 && newCol<tCol && !vis[newRow][newCol] && grid[newRow][newCol]=='1'){
                vis[newRow][newCol]=1;
                dfs(newRow,newCol,vis,grid,tRow,tCol);
            }
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,vis,grid);
                    // dfs(i,j,vis,grid,m,n);
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends