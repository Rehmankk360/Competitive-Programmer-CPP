class Solution {
public:

vector<int> addToArrayForm(vector<int>& num, int k) {
    int carry=k,res;
   
    for(int i=0;i<num.size();i++){
        res=carry+num[num.size()-i-1];
        num[num.size()-i-1]=res%10;
        carry=res/10;
    }
	
    while(carry!=0){
        num.insert(num.begin(),carry%10);
        carry/=10;
    }
	
    return num;
}
};