/*
Instead od using whole objects use a interface
and let all kind of objects implement that, that
we can just this interface object instead of telling other details about
objects
*/

#include <iostream>
#include <vector>
#include <memory>
#include <unordered_set>

using namespace std;

class Subscriber {
public:
    virtual void update(int r, int w, int o) = 0;
};

class Server {
public:
    virtual void AddSubscriber(shared_ptr<Subscriber> a) = 0;
    virtual void RemoveSubscriber(shared_ptr<Subscriber> a) = 0;
    virtual void NotifySubscribers() = 0;
};

class AverageScrore : public Subscriber {
    int runs, wickets, overs;
public:
    AverageScrore() {
        runs = wickets = overs = 0;
    }

    void update(int r, int w, int o) override {
        runs = r;
        wickets = w;
        overs = o;
        display();
    }

private:
    void display() {
        cout << "Average Score " << ((double)runs*(1.0))/overs << endl;
    }
};

class TotalScore : public Subscriber {
    int runs, wickets, overs;
public:
    TotalScore() {
        runs = wickets = overs = 0;
    }

    void update(int r, int w, int o) override {
        runs = r;
        wickets = w;
        overs = o;
        display();
    }

private:
    void display() {
        cout << "Total Score " << runs << endl;
    }
};

class CricketData : public Server {
    int runs, wickets, overs;
    unordered_set<shared_ptr<Subscriber>> subscribers;
public:
    CricketData() {
        runs = 10;
        wickets = 2;
        overs = 10;
    }

    void update(int r, int w, int o) {
        runs = r;
        wickets = w;
        overs = o;
        NotifySubscribers();
    }

    void AddSubscriber(shared_ptr<Subscriber> s) override {
        subscribers.insert(s);
    }

    void RemoveSubscriber(shared_ptr<Subscriber> s) override {
        subscribers.erase(s);
    }

    void NotifySubscribers() override {
        for (auto subscriber : subscribers) {
            subscriber->update(runs, wickets, overs);
        }
    }
};

int main() {
    auto cd = make_shared<CricketData>();

    auto s1 = make_shared<AverageScrore>();
    auto s2 = make_shared<TotalScore>();

    cd->AddSubscriber(s1);
    cd->AddSubscriber(s2);

    cd->update(5, 10, 15);

    cd->RemoveSubscriber(s1);
    cd->update(50, 10, 15);

    return 0;
}