#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

//binary search
int BinarySearch(vector<int> &arr, int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return BinarySearch(arr, l, mid - 1, x);

        return BinarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

void generate(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
}
// best case number found in the first iteration in middle itself
void input_generator1(vector<pair<int, int>> &store)
{
    for (int i = 1e2; i <= 1e6; i*=10)
    {
        vector<int> arr(i);
        generate(arr, i);

        // clock_t time_req ;
        int t = 0;
        for (int m = 1; m <= 10; m++)
        {
            // time_req = clock();
            auto start = high_resolution_clock::now();
            BinarySearch(arr, 0, i - 1, i / 2); // l and r and x
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);

            // time_req = clock() - time_req;
            t += duration.count();
        }
        t = (t / 10);
        t=t*1e7;
        store.push_back({i,t});
    }
}
// worst case :- number not found
void input_generator2(vector<pair<int, int>> &store)
{
    for (int i = 1; i <= 1e7; i *=10)
    {
        vector<int> arr(i);
        generate(arr, i);

        // clock_t time_req;
        int t = 0;
        for (int m = 1; m <= 10; m++)
        {
            auto start = high_resolution_clock::now();
            BinarySearch(arr, 0, i - 1, i +2); // l and r and x
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop - start);

            // time_req = clock() - time_req;
            t += duration.count();
        }
        t = (t / 10);
        store.push_back({i,t});
    }
}
int main()
{
    vector<pair<int, int>> store1;
    input_generator1(store1);

    cout << "Time taken\tNumber of Inputs " << endl;

    for (auto i : store1)
    {
        cout << i.first << "\t" << i.second << endl;
    }

    cout << endl
         << endl
         << "Worst case complexity " << endl
         << endl;

    vector<pair<int, int>> store2;
    input_generator2(store2);
    cout << "Time taken\tNumber of Inputs " << endl;
    for (auto i : store2)
    {
        cout << i.first << "\t" << i.second << endl;
    }
    return 0;
}










//linear search
int search(vector<int> &arr ,int i,int x)
{
    if(i==arr.size())
    return -1;
    if(arr[i]==x) return x;
    else search(arr,i+1,x);
}
// best case search 1st number :- T.c = constant
void input_generator(vector<pair<int,int>> &store)
{
    for(int n=1e2; n<1e4 ; n+=100)
    {
        vector<int> arr(n);
        for(int i=1 ; i<n ;i++)
        arr[i-1] = i ;
        int t=0 ;
        for(int m=1 ; m<=10;m++)
        {
            auto start=high_resolution_clock::now();
            search(arr,0,n+2) ;
            auto stop=high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop-start);
            t+=duration.count();
        }
        t=t/10;
        store.push_back({n,t});

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
}














//towers of hanoi
void TOH(int n,int A,int B,int C)
{
    if(n>=1)
    {
        TOH(n-1,A,C,B);
        // from A to C using B (1 disc transfer)
        TOH(n-1,B,A,C);
    }
}
void input_generator(vector<pair<int,int>> &store)
{
    for(int n= 10 ; n<=50; n+=5)
    {
        clock_t time_req;
        int t=0;
        for(int m=1 ; m<=10;m++)
        {
            auto start = high_resolution_clock::now();
            TOH(n,1,2,3);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);

            t+=duration.count() ;
        }
        t= t/10;
        cout << n << "\t" << t << endl;
        store.push_back({n,t});
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











