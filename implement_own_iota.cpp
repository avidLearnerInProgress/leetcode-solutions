#include <bits/stdc++.h>
using namespace std;

void reverse(char str[], int length) 
{ 
    int start = 0; 
    int end = length -1; 
    while (start < end) 
    { 
        swap(*(str+start), *(str+end)); 
        start++; 
        end--; 
    } 
} 

string iota_(int x){
    bool isNegative = false;
    int i=0, base = 10;
    char str[100];
    
    if(x == 0){
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
    
    if(x < 0 and base == 10){
        isNegative = true;
        x = -x;
    }
        
    while(x!=0){
        int rem = x%base;
        str[i++] = rem > 9 ? (rem-10) + 'a' : rem + '0';
        x /= base;
    }
    
    if(isNegative)
        str[i++] = '-';
    str[i] = '\0';
    reverse(str, i);
    return str;
}

int main() {
	int x = 1011;
	cout<<iota_(x)<<"\n";
	return 0;
}