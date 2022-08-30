class Solution {
public:
    int minNumberOfHours(int iniEne, int iniExp, vector<int>& ene, vector<int>& exp) {
        int sumEne=0;
        int ans=0;
        for(int i=0;i<size(ene);i++)
        {
            sumEne+=ene[i];
        }
        if(sumEne>=iniEne)
        {
            ans+=(sumEne-iniEne)+1;
        }
        for(int i=0;i<size(exp);i++)
        {
            if(iniExp>exp[i])
                iniExp+=exp[i];
            else
            {
                ans+=(exp[i]-iniExp)+1;
                iniExp+=((exp[i]-iniExp)+1)+exp[i];
            }
            
        }
        return ans;
    }
};