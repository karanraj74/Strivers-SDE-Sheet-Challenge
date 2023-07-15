class Solution {
public:
    int contains(string str,string b){
        if(str.find(b) != string::npos){
            return 1;
        }
        return 0;
    }
    int repeatedStringMatch(string a, string b) {
        string str=a;
        int repeat = b.size() / a.size();

        for(int i=0;i<repeat+2;i++){
            if(contains(str,b)){
                return (i+1);
            }
            str += a;
        }
        return -1;
    }
};
