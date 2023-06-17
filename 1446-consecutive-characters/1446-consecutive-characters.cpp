class Solution {
public:
    int maxPower(string s) {
        
        int n = s.size();

        int i =0;

        int j =1;

        int sum = 1;

        int count =0;

        while( j < n){
            if(s[j-1] == s[j]){
                sum++;
            }
            else if(s[j-1] != s[j]){
                count = max(count,sum);

                i = j;

                sum = 1;
            }
            j++;
        }

        count = max(count,sum);

        return count;
    }
};
