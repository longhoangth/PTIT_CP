#include <iostream>
#include <vector>
using namespace std;

void solve(string s, int i, int j, int level, string temp,
		vector<string>& res)
{
	if (i == (j + 1) && level == 5) {
		res.push_back(temp.substr(1));
	}

	// Digits of a number ranging 0-255 can lie only between
	// 0-3
	for (int k = i; k < i + 3 && k <= j; k++) {
		string ad = s.substr(i, k - i + 1);

		// Return if string starting with '0' or it is
		// greater than 255.
		if ((s[i] == '0'&&ad.size()>1) || stol(ad) > 255)
			return;

		// Recursively call for another level.
		solve(s, k + 1, j, level + 1, temp + '.' + ad, res);
	}
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.length();

        vector<string> ans;

        solve(s, 0, n - 1, 1, "", ans);

        cout << ans.size() << endl;
    }
	return 0;
}