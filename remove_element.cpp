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