class Solution {
public:
    int romanToInt(string s) {
        map<char,int>mp;
        mp.insert(make_pair('I',1));
        mp.insert(make_pair('V',5));
        mp.insert(make_pair('X',10));
        mp.insert(make_pair('L',50));
        mp.insert(make_pair('C',100));
        mp.insert(make_pair('D',500));
        mp.insert(make_pair('M',1000));
        int n=s.size();
        int num=0;
        int sum=0;
        for(int i=0;i<n;){
            if(i==n-1 || mp[s[i]]>=mp[s[i+1]]){
                num=mp[s[i]];
                i++;
            }
            else{
                num=mp[s[i+1]]-mp[s[i]];
                i=i+2;
            }
            sum=sum+num;
        }
        return sum;
    }
};
