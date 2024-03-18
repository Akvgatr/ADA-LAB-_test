#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;




//kth smallest partition
int Partition(vector<int>&arr , int low , int high)
{
    int i = low ;
    int j = high ;
    int pivot = arr[low];
     while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}
// kth smallest element
int kthPartition(vector<int> arr , int low , int high , int k)
{
    if(low<high)
    {
        int j= Partition(arr,low,high);
        if(j==k) return arr[j];
        else if (j>k)
        kthPartition(arr,low,j-1,k);
        else kthPartition(arr,j+1,high,k);
    }
}
void input_generator(vector<pair<int,int>> &store)
{
    for(int i=10; i<=1e4; i+=1000)
    {
        vector<int> arr(i);
        generate(arr.begin() , arr.end() , rand) ;

        clock_t time_req;
        int t=0;
        for(int m=1 ; m<=10;m++)
        {
            auto start = high_resolution_clock::now();
            kthPartition(arr,0,i-1,i+6);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop - start);

            t+=duration.count() ;
        }
        t= t/10;
        store.push_back({i,t});
    }
}
int main()
{
    vector<pair<int,int>> store;
    input_generator(store);

    cout << "Number of inputs \tTime taken\n\n";
    for(auto i :store)
    {
        cout << i.first << " \t" << i.second << endl;
    } 
    return 0;
}








//power of a number
int Power(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }

    if (n == 1)
    {
        return x;
    }

    int res = Power(x, n / 2);

    if (n % 2 == 0)
    {
        return res * res;
    }
    else
    {
        return x * res * res;
    }
}

int main()
{

    int i = 100000;
    do
    {
        int x = 2;

        int n = i; 


        clock_t start, end;

        start = clock();

        for (int i = 0; i < 100; i++)
            Power(x, n);

        end = clock();

        double time_taken = double(end - start) / CLOCKS_PER_SEC;

        double average_time = time_taken / 100;

        cout << "\nAverage Time taken by Power function is : " << fixed
             << average_time << setprecision(5) << " sec" << endl;
        i = i + 10;
    } while (i != 10000000);

    return 0;
}









//merge 2 sorted lists
vector<int> randomnumbers(vector<int> arr, int n)
{
    int N = 100; // This function will generate random numbers for n=50 it will generate 50 numbers
    for (int i = 0; i < n; i++)
    {
        arr.push_back(rand() % N);
    }

    return arr;
}

void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

vector<int> Mergelists(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> arr3;
    int start1 = 0;
    int start2 = 0;

    while (start1 < arr1.size() && start2 < arr2.size())
    {
        if (arr1[start1] < arr2[start2])
        {
            arr3.push_back(arr1[start1]);
            start1++;
        }
        else
        {
            arr3.push_back(arr2[start2]);
            start2++;
        }
    }

    while (start1 < arr1.size())
    {
        arr3.push_back(arr1[start1]);
        start1++;
    }

    while (start2 < arr2.size())
    {
        arr3.push_back(arr2[start2]);
        start2++;
    }

    return arr3;
}

int main()
{
    vector<int> merged;

    int input_size;

    for (int input_size = 1000; input_size <= 1000000; input_size = input_size + 20000)
    {
        merged = randomnumbers(merged, input_size);

        vector<int> arr1;
        for (int i = 0; i < input_size / 2; i++)
        {
            arr1.push_back(merged[i]);
        }
        vector<int> arr2;
        for (int i = input_size / 2; i < input_size; i++)
        {
            arr2.push_back(merged[i]);
        }

        clock_t start, end;

        start = clock();

        for (int i = 0; i < 100; i++)
            merged = Mergelists(arr1, arr2);

        end = clock();

        double time_taken = double(end - start) / CLOCKS_PER_SEC;

        double average_time = time_taken / 100;

        cout << "\nAverage Time taken by for input size " << input_size << " is : " << fixed
             << time_taken << setprecision(5);
        cout << " sec " << endl;
    }
    return 0;
}
