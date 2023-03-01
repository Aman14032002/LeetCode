class Solution {
	void rot(string &s){
		char x = s[0];

		s.erase(s.begin());
		s.push_back(x);
}
public:
	bool rotateString(string s, string goal) {
		if(s.size() != goal.size()){
			return false;
		}
		if(s == goal){
			return true;
		}

		int n = s.size();

		while(n--){
			if(s == goal){
				return true;
			}
			rot(s);
		}

		return false;
	}
};