#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int randomizedPartition(vector<int>& arr, int low, int high) {
    int random = low + rand() % (high - low + 1);
    swap(arr[random], arr[high]);
    return partition(arr, low, high);
}

void quickSort(vector<int>& arr, int low, int high, bool randomized) {
    if (low < high) {
        int pi;
        if (randomized) {
            pi = randomizedPartition(arr, low, high);
        } else {
            pi = partition(arr, low, high);
        }

        quickSort(arr, low, pi - 1, randomized);
        quickSort(arr, pi + 1, high, randomized);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> arrDeterministic = arr;
    vector<int> arrRandomized = arr;

    quickSort(arrDeterministic, 0, n - 1, false);
    quickSort(arrRandomized, 0, n - 1, true);

    cout << "Sorted array using deterministic Quick Sort:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arrDeterministic[i] << " ";
    }

    cout << "\nSorted array using randomized Quick Sort:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arrRandomized[i] << " ";
    }

    return 0;
}
