#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<string, double> PAIR;
map<pair<string, string>, int> student;
vector<string> idSet;
vector<string> subSet;
map<string, double> average;

struct CmpByValue
{
	bool operator() (const PAIR & lhs, const PAIR& rhs) {
		return lhs.second < rhs.second;
	}
};
int main()
{
	int n, score;
	string name, id, subject;
	cin >> n;

	idSet.emplace_back("AA");
	subSet.emplace_back("AA");//防止subscrip out of range

	for (int i = 0; i < n; i++)
	{
		cin >> name >> id >> subject >> score;
		idSet.emplace_back(id);
		subSet.emplace_back(subject);
		student[make_pair(id, subject)] = score;
	}

	//去除重复元素
	sort(idSet.begin(), idSet.end());
	idSet.erase(unique(idSet.begin(), idSet.end()), idSet.end());
	sort(subSet.begin(), subSet.end());
	subSet.erase(unique(subSet.begin(), subSet.end()), subSet.end()); 

	for (int i = 0; i < idSet.size()-1; i++) {
		int sum = 0;
		for (int j = 1; j < subSet.size(); j++) {
			map<pair<string, string> , int>::iterator iter = student.begin();
			for (; iter != student.end(); ++iter) {
				if (iter->first.first==idSet[i] && iter->first.second==subSet[j] ) {
					sum += iter->second;
				}
			}
		}
		double mean = 0;
		if (subSet.size() != 0) {
			mean = sum / (subSet.size() - 1);
		}
		average[idSet[i]] = mean;
	}
	
	int sum = 0;
	map<string, double>::iterator iter = average.begin();
	for (; iter != average.end(); ++iter) {
		sum += iter->second;
	}
	double mean = 0;
	if (average.size() != 0) {
	    mean = sum / average.size();
	}
	
	/*把map元素转存进vector中*/
	vector<PAIR> idList(average.begin(), average.end());
	sort(idList.begin(), idList.end(), CmpByValue());

	for (int i = idList.size()-1; i >= 0; i--) {
		if (idList[i].second <= mean) {
			cout << idList[i].first << endl;
		}
	}

	cin.get();
	cin.get();
	
}