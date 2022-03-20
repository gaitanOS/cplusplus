#include <map>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        
        map<char, int> romanNumerals {
            {'M', 1000},
            {'D', 500},
            {'C', 100},
            {'L', 50},
            {'X', 10},
            {'V', 5},
            {'I', 1}
            
        };
        int intValue = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(romanNumerals[s[i]] < romanNumerals[s[i + 1]]){
                //I,X,C in front of some other value
                intValue += (romanNumerals[s[i + 1]] - romanNumerals[s[i]]);
                i++; //you have to skip over the last value otherwise it will add it again
                
            }
            else{
                intValue += romanNumerals[s[i]];
            }
        }                                                        
        return intValue;
    }
};
