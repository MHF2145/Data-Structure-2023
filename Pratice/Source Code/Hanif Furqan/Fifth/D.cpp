#include <iostream>
#include <queue>
#include <vector>

struct Product
{
    int id;
    int arrivalTime;
    int processingTime;
    int blockTime;
    int blockDuration;
};

struct Event
{
    int time;
    int productId;
    std::string action;
};

bool operator>(const Event &a, const Event &b)
{
    return a.time > b.time;
}

void scheduleMachine(int timeout, std::vector<Product> &products)
{
    std::priority_queue<Event, std::vector<Event>, std::greater<Event>> events;
    std::queue<Product> queue;
    int currentTime = 0;

    for (const auto &product : products)
    {
        events.push({product.arrivalTime, product.id, "Arrival"});
        queue.push(product);
    }

    while (!events.empty())
    {
        Event event = events.top();
        events.pop();
        currentTime = event.time;

        if (event.action == "Arrival")
        {
            Product product = queue.front();
            queue.pop();

            if (currentTime >= product.arrivalTime)
            {
                int remainingTime = product.processingTime;

                if (remainingTime > timeout)
                {
                    events.push({currentTime + timeout, product.id, "Timeout"});
                    remainingTime -= timeout;
                }
                else
                {
                    events.push({currentTime + remainingTime, product.id, "Finish"});
                    remainingTime = 0;
                }

                if (remainingTime > 0)
                {
                    events.push({currentTime + product.blockTime, product.id, "Block"});
                    product.processingTime = remainingTime;
                    queue.push(product);
                }
            }

            if (!queue.empty())
            {
                events.push({currentTime, queue.front().id, "Start"});
            }
        }
        else if (event.action == "Start")
        {
            Product product = queue.front();
            queue.pop();
            events.push({currentTime + product.processingTime, product.id, "Finish"});
        }
        else if (event.action == "Timeout")
        {
            Product product = products[event.productId - 1];
            product.processingTime -= timeout;

            if (product.processingTime > 0)
            {
                events.push({currentTime + product.blockTime, product.id, "Block"});
                queue.push(product);
            }
        }
        else if (event.action == "Block")
        {
            Product product = products[event.productId - 1];
            product.blockTime += product.blockDuration;
            events.push({currentTime, product.id, "Arrival"});
        }
        else if (event.action == "Finish")
        {
            std::cout << currentTime << ": Mesin menyelesaikan produk " << event.productId << std::endl;
        }
    }
}

int main()
{
    int timeout;
    std::cin >> timeout;

    std::vector<Product> products;
    int id = 1;

    while (true)
    {
        int arrivalTime, processingTime, blockTime, blockDuration;
        std::cin >> arrivalTime;

        if (arrivalTime == -1)
        {
            break;
        }

        std::cin >> processingTime >> blockTime >> blockDuration;
        products.push_back({id++, arrivalTime, processingTime, blockTime, blockDuration});
    }

    scheduleMachine(timeout, products);

    return 0;
}
