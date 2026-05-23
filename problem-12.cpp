/*
12. Integer to Roman
Time Complexity: O(1) as the number of Roman numeral symbols is fixed and does not depend on the input size.
Space Complexity: O(1) as we are using only a constant amount of extra space to store the Roman numeral symbols and the resulting string.
Approach: We use a vector of pairs to store the integer values and their corresponding Roman numeral symbols. 
We iterate through the vector and repeatedly subtract the integer values from the input number 
while appending the corresponding Roman numeral symbols to the result string until the input number is reduced to zero.
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> roman = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        string ans = "";

        for (const auto& [x, y] : roman){
            if (num == 0) break;
        
            int qty = num / x;

            for(int i = 0; i < qty; i++){
                ans += y;
            }
            
            num %= x;
        }

        return ans;
    }
};