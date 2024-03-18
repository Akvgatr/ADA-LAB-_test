#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;



//magic square
void generateMagicSquare(int n)
{
    vector<vector<int>> magicSquare;
    magicSquare = vector<vector<int>>(n, vector<int>(n, 0));

    int i = n / 2;
    int j = n - 1;

    for (int num = 1; num <= n * n;)
    {
        if (i == -1 && j == n)
        {
            j = n - 2;
            i = 0;
        }
        else
        {
            if (j == n)
                j = 0;
            if (i < 0)
                i = n - 1;
        }
        if (magicSquare[i][j])
        {
            j -= 2;
            i++;
            continue;
        }
        else
            magicSquare[i][j] = num++;

        j++;
        i--;
    }
}


int main()
{

    int input_size = 3;

    while (input_size < 9999)
    {
        // to calculate time if an algorithm runs 100 times for a specific input
        clock_t start, end;

        start = clock();

        for (int i = 0; i < 100; i++)
            generateMagicSquare(input_size);

        end = clock();

        // total time taken for running an algorithm 100 times for a specific input
        double time_taken = double(end - start) / CLOCKS_PER_SEC;

        // avearge time time_taken/100
        double average_time = time_taken / 100;

        cout << "\nAverage Time taken by for input size " << input_size << " is : " << fixed
             << time_taken << setprecision(5);
        cout << " sec " << endl;
        input_size = input_size + 200;
    }
    return 0;
}




//exact position of elements
void print(vector<int> arr)
{
    // to print the numbers generated
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

vector<int> randomnumbers(vector<int> arr, int n)
{
    int N = 100;
    for (int i = 0; i < n; i++)
    {
        arr.push_back(rand() % N);
    }

    return arr;
}

vector<int> exactPositionPivot(vector<int> &arr)
{
    int low = 0;
    int high = arr.size() - 1;
    int pivotIndex = low;

    while (low < high)
    {
        while (arr[low] <= arr[pivotIndex])
        {
            low++;
        }

        while (arr[high] > arr[pivotIndex])
        {
            high--;
        }

        if (low < high)
        {
            swap(arr[high], arr[low]);
        }
    }

    swap(arr[pivotIndex], arr[high]);

    return arr;
}

int main()
{
    vector<int> arr;

    int input_size;

    for (int input_size = 1000; input_size <= 1000000; input_size = input_size + 20000)
    {
        arr = randomnumbers(arr, input_size);

        clock_t start, end;

        start = clock();

        for (int i = 0; i < 100; i++)
            exactPositionPivot(arr);

        end = clock();

        double time_taken = double(end - start) / CLOCKS_PER_SEC;

        double average_time = time_taken / 100;

        cout << "\nAverage Time taken by for input size " << input_size << " is : " << fixed
             << time_taken << setprecision(5);
        cout << " sec " << endl;
    }
    return 0;
}




// max min of elements
void MaxMin(vector<int> &arr, int start, int end, int &max, int &min)
{
    if (start == end)
    {
        max = min = arr[start];
    }
    else if (start == end - 1)
    {
        if (arr[start] < arr[end])
        {
            max = arr[end];
            min = arr[start];
        }
        else
        {
            max = arr[start];
            min = arr[end];
        }
    }
    else
    {
        int mid = (start + end) / 2;
        int max1, min1;
        MaxMin(arr, start, mid, max, min);
        MaxMin(arr, mid + 1, end, max1, min1);
        if (max < max1)
            max = max1;
        if (min > min1)
            min = min1;
    }
}

int main()
{
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int n = arr.size();
    int max_val = INT_MIN;
    int min_val = INT_MAX;

    MaxMin(arr, 0, n - 1, max_val, min_val);

    cout << "Max value: " << max_val << endl;
    cout << "Min value: " << min_val << endl;

    return 0;
}
