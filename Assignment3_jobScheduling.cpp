// job scheduling
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int jobs;
    cout<<"Enter Number of jobs : ";
    cin>>jobs;

    int profit,deadline;
    string jobId;

    priority_queue<pair<int,pair<int,string>>> pq;
    int maxDeadline = INT_MIN;

    for(int i = 0; i<jobs; i++){
        cout<<"Enter JOB ID deadline and profit : ";
        cin>>jobId>>deadline>>profit;

        maxDeadline = max(maxDeadline,deadline);
        pq.push({profit,{deadline,jobId}});
    }

    vector<string> allocation(maxDeadline,"");

    while(!pq.empty()){
        pair<int,pair<int,string>> temp = pq.top();
        pq.pop();

        int currJobProfit = temp.first;
        int currJobDeadline = temp.second.first;
        string currJobId = temp.second.second;


        int j = currJobDeadline-1;
        while(j >= 0){
            if(allocation[j] == ""){
                allocation[j] = currJobId;
                break;
            }
            j--;
        }
    }

    string ans = "";
    for(auto i:allocation){
        if(i != ""){
            ans+=i;
            ans+=" ";
        }
    }
    cout<<ans;

    return 0;
}