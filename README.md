# Impledge-

First getFileContent function read the given txt file and make vector of string(say "v").Construct Trie from "v" using insert function after that longestStr function inside a
while loop to find a longest string from the "v" and set v[index of longest string]="".Then solve function checks the string whether compounded or not.

Solve() Function ----- it takes three arguments first string to be checked,second root of trie and third l=0


 Base case-- if length of string == 0 && l!=1 then return true (where l==1 it shows that the string found in trie is itself)

 for i=0 to i=length of string and increment i by 1
 
   if substr(0,i) present in trie then recursevly check for solve(substr(i,length of string -i),root of trie,l+1) == true then return true
   
 if for all i not found then return false
 end
 
 Time CompLexity Analysis----- I uses trie because trie search function,insert function and delete function takes O(len) time complexity where len is the largest length of string. It is fatser than Hasing.
 
 Input of the program
  
  the files are already present in this git repository
 
 Output Of The Program 
   
   FOR INPUT 01--------
   
   Longest Compound Word: ratcatdogcat    
   
   Second Largest Compound Word: catsdogcats  
   
   Time Taken To Process The Input File: 0 sec
   
   FOR INPUT 02---------
   Longest Compound Word: ethylenediaminetetraacetates   
   
   Second Largest Compound Word: electroencephalographically
   
   Time Taken To Process The Input File: 1 sec
