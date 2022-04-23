class Solution {
private:
	const string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	map<string, string> index, rev_index;
	random_device rd;
    const string BASE_URL = "http://tinyurl.com/";
    
public:
	string encode(string longUrl) {
		string code;
		if (!index.count(longUrl)) {
			for (int i = 0; i < 6; i++)
				code.push_back(charset[rd() % charset.size()]);
			index.insert({longUrl, code});
			rev_index.insert({code, longUrl});
		} else
			code = index[longUrl];
		return BASE_URL + code;
	}
    
	string decode(string shortUrl) {
		if (shortUrl.size() != 25 || !rev_index.count(shortUrl.substr(19, 6)))
			return "";
		return rev_index[shortUrl.substr(19, 6)];
	}

};