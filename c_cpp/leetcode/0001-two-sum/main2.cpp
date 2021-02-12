// Time Complexity: O(n)
// Space Complexity: O(n)
// 数组有序，可以使用双指针，分别从头尾遍历
// 数组无序，使用 hash 结构，这个题目就是强调 hash 的使用场景
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> record;      
        for(int i = 0 ; i < nums.size() ; i ++){

            int complement = target - nums[i];
            if(record.find(complement) != record.end()){
                return vector<int>{i,record[complement]};
                // 用 res 中数据初始化返回值，参数是迭代器，左闭右开 
                // int res[] = {i, record[complement]};            //OK
                // return vector<int>(res, res + 2);               //OK
            }
            record[nums[i]] = i;
        }
        return {};
        //throw invalid_argument("the input has no solution");     //OK
        
    }   
};
