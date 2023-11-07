#include <iostream>
#include <vector>

int knapsack(std::vector<int> values, std::vector<int> weights, int capacity) {
    int n = values.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = std::max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int n;
    std::cout << "Enter the number of items: ";
    std::cin >> n;

    std::vector<int> values(n);
    std::vector<int> weights(n);

    std::cout << "Enter the values and weights of the items:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "Item " << i + 1 << " - Value: ";
        std::cin >> values[i];
        std::cout << "Item " << i + 1 << " - Weight: ";
        std::cin >> weights[i];
    }

    int capacity;
    std::cout << "Enter the knapsack capacity: ";
    std::cin >> capacity;

    int max_value = knapsack(values, weights, capacity);
    std::cout << "Maximum value in the knapsack: " << max_value << std::endl;

    return 0;
}
