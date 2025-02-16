#include <iostream>
#include <vector>
#include <algorithm> // Required for sort
#include <iomanip>   //Required for setprecision

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n; j++) {
                if (j != (i + 1) && nums[j] == nums[j - 1]) continue;
                int k = j + 1;
                int l = n - 1;
                while (k < l) {
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if (sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k - 1]) k++;
                        while (k < l && nums[l] == nums[l + 1]) l--;
                    } else if (sum < target)
                        k++;
                    else
                        l--;
                }
            }
        }
        return ans;
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
    vector<vector<int>> result = sol.fourSum(nums, target);

    cout << "Four-sum combinations that equal the target:" << endl;
    if (result.empty()) {
        cout << "No combinations found." << endl;
    } else {
        for (const auto& combination : result) {
            cout << "[";
            for (size_t i = 0; i < combination.size(); ++i) {
                cout << combination[i];
                if (i < combination.size() - 1) {
                    cout << ", ";
                }
            }
            cout << "]" << endl;
        }
    }

    return 0;
}