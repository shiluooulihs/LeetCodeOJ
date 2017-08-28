#pragma once
#include <string>
#include <vector>
using namespace  std;
struct TrieNode
{
	int count;
	bool isExist;
	struct TrieNode* next[26];
	TrieNode() :count(0), isExist(false) {
		//for (int i=0;i<26;i++)
		//{
		//	next[i] = NULL;
		//}
		memset(next, 0, sizeof(next));
	}
};
void TrieInsert(TrieNode* root, string word) {
	TrieNode* p = root;
	for (int i = 0; i < word.length(); i++) {
		if (!p->next[word[i] - 97]) {
			p->next[word[i] - 97] = new TrieNode();
		}
		p = p->next[word[i] - 97];
		p->count++;
	}
	p->isExist = true;
}
TrieNode* TrieSearch(TrieNode* root, string word) {
	TrieNode* p = root;
	for (int i = 0; i < word.length(); i++) {
		if (!p->next[word[i] - 97]) {
			return NULL;
		}
		p = p->next[word[i] - 97];
	}
	if (p->isExist) return p;
	else return NULL;
}
void TrieDestory(TrieNode* root) {
	if (!root) return;
	for (int i = 0; i < 26; i++) {
		TrieDestory(root->next[i]);
	}
	delete root;
}
class Solution {
public:
	string replaceWords(vector<string>& dict, string sentence) {
		TrieNode* root = new TrieNode();
		for (int i = 0; i < dict.size(); i++) {
			TrieInsert(root, dict[i]);
		}
		TrieDestory(root);
		return "";
	}
};