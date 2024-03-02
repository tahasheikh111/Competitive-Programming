/*Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.*/


#include <iostream>

#include <vector>
using namespace std;

class Solution {
public:
    Solution(){}

    int removeElement(vector<int>& nums, int val) {
        int k=0;
        int flag=0;
        int end=nums.size()-1;
        for(int i=0;i<end+1;i++){
            if(nums[i]==val){
                while(nums[i]==nums[end]){
                    if(i==end){ 
                        flag=1;
                        break;
                    }
                    end--;
                }
                if(flag==1){
                    break;
                }
                k++;
                nums[i]=nums[end];
                nums[end]=val;
                end--;
            }
            else{
                cout<<"hy";
                k++;
            }
        }
        nums.erase(nums.begin() + k, nums.end());

        return k;
    }
};

int main()
{
    vector<int> nums1 = {1};
    Solution s1;
    cout<<"value which is different is "<<s1.removeElement(nums1, 1)<<endl;
    for (auto i : nums1)
    {
        cout << i << endl;
    }
}