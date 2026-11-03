#include <iostream>
using namespace std;

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int binarySearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x) return mid;
        else if (arr[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    const int N = 10;
    int arr[N], original[N];

    cout << "Enter 10 integers:\n";
    for (int i = 0; i < N; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
        original[i] = arr[i];
    }

    int choice;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Selection Sort\n";
        cout << "2. Bubble Sort\n";
        cout << "3. Insertion Sort\n";
        cout << "4. Binary Search\n";
        cout << "5. Display Array\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                selectionSort(arr, N);
                cout << "Array after Selection Sort: ";
                display(arr, N);
                break;
            case 2:
                // reset to original for fair sorting
                for(int i=0; i<N; i++) arr[i]=original[i];
                bubbleSort(arr, N);
                cout << "Array after Bubble Sort: ";
                display(arr, N);
                break;
            case 3:
                for(int i=0; i<N; i++) arr[i]=original[i];
                insertionSort(arr, N);
                cout << "Array after Insertion Sort: ";
                display(arr, N);
                break;
            case 4: {
                // Binary search needs sorted array
                insertionSort(arr, N);
                cout << "Sorted Array: ";
                display(arr, N);
                int x;
                cout << "Enter element to search: ";
                cin >> x;
                int result = binarySearch(arr, N, x);
                if (result != -1)
                    cout << "Element found at index " << result << endl;
                else
                    cout << "Element not found!" << endl;
                break;
            }
            case 5:
                cout << "Current Array: ";
                display(arr, N);
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}