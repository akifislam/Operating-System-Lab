/*
    Jar Priority Beshi She Age Pabe - Priority Scheduling
    Remember, Lower Prioriy Value means Higher Priority
    1 means 1st Priority 
    10 means 10th Priority

    Akif Islam
    11 July 2023
*/

#include<bits/stdc++.h>
using namespace std;


struct process{
    string processID;
    int priority;
    int burst;
    int waitingtime;
    int turnaround;
};


int no_of_process;
vector<process> vec(1000);

bool comp(const process &p1, const process &p2){
    return p1.priority<p2.priority;
}

void put_dash(int count){
    for (int i = 0; i < count; i++)
    {
        cout<<"-";
    }  
}

void put_space(int count){
    for (int i = 0; i < count; i++)
    {
        cout<<" ";
    }  
}

void gant_chart_maker(){
    for (int i = 0; i < no_of_process; i++)
    {
        put_space(vec[i].waitingtime);//
        cout<<vec[i].processID;//P1
        put_dash(vec[i].burst);//P1-----------13
        cout<<vec[i].turnaround<<endl;
    }
    
}



// This function is just for debug, not for production/exam
void emergency_print(){
    cout<<"__________________________________________________________________"<<endl;
    cout<<"PID\t\tPriority\t\tBURST\t\tWAITING\t\tTAROUND"<<endl;   
    
    for (int i = 0; i < no_of_process; i++)
    {
        cout<<vec[i].processID<<"\t\t"<<vec[i].priority<<"\t\t"<<vec[i].burst<<"\t\t"<<vec[i].waitingtime<<"\t\t"<<vec[i].turnaround<<endl;   
    }
    cout<<"__________________________________________________________________"<<endl;
    
}

int main(){
    
    freopen("input.txt","r",stdin);

    cin>>no_of_process;
    vec.resize(no_of_process);
    
    //Input
    for (int i = 0; i < no_of_process; i++)
        cin>>vec[i].processID>>vec[i].burst>>vec[i].priority;
    
    sort(vec.begin(),vec.end(),comp);

    //Calculating Waiting and Turnaround Time
    int clock_time = 0;

    for (int i = 0; i < no_of_process; i++)
    {
        vec[i].waitingtime = clock_time; //Karon Prothom Process k kono wait korte hoyna
        clock_time+=vec[i].burst; // Prothom Process Finish Ho gayi
        vec[i].turnaround = clock_time; //So, TurnAround Time Save kar diya :p  
    }
    
    gant_chart_maker();
    emergency_print();     
}