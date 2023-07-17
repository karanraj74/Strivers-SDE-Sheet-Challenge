class Solution {
public:
    int compareVersion(string v1, string v2) {
        v1.push_back('.');
        v2.push_back('.');
        int n = v1.size();
        int m = v2.size();
        int i = 0, j = 0;

        while(i < n || j < m){
            int a = 0;
            while(i < n && v1[i] != '.'){
                a = (a * 10) + (v1[i]-'0');
                i++;
            }
            int b = 0;
            while(j < m && v2[j] != '.'){
                b = (b * 10) + (v2[j]-'0');
                j++;
            }
            // cout<<a<<" "<<b<<endl;
            i++;
            j++;
            if(a < b) return -1;
            else if(a > b) return 1;
        }
        return 0;
    }
};
