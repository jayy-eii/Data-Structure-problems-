#include <iostream>
#include <vector>
using namespace std;

// ---------- Merge Sort ----------
// Named mergeArrays (not merge) so it doesn't clash with std::merge
void mergeArrays(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left;      // pointer for left half
    int j = mid + 1;   // pointer for right half

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }
    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (int k = left; k <= right; k++) {
        arr[k] = temp[k - left];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    mergeArrays(arr, left, mid, right);
}

// ---------- Bubble Sort ----------
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;  // already sorted
    }
}

// ---------- Helpers ----------
void printArray(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> original = {64, 34, 25, 12, 22, 11, 90};

    vector<int> a = original;
    cout << "Original:     ";
    printArray(a);

    mergeSort(a, 0, a.size() - 1);
    cout << "Merge sorted: ";
    printArray(a);

    vector<int> b = original;
    bubbleSort(b);
    cout << "Bubble sorted: ";
    printArray(b);

    return 0;
}