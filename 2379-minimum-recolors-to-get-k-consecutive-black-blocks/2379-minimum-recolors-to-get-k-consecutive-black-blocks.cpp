class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int W=0;
        int B=0;
        for (int i=0;i<k;++i) (blocks[i]=='B'?++B:++W);
        int c=0;
        int ans=W;
        for (int i=1;i<blocks.size()-k+1;++i){
            (blocks[i+k-1]=='B'?++B:++W);
            (blocks[c]=='B'?--B:--W);
            ++c;
            ans=min(ans,W);
        }
        return ans;
    }
};