#include <windows.h>

#include <iostream>
#include <vector>    
#include <algorithm>  

using namespace std;

int knapsack_dp(int W, int wt[], int val[], int n) {

    vector<vector<int>> dp(n + 1, vector<int>(W + 1));

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
 
                dp[i][w] = 0;
            } else if (wt[i - 1] <= w) {

                dp[i][w] = max(
                    val[i - 1] + dp[i - 1][w - wt[i - 1]],
                    dp[i - 1][w]
                );
            } else {

                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    // Call the new DP function
    int result = knapsack_dp(W, wt, val, n);

    cout << "Maximum value in knapsack = " << result << endl;
    return 0;
}