#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int knapsack(int W, int n, vector<int>& w, vector<int>& v) {

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));


    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= W; ++j) {

            if (w[i - 1] <= j) {

                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
            } else {

                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][W];
}

int main() {

    int W = 10;
    int n = 4;
    vector<int> w = {2, 1, 5, 3};
    vector<int> v = {300, 200, 400, 500};


    int maxValue = knapsack(W, n, w, v);


    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}

