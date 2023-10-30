#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void inputArray(vector<double>& arr, int n) {
    if (n == 0) {
        return;
    }

    double element;
    cout << "Input elem of array: ";
    cin >> element;
    arr.push_back(element);

    inputArray(arr, n - 1); 
}

void printArray(const vector<double>& arr, int index) {
    if (index < arr.size()) {
        cout << arr[index] << " ";
        printArray(arr, index + 1);
    }
}

int countElementsInRange(const vector<double>& arr, double A, double B, int index) {
    if (index == arr.size()) {
        return 0;
    }

    int countInRange = (arr[index] >= A && arr[index] <= B) ? 1 : 0;   //ternar operator
    return countInRange + countElementsInRange(arr, A, B, index + 1);
}

double findMaxElement(const vector<double>& arr, int index, double maxElement) {
    if (index == arr.size()) {
        return maxElement;
    }

    if (arr[index] > maxElement) {
        maxElement = arr[index];
    }

    return findMaxElement(arr, index + 1, maxElement);
}

double sumAfterMax(const vector<double>& arr, int index, double maxElement, double sum, bool foundMax) {
    if (index == arr.size()) {
        return sum;
    }

    if (foundMax) {
        sum += arr[index];
    }

    if (arr[index] == maxElement) {
        foundMax = true;
    }

    return sumAfterMax(arr, index + 1, maxElement, sum, foundMax);
}

vector<int> sortEvenElementsByAbsoluteValue(const vector<double>& arr, int index, vector<int> indices) {
    if (index == arr.size()) {
        return indices;
    }

    if (index % 2 == 0) {
        indices.push_back(index);
    }

    return sortEvenElementsByAbsoluteValue(arr, index + 1, indices);
}

int main() {
    vector<double> arr;
    int n;
    cout << "Input size of array: ";
    cin >> n;

    inputArray(arr, n);

    printArray(arr, 0);

    double A, B;
    cout << "Input diapazon [A, B]:" << endl;
    cout << "A: "; cin >> A;
    cout << "B: "; cin >> B;

    int count = countElementsInRange(arr, A, B, 0);
    cout << "Count elem in diapazon [" << A << ", " << B << "]: " << count << endl;

    double maxElement = findMaxElement(arr, 0, arr[0]);
    double sum = sumAfterMax(arr, 0, maxElement, 0, false);

    vector<int> sortedIndices = sortEvenElementsByAbsoluteValue(arr, 0, {});
    sort(sortedIndices.begin(), sortedIndices.end(), [&arr](int i, int j) {
        return abs(arr[i]) > abs(arr[j]);
        });

    int j = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (i % 2 == 0) {
            cout << arr[sortedIndices[j++]] << " ";
        }
        else {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    return 0;
}






