// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"
#include <string>
#include <map>
#include <vector>
#include <iterator>

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

			// Copy linked list into a vector
			node = head;
			do 
			{
				vecF.push_back(node->val);
				node = node->next;
			} while (node != nullptr);

			// Create reverse vector
			for (std::vector<int>::iterator it = vecF.end(); it != vecF.begin(); --it)
			{
				vecR.push_back(*it);
			}

			// Compare vectors
			return (vecF == vecR);
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

	problem234::ListNode L1(1);
	problem234::ListNode L2(2, &L1);
	problem234::ListNode L3(2, &L2);
	problem234::ListNode L4(1, &L3);
	problem234::ListNode* Lhead = &L4;

	problem234::Solution A;
	bool palindrome = A.isPalindrome(Lhead);

	return 0;
}
