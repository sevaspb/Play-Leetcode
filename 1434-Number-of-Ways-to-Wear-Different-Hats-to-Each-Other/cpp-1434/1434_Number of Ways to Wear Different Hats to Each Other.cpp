/*
Problem Link - here
https://leetcode.com/contest/biweekly-contest-25/problems/number-of-ways-to-wear-different-hats-to-each-other/

There are n people and 40 types of hats labeled from 1 to 40.
Given a list of list of integers hats, where hats[i] is a list of all hats preferred by the i-th person.
Return the number of ways that the n people wear different hats to each other.
Since the answer may be too large, return it modulo 10^9 + 7.

Example 1:
Input: hats = [[3,4],[4,5],[5]]
Output: 1
Explanation: There is only one way to choose hats given the conditions. 
First person choose hat 3, Second person choose hat 4 and last one hat 5.

Example 2:
Input: hats = [[3,5,1],[3,5]]
Output: 4
Explanation: There are 4 ways to choose hats
(3,5), (5,3), (1,3) and (1,5)

Example 3:
Input: hats = [[1,2,3,4],[1,2,3,4],[1,2,3,4],[1,2,3,4]]
Output: 24
Explanation: Each person can choose hats labeled from 1 to 4.
Number of Permutations of (1,2,3,4) = 24.

Example 4:
Input: hats = [[1,2,3],[2,3,5,6],[1,3,7,9],[1,8,9],[2,5,7]]
Output: 111

Constraints:
n == hats.length
1 <= n <= 10
1 <= hats[i].length <= 40
1 <= hats[i][j] <= 40
hats[i] contains a list of unique integers.

--------
Solution :

For me  better way to understand a problem is DP or not is -
      - See if you have choices for each object like we can take it or leave it 
      - see if there is no particular way to answer the question without trying everything 
      - the constraint (usually it is very small like 30,50)
Of course this is for basic classical DP . There are DP problems with 10^5 constraint ,  DP in a tree etc.
You can also check generalized way of finding a DP problem here

Now about this problem 
First thing come in mind every person has a choice of hat either to take it or leave it 
And as we want to find how many ways they can do this aka all possible ways 
hence this is a classical basic DP problem 
But the problem here is there could be 40 hats 
So 2^40 choices which is huge but with memorization this can be reduced
But wait again what we are gonna memorize ?

Well for DP problem if a step is repeated then we have to answer from memorization 
Now in this particular problem what steps will be repeated ?

some person taken some hat
the remaining person are left with  limited choices
in another orientation some person taken some hat 
the remaining person's are same as we are going from 1 to upwards (suppose)
in some the remaining choices can be also same so we can answer from our previous calculation

So we have to have position - indicating which person we are currently in
                                  mask -  indication if jth bit is 1 jth hat is taken 
You can find detail about mask here
Now as you know we need 2^40 big integer to keep the track of hats (which are taken which are not)
which is impossible 

So what we do now?

Observe that hats are 40 but people are 10 
every hat has a owner choice (the person's who want this hat)
also 2^10 is not that large 
So lets rearrange the problem a bit 


There are some hats (at most 40 )  who have a owner list (we can make it from the given hat list)
in how many way hats can choose there owner 

Hope you have understood till now.
Now we will understand how to solve it along with code 
start reading from the numberofways function

C++ code:

*/

class Solution {
public:
    #define mod 1000000007
    int dp[42][2048],n;
    vector<int>ok[42];
    int make(int pos,int taken)
    {
        if(__builtin_popcount(taken)==n)  //__builtin_popcount indicates number of set bit 
            return 1;// number of people hats have taken is n then we found a way
        if(pos>40)       // there are only 40 hats
            return 0;
        if(dp[pos][taken]!=-1)  // if we have come to this hat with this orientation of 
            return dp[pos][taken];   // people before then return answer from memory
        int p=0;
        p+=make(pos+1,taken);  // going to the next hat without taking any person 
        p%=mod;
        for(int i=0;i<ok[pos].size();i++)  // list of person for this hat 
        {
            if((taken & 1<<ok[pos][i])==0)  // if this person is yet not taken
            {
                int arrange= taken | 1<<ok[pos][i]; // take this person
                p+=make(pos+1,arrange); // go to the next hat with new orientation
                p%=mod;
            }
        }
        return dp[pos][taken]=p;  // memorize
    }
    int numberWays(vector<vector<int>>& hats) {
          n=hats.size(); // we have n people 
          memset(dp,-1,sizeof(dp));  // for memorization
          for(int i=0;i<hats.size();i++)
          {
              for(int j=0;j<hats[i].size();j++)
              {
                  ok[hats[i][j]].push_back(i+1);  //hats[i][j] have i+1 as an owner 
              }
          }
          return make(1,0); // make function will calculate the answer 
    }
};
