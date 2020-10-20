#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<string>> findAnagrams(const vector<string>& dict);



vector<vector<string>> findAnagrams(const vector<string>& dict)
{

    // Your code here...
    vector<vector<string>> result;
    std::unordered_map<string, vector<string>> anagrams;
    for (int i = 0; i < dict.size(); i++) {
        string temp = dict.at(i);
        sort(temp.begin(), temp.end());
        anagrams[temp].push_back(dict.at(i));
    }
    for (auto& x : anagrams) {
        result.push_back(x.second);
    }
    return result;
}