#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

vector<int> findKthSmallest(vector<int> nums, int k) 
{
    if(k >= nums.size() || nums.size() == 0)
        return nums;
    vector<int> heap(nums.begin(), nums.begin() + k);
    sort(heap.begin(),heap.end(),cmp);
    int p , q;
    for(int i=k;i<nums.size();i++)
    {
        if(nums[i] < heap[0])
        {
            heap[0] = nums[i];
            p = 0;
            
            while(p<k)
            {
                q = 2 * p + 1;
                if( p >= k)
                    break;
                if((q<k-1) && (heap[q+1]>heap[q]))
                    q = q+1;
                if(heap[q] > heap[p])
                {
                    swap(heap[p],heap[q]);
                    p = q;
                }
                else
                    break;
            }
        }
    }
    return heap;
}

int main()
{
    int n[] = {4,5,1,6,2,7,3,8};
    vector<int> nums(n,n+8);
    nums = findKthSmallest(nums,4);
    for(int i=0;i<nums.size();i++)
        cout<<nums[i]<<" ";
    cout<<endl;
    return 0;
}