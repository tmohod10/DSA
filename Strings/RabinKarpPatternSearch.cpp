#define d 256
const int q = 101;

void rabinKarpPatternSearch(string txt, string pat) {
	int n = txt.length();
	int m = pat.length();

	int h = 1;
	for(int i = 1; i <= (m - 1); i++) {
		h = (h * d) % q; 
	}

	int p = 0, t = 0;
	for(int i = 0; i < m; i++) {
		p = (p * d + pat[i]) % q;
		t = (t * d + txt[i]) % q;
	}

	for(int i = 0; i <= (n - m); i++) {
		if(p == t) {
			for(int j = 0; j < m; j++) {
				if(txt[i + j] != pat[j]) {
					break;
				}
			}
			if(j == m) {
				cout << i << " " << i + j - 1 << endl;
			}
		}
		if(i < (n - m)) {
			t = ((d * (t - txt[i] * h)) + txt[i + m]) % q;
			if(t < 0) {
				t = t + q;
			}
		}
	}
}