class Solution {
public:
    string reverseWords(string s) {
        string ans;
        string word;
        stack<string>st;
        
        for(int i=0;i<s.size();i++){
            if(s[i]==' ' && word.size()!=0){
                st.push(word);
                word="";
            }
            else if(s[i]==' '){
                continue;
            }
            else{
                word=word+s[i];
            }
        }
        if(word.size()!=0){
            st.push(word);
        }
        while(!st.empty()){
            ans=ans+st.top()+' ';
            st.pop();
        }
        ans.pop_back();
        return ans;
    }
};
