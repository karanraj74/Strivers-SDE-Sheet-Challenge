#include<bits/stdc++.h>

int minCharsforPalindrome(string s) {
	// Write your code here.
	int n = s.size();
	int i = 0, j = n - 1, trim = j;
	int ans = 0;

	while(i < j){
		if(s[i] == s[j]){
			i++;
			j--;
		}
		else{
			ans++;
			i = 0;
			j = --trim;
		}
	}
	
	return ans;
}
