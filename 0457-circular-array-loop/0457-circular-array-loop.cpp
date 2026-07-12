class Solution {
public:

    int getNext(vector<int>& nums, int index)
    {
        int n = nums.size();

        int next = (index + nums[index]) % n;

        if(next < 0)
            next += n;

        return next;
    }

    bool circularArrayLoop(vector<int>& nums) {

        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            bool forward = nums[i] > 0;

            int slow = i;
            int fast = i;

            while(true)
            {
                // Move slow one step
                slow = getNext(nums, slow);

                // Wrong direction
                if((nums[slow] > 0) != forward)
                    break;

                // Move fast first step
                fast = getNext(nums, fast);

                if((nums[fast] > 0) != forward)
                    break;

                // Move fast second step
                fast = getNext(nums, fast);

                if((nums[fast] > 0) != forward)
                    break;

                // Found cycle
                if(slow == fast)
                {
                    // Ignore one-element cycle
                    if(slow == getNext(nums, slow))
                        break;

                    return true;
                }
            }
        }

        return false;
    }
};