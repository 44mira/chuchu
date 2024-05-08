#include <iostream>
#include <cmath>

// Function declarations
int findSmallest(int arr[], int SIZE);
int findLargest(int arr[], int SIZE);
double calcAvg(int arr[], int SIZE);
double calcVariance(int arr[], int SIZE);
double calcStndDev(int arr[], int SIZE);
void inputData(int arr[], int& SIZE);
void printCalculations(int arr[], int SIZE);

// Main function
int main(){
    int array[10], size;
    inputData(array, size);
    printCalculations(array, size);
}

// Function to find smallest value in array
int findSmallest(int arr[], int SIZE){
    int min = arr[0];
    for (int i = 1; i < SIZE; i++){
        if (min > arr[i]) min = arr[i];
    }
    return min;
}

// Function to find largest value in array
int findLargest(int arr[], int SIZE){
    int max = arr[0];
    for (int i = 1; i < SIZE; i++){
        if (max < arr[i]) max = arr[i];
    }
    return max;
}

// Function to calculate the average (or mean) of the values in the array
double calcAvg(int arr[], int SIZE){
    double average = 0;
    // Sums all the values together
    for (int i = 0; i < SIZE; i++){
        average += arr[i];
    }
    // Returns the average, or the sum divided by the total number of values
    return (average/SIZE);
}

// Function to calculate the variance of the values in the array
double calcVariance(int arr[], int SIZE){
    double result = 0;
    // Sums all the values in the array subtracted by the mean raised to 2.
    for (int i = 0; i < SIZE; i++){
        result += pow((arr[i] - calcAvg(arr, SIZE)),2);
    }
    // Returns the calculated sum divided by the total number of values
    return (result/SIZE);
}

// Function to calculate the standard deviation of the values in the array
double calcStndDev(int arr[], int SIZE){
    // Standard deviation is just the square root of variance.
    // We call the calcVariance() function and find its square root
    return sqrt(calcVariance(arr, SIZE));
}

// Function to input data into array and get number of values
void inputData(int arr[], int& size){
    size = 0;
    std::cout << "Input integers to calculate basic statistics for: \n";
    // For loop that asks for inputs to store in array.
    // Ends once 0 is encountered or max size (10) is reached.
    for (int i = 0; i < 10; i++){
        std::cin >> arr[i];
        size++;
        if(arr[i]==0) break;
    }   
}

// Function to output the calculations
void printCalculations(int arr[], int size){
    std::cout<< "Calculations:\n";
    std::cout<< "Largest: " << findLargest(arr,size) << "\n";
    std::cout<< "Smallest: " << findSmallest(arr, size) << "\n";
    std::cout<< "Average: " << calcAvg(arr, size) << "\n";
    std::cout<< "Standard Deviation: " << calcStndDev(arr, size) << "\n";
    std::cout<< "Variance: " << calcVariance(arr, size) << "\n";
}