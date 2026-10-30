#include <bits/stdc++.h>
#include <clocale>
#define ll long long
#define ld long double
#define endl '\n'
using namespace std;

signed main() {
    setlocale(LC_CTYPE, "rus");
    float x,y; cin >> x >> y;
    float R = cos(2*x) * sin(y);
    float S = exp(1.0 / x) * log(y);
    cout << R << " " << S << endl;
    auto C = max(R, S);
    cout << C << endl;
#ifdef _WIN32
    system("pause");
#endif
    return 0;
}
