/*
There are several cards arranged in a row, and each card has an associated number of points The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

Example 1:
Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.

Example 2:
Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.

Example 3:
Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.

Example 4:
Input: cardPoints = [1,1000,1], k = 1
Output: 1
Explanation: You cannot take the card in the middle. Your best score is 1. 

Example 5:
Input: cardPoints = [1,79,80,1,1,1,200,1], k = 3
Output: 202

Constraints:

1 <= cardPoints.length <= 10^5
1 <= cardPoints[i] <= 10^4
1 <= k <= cardPoints.length


Solution :

You may have seen its level 1 problem 
Well let me change the problem statement a little bit then you will understand why 

You need to find smallest subarray with cardPoints.size()-k elements
Because the remaining k elements you will take 
So its a classical basic sliding window problem now
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// You can use cerr instead of cout to debug. cerr writes to the standard error stream which is not seen by the online judge.
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl;
#define INF         (unsigned)!((int)0)
#define BETTER_INF  ((unsigned) ~0)


typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
      ull len=cardPoints.size()-k;  // the size of required subarray
      ull tot=0,sum=0,ans=BETTER_INF;
        for(ull i=0;i<cardPoints.size();i++)
        {
            if(len==0)  // in case k = cardPoints.size()
               ans=0;
            sum+=cardPoints[i];  // keeping the sum of subarray of length len
            tot+=cardPoints[i];  // keeping total sum
            if(i>=len-1)   // from here first subarray starts
            {
                 ans=min(ans,sum);  // keeping the sum with minimum subarray
                sum-=cardPoints[i-len+1]; // eliminating the rightmost element from subarray
            }
        }
        return tot-ans; 
    }
};


int main() {
	fastio;

    #ifndef ONLINE_JUDGE
    // ifstream cin("input.txt"); // Read from file via stdin
    // ofstream cout("output.txt"); // Write to file via stdout
    // ofstream cerr("error.txt"); // Write to file via stderr
    #endif

    vector<int>cardPoints1 = {1,2,3,4,5,6,1};
    cout << Solution().maxScore(cardPoints1, 3) << endl;
    // 12

    vector<int>cardPoints2 = {2, 2, 2};
    cout << Solution().maxScore(cardPoints2, 2) << endl;
    // 4

    vector<int>cardPoints3 = {9,7,7,9,7,7,9};
    cout << Solution().maxScore(cardPoints3, 7) << endl;
    // 55

    vector<int>cardPoints4 = {1,1000,1};
    cout << Solution().maxScore(cardPoints4, 1) << endl;
    // 1

    vector<int>cardPoints5 = {1,79,80,1,1,1,200,1};
    cout << Solution().maxScore(cardPoints5, 3) << endl;
    // 202

    vector<int>cardPoints6 = {1};
    cout << Solution().maxScore(cardPoints6, 1) << endl;
    // 1

	return 0;
}
