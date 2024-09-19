#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rodCutting(int n, vector<int>& prices) {

    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; ++i) {

        for (int j = 1; j <= i; ++j) {

            dp[i] = max(dp[i], prices[j - 1] + dp[i - j]);
        }
    }

    return dp[n];
}

int main() {

    int n = 8;
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};

    int maxValue = rodCutting(n, prices);

    cout << "Maximum value obtainable: " << maxValue << endl;

    return 0;
}

