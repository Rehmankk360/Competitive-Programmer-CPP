class Solution {
public:
    int maxArea(vector<int>& height) {
        
        auto start=0;
        int end=height.size()-1;
        int maxm = 0;
        
        while(start<end){
            
            maxm=max(maxm,(end-start)*min(height[start],height[end]));
            
            if(height[start]>height[end]) end--;
            else start++;
        }
        return maxm;
    }
};