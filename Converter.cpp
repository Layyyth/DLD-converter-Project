#include<bits/stdc++.h>
#define ll long long
using namespace std;
void display(){
cout<<"Choose Your Case\n1-Bin to Octa\t2-Bin to Dec\t3-Bin to Hex\n4-Octa to Bin\t5-Octa to Dec\t6-Octa to Hex\n7-Dec to Bin\t8-Dec to Octa\t9-Dec to Hex\n10-Hex to Bin\t11-Hex to Octa\t12-Hex to Dec"<<endl;}

int case1(int x){
    int y=0,z=0,i=0;
    while(x!=0){
       y+=(x%10)*pow(2,i);
       i++;
       x/=10;}
       i=1;          // later on modification(let's use this part as a previous existing function), shortcut idea is to creat a binary to decimal function
       while(y!=0){
        z+=(y%8)*i;
        y/=8;
        i*=10;} 
        return z;}

int case2(int x){
 int y=0,i=0;
while(x!=0){
    int rem=x%10;
    x=x/10;
    y+=rem*pow(2,i);
    i++;}
  return y;}

int case3(int x){
    int y=0,z=0,i=0;
    while(x!=0){
       y+=(x%10)*pow(2,i);
       i++;
       x/=10;}
       i=1;          // later on modification(let's use this part as a previous existing function)
       while(y!=0){
        z+=(y%16)*i;
        y/=16;
        i*=10;} 
        return z;}

int case4(int x){
    int z=0,y=0,count=0;
    while(x!=0){
         z+=(x%10)*pow(8,count);
      ++count;
      x/=10;}
    count = 1;
   while (z!=0) {
      y+=(z%2)*count;
      z/=2;
      count*= 10;}
   return y;}

int case5(int x){
      int z = 0, i = 0, rem;
    while (x!=0){
        rem =x%10;
        x/=10;
        z+=rem* pow(8, i);
        ++i;}
    return z;}
 
   void DecimalToHexa(int x){    ////////////// // DECIMAL TO HEXA FUNCTION  
   int rem, i=0;
    char hexaDecimalNum[50];  
    while(x!=0){
        rem =x%16;
        if(rem<10)
            rem = rem+48;
        else
            rem = rem+55;
        hexaDecimalNum[i] = rem;
        i++;
        x/=16;}
    for(i=i-1; i>=0; i--)
        cout<<hexaDecimalNum[i]<<endl;}

int case6(int x){
 int decimal=0,i=0,rem; char hexaDecimalNum[50];
 while(x!=0){
  rem=x%10;
  x/=10;
  decimal+=rem*pow(8,i);
  i++;}
  DecimalToHexa(decimal);
  return 0;}

 int case7(int x){  
 ll binary=0; int rem,i=1;
 while(x!=0){
  rem=x%2;
  x/=2;
  binary+=rem*i;
  i*=10;}
  return binary;}

int case8(int x){
    int rem, i=1,octalNumber=0;
    while (x!=0)
    {
       rem = x% 8;
       x/=8;
       octalNumber+=rem*i;
        i*= 10;}
    return octalNumber;}

int case9(int x){ DecimalToHexa(x); return 0;}

string case10(string t){
  string bin="";  int num=0;
  for(int i=0;i<t.length();i++){
    string tmp = "";
    if(t[i]>='0' && t[i]<='9'){
      num=int(t[i])-48;
      while(num>0){
        tmp+=char(num%2+48);
        num/=2;}
      while(tmp.length()!=4){
        tmp+='0';}
      num=0;}
    else{ num = t[i]-'A'+10;
    while(num>0){
        tmp+=char(num%2+48);
        num/=2; }
    }
    for(int j=3;j>=0;j--){
      bin+=tmp[j];}
       }
 return bin;}

  void FromHexToDec(string t){         ///// function to convert from hex to dec 
    int len=t.size(); int base=1; int dec=0;
  for(int i=len-1;i>=0;i--){
    if(t[i]>='0' && t[i]<='9'){
      dec+=(t[i]-48)*base;
      base*=16; }
    else if(t[i]>='A' && t[i]<='F'){
      dec+=(t[i]-55)*base;
      base*=16;} } cout<<dec<<endl; }

int case12(string t){ FromHexToDec(t); return 0;}
 
int case11(string t){
  //1- convert from hex to decimal 
   int len=t.size(); int base=1; int dec=0;  int rem, i=1,octalNumber=0;
  for(int i=len-1;i>=0;i--){
    if(t[i]>='0' && t[i]<='9'){
      dec+=(t[i]-48)*base;
      base*=16; }
    else if(t[i]>='A' && t[i]<='F'){
      dec+=(t[i]-55)*base;
      base*=16;} } 
      //2- convert from decimal to octal 
    while (dec!=0)
    {
       rem = dec% 8;
       dec/=8;
       octalNumber+=rem*i;
        i*= 10;}
    return octalNumber;


}


int main(){
 int number; 
 string Str;
 display();
int casenumber; 
cin>>casenumber;
switch (casenumber){
case 1:  cout<<"Enter The Number : "<<endl; cin>>number; cout<<"The Result = "<<case1(number)<<endl; break;
case 2:  cout<<"Enter The Number : "<<endl; cin>>number; cout<<"The Result = "<<case2(number)<<endl; break; 
case 3:  cout<<"Enter The Number : "<<endl; cin>>number; cout<<"The Result = "<<case3(number)<<endl; break;
case 4:  cout<<"Enter The Number : "<<endl; cin>>number; cout<<"The Result = "<<case4(number)<<endl; break;
case 5:  cout<<"Enter The Number : "<<endl; cin>>number; cout<<"The Result = "<<case5(number)<<endl; break;
case 6:  cout<<"Enter The Number : "<<endl; cin>>number; cout<<"The Result = "<<case6(number)<<endl; break;
case 7:  cout<<"Enter The Number : "<<endl; cin>>number; cout<<"The Result = "<<case7(number)<<endl; break;
case 8:  cout<<"Enter The Number : "<<endl; cin>>number; cout<<"The Result = "<<case8(number)<<endl; break;
case 9:  cout<<"Enter The Number : "<<endl; cin>>number; cout<<"The Result = "<<case9(number)<<endl; break;
case 10:  cout<<"Enter The Number : "<<endl; cin>>Str; cout<<"The Result = "<<case10(Str)<<endl; break;
case 11:  cout<<"Enter The Number : "<<endl; cin>>Str; cout<<"The Result = "<<case11(Str)<<endl; break;
case 12:  cout<<"Enter The Number : "<<endl; cin>>Str; cout<<"The Result = "<<case12(Str)<<endl; break; }
return 0; }
/*
 Project Notes :
 Description : This code is written to convert between numeric systems.
 Time Complexity = O(n)
 Run Time = 1.3s 
 File Size =5kbs
 Project Time : 4hrs 40mins
 Done By: Aj
 student num : 152681
 - Output Size: 1.86406230926514 MiB
- Compilation Time: 0.94s
*/
