#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
struct Info {
	int index;
	string url;
	double basic, external, link;
};

vector<Info> scores;
map<string, double> cnt;

bool cmp(Info& A, Info& B) {
	if (A.basic + A.link == B.basic + B.link) {
		return A.index < B.index;
	}
	return A.basic + A.link > B.basic + B.link;
}

void setBasic(int index, string word, string page) {
	int start = page.find("<BODY>");
	int end = page.find("</BODY>");
	start += 6;
	page = page.substr(start, end - start);
	double basic = 0;
	int idx = page.find(word);

	string cur;
	for (int i = 0; i < page.size(); i++) {	// find 무한 반복하면서 찾으면 띄어쓰기 단위로 찾지 못함
		if (!isalpha(page[i])) {
			if (cur == word) {
				basic++;
			}
			cur = "";
		}
		else {
			cur += page[i];
		}
	}
	scores[index].basic = basic;
}

void setExternal(int index, string word, string page) {
	string target = "<A HREF=\"HTTPS://";
	int start = page.find(target);

	int external = 0;
	vector<string> external_list;
	while (start != page.npos) {
		page = page.substr(start + target.size());
		external++;
		int end = page.find("\"");
		external_list.push_back(page.substr(0, end));
		start = page.find(target);
	}   // end of while
	scores[index].external = external;
	for (string key : external_list) {
		cnt[key] += scores[index].basic / scores[index].external;
	}
}

void setUrl(string page, int index) {
	string target = "<META PROPERTY=\"OG:URL\" CONTENT=\"HTTPS://";
	int idx = page.find(target);
	page = page.substr(idx + target.size());
	int end = page.find("/>");
	scores[index].url = page.substr(0, end - 1);
}

void setLink() {
	for (int i = 0; i < scores.size(); i++) {
		scores[i].link = cnt[scores[i].url];
	}
}

int solution(string word, vector<string> pages) {
	int answer = 0;
	for (int i = 0; i < pages.size(); i++) {
		transform(pages[i].begin(), pages[i].end(), pages[i].begin(), ::toupper);
		scores.push_back({ i });
		setUrl(pages[i], i);
	}   // end of for

	transform(word.begin(), word.end(), word.begin(), ::toupper);
	for (int i = 0; i < pages.size(); i++) {
		string page = pages[i];
		setBasic(i, word, page);
		setExternal(i, word, page);
	}

	setLink();

	sort(scores.begin(), scores.end(), cmp);

	answer = scores[0].index;

	return answer;
}