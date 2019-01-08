#include <iostream>
#include <thread>
#include <unistd.h>
#include <mutex>
using namespace std;

static mutex m;

void printSum(int i, int j)
{
    m.lock();
    cout << i+j << endl;
    m.unlock();
}

class printSumObj {
public:
    void operator()(int i, int j) {
        m.lock();
        cout << i+j << endl;
        m.unlock();
    }
};

auto printSumLamda = [](int i, int j) {
    m.lock();
    cout << i+j << endl;
    m.unlock();
};

int main(int argc, const char * argv[]) {
    thread t1(printSum,1,2);
    thread t2(printSumLamda,2,2);
    thread t3(printSumObj(),2,3);
    t1.join();
    t2.join();
    t3.join();
    cout << endl;
    thread t4(printSum,1,2);
    thread t5(printSumLamda,2,2);
    thread t6(printSumObj(),2,3);
    t4.detach();
    t5.detach();
    t6.detach();
    usleep(500);
}
