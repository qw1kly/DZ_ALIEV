#include <iostream>
#include <list>

using namespace std;

void heapify(list<int>& arr, int n, int i) {
    int largest = i; // Предполагаем, что корень является наибольшим
    int left = 2 * i + 1; // Индекс левого потомка
    int right = 2 * i + 2; // Индекс правого потомка

    if (left < n && arr.begin() != arr.end() && next(arr.begin(), left) != arr.end() && *next(arr.begin(), left) > *next(arr.begin(), largest)) {
        largest = left;
    }

    if (right < n && arr.begin() != arr.end() && next(arr.begin(), right) != arr.end() && *next(arr.begin(), right) > *next(arr.begin(), largest)) {
        largest = right;
    }

    if (largest != i) {
        swap(*next(arr.begin(), i), *next(arr.begin(), largest));

        heapify(arr, n, largest);
    }
}

void pyramidSORT_Aliev(list<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(*arr.begin(), *next(arr.begin(), i));

        heapify(arr, i, 0);
    }
}

int main() {
    list<int> arr = {12, 11, 13, 5, 6, 7};
    for (auto it = arr.begin(); it != arr.end(); it++) {
        cout << *it << " ";
    }

    heapSort(arr);

   
    for (auto it = arr.begin(); it != arr.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
