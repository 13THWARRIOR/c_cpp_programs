#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

std::mutex mu;
std::mutex mu2;

void threadexampleone() {
    std::lock_guard<std::mutex> lock(mu);
    static int i = 0;
    cout << "i -> " << i << endl;
    i = i+2;
}

void threadexampletwo() {
    std::lock_guard<std::mutex> lock(mu);
    static int j = 1;
    cout << "j -> " << j << endl;
    j = j+2;
}

int main(void) {
    for (int i =0; i<=10; i++) {
        thread t1(threadexampleone);
        thread t2(threadexampletwo);
        t1.join();
        t2.join();
    }
    return 0;
}
