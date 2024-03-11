#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;



//selection sort
void selectionSort(vector<int>& arr , int n)
{
    for(int i=0 ; i<n-1 ; i++)  // n-1 number of passes
    {
        int min = i;  // let this be the index of the min element
        for(int j=i+1 ; j<n; j++)  // compare with all the succeeding elements of the array
        {
            if(arr[j]<arr[min])
            min = j;
        }
        swap(arr[min] , arr[i]);
    }
}
void input_generator(vector<pair<int,int>> &store)
{
    for(int i=10 ; i<=1e4 ; i+=1000)
    {
        vector<int> arr(i);
        generate(arr.begin() , arr.end() , rand) ;
    
        clock_t time_req;
        int t=0;
        for(int m=1 ; m<=10 ; m++)
        {
            time_req = clock();
            selectionSort(arr,i);
            time_req = clock() - time_req;
            t+=(time_req) ;
        }
        t=(t/10);
        store.push_back({t,i});

    }
}
int main()
{

    vector<pair<int,int>> store;
    input_generator(store);

    for(auto i : store)
    {
        cout << "Time " << "\t" << "Number of inputs " << endl;
        cout << i.first << "\t" << i.second << endl;
    }
    return 0;
}
























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



































//sum of n numbers
int get_sum(vector<int> &arr , int i)
{
    if(i==arr.size())
    return 0; 
    return arr[i] + get_sum(arr,i+1);
}
void input_generator(vector<pair<int,int>> &store)
{
    for(int i=1000 ; i<=1e4; i+=300)
    {
        vector<int> arr(i);
        for(int j=1 ; j<=i ;j++)
        arr[j-1] = j;
    
        int t=0;
        for(int m=1 ; m<=10 ; m++)
        {
            auto start = high_resolution_clock::now();
            get_sum(arr,0);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);

            t+=duration.count() ;
        }
        t= t/10;
        store.push_back({t,i});

    }
}
int main()
{
    vector<pair<int,int>> store;
    input_generator(store);

    cout << "Time " << "\t" << "Number of inputs " << endl << endl;
    for(auto i : store)
    {
        cout << i.first << "\t" << i.second << endl;
    }
    return 0;
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









































//permutation generator
void PG(vector<int> &arr ,int i)
{
    if(i==arr.size())
    {
        // for(auto j:arr)
            // print the numbers
            return;
    }
    for(int idx=i; idx<arr.size();idx++)
    {
        swap(arr[idx],arr[i]);
        PG(arr,i+1);
        swap(arr[idx],arr[i]);
    }
}
void input_generator(vector<pair<int,int>> &store)
{
    for(int n=1; n<=20; n+=1)
    {
        vector<int> arr(n);
        for(int i=1 ; i<=n ;i++)
        {
            arr[i-1] = i ;
        }
        int t=0 ;
        for(int m=1 ;m<=10 ;m++)
        {
            auto start=high_resolution_clock::now();
            PG(arr,0);
            auto stop=high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop-start) ;
            t+= duration.count();
        }
        t=t/10;
        cout << n << "\t " << t << endl;
        store.push_back({n,t}) ;
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







































//merge sort

// Function to merge two sorted lists
void merge(vector<int>& arr, int low, int mid, int high) {
   // Implementation of the merge function (as previously provided)
   // ...
}

// Function to perform merge sort
void mergeSort(vector<int>& arr, int low, int high) {
   // Implementation of the mergeSort function (as previously provided)
   // ...
}

int main() {
   // Input sizes
   vector<int> inputSizes = {100000, 500000, 1000000, 5000000, 10000000};

   for (int size : inputSizes) {
       // Perform multiple iterations for more accurate measurements
       for (int iteration = 0; iteration < 10; ++iteration) {
           // Generate a sorted list
           vector<int> arr(size);
           
           // Use iota to initialize a sorted list
           iota(arr.begin(), arr.end(), 1);

           // Choose a random index to split the list
           int j = size / 2;

           auto start = high_resolution_clock::now();

           // Merge the two sorted lists
           mergeSort(arr, 0, j - 1);
           mergeSort(arr, j, size - 1);

           merge(arr, 0, j - 1, size - 1);

           auto stop = high_resolution_clock::now();
           auto duration = duration_cast<microseconds>(stop - start); // Change to microseconds

           // Output time and input size
           cout << "Input Size: " << size << "\tIteration: " << iteration + 1
                << "\tTime taken: " << duration.count() << " microseconds" << endl;
       }
   }

return 0;
}













































//horners rule
int Horners(vector<int> arr , int i , int x)
{
    if(i==arr.size())
    return 0;
    return arr[i] + x*Horners(arr,i+1,x);
}
void input_generator(vector<pair<int,int>> &store)
{
    for(int i=10 ; i<=1e4 ; i+=500)
    {
        vector<int> arr(i);
        generate(arr.begin(),arr.end(),rand);

        int t=0;
        for(int m=1; m<=10 ;m++)
        {
            auto start = high_resolution_clock::now();
            Horners(arr,0,4);  // let x=4 
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);

            t+=duration.count() ;
        }
        t= t/10;
        cout << i << "\t" << t << endl;
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











































// quick sort
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
int kthPartition(vector<int> arr , int low , int high)
{
    if(low<high)
    {
        int j= Partition(arr,low,high);
        kthPartition(arr,low,j-1);
        kthPartition(arr,j+1,high);
    }
}
void input_generator_avg(vector<pair<int,int>> &store)
{
    for(int i=10; i<150 ; i+=10)
    {
        vector<int> arr(i);
        generate(arr.begin() , arr.end() , rand) ;

        clock_t time_req;
        int t=0;
        for(int m=1 ; m<=10;m++)
        {
            auto start = high_resolution_clock::now();
            kthPartition(arr,0,i-1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop - start);

            t+=duration.count() ;
        }
        t= t/10;
        store.push_back({i,t});
    }
}
void input_generator_Worst(vector<pair<int,int>> &store)
{
    for(int i=10; i<150 ; i+=10)
    {
        vector<int> arr(i);
        for(int n=0 ; n<i ; n++)
        arr[n] = n+1;

        clock_t time_req;
        int t=0;
        for(int m=1 ; m<=10;m++)
        {
            auto start = high_resolution_clock::now();
            kthPartition(arr,0,i-1);
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
    input_generator_avg(store);

    cout << "Average Case\n" ;
    cout << "Number of inputs \tTime taken\n\n";
    for(auto i :store)
    {
        cout << i.first << " \t" << i.second << endl;
    } 

    cout << "Worst Case Complexity\n\n" ;
    
    vector<pair<int,int>> store1;
    input_generator_Worst(store1);
    cout << "Number of inputs \tTime taken\n\n";
    for(auto i :store1)
    {
        cout << i.first << " \t" << i.second << endl;
    } 
    return 0;
}








































//iterative quick sort
int partition(vector<int> &arr, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = arr[low];
    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
            i++;
        while (arr[j] > pivot && j >= low + 1)
            j--;
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}
void IterativeQS(vector<int> &arr, int low, int high, int &recCalls)
{
    // low and high of the separated portion of elements
    stack<pair<int, int>> st;
    while (1)
    {
        while (low < high)
        {
            int j = partition(arr, low, high);
            if (j - low > high - j)
            {
                st.push({low, j - 1});
                low = j + 1;
                recCalls++;
            }
            else
            {
                st.push({j + 1, high});
                high = j - 1;
                recCalls++;
            }
            // cout << endl << "Recursion Calls made are :- " << recCalls << endl ;
        }
        if (st.empty())
        {
            recCalls--;
            return;
        }
        low = st.top().first;
        high = st.top().second;
        st.pop();
    }
}
void input_generator(vector<pair<int, pair<int, int>>> &store)
{
    for (int i = 1e3; i <= 1500; i += 50)
    {
        vector<int> arr(i);
        for (int it = 0; it < i; it++)
        {
            arr[it] = rand() % 50;
        }

        clock_t time_req;
        int t = 0;
        int recCalls = 0;
        int avgCalls = 0;
        for (int m = 1; m <= 10; m++)
        {
            auto start = high_resolution_clock::now();
            recCalls = 0;
            IterativeQS(arr, 0, i - 1, recCalls);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);

            t += duration.count();
            avgCalls += recCalls;
        }
        t = t / 10;
        avgCalls /= 10;
        store.push_back({i, {t, avgCalls}});
    }
}
int main()
{
    // Inputs,Time taken and average recursion calls made each time for n number of elements
    vector<pair<int, pair<int, int>>> store;
    input_generator(store);

    cout << "Number of inputs \tTime taken \tRecursive Calls\n\n";
    for (auto i : store)
    {
        cout << i.first << " \t" << i.second.first << "\t\t" << i.second.second << endl;
    }
    return 0;
}































//knapsack
void KnapSack(vector<int>&profit , vector<int>& weight , float maxW)
{
    int n=profit.size();
    vector<pair<int,int>> arr(n) ;
    vector<int> X(n);
    // case I -> sort according to non-decreasing weights
    for(int i=0 ; i<n ; i++)
    {
        arr[i] = {weight[i],profit[i]};
    }

    QuickSort(arr,0,n-1);
    float prft =0 ;
    float currWt =0 ;
    int it =0 ;
    float W = maxW;
    while(it<n)
    {
        if(arr[it].first <= W  )
        {
            prft +=arr[it].second ;
            X[it]=1 ;
            W = W-arr[it].first;
        }
        else break;
        it++;
    }
    if(it<n)
    {
        prft += (W / arr[it].first) * (arr[it].second) ;
    }
    cout << "Sorting Weights in non-decreasing order  :- " << prft << endl ;


    // case II -> sort Profits
    for(int i=0 ; i<n ; i++)
    {
        arr[i] = {profit[i],weight[i]};
    }
    QuickSort(arr,0,n-1);
    reverse(arr.begin(),arr.end());

    prft =0 , currWt=0 , it =0;
    W=maxW;
    while(it<n)
    {
        if(arr[it].first <= W  )
        {
            prft +=arr[it].first ;
            X[it]=1 ;
            W = W-arr[it].second;
        }
        else break;
        it++;
    }
    if(it<n)
    {
        prft += (W / arr[it].second) * (arr[it].first) ;
    }
    cout << "Sorting profits in non-increasing order  :- " << prft << endl ;

// CASE - III Sorting in non-increasing order of profits/weights
    vector<pair<float,pair<float,float>>> A(n) ;
    for(int i=0 ; i<n ; i++)
    {
        A[i] ={profit[i]/weight[i],{profit[i],weight[i]}};
    }
    QuickSortPW (A,0,n-1);
    reverse(A.begin(),A.end());
    prft =0 , currWt=0 , it =0;
    W=maxW;
    while(it<n)
    {
        if(A[it].second.second <= W  )
        {
            prft +=A[it].second.first ;
            W = W-A[it].second.second;
        }
        else break;
        it++;
    }
    if(it<n)
    {
        prft += (W / A[it].second.second) * (A[it].second.first) ;
    }
    cout << "Sorting profits/weights in non-increasing order  :- " << prft << endl ;
}
int main()
{
    vector<int> profit ={5,15,10,20} ;
    vector<int> weight = {3,2,1,4} ;
    
    KnapSack(profit,weight,5);
    return 0 ;
}

























//prims algo
class PrimsAlgo
{
    private:
    int n, m ,minCost;
    vector<vector<int>> G;
    vector<int> near; 
    public :
    PrimsAlgo(int vertices,int edges)
    {
        n = vertices ;
        m = edges ;
        G.resize(n+1) ;
        for(int i=0 ; i<=n ; i++)
            G[i].resize(n+1,1e9) ;
        for(int i= 0 ; i<=n ; i++)
        G[i][i] = 0;
        
        near.resize(n+1,0);
        minCost=0;
    }
    void createGraph()
    {
        for(int i=0 ; i<m ; i++)
        {
            int u,v,w ;
            cout << "Enter edge :- " << endl ;
            cout << "Enter vertex 1 :- " ; cin >> u ;
            cout << "Enter vertex 2 :- " ; cin >> v ;
            cout << "Enter weight of the edge " ; cin >> w ;
            G[u][v] = w;
            G[v][u] = w ;
        }
    }
    pair<int,int> minWt()
    {
        int u,v,minC = 1e9; 
        for(int i=1 ; i<=n ; i++)
        {
            for(int j=1; j<=n ; j++)
            {
                if(G[i][j]!=0 && minC > G[i][j])
                {
                    minC = G[i][j] ;
                    u =i ;
                    v=j;
                }
            }
        }
        return {u,v} ;
    }
    int chooseVertex()
    {
        int u =0, minC = 1e9 ;
        for(int i=1 ; i<=n ; i++)
        {
            int j = near[i] ;
            
            if(j!=0 && G[i][j]!=0 && G[i][j]!=1e9 && minC > G[i][j])
            {
                minC = G[i][j] ;
                u = i ;
            }
        }
        return u ;
    }
    int nearUpdVert (int u)
    {
        int w , minC = 1e9 ;
        for(int i=1 ;i <=n ; i++)
        {
            if(near[i]!=0 && G[i][near[i]]!=1e9 &&G[i][near[i]] >= G[u][i])
            {
                near[i] = u ;
                w=i ;
            }
        }
        return w; 
    }
    void Prims (vector<vector<int>> &MST)
    {
        pair<int,int> temp = minWt();
        int k=temp.first ;
        int l=temp.second ;
        cout << k << "\t" << l << endl ;
        MST[1][1] = k ;
        MST[1][2] = l ;
        for(int i=1 ; i<=n ; i++)
        {
            if(G[i][k]!=1e9 && G[i][l]!=1e9 && G[i][k]!=0 &&  G[i][k]!=0 && G[i][k]<G[i][l])
            near[i]=k;
            else near[i]=l;
        }
        near[k] = near[l] = 0;
        minCost += G[k][l] ;
        
        cout << endl << "NEAR" << endl ;
        for(auto i : near)
        cout << i << "\t" ;
        cout << endl ;
        
        for(int j=2 ; j <= n ; j++)
        {
            if(j==m) break ;
            int u = chooseVertex();
            cout << "Choose " << endl ;
            cout << u << endl ;
            cout << near[u] << endl ;
            
            MST[j][1] = u;
            MST[j][2] = near[u] ;
            if(G[u][near[u]]!=1e9 && G[u][near[u]]!=0 )
            minCost += G[u][near[u]];
            near[u] =0 ;
            for(int k=1; k<=n ; k++)
            {
                int w = nearUpdVert(u);
                near[w] = u ;
            }
        }  
        cout << "MINCOST IS " << minCost << endl ;
    }
};

int main()
{
    int n, m ;
    cout << "Enter number of vertices " ; 
    cin >> n ;
    cout << "\nEnter number of edges " ; 
    cin >> m ;

    PrimsAlgo P(n,m) ;
    P.createGraph() ;
    vector<vector<int>> MST(n+1,vector<int>(3,0)) ;
    P.Prims(MST) ;

    for(int i=1 ; i<n ; i++)
    {
        cout << MST[i][1] << "\t" << MST[i][2] << endl ;
    }
    return 0 ;
}
