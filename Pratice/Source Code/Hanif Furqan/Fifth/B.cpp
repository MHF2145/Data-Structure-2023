#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

struct Circle
{
    double x;
    double y;
    double r;
};

double calculateMinRubberLength(const std::vector<Circle> &circles)
{
    double totalLength = 0.0;
    int n = circles.size();

    for (int i = 1; i < n; i++)
    {
        double dx = circles[i].x - circles[i - 1].x;
        double dy = circles[i].y - circles[i - 1].y;
        double distance = std::hypot(dx, dy);

        double overlap = distance - circles[i].r - circles[i - 1].r;
        if (overlap > 0)
        {
            totalLength += overlap;
        }
        else
        {
            double maxRadius = std::max(circles[i].r, circles[i - 1].r);
            totalLength += maxRadius - distance + std::min(circles[i].r, circles[i - 1].r);
        }
    }

    // Consider the connection between the first and last circle
    double dx = circles[0].x - circles[n - 1].x;
    double dy = circles[0].y - circles[n - 1].y;
    double distance = std::hypot(dx, dy);

    double overlap = distance - circles[0].r - circles[n - 1].r;
    if (overlap > 0)
    {
        totalLength += overlap;
    }
    else
    {
        double maxRadius = std::max(circles[0].r, circles[n - 1].r);
        totalLength += maxRadius - distance + std::min(circles[0].r, circles[n - 1].r);
    }

    return totalLength;
}

int main()
{
    int n;
    std::cout << std::fixed << std::setprecision(3); // Mengatur presisi desimal menjadi 3 angka

    while (std::cin >> n && n != -1)
    {
        std::vector<Circle> circles(n);
        for (int i = 0; i < n; i++)
        {
            std::cin >> circles[i].x >> circles[i].y >> circles[i].r;
        }

        double minRubberLength = calculateMinRubberLength(circles);
        std::cout << minRubberLength << std::endl;
    }

    return 0;
}
