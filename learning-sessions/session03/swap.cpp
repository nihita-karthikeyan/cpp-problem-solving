// Swap two numbers using a temporary variable
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << "Before: " << a << " " << b << endl;

    int temp = a;
    a = b;
    b = temp;

    cout << "After: " << a << " " << b << endl;
    return 0;
}
