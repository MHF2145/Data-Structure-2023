#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Product {
    int id;
    int arrivalTime;
    int processingTime;
    int blockTime;
    int blockDuration;
    int remainingTime;

    Product(int _id, int ti, int lpi, int bi, int lbi) {
        id = _id;
        arrivalTime = ti;
        processingTime = lpi;
        blockTime = bi;
        blockDuration = lbi;
        remainingTime = lpi;
    }
};

struct Event {
    int time;
    int machineId;
    int productId;
    string activity;

    Event(int _time, int _machineId, int _productId, string _activity) {
        time = _time;
        machineId = _machineId;
        productId = _productId;
        activity = _activity;
    }
};

struct Machine {
    int id;
    int timeout;
    int currentTime;
    int currentProduct;
    bool isBlocked;

    Machine(int _id, int _timeout) {
        id = _id;
        timeout = _timeout;
        currentTime = 0;
        currentProduct = -1;
        isBlocked = false;
    }
};

bool operator>(const Event& a, const Event& b) {
    return a.time > b.time;
}

vector<Event> simulateProduction(int timeout, vector<Product>& products) {
    priority_queue<Event, vector<Event>, greater<Event>> eventQueue;
    vector<Machine> machines;
    queue<int> productQueue;

    // Initialize machines
    for (int i = 0; i < products.size(); i++) {
        Machine machine(i, timeout);
        machines.push_back(machine);
        productQueue.push(i);
    }

    // Start the production
    int currentTime = 0;
    while (!productQueue.empty()) {
        int productId = productQueue.front();
        productQueue.pop();
        machines[productId].currentProduct = productId;
        machines[productId].currentTime = currentTime;
        eventQueue.push(Event(currentTime, machines[productId].id, productId, "Mesin mengerjakan"));

        int remainingTime = products[productId].remainingTime;
        if (remainingTime <= machines[productId].timeout) {
            // Product completed before timeout
            currentTime += remainingTime;
            products[productId].remainingTime = 0;
            eventQueue.push(Event(currentTime, machines[productId].id, productId, "Mesin menyelesaikan"));
            machines[productId].currentProduct = -1;
        } else {
            // Product blocked
            currentTime += machines[productId].timeout;
            products[productId].remainingTime -= machines[productId].timeout;
            eventQueue.push(Event(currentTime, machines[productId].id, productId, "Mesin memblokir"));
            machines[productId].isBlocked = true;
        }
    }

    vector<Event> events;
    while (!eventQueue.empty()) {
        events.push_back(eventQueue.top());
        eventQueue.pop();
    }

    return events;
}

int main() {
    int timeout;
    cin >> timeout;

    vector<Product> products;
    int id = 1;
    int ti, lpi, bi, lbi;
    while (cin >> ti) {
        if (ti == -1) {
            break;
        }
        cin >> lpi >> bi >> lbi;
        products.push_back(Product(id, ti, lpi, bi, lbi));
        id++;
    }

    vector<Event> events = simulateProduction(timeout, products);

    for (const auto& event : events) {
        cout << event.time << ": " << event.activity << " produk " << event.productId << endl;
    }

    return 0;
}
