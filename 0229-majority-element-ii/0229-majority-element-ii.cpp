class Solution {
public:
   vector<int> majorityElement(vector<int>& nums) {
    unordered_map<int, int> freqMap;
    vector<int> result;

    // Count frequency of each element
    for (int num : nums)
        freqMap[num]++;

    // Check if frequency is more than n/3
    int n = nums.size();
    for (auto& pair : freqMap) {
        if (pair.second > n / 3)
            result.push_back(pair.first);
    }

    return result;
}

};