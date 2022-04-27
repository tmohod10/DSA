void patternSearchNaive(string s, string p) {
	int n = s.length();
	int m = p.length();
	for(int i = 0; i <= (n - m); i++) {
		int j;
		for(j = 0; j < m; j++) {
			if(s[i + j] != p[j]) {
				break;
			}
		}
		if(j == m) {
			cout << i << " ";
		}
	}
}