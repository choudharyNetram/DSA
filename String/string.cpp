#include<iostream>
#include<string>
using namespace std ;
/*int main(){
    string str ;
    cin>>str ;
    cout<<str<<endl ;
    return 0;
}

// for adding a character in a string use push_back function,  not use s = s+x ;
int main(){
    //string str1(5, 'n');
    //string str1 = "Netram choudhary";
    string str1 ;
    getline(cin, str1) ;
    cout<<str1<<endl ;
    return 0; 
}
int main(){
    string s1 = "netram";
    string s2 = "komal" ;
    //s1.append(s2)  //
    s1 = s1+s2 ;
    cout<<s1<<endl ;
    cout<<s1[1]<<endl ;
    // clear function -- it's delete all the string 
    s1.clear();
    cout<<s1<<endl;
    return 0 ; 
    }
    */
// comparing 2 strings 
/*
int main(){
    string s1 = "abc";
    string s2 = "abcd";
    cout<<s2.compare(s1)<<endl; // output 1 when strings are unequal
    if(s1.compare(s2)==0){      // 0 when string are equal 
    
        cout<<"strings are equal" ;
    }
    return 0 ;
}
   
    if(!s1.compare(s2)){
        cout<<"strings are equal" ;
    }
    // empty funtion 
    s1.clear();
    if(s1.empty()){
        cout<<"string s1 is empty" ;
    }
    if(!s2.empty()){
        cout<<"string s2 is not empty ";
    }
    return 0 ;
}   


// erase funtion 
int main(){
    string s1 = "Netramjat" ;
    //s1.erase(6,3);  // string_name.erase(starting index, how many elements you want to delete)
    //cout<<s1<<endl ;
    // finding a substring in a string 
    cout<<s1.find("jat")<<endl ;// -- it's give the starting index of the substing 
    int k = s1.find("jat") ;
    cout<<k<<endl ; 
    // inserting in a string
    s1.insert(6, "Ghosliya") ;// insert(index where you want to insert, what you  want to insert)
    cout<<s1<<endl ;
    // size or length of a string
    cout<<)<<ens1.size()<<endl;
    cout<<s1.length(dl;
    // use of length
    for(int i = 0; i<s1.length();i++){
        cout<<s1[i]<<endl ;
    }
    
    // substr function
    string s3 = s1.substr(6,8) ;  // this give the sub string starting index is 6 and total 8 charcter
    cout<<s3<<endl;
    string s4 = "8348";
    // string to integer --- stoi function
    int n = stoi(s4) ;
    cout<<n+2<<endl;
    // intger/float/double to string --- to_string fuction
    int j = 5757 ;
    string i = to_string(j);
    cout<<i<<endl ;
    cout<<i+"2"<<endl;
    return 0 ;
}
*/

// sorting a sti
// for this we must include a hadder file
#include<algorithm>
/*
int main(){
    string s = "netram jat";
    sort(s.begin(),s.end());// by s.begin() we get starting iterator or by s.end() we get ending iteator
    cout << s <<endl; 
     
    return 0 ;
}
*/


// problems of strings 
// converting lower case to upper case or upper case to lower 
/*
int main(){
    string s1 = "abchefjKLAD"; // converting upper case 
    for(int i = 0; i<s1.size(); i++){
        if(s1[i]>='a' && s1[i]<='z'){
            s1[i] -= 32 ; // the difference of the skai values of 'a' and 'A' is 32 
        }
    }
    cout<<s1<<endl; 
    return 0 ;
}
*/
// converting by in-built fuction 
//#include<algorithm>
/*int main(){
    string str = "netram JAt" ;
    // toupper for converting in upper 
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout << str <<endl ;
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    cout<<str<<endl ;
    return 0 ;
}
*/

/*
// forming the biggest number from the given string 
int main(){
    string str = "12349875" ;
     
    for(int i = 0; i<str.length(); i++){
        int larchari = i ; 
         
        for(int j = i; j<str.length();j++){
            if(str[j]>str[larchari]){
                larchari = j;
                
            }
        }
        int temp = str[larchari] ; 
        str[larchari] = str[i] ;
        str[i] = temp ;
        

    }
    cout<<str<<endl ;
    return 0 ;
}
*/
/*
// 2nd method by inbuilt function 
int main(){
    string str = "233485";
    sort(str.begin(), str.end(), greater<int>());// sorting in reverse direction
    cout<<str<<endl ;
    return 0 ; 
}
*/

// counting which character is accur more times in  a string 
// time complexity o(n*2)
/*
int main(){
    string str = "asssd";
    int maxcount = 0 ; 
    int maxin = 0 ;
    for(int i = 0; i<str.length();i++){
        int count = 1 ; 
        for(int j=i+1 ;j<str.length();j++){
            if(str[j]==str[i]){
                count++ ;
                
            }
        }
        if(maxcount<count){
            maxcount = count ; 
            maxin = i ; 
        }
        
    }
    cout<<str[maxin]<<" "<<maxcount ;
    return 0 ;  
}
*/
/*

// method second 
int main()
{
    string  s = "abddd";
    int freq[26];
    for(int i=0 ; i<26; i++){
        freq[i] = 0 ;
    }
    for(int i = 0; i<s.length();i++)
    {
        freq[s[i]-'a'] ++;
    }
    int maxcou = 0 ;
    int index = 0 ;
    for(int i = 0; i<26; i++){
        if(freq[i]>maxcou){
            maxcou = freq[i];
            index = i ; 
        }
    }
    char ans = 'a'+index ; 
    cout<<maxcou<<" " <<ans ;
    return 0 ; 
}
*/