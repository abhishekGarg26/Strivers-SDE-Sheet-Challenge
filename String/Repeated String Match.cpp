#include <bits/stdc++.h> 
using namespace std;

// Approach-1
class Solution {
public:
    int check(string a,string b){
        int n=a.size();
        int m=b.size();
        for(int i=0;i<=n-m;i++){
            int j;
            for(j=0;j<m;j++){
                if(a[j+i]!=b[j]) break;
            }
            if(j==m) return 1;
        }
        return 0;
    }
    int repeatedStringMatch(string a, string b) {
        string tmp=a;
        int ans=1;
        while(a.size()<b.size()){
            a+=tmp;
            ans+=1;
        }
        if(check(a,b)) return ans;
        if(check(a+tmp,b)) return ans+1;
        return -1;
    }
};

// Approach-2 (Rabin-Karp Algorithm)

class Solution {
private:
    int BASE = 1000000;
public:
    int repeatedStringMatch(string A, string B) {
        if(A == B) return 1;
        int count = 1;
        string source = A;
        while(source.size() < B.size()){
            count++;
            source+=A;
        }
        if(source == B) return count;
        if(Rabin_Karp(source,B) != -1) return count;
        if(Rabin_Karp(source+A,B) != -1) return count+1;
        return -1;
    }
    int Rabin_Karp(string source, string target){
        if(source == "" or target == "") return -1;
        int m = target.size();
        int power = 1;
        for(int i = 0;i<m;i++){
            power = (power*31)%BASE;
        }
        int targetCode = 0;
        for(int i = 0;i<m;i++){
            targetCode = (targetCode*31+target[i])%BASE;
        }
        int hashCode = 0;
        for(int i = 0;i<source.size();i++){
            hashCode = (hashCode*31 + source[i])%BASE;
            if(i<m-1) continue;
            if(i>=m){
                hashCode = (hashCode-source[i-m]*power)%BASE;
            }
            if(hashCode<0)
                hashCode+=BASE;
            if(hashCode == targetCode){
                if(source.substr(i-m+1,m) == target)
                    return i-m+1;
            }
        }
        return -1;
    }
};

// Approach Rabin-Karp Coded by me as Base 1

void rollingHash(string text,string pattern,map<char,int> mp,int hashPattern,vector<int> &ans){
	int n=text.size();
	int m=pattern.size();
	int hashVal=0;
	int highestpow=pow(1,m-1);
	for(int i=0;i<n;i++){
		if(i<m) hashVal+=(mp[text[i]]*pow(1,m-1-i));
		else hashVal=(((hashVal-(mp[text[i-m]]*highestpow))*1)+mp[text[i]]);
		if(hashVal==hashPattern){
			int j,k;
			for(j=i-m+1,k=0;j<=i;j++,k++){
				if(text[j]!=pattern[k]) break;
			}
			if(k==m) ans.push_back(i-m+2);
		}
	}
	return;
}
vector<int> stringMatch(string text, string pattern) {
	// Write your code here.
	map<char,int> mp;
	for(int i=97;i<123;i++){
		int size=mp.size();
		mp[char(i)]=size+1;
	}
	int hashPattern=0;
	int m=pattern.size();
	for(int i=0;i<m;i++){
		hashPattern+=mp[pattern[i]]*pow(1,m-1-i);
	}
	vector<int> ans;
	rollingHash(text,pattern,mp,hashPattern,ans);
	
	return ans;
	
}
