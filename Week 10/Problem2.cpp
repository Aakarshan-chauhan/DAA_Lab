#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
struct task{
    int index;
    int time;
    int deadline;
};

bool comp(const task & a, const task &b){
    return(a.deadline < b.deadline);
}
int main(){
    int n; 
    cin>>n;

    int max_deadline = -1;
    vector<task> jobs(n);
    for(int i = 0 ; i < n; i++){
        jobs[i].index = i;
        cin>>jobs[i].time;
    }
    for(int i = 0; i < n; i++){
        int temp;
        cin>>temp;
        jobs[i].deadline = temp;
        if(temp > max_deadline)
            max_deadline = temp;
    }

    sort(jobs.begin(), jobs.end(), comp);
    vector<int> seq;

    int start = 0;
    for(int i = 0 ; i < n ; i++){
        int j = jobs[i].deadline - 1;
        if(jobs[i].deadline >= jobs[i].time + start){
            seq.push_back(jobs[i].index);
            start += jobs[i].time;
        }
    }

    cout<<"Max number of tasks : "<<seq.size()<<endl;
    cout<<"Selected task numbers: " ;
    for(auto i : seq){
        if(i!=-1)
            cout<<i+1<<", ";
    }

    return 0 ;
}