#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

float inKey = 0, outKey = 0;

vector<float> generate(int n) {
    // Initialize array
    vector<float> array = {};

    // Set seed for random variables
    random_device rd;
    mt19937 gen(rd());

    // Populate array with random floats 1.0-1000.0
    uniform_real_distribution<float> randomFloat(1.0f, 1000.0f);

    for (int i = 0; i < n; i++) array.push_back(randomFloat(gen));

    // Get two keys: one in array (inKey) and one not in array (outKey)
    uniform_int_distribution<int> randomIndex(0, n - 1);

    inKey = array[randomIndex(gen)];
    outKey = randomFloat(gen);

    while (true) {
        int index = -1;

        for (int i = 0; i < array.size(); i++)
            if (outKey == array[i]) {
                outKey = randomFloat(gen);
                index = i;
                break;
            }
        
        if (index == -1) break;
    }

    // Print keys
    cout << endl << "The key in the array is " << inKey << "." << endl
                 << "The key not in the array is " << outKey << "." << endl << endl;
    
    return array;
}

int linearSearch(const vector<float>& array, float key) {
    // Start timer
    auto start = chrono::steady_clock::now();

    int index = -1;

    // Find key through linear search
    for (int i = 0; i < array.size(); i++)
        if (key == array[i]) {
            index = i;
            break;
        }

    // End timer
    auto end = chrono::steady_clock::now();

    // Compute and print running time
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start);

    cout << "The running time for the linear search was " << elapsed.count() << " nanoseconds." << endl;

    // Return if key was found and index
    if (index == -1)
        cout << "The key was not found." << endl << endl;
    else
        cout << "The key was found at index " << index + 1 << "." << endl << endl;

    return index;
}

vector<float> insertionSort(const vector<float>& array) {
    // Create new array
    vector<float> insertionSortArray = array;

    // Start timer
    auto start = chrono::steady_clock::now();

    // Sort via insertion sort
    for (int i = 1; i < insertionSortArray.size(); i++) {
        float key = insertionSortArray[i];
        int j = i - 1;

        // Move elements that are greater than key up
        while ((j >= 0) && (insertionSortArray[j] > key)) {
            insertionSortArray[j + 1] = insertionSortArray[j];
            j -= 1;
        }
        insertionSortArray[j + 1] = key;
    }

    // End timer
    auto end = chrono::steady_clock::now();

    // Compute and print running time
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start);

    cout << "The running time for the insertion sort was " << elapsed.count() << " nanoseconds." << endl << endl;

    return insertionSortArray;
}

vector<float> merge(const vector<float>& left, const vector<float>& right) {
    // Create new array
    vector<float> mergeSortArray = {};

    // Reserve memory for the array
    mergeSortArray.reserve(left.size() + right.size());
    
    size_t i = 0, j = 0;

    // Order elements from smallest to largest
    while ((i < left.size()) && (j < right.size())) {
        if (left[i] <= right[j])
            mergeSortArray.push_back(left[i++]);
        else
            mergeSortArray.push_back(right[j++]);
    }
    
    // Append remaining elements from the left
    while (i < left.size())
        mergeSortArray.push_back(left[i++]);
    
    // Append remaining elements from the right
    while (j < right.size())
        mergeSortArray.push_back(right[j++]);
    
    return mergeSortArray;
}

vector<float> mergeSort(vector<float> array) {
    if (array.size() <= 1) return array;
    
    size_t mid = array.size() / 2;
    
    // Split array in half
    vector<float> leftHalf(array.begin(), array.begin() + mid);
    vector<float> rightHalf(array.begin() + mid, array.end());

    return merge(mergeSort(leftHalf), mergeSort(rightHalf));
}

int binarySearch(const vector<float>& array, float key) {
    // Start timer
    auto startBinary = chrono::steady_clock::now();

    int low = 0;
    int high = array.size() - 1;

    int index = -1;

    while (low <= high) {
        // Find middle of potential matches
        int mid = low + (high - low) / 2;

        // Divide array
        if (array[mid] == key) {
            index = mid;
            break;
        }
        else if (array[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    // End timer
    auto endBinary = chrono::steady_clock::now();

    // Compute and print running time
    auto elapsedBinary = chrono::duration_cast<chrono::nanoseconds>(endBinary - startBinary);

    cout << "The running time for the binary search was " << elapsedBinary.count() << " nanoseconds." << endl;

    // Return if key was found and index
    if (index == -1)
        cout << "The key was not found." << endl << endl;
    else
        cout << "The key was found at index " << index + 1 << "." << endl << endl;

    return index;
}

int main() {
    // Get length of array
    cout << "Enter the length of the array: ";
    unsigned int size = 0;
    cin >> size;

    // Start timer
    auto startProgram = chrono::steady_clock::now();

    // Create array
    vector<float> array = generate(size);

    // Search for keys
    linearSearch(array, inKey);
    linearSearch(array, outKey);

    // Sort arrays
    vector<float> insertionSortedArray = insertionSort(array);

    // Start timer
    auto startMerge = chrono::steady_clock::now();

    vector<float> mergeSortedArray = mergeSort(array);

    // End timer
    auto endMerge = chrono::steady_clock::now();

    // Compute and print running time
    auto elapsedMerge = chrono::duration_cast<chrono::nanoseconds>(endMerge - startMerge);

    cout << "The running time for the merge sort was " << elapsedMerge.count() << " nanoseconds." << endl << endl;

    vector<float> sortedArray = insertionSortedArray = mergeSortedArray;

    // Binary search
    binarySearch(sortedArray, inKey);
    binarySearch(sortedArray, outKey);

    // End timer
    auto endProgram = chrono::steady_clock::now();

    // Compute and print running time
    auto elapsedProgram = chrono::duration_cast<chrono::nanoseconds>(endProgram - startProgram);

    cout << "The running time for the program was " << elapsedProgram.count() << " nanoseconds." << endl;

    return 0;
}