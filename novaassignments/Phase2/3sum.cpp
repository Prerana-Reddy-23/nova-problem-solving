#include <iostream>
#include <vector>
#include <algorithm>
#include <limits> // for INT_MAX

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min_diff = INT_MAX;
        int closest_sum = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int p1 = 0; p1 < n - 1; ++p1) {
            int p2 = p1 + 1, p3 = n - 1;
            while (p2 < p3) {
                int sum = nums[p1] + nums[p2] + nums[p3];
                if (sum > target)
                    p3--;
                else if (sum < target)
                    p2++;
                else
                    return sum;
                int diff = abs(sum - target);
                if (diff < min_diff) {
                    min_diff = diff;
                    closest_sum = sum;
                }
            }
        }
        return closest_sum;
    }
};

int main() {
    vector<int> nums;
    int n, target, temp;

    // Input for nums
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the elements of the array, separated by spaces: ";
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        nums.push_back(temp);
    }

    // Input for target
    cout << "Enter the target sum: ";
    cin >> target;

    Solution sol;
    int closestSum = sol.threeSumClosest(nums, target);

    cout << "The three-sum closest to the target is: " << closestSum << endl;

    return 0;
}