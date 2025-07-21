#include <iostream>
using namespace std;

int main() {
    int x = 0b1111; 
    cout << "Original: " << x << " (binary: 0111)" << endl;

    // Turn ON bit 3 (value = 8)
    x = x | (1 << 3); // 001 -> 100 | 111 -> 111 -> 8
    cout << "After setting bit 3: " << x << " (binary: 1111)" << endl;

    // Turn OFF bit 1 (value = 2)
    x = x & ~(1 << 1); // 1 0 1 & 1 1 1 = 1 0 1 -> 5
    cout << "After clearing bit 1: " << x << " (binary: 1101)" << endl;

    return 0;
}
