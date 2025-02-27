#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> dq;
    vector<int> ans;

    // first window of k size
    for (int i = 0; i < k; i++)
    {
        // chote element remove kr do
        while (!dq.empty() && nums[i] >= nums[dq.back()])
        {
            dq.pop_back();
        }
        // inserting index, so that we can checkout of window element
        dq.push_back(i);
    }

    // store answer for first window
    ans.push_back(nums[dq.front()]);

    // remaining window ko process karna h
    for (int i = k; i < nums.size(); i++)
    {
        // remove out of window element
        if (!dq.empty() && i - dq.front() >= k)
        {
            dq.pop_front();
        }

        // ab firse current element ke liye chotte element ko remove kerna h
        while (!dq.empty() && nums[i] >= nums[dq.back()])
        {
            dq.pop_back();
        }
        // inserting index, so that we can checkout of window element
        dq.push_back(i);

        // current window kea answer store karna h
        ans.push_back(nums[dq.front()]);
    }
    return ans;
};

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> ans = maxSlidingWindow(nums, k);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}