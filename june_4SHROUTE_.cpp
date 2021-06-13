#include <bits/stdc++.h>
using namespace std;

long long int findMinimumTime(long long int*trains_ , long long int destination , long long int total_train ) {
	// 3 choices

	// i need to know where i want to go and where can i go ? i.e by default to right
	// in the begining since start is 1 always.

	long long int tele , left , right ;

	for (int i = 0; i < total_train ; ++i) {
		if (trains_[i] != 0)
			tele = teleportHoja( trains_[i] );
	}


}

int main(int argc, char const *argv[]) {

	int t;
	cin >> t;
	while (t--) {
		long long int n , m ;
		cin >> n >> m;
		long long int trains_[n] , passengers_[m];

		for (int i = 0; i < n; ++i)
			cin >> trains_[i];

		for (int i = 0; i < m; ++i)
			cin >> passengers_[i];

		for (int i = 0; i < m; ++i) {
			long long int minTime = findMinimumTime( trains_ , passengers_[i] , n );
			cout << minTime << " ";
		}
		cout << endl;
	}


	return 0;
}