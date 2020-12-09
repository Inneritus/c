#include <iostream>
#include <unordered_map>
#include <vector>


using namespace std;
int main()
{
    int n;
    cin>>n;
    
    vector<int> A(n+3,0);
    //create a input vector/array 
    long long Sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        Sum=Sum+A[i];
    }
    //Sum of elements of total array is stored
    cout<<"\nCan the Array be divided into 2 equal sums allowing moving? Answer is : \n";
    if(Sum&1)
    {
        cout<<"NO\n";
        return 0;
        // Sum cant be divided into equal parts if it is odd

    }
    
    unordered_map<long long, int> first, second;
    //creates two maps first and second, Key is element and value is the count 
    //or amount of times the Key occurs

    first[A[0]]=1;
    //initializing the maps
    // store 1 element in first map
    for(int i=1;i<n;i++)
    {
        second[A[i]]++;
        //accounts for duplicate numbers in the same array!
        //initializing second map
        // n-1 elements from A1 to AN-1 is stored with value pairs

    }
    long long Sdash=0;
    for(int i=0;i<n;i++)
    {
        Sdash=Sdash+A[i];
        if(Sdash==Sum/2)
        {
            cout<<"YES\n";
            return 0;
        }
        if(Sdash<(Sum/2))
        {
            long long x=Sum/2-Sdash;
            if(second[x]>0)
            {
                cout<<"YES\n";
                return 0;
            }
        }
        else
        {
            long long y = Sdash-Sum/2;
            if(first[y]>0)
            {
                cout<<"YES\n";
                return 0;
            }
        }
        first[A[i+1]]++;
        second[A[i+1]]--;
    }

    cout<<"NO\n";

}