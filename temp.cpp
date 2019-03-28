//solution 1

bool inter(int index,int a,vector<int>& nums){
    bool temp;
    if(index+a >= nums.size()-1){return true;}
    else{
        for(int i = index+1;i<=a+index&&i<nums.size();i++){
            temp = inter(i,nums[i],nums);
            if(temp == true){return temp;}
        }
    }
    return false;
}
class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool refluse = inter(0,nums[0],nums);
        return refluse;
    }
};



//solution 2
bool inter(int index,int a,vector<int>& nums,int* ch){
    bool temp;
    if(index+a >= nums.size()-1){return true;}
    else{
        ch[index] = 1;
        for(int i = index+1;i<=a+index&&i<nums.size();i++){
            if(ch[i] == 1){continue;}
            temp = inter(i,nums[i],nums,ch);
            if(temp == true){return temp;}
        }
    }
    return false;
}


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ch_len = nums.size();
        int ch[ch_len];
        memset(ch,0,sizeof(ch));
        bool refluse = inter(0,nums[0],nums,ch);
        return refluse;
    }
};

//solution 3;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int nums_len = nums.size();
        int ch[nums_len];
        memset(ch,0,sizeof(ch));
        for(int i = 0;i<nums_len;i++){
            if(nums[i]+i >= nums_len-1){ch[i] = 1;}
        }
        for(int i = nums_len-1;i>=0;i--){
            if(ch[i] == 0){
                for(int z = i+1;z<=i+nums[i] && z<nums_len;z++){
                    if(ch[z] == 1){ch[i] = 1;break;}
                }
            }
        }
        if(ch[0] == 1){return true;}
        else{return false;}
    }
};
//solution 4
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int nums_len = nums.size();
        int node_number = nums_len - 1;
        for(int i = nums_len-1;i>=0;i++){
            if(i+nums[i] >= node_number){node_number = i;}
        }
        if(node_number == 0){return true;}
        else{return false;}
   }
};

