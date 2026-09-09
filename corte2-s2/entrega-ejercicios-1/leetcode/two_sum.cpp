#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> vistos;

    for (int i = 0; i < nums.size(); i++) {
        int complemento = target - nums[i];

        if (vistos.find(complemento) != vistos.end()) {
            return {vistos[complemento], i};
        }

        vistos[nums[i]] = i;
    }

    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> resultado = twoSum(nums, target);

    cout << "[" << resultado[0] << ", " << resultado[1] << "]" << endl;

    return 0;
}