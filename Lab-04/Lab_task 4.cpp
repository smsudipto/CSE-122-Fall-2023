#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[right]);
    return i;
}

int quickSelect(int arr[], int left, int right, int K) {
    if (left <= right) {
        int pivotIndex = partition(arr, left, right);

        if (pivotIndex == K - 1)
            return arr[pivotIndex];
        else if (pivotIndex > K - 1)
            return quickSelect(arr, left, pivotIndex - 1, K);
        else
            return quickSelect(arr, pivotIndex + 1, right, K);
    }
    return -1;
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int N = sizeof(arr) / sizeof(arr[0]);
    int K = 3;

    int result = quickSelect(arr, 0, N - 1, K);
    cout << "The " << K << "'th smallest element is: " << result << endl;

    return 0;
}

