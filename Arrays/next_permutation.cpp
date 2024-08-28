1 BRUTE
generate all possible subsets using recursion and store them in a vector "all_permutations"
sort the vector "all_permutations"
then do linear search to find the next greater element
( the next element after the given in the array will be your answer )
image.pngin the example above, 
321 is then next element after 312
therefore 321 will be your answer
N! is the number of permutations of a number with N digits
Time complexity: N!xN + N!logN! + N!
Space complexity: N!
2 OPTIMAL
image.png

in the example above (2154300) you observed
moving from right to left in the number
(i.e. 1s digit to 10s, 100s, and so on)
(moving in this fashion because you need to find the just greater number, and thus i have to look for the smallest change in the number, and so moving from 1s)
break point is when the element is smaller than the prev (moving from right to left)
when you encounter the break point (21 // 54300),
image.png
i will call
21 as leftPart
54300 as rightPart (which is sorted in desc order always obviously, as it's the condition of break point)
now just see the just next largest element than ith element in rightPart i.e 3
swap the elements (i.e. 3 and 1)
now it becomes: 23 // 54100
now you just need to make the rightPart in ascending order to make it smallest number
if you observe rightPart is in desc order
if you reverse it is becomes asc order, which is what you want
23 // 00145 or 2300145 is now your next permutation of 2154300
3 STL function
next_permutation(A.begin(), A.end);
return A; 


CODE for 2-Optimal
class Solution {
public:
    void nextPermutation(vector<int>& A) {
    int n = A.size(); // size of the array.

    // Step 1: Find the break point, 1s digit to 10s, 100s, and so on
    int ind = -1; // break point
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] < A[i + 1]) {
            // index i is the break point
            ind = i;
            break;
        }
    }

    // EDGE CASE: If break point does not exist
    // It means the array was already sorted in desc order
    if (ind == -1) {
        // reverse the whole array:
        reverse(A.begin(), A.end());
        return ;
    }

    // Step 2: Find the next greater element in rightPart
    for (int i = n - 1; i > ind; i--) {
        if (A[i] > A[ind]) {
            swap(A[i], A[ind]);
            break;
        }
    }

    // Step 3: reverse the rightPart
    reverse(A.begin() + ind + 1, A.end());
    }
};
