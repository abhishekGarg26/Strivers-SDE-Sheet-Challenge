#include <bits/stdc++.h> 
using namespace std;

// Approach -1 

bool inDict(string s,vector<string> wordDict){
        for(int i=0;i<wordDict.size();i++){
            if(s==wordDict[i]){
                return true;
            }
        }
        return false;
    }
    void solve(int ind,string s, vector<string> &ans,string str,vector<string> &wordDict){
        if(ind==s.size()){
            ans.push_back(str.substr(0,str.size()-1));
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(inDict(s.substr(ind,i-ind+1),wordDict)){
                str+=s.substr(ind,i-ind+1)+" ";
                solve(i+1,s,ans,str,wordDict);
                str.erase(str.size()-(i-ind+2),i-ind+2);
            }
        }
    }
vector<string> getAllValidSentences(string &s, vector<string> &wordDict)
{
    //  write your code here.
	vector<string> ans;
     string str="";
     solve(0,s,ans,str,wordDict);
     return ans;
}


// Approach -2

bool f(int ind,int n,string str,string &s,unordered_set<string> &st,vector<string> &ans){
    if(ind==n){
        ans.push_back(str);
        return true;
    }
    for(int l=1;l<=n;l++){
        if(l<=n-ind && st.find(s.substr(ind,l))!=st.end() && f(ind+l,n,str+s.substr(ind,l)+" ",s,st,ans)){
            continue;
        }
    }
    return false;
}
vector<string> wordBreak(string &s, vector<string> &wordDict)
{
    // Write your code here
    int n = s.size();
    vector<string> ans;
    unordered_set<string> st;
    for(auto it : wordDict){
        st.insert(it);
    }
    f(0,n,"",s,st,ans);
    return ans;
    

}

// Approach -3 (Using Recursion)

/*

    Time Complexity: O(N * (2 ^ (N - 1)))
    Space Complexity: O(N* (2 ^ (N - 1))
    
    Where N is the length of the string S.

*/


vector<string> wordBreakHelper(string &s, int idx, unordered_set<string> &dictSet, int size)
{
    // Base Condition
    if (idx == size)
    {
        return {""};
    }

    vector<string> subPart, completePart;
    string word = "";

    /*
        Start exploring the sentence from the index until we wouldn't find 'j' such that substring [index,j] exists in the dictionary as a word.
    */
    for (int j = idx; j < size; j++)
    {

        word.push_back(s[j]);
        if (dictSet.count(word) == 0)
        {
            continue;
        }

        //  Get the answer for rest of sentence from 'j' to s.size().
        subPart = wordBreakHelper(s, j + 1, dictSet, size);

        //  Append "word" with all the answer that we got.
        for (int i = 0; i < subPart.size(); i++)
        {
            if (subPart[i].size() != 0)
            {
                string temp = word;
                temp.append(" ");
                temp.append(subPart[i]);
                subPart[i] = temp;
            }
            else
            {
                subPart[i] = word;
            }
        }

        for (int i = 0; i < subPart.size(); i++)
        {
            completePart.push_back(subPart[i]);
        }
    }
    return completePart;
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    //  Set to check the whether any word exists in the dictionary or not.
    unordered_set<string> dictSet;

    for (int i = 0; i < dictionary.size(); i++)
    {
        dictSet.insert(dictionary[i]);
    }
    return wordBreakHelper(s, 0, dictSet, s.size());
}

// Aproach -4 (Using DP)

/*

    Time Complexity: O(N * (2 ^ (N - 1)))
    Space Complexity: O(N* (2 ^ (N - 1)))
    
    Where N is the length of the string S.

*/



vector<string> wordBreakHelper(string &s, int idx, unordered_set<string> &dictSet, unordered_map<int, vector<string>> &dp, int size)
{
    // Base Condition
    if (idx == size)
    {
        return {""};
    }

    // Already has a solution for the current sentence, simply return the solution.
    if (dp.find(idx) != dp.end())
    {
        return dp[idx];
    }

    vector<string> subPart, completePart;
    string word = "";

    /*
        Start exploring the sentence from the index until we wouldn't find 'j' such that substring [index,j] exists in the dictionary as a word.
    */
    for (int j = idx; j < size; j++)
    {

        word.push_back(s[j]);
        if (dictSet.count(word) == 0)
        {
            continue;
        }

        // Get the answer for rest of sentence from 'j' to s.size().
        subPart = wordBreakHelper(s, j + 1, dictSet, dp, size);

        // Append "word" with all the answer that we got.
        for (int i = 0; i < subPart.size(); i++)
        {
            if (subPart[i].size() != 0)
            {
                string temp = word;
                temp.append(" ");
                temp.append(subPart[i]);
                subPart[i] = temp;
            }
            else
            {
                subPart[i] = word;
            }
        }

        for (int i = 0; i < subPart.size(); i++)
        {
            completePart.push_back(subPart[i]);
        }
    }

    // Store all the answer for the current index in the map
    dp[idx] = completePart;

    return dp[idx];
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // dp[idx] will store the all possible sentence which have been formed from the current index 'idx' to end of the given s.
    unordered_map<int, vector<string>> dp;

    //  Set to check whether any word exists in the dictionary or not.
    unordered_set<string> dictSet;

    for (int i = 0; i < dictionary.size(); i++)
    {
        dictSet.insert(dictionary[i]);
    }
    return wordBreakHelper(s, 0, dictSet, dp, s.size());
}