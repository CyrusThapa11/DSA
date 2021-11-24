
#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x
#define debug(x) cout<<#x<<" "<<x<<endl;

//----------------------------------------------------------------------------------


using namespace std;

void init_code() {
   fast_io;
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}

void merge(int *arr, int low , int mid , int high) {

   // low = 4 , mid = 5 high = 7
   int len1 = mid - low + 1;
   int len2 = high - mid;

   int arr1[ len1];
   int arr2[ len2 ];

   for (int i = 0 ; i < len1  ; ++i)
      arr1[i] = arr[low + i];

   for (int i = 0 ; i < len2 ; ++i)
      arr2[i] = arr[mid + i + 1];

   int arr_1Ptr = 0;
   int arr_2Ptr = 0;
   int mainArrayPtr = low;

   while (arr_1Ptr < len1 && arr_2Ptr < len2   ) {
      if (arr1[arr_1Ptr] < arr2[arr_2Ptr] ) {
         arr[mainArrayPtr++] = arr1[arr_1Ptr++];
      } else {
         arr[mainArrayPtr++] = arr2[arr_2Ptr++];
      }
   }

   while (arr_1Ptr < len1) {
      arr[mainArrayPtr++] = arr1[arr_1Ptr++];
   }

   while (arr_1Ptr < len1) {
      arr[mainArrayPtr++] = arr2[arr_1Ptr++];
   }

   return;
}

void mergeSort(int *arr, int l , int r) {
   if (l > r)return;

   if (l < r) {
      int mid = (l + r) / 2;
      mergeSort(arr, l, mid);
      mergeSort(arr, mid + 1, r);

      merge(arr, l, mid, r);
   }

   return;
}

int partition(int*arr, int low , int high) {

   int IdxOfLastSmallestNumber = low - 1;
   int swapper = low;
   // int i = 0
   int pivotElem = arr[high];

   while ( swapper < high  ) {

      if (arr[swapper] < pivotElem ) {
         IdxOfLastSmallestNumber++;
         swap(arr[IdxOfLastSmallestNumber], arr[swapper]);
      }

      swapper++;
   }

   swap(arr[high ], arr[IdxOfLastSmallestNumber + 1]);

   return IdxOfLastSmallestNumber + 1;
}

void quickSort(int *arr, int low , int high) {

   if (low > high)return;

   int partitionIdx = partition(arr, low, high);

   quickSort(arr, low, partitionIdx - 1);
   quickSort(arr,  partitionIdx + 1 , high);

   return;
}

void dnfSort(int *arr , int n) {
   int low = 0 , mid = 0 , high = n - 1;

   while (mid < high) {

      if (arr[mid] == 0) {
         swap(arr[low++], arr[mid++]);
      } else if (arr[mid] == 1)mid++;
      else {
         swap(arr[mid], arr[high--]);
      }
   }
   return;
}

void waveSort(int *arr, int n) {

   for (int i = 1; i < n - 1; i += 2) {
      if (arr[i] > arr[i - 1] )swap(arr[i], arr[i - 1]);

      if ( arr[i] > arr[i + 1] )swap(arr[i], arr[i + 1]);
   }
   return ;
}

int main() {
   init_code();
   int t = 1;
   // cin >> t;
   while (t--) {

      int n ;
      cin >> n;
      int arr[n];
      for (auto &i : arr)
         cin >> i;

      // bubble :

      // for (int i = 0; i < n ; ++i)
      // {
      //    for (int j = 0 ; j < n - i - 1 ; ++j)
      //    {
      //       if (arr[j] > arr[j + 1]) {
      //          swap(arr[j + 1], arr[j]);
      //       }
      //    }
      // }

      // insertion : insert the current number to its
      // correct position while comparing it with
      // previous elements

      // for (int i = 1; i < n; ++i)
      // {
      //    int currElem = arr[i];
      //    int j = i - 1;
      //    while (j >= 0 && arr[j] > currElem) {
      //       arr[j + 1] = arr[j];
      //       j--;
      //    }
      //    arr[j + 1] = currElem;
      // }

      // mergeSort(arr, 0, n - 1);

      // quickSort(arr, 0, n - 1);

      // dnfSort(arr, n);

      waveSort(arr, n);

      for (auto &i : arr)
         cout << i << " ";
   }
   return 0;
}
