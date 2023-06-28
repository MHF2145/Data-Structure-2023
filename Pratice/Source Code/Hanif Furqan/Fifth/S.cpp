//Harusnya ga salah, Bismillah
#include <bits/stdc++.h>

int countOrderedPairs(std::vector<int> &nums, int k);

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }

    int result = countOrderedPairs(nums, k);
    std::cout << result << std::endl;

    return 0;
}

int countOrderedPairs(std::vector<int> &nums, int k)
{
    int count = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            int concat1 = nums[i];
            int concat2 = nums[j];

            int temp = nums[j];
            while (temp > 0)
            {
                concat1 *= 10;
                temp /= 10;
            }
            concat1 += nums[j];

            temp = nums[i];
            while (temp > 0)
            {
                concat2 *= 10;
                temp /= 10;
            }
            concat2 += nums[i];

            if (concat1 % k == 0)
            {
                count++;
            }

            if (concat2 % k == 0 && concat1 != concat2)
            {
                count++;
            }
        }
    }

    return count;
}