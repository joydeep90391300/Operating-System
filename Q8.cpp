#include<bits/stdc++.h>
using namespace std;

struct process
{
	int id;
	int arr_time;
	int bur_time;
	int wait_time;
	int priority;
	int start_time;
	int comp_time;
	int tat;
};


int main()
{
	 int n,i;
	 
    struct process p[100];
    float avg_tat;
    float avg_wait_time;
    int total_tat = 0;
    int total_wait_time = 0;
    int completed[100];
    memset(completed,0,sizeof(completed));
    
    cout<<"Enter the number of processes\n";
	cin>>n;
	
	for(i=0;i<n;i++)
	{
		cout<<"Enter the arrival time of process "<<i+1<<"\n";
		cin>>p[i].arr_time;
		cout<<"Enter the burst time of process "<<i+1<<"\n";
		cin>>p[i].bur_time;
		cout<<"Enter the priority of process "<<i+1<<"\n";
		cin>>p[i].priority;
		p[i].id = i+1;
	}
	
	int curr_time = 0;
	int complete = 0;
	
	while(complete!=n)
	{
		int index=0;
		int max=0;
		for(i=0;i<n;i++)
		{
			if(p[i].arr_time<=curr_time  && completed[i]==0)
			{
				if(p[i].priority > max)
				{
					max = p[i].priority;
					index = i;
				}
				else if(p[i].priority == max)
				{
					if(p[i].arr_time < p[index].arr_time)
					{
						index = i;
					}
				}
			}
		}
		
		if(index!=-1)
		{
			p[index].start_time = curr_time;
			p[index].comp_time = p[index].start_time + p[index].bur_time;
			p[index].tat = p[index].comp_time - p[index].arr_time;
			p[index].wait_time = p[index].tat - p[index].bur_time;
			
			total_tat += p[index].tat;
			total_wait_time += p[index].wait_time;
			
			completed[index] = 1;
			complete++;
			curr_time = p[index].comp_time;
		}
		else
		{
			curr_time++;
		}
	}
	
	int min_arr_time = 10000000;
	int max_comp_time = -1;
	
	for(i=0;i<n;i++)
	{
		 min_arr_time = min(min_arr_time,p[i].arr_time);
        max_comp_time = max(max_comp_time,p[i].comp_time);
	}
	
	avg_tat = (float)total_tat/n;
	avg_wait_time = (float)total_wait_time/n;
	
    cout<<"#P\t"<<"AT\t"<<"BT\t"<<"PRI\t"<<"ST\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"RT\t"<<"\n"<<endl;

	for(i=0;i<n;i++)
	{
		cout<<p[i].id<<"\t"<<p[i].arr_time<<"\t"<<p[i].bur_time<<"\t"<<p[i].priority<<"\t"<<p[i].start_time<<"\t"<<p[i].comp_time<<"\t"<<p[i].tat <<"\t"<<p[i].wait_time<<"\n";
	}
	
	cout<<"Average turnaround time  "<<avg_tat<<"\n";
	cout<<"Average waiting time  "<<avg_wait_time<<"\n";
	return 0;
}

