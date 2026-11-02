
#include <bits/stdc++.h>
using namespace std;

int knapsack(int capacity, int weight[], int profit[], int n) {

    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {

            if (weight[i - 1] <= w) {

                int include = profit[i - 1] + dp[i - 1][w - weight[i - 1]];
                int exclude = dp[i - 1][w];

                dp[i][w] = max(include, exclude);
            }
            else {
                dp[i][w] = dp[i - 1][w];
            } 
        }
    }

    return dp[n][capacity];
}


int main() {

    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    int profit[n], weight[n];

    cout << "Enter profits: ";
    for (int i = 0; i < n; i++) {
        cin >> profit[i];
    }

    cout << "Enter weights: ";
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    cout << "Enter capacity: ";
    cin >> capacity;

    cout << "Maximum Profit: "
         << knapsack(capacity, weight, profit, n);

    return 0;
}

