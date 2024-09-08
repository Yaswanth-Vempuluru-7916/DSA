    #include<bits/stdc++.h>
    using namespace std;

    void selection(vector<int>&arr , int n){

        int mini;
        for(int i=0;i<n-1;i++){
            mini = i;

            for(int j=i+1;j<n;j++){
                if(arr[j]<arr[mini]){
                    mini = j;
                }
            }
            swap(arr[i],arr[mini]);
        }

    }


    int main(){

            vector<int>arr{1,53,82,701,5,0,53,198,54,2,41,63};
            cout<<"Before Sorting : "<<endl;
            
            for(auto elem : arr){
                cout<<elem<<" ";
            }

            selection(arr,arr.size());

            cout<<"\nAfter Sorting : "<<endl;

            for(auto elem : arr){
                cout<<elem<<" ";
            }

    return 0;

    }