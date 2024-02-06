#include<bits/stdc++.h>
using namespace std;


using namespace std::chrono;
//
//// Function to merge two sorted lists
//void merge(vector<int>& arr, int low, int mid, int high) {
//    // Implementation of the merge function (as previously provided)
//    // ...
//}
//
//// Function to perform merge sort
//void mergeSort(vector<int>& arr, int low, int high) {
//    // Implementation of the mergeSort function (as previously provided)
//    // ...
//}
//
//int main() {
//    // Input sizes
//    vector<int> inputSizes = {100000, 500000, 1000000, 5000000, 10000000};
//
//    for (int size : inputSizes) {
//        // Perform multiple iterations for more accurate measurements
//        for (int iteration = 0; iteration < 10; ++iteration) {
//            // Generate a sorted list
//            vector<int> arr(size);
//            
//            // Use iota to initialize a sorted list
//            iota(arr.begin(), arr.end(), 1);
//
//            // Choose a random index to split the list
//            int j = size / 2;
//
//            auto start = high_resolution_clock::now();
//
//            // Merge the two sorted lists
//            mergeSort(arr, 0, j - 1);
//            mergeSort(arr, j, size - 1);
//
//            merge(arr, 0, j - 1, size - 1);
//
//            auto stop = high_resolution_clock::now();
//            auto duration = duration_cast<microseconds>(stop - start); // Change to microseconds
//
//            // Output time and input size
//            cout << "Input Size: " << size << "\tIteration: " << iteration + 1
//                 << "\tTime taken: " << duration.count() << " microseconds" << endl;
//        }
//    }
//
//    return 0;
//}











//// Function to perform partition around a given element
//int partition(vector<int>& arr, int low, int high, int pivot) {
//    // Move pivot to the end
//    swap(arr[pivot], arr[high]);
//
//    int i = low - 1;
//
//    // Iterate through the array
//    for (int j = low; j < high; j++) {
//        if (arr[j] <= arr[high]) {
//            i++;
//            swap(arr[i], arr[j]);
//        }
//    }
//
//    // Move pivot back to its correct position
//    swap(arr[i + 1], arr[high]);
//    return i + 1;
//}
//
//// Function to perform quicksort partitioning
//void quicksortPartition(vector<int>& arr, int low, int high) {
//    if (low < high) {
//        // Choose a random pivot
//        random_device rd;
//        mt19937 gen(rd());
//        uniform_int_distribution<> dis(low, high);
//        int pivot = dis(gen);
//
//        // Perform partition
//        int pivotIndex = partition(arr, low, high, pivot);
//
//        // Recursively partition the two halves
//        quicksortPartition(arr, low, pivotIndex - 1);
//        quicksortPartition(arr, pivotIndex + 1, high);
//    }
//}
//
//int main() {
//    // Input sizes
//    vector<int> inputSizes = {1000, 5000, 10000, 50000, 100000};
//
//    for (int size : inputSizes) {
//        // Generate a random list
//       vector<int> arr(size);
//       iota(arr.begin(), arr.end(), 1);
//       random_shuffle(arr.begin(), arr.end());
//
//        // Choose a random element n
//        random_device rd;
//      mt19937 gen(rd());
//        uniform_int_distribution<> dis(1, size);
//        int n = dis(gen);
//
//        auto start = std::chrono::high_resolution_clock::now();
//
//        // Perform partitioning
//        quicksortPartition(arr, 0, size - 1);
//
//        auto stop = std::chrono::high_resolution_clock::now();
//        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
//
//        // Output time and input size
//        cout << "Input Size: " << size << "\tTime taken: " << duration.count() << " microseconds" << endl;
//    }
//
//    return 0;
//}
//
//











//int power(int m, long long n) {
//    if (n == 0) {
//        return 1;
//    } else if (n % 2 == 0) {
//        int temp = power(m, n / 2);
//        return temp * temp;
//    } else {
//        return m * power(m, n - 1);
//    }
//}
//vector<int> merge(vector<int>arr,vector<int>brr)
//{   
//    int lowA , lowB , highA , highB;
//    vector<int>vec;
//    lowA = 0;
//    lowB = 0;
//    highA = arr.size();
//    highB = brr.size();
//    while(lowA < highA && lowB < highB)
//    {
//       if(lowA >= lowB)
//       {
//         vec.push_back(brr[lowB]);
//         lowB++;
//       }
//       else if(lowB>= lowA)
//       {
//         vec.push_back(arr[lowA]);
//         lowA++;
//       }
//    }
//    if(lowA == highA+1)
//    {
//        for(int h = lowB ; h < highB ; h++)
//        {
//           vec.push_back(brr[lowB]);
//           lowB++;
//        }
//    }
//    else if(lowB == highB+1)
//    {
//        for(int h = lowA ; h<highA ; h++)
//        {
//            vec.push_back(arr[lowA]);
//            lowA++;
//        }
//    }
//    return vec;
//}
//void selection_sort(vector<int>&arr , int n)
//{
//  for(int i=0 ; i<n ; i++)
//  {
//   int max = i;
//   for(int j=1 ; j<i ; j++)
//   {
//      if(arr[j]>=arr[i])
//      {
//        max = j;
//      }
//   }
//   if(max!=i)
//   {
//    swap(arr[max],arr[i]);
//   }
//  }  
//}
//vector<int>correct_pos(vector<int>arr,int ele) //array and element as arguments
//{
//  int i = 0;
//  int j = arr.size(); 
//  while(arr[i]!=ele)
//  {
//    i++;
//  }
//  int indx = i-1;
//  while(j>i)
//  {
//    
//  }
//}
//int partition(vector<int>& arr, int low, int high, int pivot) {
//    // Move pivot to the end
//    swap(arr[pivot], arr[high]);
//
//    int i = low - 1;
//
//    // Iterate through the array
//    for (int j = low; j < high; j++) {
//        if (arr[j] <= arr[high]) {
//            i++;
//            swap(arr[i], arr[j]);
//        }
//    }
//
//    // Move pivot back to its correct position
//    swap(arr[i + 1], arr[high]);
//    return i + 1;
//}
//
//// Function to perform quicksort partitioning
//void quicksortPartition(vector<int>& arr, int low, int high) {
//    if (low < high) {
//        // Choose a random pivot
//        random_device rd;
//        mt19937 gen(rd());
//        uniform_int_distribution<> dis(low, high);
//        int pivot = dis(gen);
//
//        // Perform partition
//        int pivotIndex = partition(arr, low, high, pivot);
//
//        // Recursively partition the two halves
//        quicksortPartition(arr, low, pivotIndex - 1);
//        quicksortPartition(arr, pivotIndex + 1, high);
//    }
//}
//vector<int>generate(vector<int>&arr , int i)
//{
//  for(int j=0; j<i ; j++)
//  {
//    arr.push_back(rand());
//  }
//  selection_sort(arr,arr.size());
//  return arr;
//}
//void store(int i , int avg)
//{
//    cout<<i<<" "<<avg<<endl;
//}
//
//void AC()
//{   
//    // vector<int>arr;
//    // vector<int>brr;
//    int avg;
//    double time_req;
//    clock_t clk;
//    for(int i=1000 ; i<=10000 ; i+=500)
//    {  
//    //  arr = generate(arr,i);
//    //  brr = generate(brr,i);
//    for(int k=1 ; k<= 10 ; k++)
//   {
//        clk = clock();
//        power(2,i);
//        time_req = clock()-clk;
//    } 
//        avg = time_req/10;
//        store(i,time_req);
//    }
//
//}
//int main()
//{
//    AC();
//    return 0;
//}




















