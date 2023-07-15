class Solution {
public:
    int myAtoi(string s) {
       string act;
       int n = s.size();
       int i = 0;
       
       while(i < n && s[i] != '+' && s[i] != '-' && !isdigit(s[i])){
           if(s[i] != '-' && s[i] != '+' && !isdigit(s[i]) && s[i] != ' ') return 0;
           i++;
       }
    //    cout<<i<<endl;
       bool isNeg = false;
       if(s[i] == '-'){
           isNeg = true;
           i++;
       }
       if(isNeg && s[i] == '+') return 0;
       if(s[i] == '+'){
           i++;
       }
       int j = i;
       while(j < n && isdigit(s[j])){
           j++;
       }
    //    cout<<j<<endl;
       long long ans = 0;
       for(int k=i;k<j;k++){
           ans = ans * 10 + (s[k]-'0');
           if(!isNeg && ans >= INT_MAX){
               return INT_MAX;
           }
           if(isNeg && ans * (-1) <= INT_MIN){
               return INT_MIN;
           }
       }
       if(isNeg){
           return ((-1) * (int)(ans));
       }
       return (int)(ans);
    }
};
