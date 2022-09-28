#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    long long minimumTime(vector<int> &time, int totalTrips)
    {
        int numberOfBuses = time.size();
        vector<long> tipsPerBus(numberOfBuses, 0);
        int found = -1;
        int hour = 1;
        long leastTime;
        while (found < 0)
        {
            int sum = 0;
            for (int i = 0; i < numberOfBuses; i++)
            {
                long value = hour / time[i];
                tipsPerBus[i] = value;
                sum += value;
            }

            if (sum == totalTrips)
            {
                found = 1;
            }
            else
            {
                ++hour;
            }
        }
        return hour;
    }
};

class BinarySolution
{
public:
    long long minimumTime(vector<int> &time, int totalTrips)
    {
        long long int maxHour = 1e14;
        long long int minHour = 1;
        long long int result = 0;
        while (minHour < maxHour)
        {
            long long int mid = (maxHour + minHour) / 2;
            long long int numberOfTrips = 0;

            for (int tripTime : time)
            {
                numberOfTrips += mid / tripTime;
            }

            if (numberOfTrips >= totalTrips)
            { // success condition

                maxHour = mid;
            }
            else
            {
                minHour = mid + 1;
            }
        }

        return maxHour;
    }
};

int main()
{
    // vector<int> time{1, 2, 3};
    // int totalTrips = 5;

    // Solution s;
    // int response = s.minimumTime(time, totalTrips);
    // cout << response << endl;

    vector<int> time{2};
    int totalTrips = 1;
    BinarySolution bs;
    long response = bs.minimumTime(time, totalTrips);
    cout << response << endl;
}