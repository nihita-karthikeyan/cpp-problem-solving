// Read length and breadth, print area and perimeter
#include <iostream>
using namespace std;

int main() {
    int l, b;
    cout << "Enter length and breadth of the rectangle: ";
    cin >> l >> b;
    int Area = l * b;
    int Perimeter = 2 * (l + b);
    cout << "Area is " << Area << endl;
    cout << "Perimeter is " << Perimeter << endl;
    return 0;
}
