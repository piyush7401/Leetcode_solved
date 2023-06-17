class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int n = nums.size();

        int i =0;

        int j =0;

        int sum =0;
        int count =0;

        while( j < n){
            if(nums[j] == 1){
                sum++;
            }
            else if(nums[j] == 0){
                if(k != 0){
                    sum++;
                    k--;

                    cout<<sum<<"\n";

                    count = max(count,sum);
                }
                else if( k == 0){

                    cout<<sum<<"\n";

                    count = max(count,sum);

                    while(nums[i] != 0){
                        i++;
                    }

                    i++;

                    sum = j - i + 1;

                    cout<<sum<<"\n";

                    count = max(count,sum);

                }
            }
            j++;
        }

        count = max(sum,count);

        return count;
    }
};