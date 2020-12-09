#include <iostream>
using namespace std;
class Solution{
public:
    vector<int> twoSum(vector<int>&nums, int target)
    //our function that inputs array nums and target and outputs indices that add up to target

    {
        vector<int> ans;
        int i;
        //where we will store our two indices p.s its a vectorized array
        unordered_map<int ,int> mpp;
        //creates our hashtable/hashmap called mpp taking int values of both key and value
        for(i=0;i<nums.size(),i++)
        {
            if(mpp.find(target-nums[i])!=mpp.end())
            //basically condition to check if target-nums[i] exists in hashmap or not
            {
                ans.pushback(mpp[target-nums[i]]);
                //puts index of hashmap containing target -nums[i]in ans
                ans.pushback(i);
                //puts index of nums[i]of array in ans
                return ans;

            }
            mpp[nums[i]]=i;
            //puts the key value pair nums[i],i in hashmap

        }
        return ans;

    }

};
