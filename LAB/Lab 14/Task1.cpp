#include <iostream>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <cstring>
using namespace std;

struct Result {
    long long comp;
    long long exch;
    double time;
};

const int MAX_SIZE = 50000;

void generateArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        a[i] = rand();
}

Result bubbleSort(int a[], int n) {
    Result r = { 0, 0, 0 };
    int* temp = new int[n];
    memcpy(temp, a, n * sizeof(int));
    
    clock_t start = clock();

    bool swapped = true;
    for (int pass = 0; pass < n - 1 && swapped; pass++) {
        swapped = false;
        for (int j = 0; j < n - pass - 1; j++) {
            r.comp++;
            if (temp[j] > temp[j + 1]) {
                swap(temp[j], temp[j + 1]);
                r.exch++;
                swapped = true;
            }
        }
    }

    clock_t end = clock();
    r.time = double(end - start) / CLOCKS_PER_SEC;
    delete[] temp;
    return r;
}

Result selectionSort(int a[], int n) {
    Result r = { 0, 0, 0 };
    int* temp = new int[n];
    memcpy(temp, a, n * sizeof(int));
    
    clock_t start = clock();

    for (int i = 0; i < n - 1; i++) {
        int key = i;
        for (int j = i + 1; j < n; j++) {
            r.comp++;
            if (temp[j] < temp[key])
                key = j;
        }
        if (key != i) {
            swap(temp[i], temp[key]);
            r.exch++;
        }
    }

    clock_t end = clock();
    r.time = double(end - start) / CLOCKS_PER_SEC;
    delete[] temp;
    return r;
}

Result insertionSort(int a[], int n) {
    Result r = { 0, 0, 0 };
    int* temp = new int[n];
    memcpy(temp, a, n * sizeof(int));
    
    clock_t start = clock();

    for (int k = 1; k < n; k++) {
        int y = temp[k];
        int j = k - 1;
        while (j >= 0) {
            r.comp++;
            if (y < temp[j]) {
                temp[j + 1] = temp[j];
                r.exch++;
                j--;
            }
            else break;
        }
        temp[j + 1] = y;
        r.exch++;
    }

    clock_t end = clock();
    r.time = double(end - start) / CLOCKS_PER_SEC;
    delete[] temp;
    return r;
}

Result heapSort(int a[], int n) {
    Result r = { 0, 0, 0 };
    int* temp = new int[n];
    memcpy(temp, a, n * sizeof(int));
    
    clock_t start = clock();

    make_heap(temp, temp + n);
    sort_heap(temp, temp + n);

    clock_t end = clock();
    r.time = double(end - start) / CLOCKS_PER_SEC;
    delete[] temp;
    return r;
}

int main() {
    srand(time(0));

    int sizes[] = { 10, 100, 1000, 5000, 10000, 20000, 50000 };
    int numSizes = 7;

    cout << left
         << setw(8)  << "N" << " | "
         << setw(22) << "Bubble Sort (C / E)" << " | "
         << setw(24) << "Selection Sort (C / E)" << " | "
         << setw(24) << "Insertion Sort (C / E)" << " | "
         << setw(18) << "Heap Sort Time (s)"
         << endl;

    cout << string(110, '-') << endl;

    int* data = new int[MAX_SIZE];

    for (int i = 0; i < numSizes; i++) {
        int n = sizes[i];
        generateArray(data, n);

        Result b = bubbleSort(data, n);
        Result s = selectionSort(data, n);
        Result ins = insertionSort(data, n);
        Result h = heapSort(data, n);

        cout << setw(8) << n << " | "
             << setw(10) << b.comp << " / " << setw(9) << b.exch << " | "
             << setw(10) << s.comp << " / " << setw(11) << s.exch << " | "
             << setw(10) << ins.comp << " / " << setw(11) << ins.exch << " | "
             << fixed << setprecision(6) << setw(18) << h.time
             << endl;
    }

    delete[] data;
    return 0;
}