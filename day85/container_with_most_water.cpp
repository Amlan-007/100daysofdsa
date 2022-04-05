#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height){
    int max_area=0;
    int left=0,right=height.size()-1;
    while(left<right){
        int area=min(height[left],height[right])*(right-left);
        max_area=max(max_area,area);
        if(height[left]<height[right])
            left++;
        else
            right--;
    }
    return max_area;
}

int main(){
    vector<int> height={1,8,6,2,5,4,8,3,7};
    cout<<maxArea(height);
    return 0;
}