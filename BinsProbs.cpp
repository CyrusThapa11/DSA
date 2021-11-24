
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


bool canAllocate(int *arr, int noOfPagesPerPerson, int n , int k) {

   int sum = 0 , studentsReqForThesePages = 1 ;

   for (int i = 0; i < n; ++i) {

      if (arr[i] > noOfPagesPerPerson )return 0;

      if ( sum + arr[i] <= noOfPagesPerPerson ) {
         sum += arr[i];

      } else if (sum + arr[i] > noOfPagesPerPerson ) {
         studentsReqForThesePages++;
         sum = arr[i];
         if (studentsReqForThesePages > k)return 0;
      }
   }

   return 1;
}

int pageAllocation(int *arr , int n , int k) {

   int start = arr[0] , canAllocateThesePages , ans = INT_MAX , end = 0 ;
   for (int i = 0; i < n; ++i) {
      end += arr[i];
   }

   while (start <= end) {

      int canAllocateThesePages = (start + end) / 2;

      if (canAllocate(arr, canAllocateThesePages , n , k)) {

         ans = min(ans, canAllocateThesePages);
         end = canAllocateThesePages - 1;

      } else {
         start = canAllocateThesePages + 1;
      }

   }

   return ans;
}

bool isTheDiffPsbl(int* arr, int n, int k, int diffAmongNums) {

   int nums = 1;
   int prev = arr[0];
   for (int i = 1; i < n; ++i) {
      if ( arr[i] - prev >= diffAmongNums ) {
         nums++;
         prev = arr[i];
         if (nums == k)return 1;
      }
   }


   return 0;
}

int maxDiffInSetOfKnums(int * nums , int n , int k) {

   int start = 1 , end = nums[n - 1];
   int diffAmongNums = 0 , ans_ = 0 ;

   while (start < end) {
      diffAmongNums = (start + end) / 2;

      if (isTheDiffPsbl(nums, n, k, diffAmongNums)) {
         ans_ = max(ans_, diffAmongNums);
         start = diffAmongNums + 1;

      } else {
         end = diffAmongNums ;
      }
   }

   return ans_;

}

void solve() {

//------------- page allocation problem :
   int n , k;
   cin >> n ;
   cin >> k;
   // int pagesWithBooks[n];
   // for (int i = 0; i < n; ++i)
   //    cin >> pagesWithBooks[i];

   // cout << pageAllocation(pagesWithBooks, n, k) << endl;

//----------- maximum difference between any 2 pair of k elements

   int nums[n];
   for (int i = 0; i < n; ++i)
      cin >> nums[i];

   sort(nums , nums + n);

   cout << maxDiffInSetOfKnums(nums , n , k) << endl;



}

int main() {
   init_code();
   int t = 1;
   // cin >> t;
   while (t--) {
      solve();
   }






   return 0;
}
