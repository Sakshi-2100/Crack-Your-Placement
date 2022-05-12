/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.

 

Example 1:

Input: num = 3
Output: "III"
Explanation: 3 is represented as 3 ones.
Example 2:

Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 3:

Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= num <= 3999

*/

// Approch 1 using if else
    string intToRoman(int num) {
        string s;
        while(num){
            if(num>=1000){
                s+="M";
                num-=1000;
            }
            else if(num>=900){
                s+="CM";
                num-=900;
            }
            else if(num>=500){
                s+="D";
                num-=500;
            }
            else if(num>=400){
                s+="CD";
                num-=400;
            }
            else if(num>=100){
                s+="C";
                num-=100;
            }
            else if(num>=90){
                s+="XC";
                num-=90;
            }
            else if(num>=50){
                s+="L";
                num-=50;
            }
            else if(num>=40){
                s+="XL";
                num-=40;
            }
            else if(num>=10){
                s+="X";
                num-=10;
            }
            else if(num>=9){
                s+="IX";
                num-=9;
            }
            else if(num>=5){
                s+="V";
                num-=5;
            }
            else if(num>=4){
                s+="IV";
                num-=4;
            }
            else if(num>=1){
                s+="I";
                num-=1;
            }
        }
        return s;
    }


//Approach 2 O(codes used in string)        O(1)
        vector<int> integer = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> roman = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string s ="";
        
        for(int i=0;i<integer.size();i++){
            while(num>=integer[i]){
                s+=roman[i];
                num-=integer[i];
            }
        }
        return s;
    }
