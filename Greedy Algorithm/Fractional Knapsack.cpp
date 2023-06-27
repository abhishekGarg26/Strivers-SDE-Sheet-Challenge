//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    static bool comparator(Item a,Item b){
        double r1=(double) a.value/ (double) a.weight;
        double r2=(double) b.value/ (double) b.weight;
        return r1>r2;
    }
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,comparator);
        int curWeight=0;
        double finalValue=0.0;
        for(int i=0;i<n;i++){
            if(curWeight+arr[i].weight<=W){
                finalValue+=arr[i].value;
                curWeight+=arr[i].weight;
            }else{
                int remain=W-curWeight;
                finalValue+=((double)remain)*((double)arr[i].value/(double)arr[i].weight);
                break;
            }
        }
        return finalValue;
        
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends