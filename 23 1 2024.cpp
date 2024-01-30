#include <bits/stdc++.h>
using namespace std;

//int selsort(vector<int>&arr,int n)
//{
//	
//	for(int i=0;i<n-1;i++)
//	{
//		int minindex=i;
//		
//		for(int j=0;j<n;j++)
//		{
//			if(arr[j]<arr[minindex])
//			{
//				minindex=j;
//			}
//			
//			swap(arr[minindex],arr[i]);
//		}
//		
//	}
//	
//}



//
void generate(int arr[], int s) {
    for (int j = 0; j < s; j++) {
        arr[j] = rand();
    }
}

int tt(int arr[], int s) {
    clock_t t;
    t = clock();
    int k = 0;
    while (k < s) {
        for ( int j = k + 1; j < s; j++) {
          int key = arr[k];
        
            if (key > arr[j]){
       swap(arr[k], arr[j]);}
       key = arr[j];
                
        }
        k++;
    }
    return -t + clock();
}

int main() {
    int size;
	cin>> size;
    int arr[size];

    
    generate(arr, size);

    int time_taken = tt(arr, size);


   cout << "\nTime taken: " << time_taken << " clock cycles\n";

return 0;
}























































































































//
//int main() {
//    int n;
//
//    cout << "No of integers ";
//    cin >> n;
//
//    int arr[n];
//    cout << "Enter " << n ;
//    for (int i = 0; i < n; i++) {
//        cout << " Integer " << i+1 << " ";
//        cin >> arr[i];
//    }
//
//    
//    int sum = 0;
//    for (int i = 0; i < n; i++) {
//        sum += arr[i];
//    }
//
//
//    cout << " Sum " << sum << endl;
//
//return 0;
//}
















//
//
//
//
//
//
//void generate(int arr[], int s) {
//    for (int j = 0; j < s; j++) {
//        arr[j] = rand();
//    }
//}
//
//int calculateSum(int arr[], int s) {
//    int sum = 0;
//    for (int i = 0; i < s; i++) {
//        sum += arr[i];
//    }
//    return sum;
//}
//
//int main() {
//    int size;
//    cin >> size;
//    int arr[size];
//
//    generate(arr, size);
//
//    // Measure time taken to calculate the sum
//    clock_t start_time = clock();
//    int sum = calculateSum(arr, size);
//    clock_t end_time = clock();
//    int time_taken = end_time - start_time;
//
//    
//
//    cout << "\nSum of the array: " << sum << endl;
//    cout << "Time taken " << time_taken << " clock cycles";
//
//    return 0;
//}
//




//
//void generate(int arr[], int s) {
//    for (int j = 0; j < s; j++) {
//        arr[j] = rand();
//    }
//}
//






