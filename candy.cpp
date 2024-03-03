/*There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.
[1,2,4,5,2,1,0]
[1,2,3,4,2,2,1]
at index=0---> C=1 , P = 0       C=1 , P=0
at index=1---> P=1(bcz Condition Continous satisfy) , C+=P+1 (index1>index2)   P=1 , C=1+1+1
at index=2--->P=2 , C+=P+1 (index2>index1)   P=2, C=2+3+1
at index=3---> P=3 , C+=P=1 (index3>index2) P=3 , C=3+6+1
at index=4---> p=1 , C+=P+1 (index4<index3 && index4>index5)  P=1 , C=1+10+1
agr aesa na hota dono me index4 chota hota tu only P=0 , C+1;
at index=5--> p=1 , C+=P+1 (index5>index4 and index5>index6) P=1 , C=1+12+1
at index=6--> P=0 , C+=P+1 (index6<index5) P=0 , C=0+14+1

agr index i < index i+1 tu P=0 C+=P+1  at index 0 case
agr index i > index i+1 tu P=1 and C+=P+1  at index 0 case

agr index i > index i-1 && index i < index i+1 then  P++ , C+=P+1  this also valid for last one
agr index i < index i-1 && index i < index i+1 then P=0 ,C+=P+1   this also valid for last one

[1,2,87,87,87,2,1]
[1,2,3,1,3,2,1]


*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);

        // Traverse from left to right, ensuring each child has more candies than the left neighbor if their rating is higher
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Traverse from right to left, ensuring each child has more candies than the right neighbor if their rating is higher
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        // Calculate the total number of candies needed
        int totalCandies = 0;
        for (int candy : candies) {
            totalCandies += candy;
            cout<<candy<<", ";
        }
        cout<<endl;

        return totalCandies;
    }
};

int main() {
    Solution sol;
    vector<int> ratings = {1,2,87,87,87,2,1};
    int result = sol.candy(ratings);
    cout << "Minimum number of candies needed: " << result << endl;

    return 0;
}

