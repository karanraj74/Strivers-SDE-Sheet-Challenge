vector<int> stringMatch(string text, string pattern) {
	// Write your code here.
	vector<int>ans;
	for(int i=0;i<text.size();i++){
		if(text.substr(i,pattern.size()) == pattern){
			ans.push_back(i+1);
		}
	}
	return ans;
}
