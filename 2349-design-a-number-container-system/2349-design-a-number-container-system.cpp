class NumberContainers {
public:
    unordered_map<int,set<int>>map_nums; 
    unordered_map<int,int>map_index;
    NumberContainers() {
        
    }
    void change(int index, int number) {
         if(map_index.find(index)!=map_index.end())
         {
             int num=map_index[index];  
             if(map_nums[num].size()) map_nums[num].erase(index);
             if(map_nums[num].size()==0)
                 map_nums.erase(num);
         }
          map_index[index]=number;
            map_nums[number].insert(index);    
    }
    
    int find(int number) {
        if(map_nums.find(number)==map_nums.end())
            return -1;
        return *map_nums[number].begin();
    }
};