class Solution {
public:
   
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        if(n==2){
            return "11";
        }
        string s="11";
        string ans;
        while(n!=2){
            ans="";
            int count=1;
            for(int i=0;i<s.size();i++){
                if(i==s.size()-1){
                    ans=ans+to_string(count)+s[i];
                }
                else if(s[i]==s[i+1]){
                    count++;
                }
                else{
                    ans=ans+to_string(count)+s[i];
                    count=1;  
                }
            }
             s=ans;
             n--;
        }
        return ans;
    }
};
