class Solution {
public:
    
    void bfs(vector<int>& edges, int pos,unordered_map<int,bool>& v,int j,unordered_map<int,int>&m){
        if(pos==-1 || v[pos])
            return ;
        m[pos]=j;
        v[pos]=true;
        bfs(edges,edges[pos],v,j+1,m);
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int ans=-1;
        int cmp=INT_MAX;
        unordered_map<int,bool>v1;
        unordered_map<int,bool>v2;
        unordered_map<int,int>m1;
        unordered_map<int,int>m2;
        bfs(edges,node1,v1,0,m1);
        bfs(edges,node2,v2,0,m2);
        for(int i=0;i<edges.size();i++){
            if(m1.find(i)!=m1.end() && m2.find(i)!=m2.end()){
                int t=max(m1[i],m2[i]);
                if(cmp>t){
                    ans=i;
                    cmp=t;
                }
                else if(cmp==t && ans>i)
                    ans=i;
            }
        }
        return ans;
    }
};