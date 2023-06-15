#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> generateRows(int numRows){
        vector<int> ans;
        int value=1;
        ans.push_back(1);
        for(int i=1;i<numRows;i++){
            value*=(numRows-i);
            value/=i;
            ans.push_back(value);
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> matrix;
        for(int i=1;i<=numRows;i++){
            matrix.push_back(generateRows(i));
        }
        
        return matrix;        
    }
};