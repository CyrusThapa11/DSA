#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void fastInput() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}


bool prime_(int num) {
    int ans = 0;
    for (int i = 2 ; i * i <= num ; i++) {
        if (num % i == 0)return 0;
    }
    return 1;
}

void findFactors(int num) {

    stack<int>primeFacts;

    for (int i = 1 ; i <= num ; i++) {
        if (  num % i == 0 &&  prime_(i)  ) {
            primeFacts.push(i);
        }
    }

    cout << "prime facts : " << endl;
    while (!primeFacts.empty()) {

        cout << primeFacts.top() << " " ;
        primeFacts.pop();
    }
    return;
}

int main()
{
    fastInput();
    int n; cin >> n;
    findFactors(n);

    return 0;
}
