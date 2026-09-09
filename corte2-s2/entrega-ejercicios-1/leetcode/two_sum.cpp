#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }

    return {};
}

int main() {
    vector<int> nums = {3, 2, 4};
    int target = 6;

    vector<int> resultado = twoSum(nums, target);

    cout << "[" << resultado[0] << ", " << resultado[1] << "]" << endl;

    return 0;
}