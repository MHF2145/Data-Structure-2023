#include <bits/stdc++.h>
using namespace std;

struct Bus
{
    int id;
    int rating;
    int capacity;

    bool operator<(const Bus &other) const
    {
        if (rating == other.rating)
        {
            return capacity < other.capacity;
        }
        return rating < other.rating;
    }
};

int main()
{
    priority_queue<Bus> bus_queue;
    int n, available_seats = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string command;
        cin >> command;
        if (command == "REGIS")
        {
            int id, rating, capacity;
            cin >> id >> rating >> capacity;
            available_seats += capacity;
            Bus new_bus = {id, rating, capacity};
            bus_queue.push(new_bus);
        }
        else if (command == "SEWA")
        {
            int capacity;
            cin >> capacity;
            if (available_seats < capacity)
            {
                cout << "Maaf tidak ada bus yang dapat memenuhi keinginan anda" << endl;
            }
            else
            {
                while (capacity > 0 && !bus_queue.empty())
                {
                    Bus bus_to_rent = bus_queue.top();
                    bus_queue.pop();
                    cout << bus_to_rent.id << " ";
                    capacity -= bus_to_rent.capacity;
                }
                cout << "telah berhasil disewa" << endl;
            }
        }
    }
    int remaining_buses = bus_queue.size();
    if (remaining_buses > 0)
    {
        cout << "Ada " << remaining_buses << " bus yang tersisa yaitu ";
        while (!bus_queue.empty())
        {
            Bus remaining_bus = bus_queue.top();
            cout << remaining_bus.id << " ";
            bus_queue.pop();
        }
    }
    else
    {
        cout << "Tidak ada bus yang tersisa" << endl;
    }
    return 0;
}
