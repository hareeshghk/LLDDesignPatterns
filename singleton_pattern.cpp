/*
Where you want only one instance class should be present then
this pattern can be used like a DB instance for a program
*/

#include <iostream>
#include <memory>
#include <mutex>

using namespace std;

class Singleton {
    int data;
    Singleton() {
        data = 0;
    };
    static Singleton *instance_;
    static mutex mt;
public:
    static Singleton* GetInstance() {
        // to make it thread safe
        lock_guard<mutex> lg(mt);
        if (instance_ == nullptr) {
            instance_ =  new Singleton;
        }
        return instance_;
    }

    ~Singleton() {
        delete instance_;
    }
};

Singleton* Singleton::instance_ = nullptr;
mutex Singleton::mt;

int main() {
    auto db_instace = Singleton::GetInstance();
    return 0;
}