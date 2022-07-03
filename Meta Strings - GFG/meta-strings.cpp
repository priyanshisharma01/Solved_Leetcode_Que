// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool metaStrings (string s1, string s2);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s1; cin >> s1;
        string s2; cin >> s2;

        cout << metaStrings (s1, s2) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends

bool check(string S1, string S2 , int i1,int i2)
{
    S2[i1]=S1[i1];
    S2[i2]=S1[i2];
    int s2=S2.length();
    int k=0;
    for(int i=0;i<s2;i++)
    {
        if(S2[i]!=S1[i])
        {
            return false;
        }
    }
    return true;
}

bool metaStrings (string S1, string S2)
{
    int s1=S1.length();
    int s2=S2.length();
    int i1=-1;
    int i2=-1;
    int k=0;
    
    for(int i=0;i<s2;i++)
    {
       
        if(S2[i]!=S1[k])
        {
            if(i1==-1){
            i1=i;
            }
            else{
                i2=i;
            }
        }
    
        k++;
        
        
    }
    if(i1!=-1 && i2!=-1)
    {
        return check( S1,  S2 , i1, i2);
    }
    if(i1==-1 || i2==-1)
    {
        return false;
    }
    return true;
}