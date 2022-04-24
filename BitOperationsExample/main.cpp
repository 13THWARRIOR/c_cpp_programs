#include <iostream>
#include <bitset>

using namespace std;

// function to convert decimal to binary
void decToBinary(int n) {
    // array to store binary number
    int binaryNum[64];
    // counter for binary array
    int i = 0;

    if (n<=0) {
        cout << 0 << endl;
    }

    while (n > 0) {
        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
    cout << endl;
}

int main() {
    int a = 100, number;
    decToBinary(a);
    cout << "a<<3 -> "<< (a<<3) << endl;
    decToBinary(a<<3);
    number = 10;
    decToBinary(number);
    decToBinary(20);
    number = number | 10 << 1;
    cout << "number "<< number << endl;
    decToBinary(number);
    return 0;
}
