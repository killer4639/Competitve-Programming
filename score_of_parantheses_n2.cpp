class Solution {
public:
    int solve(string& s,int i,int j){
        if(i>=j){
            return 0;
        }
        if(i==j-1){
            return 1;  // rule no. 1
        }
        int cnt=0;
        for(int idx=i;idx<=j-1;idx++){
            if(s[idx]=='('){
                cnt++;
            }
            else{
                cnt--;
            }
            if(cnt==0){
                return (solve(s,i,idx)+solve(s,idx+1,j));
            }
        }
        return 2*solve(s,i+1,j-1);
        
    }
    int scoreOfParentheses(string S) {
        return solve(S,0,S.length()-1);
    }
};
