// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iterator>
#include <cmath>

namespace problem13
{
	class Solution {
	public:

		int romanToInt(std::string s) {

			std::map<std::string, int> RomanValues;
			RomanValues["I"] = 1;
			RomanValues["V"] = 5;
			RomanValues["X"] = 10;
			RomanValues["L"] = 50;
			RomanValues["C"] = 100;
			RomanValues["D"] = 500;
			RomanValues["M"] = 1000;
			RomanValues["IV"] = 4;
			RomanValues["IX"] = 9;
			RomanValues["XL"] = 40;
			RomanValues["XC"] = 90;
			RomanValues["CD"] = 400;
			RomanValues["CM"] = 900;

			int sum = 0;
			std::string key1, key2, key;
			int val1, val2;

			// Iterate over input string
			for (std::string::iterator it = s.begin(); it != s.end(); ++it)
			{
				// If there are two or more characters left
				if (next(it) != s.end()) {

					key1 = std::string(1, *it);
					if (RomanValues.contains(key1)) { val1 = (*(RomanValues.find(key1))).second; }
					else { val1 = 0; }

					key2 = std::string(1, *(next(it)));
					if (RomanValues.contains(key2)) { val2 = (*(RomanValues.find(key2))).second; }
					else { val2 = 0; }

					if (val1 >= val2) // Normal case: Roman numerals are in descending order
					{
						key = std::string(1, *it);
						if (RomanValues.contains(key)) {sum += (*(RomanValues.find(key))).second;}
						else { std::cout << "Key " << key << " not found" << std::endl; }
					}
					else // If the next is greater, subtraction is necessary
					{
						key = std::string(1, *it) + std::string(1, *(next(it))); // Concatenate next element as well
						if (RomanValues.contains(key)){ sum += (*(RomanValues.find(key))).second; }
						else { std::cout << "Key " << key << " not found" << std::endl; }
						it++; // Increment iterator an additional time
					}
				}
				else // Only one remaining character left
				{
					key = std::string(1, *it);
					if (RomanValues.contains(key)){ sum += (*(RomanValues.find(key))).second; }
					else { std::cout << "Key " << key << " not found" << std::endl; }
				}
			}

			return sum;
		}
	};

}
namespace problem234 
{
	  // Definition for singly-linked list.
	 struct ListNode {
	      int val;
	      ListNode *next;
	      ListNode() : val(0), next(nullptr) {}
	      ListNode(int x) : val(x), next(nullptr) {}
	      ListNode(int x, ListNode *next) : val(x), next(next) {}
	 };
	 class Solution {
	 public:
		 bool isPalindrome(ListNode* head) {

			 std::vector<int> vecF, vecR;
			 ListNode* node;

			 // Copy linked list into a vector and reverse vector
			 node = head;
			 while (node != nullptr)
			 {
				 vecF.push_back(node->val);
				 vecR.insert(vecR.begin(), node->val);
				 node = node->next;
			 }

			 // Compare vectors
			 return (vecF == vecR);
		 }
	 };
}
namespace problem383
{
	class Solution {
	public:
		bool canConstruct(std::string ransomNote, std::string magazine) {
			std::multiset<char> ranLetters, magLetters;

			for (auto element : ransomNote) { ranLetters.insert(element); }
			for (auto element : magazine) { magLetters.insert(element); }

			for (auto it = ranLetters.begin(); it != ranLetters.end(); ++it)
			{
				if (magLetters.count(*it) < ranLetters.count(*it)) { return false; }
			}
			return true;
		}
	};
}
namespace problem412
{
	class Solution {
	public:
		std::vector<std::string> fizzBuzz(int n) {
			std::vector<std::string> result;
			for (int i = 1; i <= n; i++)
			{
				result.push_back((i % 3 == 0 && i % 5 == 0) ? "FizzBuzz" : (i % 3 == 0 ? "Fizz" : (i % 5 == 0 ? "Buzz" : std::to_string(i))));
			}
			return result;
		}
	};
}
namespace problem876 
{
	// Definition for singly-linked list.
	struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};
	class Solution {
	public:
		ListNode* middleNode(ListNode* head) {
			int count = 1;
			ListNode* node;
			node = head;
			while (node != nullptr)
			{
				node = node->next;
				count++;
			}
			int middle = (count % 2 == 0) ? count / 2 : (count / 2) + 1;

			node = head;
			for (int i = 1; i < middle; i++)
			{
				node = node->next;
			}
			return node;

		}
	};
}
namespace problem1337
{
	class Solution {
	public:
		std::vector<int> kWeakestRows(std::vector<std::vector<int>>& mat, int k) {

			const int n = mat.size();
			const int m = mat[0].size();

			std::multiset<std::pair<int, int>> RowStrength; // Stores (index, strength)
			for (int i = 0; i < n; i++)
			{
				int j;
				for (j = 0; j < m; j++)
				{
					if (mat[i][j] == 0) break;
				}
				RowStrength.insert({ j-1, i });
			}

			std::vector<int> result;
			int i = 0;
			for (auto element : RowStrength) 
			{
				result.push_back(element.second);
				i++;
				if (i >= k) break;
			}

			return result;

		}
	};
}
namespace problem1342
{
	class Solution {
	public:
		int numberOfSteps(int num) {
			int result = 0;
			while (num > 0)
			{
				num = (num % 2 == 0) ? num / 2 : num - 1;
				result++;
			}
			return result;
		}
	};
}
namespace problem1672
{
	class Solution {
	public:
		int maximumWealth(std::vector<std::vector<int>>& accounts) {
			const int n = accounts.size();
			const int m = accounts[0].size();

			std::vector<int> Wealth;
			for (int i = 0; i < n; i++) 
			{
				int sum = 0;
				for (int j = 0; j < m; j++)
				{
					sum += accounts[i][j];
				}
				Wealth.push_back(sum);
			}

			int result = -1;
			for (auto element : Wealth) { if (element > result) result = element; }
			return result;

		}
	};
}
namespace problem112 
{

	// Definition for a binary tree node.
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
	};
 
	class Solution {
	public:
		bool hasPathSum(TreeNode* root, int targetSum) {
			if (root == NULL) {return false;}

			targetSum -= (root->val);

			if ( (root->left) == NULL && (root->right) == NULL ) 
			{
				return (targetSum == 0);
			}
			else if ((root->left) != NULL && (root->right) == NULL)
			{
				return hasPathSum(root->left, targetSum);
			}
			else if ((root->left) == NULL && (root->right) != NULL)
			{
				return hasPathSum(root->right, targetSum);
			}
			else
			{
				return (hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum));
			}
		}
	};
}

int main()
{
	/*
	problem13::Solution A;
	std::string roman1 = "I";
	std::string roman2 = "III";
	std::string roman3 = "LVIII";
	std::string roman4 = "MCMXCIV";
	std::cout << roman1 << " = " << A.romanToInt(roman1) << std::endl;
	std::cout << roman2 << " = " << A.romanToInt(roman2) << std::endl;
	std::cout << roman3 << " = " << A.romanToInt(roman3) << std::endl;
	std::cout << roman4 << " = " << A.romanToInt(roman4) << std::endl;
	*/

	/*problem383::Solution A;
	std::string R1 = "a";
	std::string M1 = "b";
	std::string R2 = "aa";
	std::string M2 = "ab";
	std::string R3 = "aa";
	std::string M3 = "aab";
	std::cout << "Ransom: " << R1 << ", Magazine: " << M1 << ", Result: " << A.canConstruct(R1, M1) << std::endl;
	std::cout << "Ransom: " << R2 << ", Magazine: " << M2 << ", Result: " << A.canConstruct(R2, M2) << std::endl;
	std::cout << "Ransom: " << R3 << ", Magazine: " << M3 << ", Result: " << A.canConstruct(R3, M3) << std::endl;*/

	/*problem412::Solution A;
	std::cout << "n = 3: ";
	for (auto element : A.fizzBuzz(3)) { std::cout << element << " "; }
	std::cout << std::endl;
	std::cout << "n = 5: ";
	for (auto element : A.fizzBuzz(5)) { std::cout << element << " "; }
	std::cout << std::endl;
	std::cout << "n = 15: ";
	for (auto element : A.fizzBuzz(15)) { std::cout << element << " "; }
	std::cout << std::endl;*/

	/*problem1337::Solution A;
	std::vector<std::vector<int>> Mat1;
	Mat1.push_back({ 1, 1, 0, 0, 0 });
	Mat1.push_back({ 1, 1, 1, 1, 0 });
	Mat1.push_back({ 1, 0, 0, 0, 0 });
	Mat1.push_back({ 1, 1, 0, 0, 0 });
	Mat1.push_back({ 1, 1, 1, 1, 1 });

	std::vector<int> res1 = A.kWeakestRows(Mat1, 3);
	for (auto element : res1) { std::cout << element << " "; }
	std::cout << std::endl;*/

	/*problem1342::Solution A;
	std::cout << "i = 14: " << A.numberOfSteps(14) << std::endl;
	std::cout << "i = 8: " << A.numberOfSteps(8) << std::endl;
	std::cout << "i = 123: " << A.numberOfSteps(123) << std::endl;*/

	return 0;
}
