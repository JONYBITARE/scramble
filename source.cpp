#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int x;
int y;
int u;
int ro(float f){
    if( (((int)(f*10))%10)<5)
    return (int)f;
    else
    return (int)f+1;
}
// The recursive way is quite simple.
//    1) break the string to two parts: 
//          s1[0..j]   s1[j+1..n]
//          s2[0..j]   s2[j+1..n]
//    2) then
//          isScramble(s1[0..j], s2[0..j]) &&  isScramble(s1[j+1..n], s2[j+1..n])
//        OR
//          isScramble(s1[0..j], s2[j+1, n]) &&  isScramble(s1[j+1..n], s2[0..j])
bool isScramble_recursion(string s1, string s2) {

      if (s1.size()!= s2.size() || s1.size()==0 || s2.size()==0) {
        return false;
    }
    if (s1 == s2)
        return true;
    
        
    string ss1 = s1;
    string ss2 = s2;
    sort(ss1.begin(), ss1.end()); 
    sort(ss2.begin(), ss2.end()); 
    if (ss1 != ss2) {
        return false;
    }else if(s1.size()<=3)
        return true;

   for (int i=1; i<s1.size(); i++) {
        if ( isScramble_recursion(s1.substr(0,i), s2.substr(0,i)))
             if (isScramble_recursion(s1.substr(i, s1.size()-i), s2.substr(i, s2.size()-i))) {
            return true;
        }
        if ( isScramble_recursion(s1.substr(0,i), s2.substr(s2.size()-i, i))) 
             if (isScramble_recursion(s1.substr(i, s1.size()-i), s2.substr(0, s2.size()-i))) {
            return true;
        }
    }

    return false;
    
}
bool isScramble_recursion_2(string s1, string s2) {
       if (s1.size()!= s2.size() || s1.size()==0 || s2.size()==0) {
        return false;
    }
    if (s1 == s2)
        return true;
    int check1=0;
    int check2=0; 
    string ss1 = s1;
    string ss2 = s2;
    sort(ss1.begin(), ss1.end()); 
    sort(ss2.begin(), ss2.end()); 
    if (ss1 != ss2) {
        return false;
    }else if(s1.size()<=3)
        return true;

     for (int i=1; i<s1.size(); i++) {
        if (isScramble_recursion_2(s1.substr(0,i), s2.substr(0,i))){
             if (isScramble_recursion_2(s1.substr(i, s1.size()-i), s2.substr(i, s2.size()-i)))
            return true;
            else if(check2==1)
            return false;
            else
                check1=1;
        }
    //if we put if else here (for the first if) there is a error (consider first 2 examples) (here)
        if (isScramble_recursion_2(s1.substr(0,i), s2.substr(s2.size()-i, i))){
             if(isScramble_recursion_2(s1.substr(i, s1.size()-i), s2.substr(0, s2.size()-i)))
            return true;
            else if(check1==1)
            return false;
            else
                check2=1;
        }
    }
    return false;  
}
int main(){
    float p=5.567f;
    cout<<ro(4.26666)<<endl;
    string s1;
    string s2;
    cout<<isScramble_recursion("abcad","aabdc")<<endl;
    cout<<isScramble_recursion_2("abcad","aabdc")<<endl;
    cout<<isScramble_recursion("abcada","aabdca")<<endl;
    cout<<isScramble_recursion_2("abcada","aabdca")<<endl;
    cout<<isScramble_recursion("abcad","aabdc")<<endl;
    cout<<isScramble_recursion_2("abcad","aabdc")<<endl;
    cout<<"eww"<<isScramble_recursion("aabcd","acadb")<<endl;
    cout<<"aweas"<<isScramble_recursion_2("aabcd","acadb")<<endl;
     cout<<"eww"<<isScramble_recursion("aabcdf","acadbf")<<endl;
    cout<<"aweas"<<isScramble_recursion_2("aabcdf","acadbf")<<endl;
    cout<<isScramble_recursion("abcada","aabdca")<<endl;
    cout<<isScramble_recursion_2("aabdca","aabdca")<<endl;
    cout<<isScramble_recursion("aabcd","acadb")<<endl;
    cout<<isScramble_recursion_2("aabcd","acadb")<<endl;
    cout<<isScramble_recursion("aabcdt","acadbt")<<endl;
    cout<<isScramble_recursion_2("aabcdt","acadbt")<<endl;
    cout<<isScramble_recursion("dcabt","adbct")<<endl;
    cout<<isScramble_recursion_2("dcabt","adbct")<<endl;
    cout<<isScramble_recursion("abdcabt","baadbct")<<endl;
    cout<<isScramble_recursion_2("abdcabt","baadbct")<<endl;
    cout<<isScramble_recursion("abacdbt","badabct")<<endl;
    cout<<isScramble_recursion_2("abacdbt","badabct")<<endl;
    cout<<isScramble_recursion("abcadbt","badcbat")<<endl;
    cout<<isScramble_recursion_2("abcadbt","badcbat")<<endl;
    cout<<isScramble_recursion("bbacdt","bcbdat")<<endl;
    cout<<isScramble_recursion_2("bbacdt","bcbdat")<<endl;
    cout<<isScramble_recursion("abbacd","abcbda")<<endl;
    cout<<isScramble_recursion_2("abbacd","abcbda")<<endl;
    cout<<isScramble_recursion("abbacdt","abcbdat")<<endl;
    cout<<isScramble_recursion_2("abbacdt","abcbdat")<<endl;
    cout<<isScramble_recursion("dacbt","cdbat")<<endl;
    cout<<isScramble_recursion_2("dacbt","cdbat")<<endl;
    cout<<isScramble_recursion("abdacbt","abcdbat")<<endl;
    cout<<isScramble_recursion_2("abdacbt","abcdbat")<<endl;
    cout<<isScramble_recursion("dycya","cdayy")<<endl;
    cout<<isScramble_recursion_2("dycya","cdayy")<<endl;
    cout<<isScramble_recursion("atbae","ateba")<<endl;
    cout<<isScramble_recursion_2("atbae","ateba")<<endl;
    cout<<isScramble_recursion("abacda","aacbda")<<endl;
    cout<<isScramble_recursion_2("abacda","aacbda")<<endl;
    cout<<isScramble_recursion("aabdaceba","abacdebaa")<<endl;
    cout<<isScramble_recursion_2("aabdaceba","abacdebaa")<<endl;
    cout<<isScramble_recursion("abacd","acbda")<<endl;
    cout<<isScramble_recursion_2("abacd","acbda")<<endl;
    cout<<isScramble_recursion("ycdabt","aycbtd")<<endl;//not scrambled from third example
    cout<<isScramble_recursion_2("ycdabt","aycbtd")<<endl;
    cout<<isScramble_recursion("ycdabt","ycbtda")<<endl;//scrambled for third example
    cout<<isScramble_recursion_2("ycdabt","ycbtda")<<endl;
    cout<<isScramble_recursion("ycdabta","aycbtda")<<endl;//this example
    cout<<isScramble_recursion_2("ycdabta","aycbtda")<<endl;
    cout<<isScramble_recursion("acdabt","acbtda")<<endl;//scrambled for third example
    cout<<isScramble_recursion_2("acdabt","acbtda")<<endl;
    cout<<isScramble_recursion("acdabt","aacbtd")<<endl;//not scrambled from third example
    cout<<isScramble_recursion_2("acdabt","aacbtd")<<endl;
    cout<<isScramble_recursion("acdabta","aacbtda")<<endl;//this example
    cout<<isScramble_recursion_2("acdabta","aacbtda")<<endl;
    cout<<"here"<<isScramble_recursion("adycaay","acdayya")<<endl;
    cout<<"here"<<isScramble_recursion("acdbaba","abcadba")<<endl;
    cout<<"here"<<isScramble_recursion_2("acdbaba","abcadba")<<endl;
     cout<<"here"<<isScramble_recursion("adycaayba","abacdayya")<<endl;
    cout<<"here"<<isScramble_recursion_2("adycaayba","abacdayya")<<endl;//here it work (error)
    cout<<"here"<<isScramble_recursion("adycyaaab","abacdayya")<<endl;
    cout<<"here"<<isScramble_recursion_2("adycyaaab","abacdayya")<<endl;//here it work (error)
    cout<<"here"<<isScramble_recursion("adycyaaba","abacdayya")<<endl;
    cout<<"here"<<isScramble_recursion_2("adycyaaba","abacdayya")<<endl;//here it work (error)
     cout<<"here 123"<<isScramble_recursion("adycaba","acdayba")<<endl;
    cout<<"here"<<isScramble_recursion_2("adycaba","acdayba")<<endl;//here it work (error)
    cout<<"here"<<isScramble_recursion("adycayba","acdayyba")<<endl;
    cout<<"here"<<isScramble_recursion_2("adycayba","acdayyba")<<endl;//here it work (error)
    cout<<"here"<<isScramble_recursion_2("dcabba","aadbcb")<<endl;
     cout<<"here"<<isScramble_recursion("dcabba","aadbcb")<<endl;
    cout<<"here"<<isScramble_recursion_2("dcabba","aadbcb")<<endl;
     cout<<"here"<<isScramble_recursion("dcayba","adycba")<<endl;
    cout<<"here"<<isScramble_recursion_2("dcayba","adycba")<<endl;
     cout<<isScramble_recursion("acdbya","bcadya")<<endl;//this not work
     cout<<isScramble_recursion("acdbya","abcady")<<endl;//this work
     cout<<isScramble_recursion("abdcya","bcadya")<<endl;
     cout<<isScramble_recursion("abdcya","abcdya")<<endl;
    cout<<isScramble_recursion("acdbaa","abcada")<<endl;
    cout<<isScramble_recursion_2("acdbaa","abcada")<<endl;
    cout<<"asf"<<isScramble_recursion("acdba","bcada")<<endl;
    cout<<"aasd"<<isScramble_recursion("acdba","abcad")<<endl;
    cout<<"asf"<<isScramble_recursion("acdyba","bcayda")<<endl;
    cout<<"aasd"<<isScramble_recursion("acdyba","abcayd")<<endl;
    cout<<isScramble_recursion("acdbaa","abcada")<<endl;
    cout<<isScramble_recursion_2("acdbaa","abcada")<<endl;//here it work (srambled)
    cout<<isScramble_recursion("adacba","acdbaa")<<endl;
    cout<<isScramble_recursion_2("adacba","acdbaa")<<endl;
    cout<<isScramble_recursion("batcbe","abtecb")<<endl;
    cout<<isScramble_recursion_2("batcbe","abtecb")<<endl;
    cout<<isScramble_recursion_2("acbad","adbca")<<endl;
    cout<<isScramble_recursion("acbad","adbca")<<endl;
    cout<<isScramble_recursion("abcdea","adbeca")<<endl;
    cout<<isScramble_recursion_2("abcdea","adbeca")<<endl;
    cout<<isScramble_recursion("abrcad","acdbra")<<endl;
    cout<<isScramble_recursion_2("abrcad","acdbra")<<endl;
    cout<<isScramble_recursion("adacb","acdba")<<endl;//here
    cout<<isScramble_recursion_2("adacb","acdba")<<endl;//here
    cout<<isScramble_recursion("adacb","acdba")<<endl;
    cout<<isScramble_recursion_2("adacb","acdba")<<endl;
    cout<<isScramble_recursion("adacb","acdba")<<endl;
    cout<<isScramble_recursion_2("adacb","acdba")<<endl;
    cout<<isScramble_recursion("abcdea","adbeca")<<endl;
    cout<<isScramble_recursion_2("abcdea","adbeca")<<endl;
    cout<<isScramble_recursion("aaabc","aacba")<<endl;
    cout<<isScramble_recursion_2("aaabc","aacba")<<endl;
    cout<<isScramble_recursion("aabcd","acadb")<<endl;
    cout<<isScramble_recursion_2("aabcd","acadb")<<endl;
    cout<<isScramble_recursion("aabcd","acdba")<<endl;
    cout<<isScramble_recursion_2("aabcd","acdba")<<endl;
    cout<<isScramble_recursion("abcd","acdb")<<endl;
    cout<<isScramble_recursion_2("abcd","acdb")<<endl;
    cout<<isScramble_recursion("abc","bca")<<endl;
    cout<<isScramble_recursion_2("abc","bca")<<endl;
    cout<<isScramble_recursion("abcd","cadb")<<endl;
    cout<<isScramble_recursion_2("abcd","cadb")<<endl;
}
