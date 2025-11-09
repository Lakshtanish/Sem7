//0-1 knapsack using DP
#include <iostream>
#include <vector>
using namespace std;

class Knapsack{
public:
    static int solve(vector<int> &profit, vector<int> &weight, int m){
        int n = profit.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }else if(weight[i] <= j){
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j - weight[i]] + profit[i]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};


int main(){
    int n;
    int w;
    cout<<"Enter number of items: ";
    cin>>n;
    cout<<"Enter maxWeight :";
    cin>>w;
    vector<int> profit(n, 0);
    cout<<"Enter profit space seperated: ";
    for(int i = 0; i < n; i++){
        cin>>profit[i];
    }

    vector<int> weight(n, 0);
    cout<<"Enter weight space seperated: ";
    for(int i = 0; i < n; i++){
        cin>>weight[i];
    }
    cout<<Knapsack::solve(profit, weight, w);

}