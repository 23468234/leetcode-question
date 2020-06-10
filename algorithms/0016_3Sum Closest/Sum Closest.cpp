class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //主要步骤：先排序；最外一个大循环遍历元素；
        //左指针k+1，右指针length-1；根据与target的比较移动指针
        sort(nums.begin(),nums.end()); //排序
        int SumClosest=nums[0]+nums[1]+nums[2]; //初始化三数之和
        
        for(int k=0;k<(nums.size()-2);k++){
            int i=k+1; //定义左指针
            int j=nums.size()-1; //定义右指针

            while(i<j){
                //比较距离target的距离大小，更新SumClosest
                int temp=abs(target-(nums[k]+nums[i]+nums[j]));
                if(temp<abs(target-SumClosest)){
                    SumClosest=nums[k]+nums[i]+nums[j];
                }
                
                //比较和target的大小，移动左右指针
                if((nums[k]+nums[i]+nums[j])>=target){
                    j=j-1;
                }
                else if((nums[k]+nums[i]+nums[j])<target){
                    i=i+1;
                }
            }
        }
        return SumClosest;
    }
};