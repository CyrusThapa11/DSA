
#include <iostream>
using namespace std;
void fastInput() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}

string convert(string hasNumber) {

    int len = hasNumber.length();

    for (int i = 0; i < len; i++) {

        if (hasNumber[i] >= '1' && hasNumber[i] <= '9' ) {
            char prevChar = hasNumber[i - 1];
            int remLen = len - i - 1;
            string segment1, segment2;
            segment1 = hasNumber.substr(0, i);
            segment2 = hasNumber.substr(i + 1, remLen);

            string appendstr = "" ;
            int rep = hasNumber[i] - '0';
            for (int i = 0; i < (rep) - 1 ; i++) {
                appendstr += prevChar;
            }
            hasNumber = segment1 + appendstr + segment2;

            len = hasNumber.length();
        }
    }
    return hasNumber;
}

int main() {
// cout<<"GfG!";
    fastInput();
    string hasNumber;
    cin >> hasNumber;

    cout << convert(hasNumber) << endl;


    return 0;
}


