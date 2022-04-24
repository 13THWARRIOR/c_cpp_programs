#include <iostream>

int stringtonumber(const std::string& s) {
    bool itsnegative = false;
    int sum=0;
    int tempasci = (int)'0';

    if (s[0]<tempasci) {
        itsnegative = true;
    }
    for(char c : s) {
        int cvalue = (int)c;
        if (itsnegative && cvalue >= tempasci) {
            sum = (sum * 10) + (-(cvalue - tempasci));
        } else if (cvalue >= tempasci) {
            sum = (sum * 10) + (cvalue - tempasci);
        }
    }
    return sum;
}

int main() {
    int number = stringtonumber("-456789");
    std::cout << number << std::endl;
    return 0;
}
