//搜索旋转排序数组
//假设按照升序排序的数组在预先未知的某个点上进行了旋转。
//( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
//搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
//你可以假设数组中不存在重复的元素。
//你的算法时间复杂度必须是 O(log n) 级别。
//https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/yi-bian-er-fen-cha-zhao-c-by-biff/

#include <vector>
using namespace std;

int search(vector<int>& v, int target) 
{
    if(v.empty())
    {
        return -1;
    }
    else if(v.size() == 1)
    {
        return v[0] == target ? 0 : -1;
    };
    int l_idx = 0;
    int r_idx = v.size() - 1;
    while(l_idx <= r_idx)
    {
        int mid = l_idx + (r_idx - l_idx) / 2;
        if(v[mid] == target)
        {
            return mid;
        };

        if(v[l_idx] < v[r_idx])  //整个区间递增,正常二分
        {
            if(v[mid] > target)
            {
                r_idx = mid - 1;
            }
            else
            {
                l_idx = mid + 1;
            }
        }
        else //跨递增区间
        {
            if(target < v[0]) //target在第二递增区间
            {
                if(v[mid] < v[0]) //mid也在第二递增区间
                {
                    if(v[mid] < target)
                    {
                        l_idx = mid + 1;
                    }
                    else
                    {
                        r_idx = mid - 1;
                    }
                }
                else  //mid在第一递增区间
                {
                   l_idx = mid + 1;
                }
            }
            else //target在第一递增区间
            {
                if(v[mid] < v[0]) //mid在第二递增区间
                {
                    r_idx = mid - 1;
                }
                else  //mid在第一递增区间
                {
                   if(v[mid] < target)
                    {
                        l_idx = mid + 1;
                    }
                    else
                    {
                        r_idx = mid - 1;
                    }
                }
            }
        }
    };

    return -1;
};


int main()
{
    vector<int> a{4,5,6,7,0,1,2};
    int b = search(a, 0);
    return 0;
}

