class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int type_a = fruits[0], type_b = -1;
        int a_idx = 0, b_idx = -1;
        int cnt = 1;
        int sol = 1;
        for(int i=1; i<fruits.size(); i++){
            /*
            if(fruits[i]!=type_a && type_b == -1){
                type_b = fruits[i];
                b_idx = i;
                cnt++;
            }
            */
            if(fruits[i]!=type_a && fruits[i]!=type_b){
                if(b_idx < a_idx){
                    cnt = i-b_idx;
                    b_idx = i;
                    type_b = fruits[i];
                }
                else{
                    cnt = i - a_idx;
                    a_idx = i;
                    type_a = fruits[i];
                }
            }
            else if(fruits[i]==type_a){
                a_idx = i;
                cnt++;
            }
            else{
                b_idx = i;
                cnt++;
            }
            sol = max(cnt, sol);
        }
        return sol;
    }
};