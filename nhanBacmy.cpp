#include <iostream>
#include <cmath>  // Include the cmath header for the fmod function

using namespace std;

int main() {
    double L1, L2;
    cin >> L1 >> L2;

    int dem = 0;
    double volume = 0;

    while (L2 > 0) {
        double n = (int(L2) % 10) * L1;  // Use (int(L2) % 10) for integer division
        dem++;
        for (int i = 1; i < dem; i++) {
            n *= 10;
        }
        volume += n;
        L2 /= 10;
    }

    cout << int(volume) << endl;

    return 0;
}
