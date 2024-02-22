class Solution {
public:
   int findPeakElement(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] < nums[mid + 1]) {
            // Peak element is on the right side
            left = mid + 1;
        } else {
            // Peak element is on the left side or mid is a peak
            right = mid;
        }
    }

    // At the end of the loop, left == right and it indicates the peak element
    return left;
}
};