#include <bits/stdc++.h>
using namespace std;
 
// Function to return ASCII
// value of a character
int valAssign(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}
 
// Function to convert a number
// from given base to decimal number
int toDecimal(string str, int base)
{
    // Stores the length
    // of the string
    int len = str.size();
 
    // Initialize power of base
    int power = 1;
 
    // Initialize result
    int num = 0;
 
    // Decimal equivalent is str[len-1]*1
    // + str[len-2]*base + str[len-3]*(base^2) + ...
    for (int i = len - 1; i >= 0; i--) {
 
        // A digit in input number must
        // be less than number's base
        if (valAssign(str[i]) >= base) {
            printf("Invalid Number\n");
            return -1;
        }
 
        // Update num
        num += valAssign(str[i]) * power;
 
        // Update power
        power = power * base;
    }
 
    return num;
}
 
// Function to return equivalent
// character of a given value
char reVal(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}
 
// Function to convert a given
// decimal number to a given base
string fromDecimal(int base, int inputNum)
{
    // Store the result
    string res = "";
 
    // Repeatedly divide inputNum
    // by base and take remainder
    while (inputNum > 0) {
 
        // Update res
        res += reVal(inputNum % base);
 
        // Update inputNum
        inputNum /= base;
    }
 
    // Reverse the result
    reverse(res.begin(), res.end());
 
    return res;
}
 
// Function to convert a given number
// from a base to another base
void convertBase(string s, int a, int b)
{
    // Convert the number from
    // base A to decimal
    int num = toDecimal(s, a);
 
    // Convert the number from
    // decimal to base B
    string ans = fromDecimal(b, num);
 
    // Print the result
    cout <<"result: " << ans << endl;
}
 
// Driver Code
int main()
{
	do{
		string input;
		int a,b;
	    cout<<"Enter the number you want to convert: ";
	    cin>>input;
	    cout<<"Enter the base of the number: ";
	    cin>>a;
	    cout<<"Enter the base you want to convert to: ";
	    cin>>b;	
	    
	    // Function Call
    	convertBase(input, a, b);
    	
    	char choice;
    	cout<<"Do you want to convert another number? y/n  ";
    	cin>>choice;
    	if(choice == 'n' || choice == 'N'){
    		break;
		}
	}while(true);
	
 
    
 
    return 0;
}
