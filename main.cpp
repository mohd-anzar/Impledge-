#include<bits/stdc++.h>
using namespace std;
//Node of Trie Data Structure
struct TrieNode {
    struct TrieNode* child[26];
    bool isEnd;
};
//Create New Node
struct TrieNode* getNode(void)
{
    struct TrieNode* Node=new TrieNode;
    Node->isEnd=false;
    for(int i=0;i<26;i++){
         Node->child[i]=NULL;
    }
    return Node;
}
 
//Insert  String
void insert(struct TrieNode* root, string str)
{
    struct TrieNode* Node=root;
    for(int i=0;i<str.length();i++){
        int index=str[i]-'a';
        if (!Node->child[index]){
            Node->child[index]=getNode();
        }
        Node=Node->child[index];
    }
    Node->isEnd=true;
}
//Search String
bool search(struct TrieNode* root, string str)
{
    struct TrieNode* Node=root;
    for(int i=0;i<str.length();i++){
        int index=str[i]-'a';
        if (!Node->child[index]){
            return false;
        }
        Node=Node->child[index];
    }
    return (Node!=NULL&&Node->isEnd);
}
//Function To Access Input File
void getFileContent(string fileName,vector<string> & v)
{
    ifstream in(fileName.c_str());
    string str;
    while (getline(in,str))
    {
        if(str.size()>0){
            v.push_back(str);
        }
    }
    in.close();

}
//Function Solve The Given Problem
bool solve(string str,struct TrieNode* root,int l){
    int n=str.size();
    if(n==0&&l!=1){
        return true;
    }
    for(int i=1;i<=n;i++){
        if(search(root,str.substr(0,i))&&solve(str.substr(i,n-i),root,l+1)){
            return true;
        }
    }
    return false;
}
//Get Longest String From Vector 
string longestStr(vector<string> &v){
    string str="";
    int j;
    for(int i=0;i<v.size();i++){
        if(str.length()<v[i].length()){
            j=i;
            str=v[i];
        }
    }
    v[j]="";
    return str;
}
//Function To Print Desired Output
void compoundWord(vector<string> &v){
    struct TrieNode* root = getNode();
    for(int i=0;i<v.size();i++){
        insert(root,v[i]);
    }
    int k=2;
    while(k){
        string str=longestStr(v);

        if(solve(str,root,0)==true){
            if(k==2){
                cout<<"Longest Compound Word: "<<str<<endl;
            }
            else{
                cout<<"Second Largest Compound Word: "<<str<<endl;
            }
            k--;
        }
    }
}
int main(){
    time_t start,end;
    cout<<"FOR INPUT 01--------"<<endl;
    time(&start);
    vector<string> v;
    getFileContent("input_01.txt", v);
    compoundWord(v);
    time(&end);
    cout<<"Time Taken To Process The Input File: "<<double(end)-double(start)<<" sec"<<endl;
    cout<<"FOR INPUT 02---------"<<endl;
    time(&start);
    vector<string> v2;
    getFileContent("input_02.txt", v2);
    compoundWord(v2);
    time(&end);
    cout<<"Time Taken To Process The Input File: "<<double(end)-double(start)<<" sec"<<endl;

}