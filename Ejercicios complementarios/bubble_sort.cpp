#include <iostream>
using namespace std;

void printArr(int arr[], int size);
void bubbleSort(int arr[], int size);
void bubbleSortInverted(int arr[], int size);

int main() {
  int arr[] = {7, 2, 8, 1, 9, 0, 4, 3, 6, 5};
  const int SIZE = sizeof(arr) / sizeof(arr[0]);

  printArr(arr, SIZE);
  cout << "Sort the array from smallest to largest (1) or viceversa (2)? ";

  while (true) {
    int input;
    cin >> input;

    if (cin.fail() || (input != 1 && input != 2)) {
      cout << "Invalid input. Enter number 1/2 to select an option: ";
      cin.clear();
      cin.ignore(1000, '\n');
    } else {
      input == 1 ? bubbleSort(arr, SIZE) : bubbleSortInverted(arr, SIZE);
      break;
    }
  }

  printArr(arr, SIZE);
  return 0;
}

void printArr(int arr[], int size) {
  using namespace std;

  cout << "[ ";

  for (int i = 0; i < size - 1; i++)
    cout << arr[i] << ", ";

  cout << arr[size - 1] << " ]\n";
}

void bubbleSort(int arr[], int size) {
  while (size >= 1) {
    int swaped = 0;

    for (int i = 1; i < size; i++) {
      if (arr[i] < arr[i - 1]) {
        swap(arr[i - 1], arr[i]);
        swaped = i;
      }
    }

    size = swaped;
  }
}

void bubbleSortInverted(int arr[], int size) {
  int limit = 0;

  while (limit <= size - 1) {
    int swaped = size;

    for (int i = size - 2; i >= limit; i--) {
      if (arr[i] < arr[i + 1]) {
        swap(arr[i + 1], arr[i]);
        swaped = i;
      }
    }

    limit = swaped;
  }
}
