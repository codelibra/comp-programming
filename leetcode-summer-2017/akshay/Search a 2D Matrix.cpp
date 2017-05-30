#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int key)
    {
        if(a.empty())
            return false;
        if(a.size()==1 && a[0].empty())
            return false;

        int left =0;
        int right=a.size()-1;
        while(right-left>1)
        {
            int mid= (left + right)/2;
            if(a[mid][0]>key)
                right = mid;
            else if(a[mid][0]<key)
                left = mid;
            else
                return true;
        }
        int row=-1;
        if((a[left][0]<=key) && (a[right][0]>key))
            row = left;
        else if(a[right][0]<=key)
            row = right;
        else
            return false;

        left =0;
        right = a[row].size()-1;
        while(right-left>1)
        {
            int mid= (left + right)/2;
            if(a[row][mid]>key)
                right = mid;
            else if(a[row][mid]<key)
                left = mid;
            else
                return true;
        }
        if(a[row][right]==key || a[row][left]==key)
            return true;
        return false;
    }
};
