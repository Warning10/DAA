#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int weight;
    int value;
};

bool compare(Item item1, Item item2) {
    double ratio1 = static_cast<double>(item1.value) / item1.weight;
    double ratio2 = static_cast<double>(item2.value) / item2.weight;
    return ratio1 > ratio2;
}

double fractionalKnapsack(std::vector<Item> items, int capacity) {
    std::sort(items.begin(), items.end(), compare);
    
    double totalValue = 0.0;
    
    for (const Item& item : items) {
        if (capacity >= item.weight) {
            totalValue += item.value;
            capacity -= item.weight;
        } else {
            totalValue += (static_cast<double>(capacity) / item.weight) * item.value;
            break;
        }
    }
    
    return totalValue;
}

int main() {
    int n, capacity;
    std::cout << "Enter the number of items: ";
    std::cin >> n;
    std::cout << "Enter the knapsack capacity: ";
    std::cin >> capacity;

    std::vector<Item> items(n);

    for (int i = 0; i < n; i++) {
        std::cout << "Enter weight and value for item " << i + 1 << ": ";
        std::cin >> items[i].weight >> items[i].value;
    }

    double maxValue = fractionalKnapsack(items, capacity);
    std::cout << "Maximum value in the knapsack: " << maxValue << std::endl;

    return 0;
}
