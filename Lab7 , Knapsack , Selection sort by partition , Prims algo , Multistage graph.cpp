#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

// knapsack
class obj
{
public:
    float profit;
    float weight;
    float profitByWeight;

    obj(float profit, float weight)
    {
        this->profit = profit;
        this->weight = weight;
        this->profitByWeight = (profit / weight);
    }
};

bool cmpProfit(obj a, obj b)
{
    return b.profit < a.profit;
}

bool cmpWeight(obj a, obj b)
{
    return b.weight > a.weight;
}

bool cmpProfitbyWeight(obj a, obj b)
{
    return b.profitByWeight < a.profitByWeight;
}

void greedyKnapsack(vector<obj> &objList, int maxWeight)
{
    sort(objList.begin(), objList.end(), cmpProfitbyWeight);
    float profit = 0;

    for (int i = 0; i < objList.size(); i++)
    {
        if (maxWeight >= objList[i].weight)
        {
            profit += objList[i].profit;
            maxWeight -= objList[i].weight;
        }
        else
        {
            profit += (maxWeight / objList[i].weight) * objList[i].profit;
            break;
        }
    }
    cout << "Maximum profit earned is " << setprecision(3) << fixed << profit << endl;
}

int main()
{
    vector<obj> objList = {obj(10, 2), obj(5, 3), obj(15, 5), obj(7, 7), obj(6, 1), obj(18, 4), obj(3, 1)};
    int maxWeight = 15;

    greedyKnapsack(objList, maxWeight);

    return 0;
}






//selection sort using partition
void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
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

int partition(vector<int> &arr, int start, int end)
{
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

int kthSmallestElement(vector<int> &arr, int k)
{
    int start = 0;
    int end = arr.size() - 1;
    int ans = -1;

    while (start <= end)
    {
        int p = partition(arr, start, end);

        if (p == k - 1)
        {
            ans = p;
            break;
        }
        else if (p < k - 1)
        {
            start = p + 1;
        }
        else
        {
            end = p - 1;
        }
    }

    return ans;
}

void selectionSort(vector<int>& arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int small = kthSmallestElement(arr, i + 1); 
        swap(arr[i], arr[small]);
    }
}
int main()
{
    vector<int> arr; // creating a dynamic array

    for(int input_size=10;input_size<100;input_size = input_size +10){

    // generating random numbers
    arr = randomnumbers(arr, input_size);

    // to calculate time if an algorithm runs 100 times for a specific input
    clock_t start, end;

    start = clock();

    for (int i = 0; i < 100; i++)
        selectionSort(arr);

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






//prims algorithm
int findMinCostVertex(int vertices, vector<vector<int>> &cost, vector<int> &near)
{
    int minCost = INT_MAX;
    int minVertex = -1;
    for (int i = 0; i < vertices; i++)
    {
        if (near[i] != -2 && cost[i][near[i]] != 0 && cost[i][near[i]] < minCost)
        {
            minCost = cost[i][near[i]];
            minVertex = i;
        }
    }
    return minVertex;
}

pair<int, int> minCostedge(vector<vector<int>> &cost)
{
    int minCost = INT_MAX;
    int k, l;
    for (int i = 0; i < cost.size(); i++)
    {
        for (int j = 0; j < cost[i].size(); j++)
        {
            if (cost[i][j] != 0 && cost[i][j] < minCost)
            {
                minCost = cost[i][j];
                k = i;
                l = j;
            }
        }
    }

    return {k, l};
}
int primAlgorithm(vector<vector<int>> &cost, int vertices, vector<vector<int>> &t)
{
    // let (k,l) be an edge of minimum cost in E;
    pair<int, int> minEdge = minCostedge(cost);
    int k = minEdge.first;
    int l = minEdge.second;
    int minCost = 0;
    minCost = cost[k][l];
    t[0][0] = k;
    t[0][1] = l;

    vector<int> near(vertices, -1);

    for (int i = 0; i < vertices; i++)
    {
        if (cost[i][l] < cost[i][k])
        {
            if (cost[i][l] != 0)
            {
                near[i] = l;
            }
            else
            {
                near[i] = k;
            }
        }
        else if (cost[i][l] > cost[i][k])
        {
            if (cost[i][k] != 0)
            {
                near[i] = k;
            }
            else
            {
                near[i] = l;
            }
        }
    }
    near[k] = near[l] = -2;

    for (int i = 1; i < t.size(); i++)
    {
        // let j be an index/vertex such that near[j] != 0 and cost[j,near[j]] is minimum;
        int j = findMinCostVertex(vertices, cost, near);
        t[i][0] = j;
        t[i][1] = near[j];
        minCost = minCost + cost[j][near[j]];
        near[j] = -2;

        for (int k = 0; k < vertices; k++)
        { // update near[]
            
            if (near[k] != -2 && cost[k][j] != 0 && cost[k][near[k]] > cost[k][j])
            {
                near[k] = j;
            }
        }
    }

    return minCost;
}

int main()
{
    int vertices;
    cout << "Enter the no. of vertices in the graph: ";
    cin >> vertices;
    int edges;
    cout << "Enter the no. of edges in the graph: ";
    cin >> edges;
    Graph g(vertices, edges, 0);

    g.makeMatrix();
    cout << "-----------------------------" << endl;
    g.displayMatrix();
    cout << "-----------------------------" << endl;
    pair<vector<vector<int>>, vector<vector<int>>> getInput = g.result();
    vector<vector<int>> t(vertices - 1, vector<int>(2, -1));
    int minCost = primAlgorithm(getInput.first, vertices, t);

    cout << "Min cost of spanning tree is " << minCost << endl;

    cout << "-----------------------------" << endl;
    cout << "Edges in the spanning tree: " << endl;
    for (auto i : t)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}



//multistage graph
struct Result
{
    int path[4];
    int length;
};
 void number_stages( int cost[4][4]){
    int stage=0;
    for(int i=1 ; i<5 ; i++){
        for( int j=1; j<5;j++){
        if(cost[i][j] !=0){
            stage ++;
            break;
        }
        }

    }
    cout<<"stages are:"<<stage;

 }
 int calculateNumStages(int cost[4][4], int number_vertices)
{
    int maxStage = 0;
    for (int i = 0; i < number_vertices; ++i)
    {
        for (int j = 0; j < number_vertices; ++j)
        {
            if (cost[i][j] != 0 && cost[i][j] != INT_MAX && j > maxStage)
            {
                maxStage = j;
            }
        }
    }
    return maxStage + 1; 
}

Result fcost(int cost[4][4], int number_vertice, int k)
{
    int fcost[number_vertice];
    fcost[number_vertice - 1] = 0;
    int d[number_vertice];
    int path[k];
    int r;

    for (int j = number_vertice - 2; j >= 0; j--)
    {
        int min = INT_MAX;
        for (int h = j + 1; h < number_vertice; h++)
        {
            if (cost[j][h] != 0 && cost[j][h] != INT_MAX)
            {
                if (cost[j][h] + fcost[h] < min)
                {
                    r = h;
                    min = cost[j][h] + fcost[h];
                }
            }
        }

        fcost[j] = cost[j][r] + fcost[r];
        d[j] = r;
    }

    Result result;
    result.length = fcost[0];
    result.path[0] = 1;
    result.path[k - 1] = number_vertice;

    for (int z = 1; z < k - 1; z++)
    {
        result.path[z] = d[result.path[z - 1] - 1] + 1;
    }

    return result;
}

int main()
{
   
    int cost[4][4] = {
        {0, 1, 2, INT_MAX},
        {INT_MAX, 0,INT_MAX , 2},
        {INT_MAX, INT_MAX, 0, 1},
        {INT_MAX, INT_MAX, INT_MAX, 0}};

    int number_vertices = 4;
    int stages = 3;

    Result result = fcost(cost, number_vertices, stages);

   cout << "Minimum cost path length: " << result.length << endl;
  cout << "Path: ";
    for (int i = 0; i < stages; i++)
    {
       cout << result.path[i] << " ";
    }
   

    return 0;
}

