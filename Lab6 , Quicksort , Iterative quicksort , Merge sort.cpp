#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

//quick sort
void print(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> randomnumbers(vector<int> arr, int n)
{
    int N = 100; // This function will generate random numbers for n=50 it will generate 50 numbers
    for (int i = 0; i < n; i++)
    {
        arr.push_back(rand() % N);
    }

    return arr;
}

int partition(vector<int> &arr,int start,int end){
    int pivotIndex = start;

   while (start < end)
    {
        while (arr[start] <= arr[pivotIndex])
        {
            start++;
        }

        while (arr[end] > arr[pivotIndex])
        {
            end--;
        }

        if (start < end)
        {
            swap(arr[end], arr[start]);
        }
    }

    swap(arr[pivotIndex], arr[end]);

    return pivotIndex;
}

void quickSort(vector<int> &arr,int s,int e){
    if(s<e){
        int q = partition(arr,s,e);
        quickSort(arr,s,q-1);
        quickSort(arr,q+1,e);
    }
}

int main(){
    vector<int> arr; // creating a dynamic array

    for(int input_size=500;input_size<10000;input_size = input_size +100){


    // generating random numbers
    arr = randomnumbers(arr, input_size);

    // to calculate time if an algorithm runs 100 times for a specific input
    clock_t start, end;

    start = clock();

    for (int i = 0; i < 100; i++)
        quickSort(arr,0,arr.size()-1);

    end = clock();

    // total time taken for running an algorithm 100 times for a specific input
    double time_taken = double(end - start) / CLOCKS_PER_SEC;

    // avearge time time_taken/100
    double average_time = time_taken / 100;

    cout << "\nAverage Time taken by for input size " << input_size << " is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;

    }
    
    return 0;
}







//iterative quicksort
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int i = low + 1;
    int j = high;
    int pivot = low;

    while (i <= j)
    {
        while (arr[i] < arr[pivot] && i <= high - 1)
        {
            i++;
        }

        while (arr[j] > arr[pivot] && j >= low + 1)
        {
            j--;
        }

        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    swap(arr[pivot], arr[j]);
    return j;
}

void quickSortIterative(int arr[], int l, int h)
{

    int stack[h - l + 1];

    int top = -1;

    stack[++top] = l;
    stack[++top] = h;

    while (top >= 0)
    {
        // Pop h and l
        h = stack[top--];
        l = stack[top--];

        int p = partition(arr, l, h);

        if (p - 1 > l)
        {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        if (p + 1 < h)
        {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}

void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        cout << arr[i] << " ";
}


int main()
{
    int arr[] = {1, 2, 3, 4, 8, 7, 5};
    int n = sizeof(arr) / sizeof(*arr);
    quickSortIterative(arr, 0, n - 1);
    printArr(arr, n);
    return 0;
}





//merge sort
void print(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> randomnumbers(vector<int> arr, int n)
{
    int N = 100; // This function will generate random numbers for n=50 it will generate 50 numbers
    for (int i = 0; i < n; i++)
    {
        arr.push_back(rand() % N);
    }

    return arr;
}

void merge(vector<int>& arr, int start, int end)
{
    int mid = (start + end) / 2;

    int firstlen = mid - start + 1;
    int secondlen = end - mid;

    vector<int> firstList(firstlen);
    vector<int> secondList(secondlen);

    int p = start;
    for (int i = 0; i < firstlen; i++)
    {
        firstList[i] = arr[p];
        p++;
    }

    for (int i = 0; i < secondlen; i++)
    {
        secondList[i] = arr[p];
        p++;
    }

    int start1 = 0;
    int start2 = 0;

    while (start1 < firstlen && start2 < secondlen)
    {
        if (firstList[start1] < secondList[start2])
        {
            arr[start++] = firstList[start1++];
        }
        else
        {
            arr[start++] = secondList[start2++];
        }
    }

    while (start1 < firstlen)
    {
        arr[start++] = firstList[start1++];
    }

    while (start2 < secondlen)
    {
        arr[start++] = secondList[start2++];
    }
}

void mergeSort(vector<int>& arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, end);
    }
}

int main()
{
    vector<int> arr; // creating a dynamic array

    for(int input_size=1000;input_size<50000;input_size = input_size +1000){


    // generating random numbers
    arr = randomnumbers(arr, input_size);

    // to calculate time if an algorithm runs 100 times for a specific input
    clock_t start, end;

    start = clock();

    for (int i = 0; i < 100; i++)
        mergeSort(arr,0,arr.size()-1);

    end = clock();

    // total time taken for running an algorithm 100 times for a specific input
    double time_taken = double(end - start) / CLOCKS_PER_SEC;

    // avearge time time_taken/100
    double average_time = time_taken / 100;

    cout << "\nAverage Time taken by for input size " << input_size << " is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;

    }

    return 0;
}
