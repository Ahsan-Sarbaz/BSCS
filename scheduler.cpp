#include<iostream>

using namespace std;

float fcfs_avg_wt = 0;
float fcfs_avg_ta = 0;

float sjf_avg_wt = 0;
float sjf_avg_ta = 0;

float srtf_avg_wt = 0;
float srtf_avg_ta = 0;


int fcfs()
{
    int bt[10], p[10], wt[10], tat[10], i, j, n;
    cout << "Enter number of process:";
    cin >> n;

    if (n > 10 || n <= 0)
    {
        cout << "\nInvalid number of processes (valid = 1...10)\n Setting it to 3\n";
        n = 3;
    }

    cout << "\nEnter Burst Time:";
    for (i = 0; i < n; i++)
    {
        cout << "\np" << i + 1 << ":";
        cin >> bt[i];
        p[i] = i + 1;
    }


    wt[0] = 0;

    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];

    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];

    cout << "Processes  " << " Burst time  "
        << " Waiting time  " << " Turn around time\n";

    int total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << i + 1 << "\t\t" << bt[i] << "\t    "
            << wt[i] << "\t\t  " << tat[i] << endl;
    }

    fcfs_avg_wt = (float)total_wt / (float)n;
    fcfs_avg_ta = (float)total_tat / (float)n;

    cout << "\nAverage waiting time = " << fcfs_avg_wt;
    cout << "\nAverage turn around time = " << fcfs_avg_ta;
    return 0;


}

void sjf()
{
    int bt[20], p[20], wt[20], tat[20], i, j, n, total = 0, pos, temp;
    float avg_wt, avg_tat;
    cout << "Enter number of process:";
    cin >> n;

    if (n > 10 || n <= 0)
    {
        cout << "\nInvalid number of processes (valid = 1...10)\n Setting it to 3\n";
        n = 3;
    }

    cout << "\nEnter Burst Time:";
    for (i = 0; i < n; i++)
    {
        cout << "\np" << i + 1 << ":";
        cin >> bt[i];
        p[i] = i + 1;
    }

    //sorting of burst times
    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (bt[j] < bt[pos])
                pos = j;
        }

        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    wt[0] = 0;


    for (i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (j = 0; j < i; j++)
            wt[i] += bt[j];

        total += wt[i];
    }

    avg_wt = (float)total / n;
    total = 0;

    cout << "\nProcess     Burst Time    Waiting Time      Turnaround Time";
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        total += tat[i];
        cout << "\np" << p[i] << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i];
    }

    avg_tat = (float)total / n;
    
    sjf_avg_ta = avg_tat;
    sjf_avg_wt = avg_wt;

    cout << "\nAverage Waiting Time = " << avg_wt;
    cout << "\nAverage Turnaround Time = "<< avg_tat;
}

void srtf()
{
    int a[10], b[10], x[10];
    int waiting[10], turnaround[10], completion[10];
    int i, j, smallest, count = 0, time, n;
    double avg = 0, tt = 0, end;

    cout << "\nEnter the number of Processes: ";  //input
    cin >> n;

    if (n > 10 || n <= 0)
    {
        cout << "\nInvalid number of processes (valid = 1...10)\n Setting it to 3\n";
        n = 3;
    }

    for (i = 0; i < n; i++)
    {
        cout << "\nEnter arrival time of process: ";  //input
        cin >> a[i];
    }
    for (i = 0; i < n; i++)
    {
        cout << "\nEnter burst time of process: ";  //input
        cin >> b[i];
    }
    for (i = 0; i < n; i++)
        x[i] = b[i];

    b[9] = 9999;
    for (time = 0; count != n; time++)
    {
        smallest = 9;
        for (i = 0; i < n; i++)
        {
            if (a[i] <= time && b[i] < b[smallest] && b[i]>0)
                smallest = i;
        }
        b[smallest]--;

        if (b[smallest] == 0)
        {
            count++;
            end = time + 1;
            completion[smallest] = end;
            waiting[smallest] = end - a[smallest] - x[smallest];
            turnaround[smallest] = end - a[smallest];
        }
    }
    cout << "Process" << "\t" << "burst-time" << "\t" << "arrival-time" << "\t" << "waiting-time" << "\t" << "turnaround-time" << "\t" << "completion-time" << endl;
    for (i = 0; i < n; i++)
    {
        cout << "p" << i + 1 << "\t\t" << x[i] << "\t\t" << a[i] << "\t\t" << waiting[i] << "\t\t" << turnaround[i] << "\t\t" << completion[i] << endl;
        avg = avg + waiting[i];
        tt = tt + turnaround[i];
    }
    cout << "\n\nAverage waiting time = " << avg / n << endl;
    cout << "Average Turnaround time = " << tt / n << endl;

    srtf_avg_wt = avg / n;
    srtf_avg_ta = tt / n;
}

int main()
{

    cout << "\n--------------------------------------\n";
    cout << "                  FCFS                \n";
    cout << "--------------------------------------\n";
    fcfs();

    cout << "\n--------------------------------------\n";
    cout << "                   SJF                \n";
    cout << "--------------------------------------\n";   
    sjf();

    cout << "\n--------------------------------------\n";
    cout << "                  SRTF                \n";
    cout << "--------------------------------------\n";
    srtf();
    
    cout << "\n\t\tAVG WT\t\tAVG TA";
    cout << "\nFCFS\t\t" << fcfs_avg_wt << "\t\t" << fcfs_avg_ta;
    cout << "\nSJF\t\t" << sjf_avg_wt << "\t\t" << sjf_avg_ta;
    cout << "\nSRTF\t\t" << srtf_avg_wt << "\t\t" << srtf_avg_ta;
    return 0;
}
