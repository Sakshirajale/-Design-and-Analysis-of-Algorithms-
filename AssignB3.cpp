//Implement a problem of minimum work to be done per day to finish given tasks within D days problem. 
//Statement: Given an array task[] of size N denoting amount of work to be done for each task, the problem 
//is to find the minimum amount of work to be done on each day so that all the tasks can be completed in at 
//most D days. Note: On one day work can be done for only one task. 
//Input: task[] = [3, 4, 7, 15],  D = 10        Output: 4 
//Input: task[] = [30, 20, 22, 4, 21], D = 6    Output: 22 
#include <iostream>
#include <vector>
#include <numeric>  // For accumulate
#include <algorithm> // For max_element
using namespace std;

// Function to check if the tasks can be completed within D days
bool canFinish(vector<int>& tasks, int maxWorkPerDay, int D) {
    int daysRequired = 1;
    int currentWork = 0;

    for (int task : tasks) {
        if (currentWork + task > maxWorkPerDay) {
            daysRequired++;
            currentWork = task;
        } else {
            currentWork += task;
        }
    }

    return daysRequired <= D;
}

// Function to find the minimum work per day to finish tasks in D days
int minWorkPerDay(vector<int>& tasks, int D) {
    int maxTask = *max_element(tasks.begin(), tasks.end());
    int totalWork = accumulate(tasks.begin(), tasks.end(), 0);

    // Binary search between maxTask and totalWork
    int left = maxTask, right = totalWork;
    int result = totalWork;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canFinish(tasks, mid, D)) {
            result = mid;  // If we can finish, try for a smaller workload
            right = mid - 1;
        } else {
            left = mid + 1;  // If we cannot finish, increase the workload
        }
    }

    return result;
}

int main() {
    // Test case 1
    vector<int> tasks1 = {3, 4, 7, 15};
    int D1 = 10;
    cout << "Minimum work per day (Test case 1): " << minWorkPerDay(tasks1, D1) << endl;

    // Test case 2
    vector<int> tasks2 = {30, 20, 22, 4, 21};
    int D2 = 6;
    cout << "Minimum work per day (Test case 2): " << minWorkPerDay(tasks2, D2) << endl;

    return 0;
}
