#include<iostream>

using namespace std;

float fcfs_avg_wt = 0;
float fcfs_avg_ta = 0;

float sjf_avg_wt = 0;
float sjf_avg_ta = 0;

float srtf_avg_wt = 0;
float srtf_avg_ta = 0;

int p[10]; // Processes
int bt[10]; // Burst Times
int wt[10]; // Waiting Times
int tat[10]; // Turnaround Times

void clear()
{
    memset(p, 0, sizeof(int) * 10);
    memset(bt, 0, sizeof(int) * 10);
    memset(wt, 0, sizeof(int) * 10);
    memset(tat, 0, sizeof(int) * 10);
}

void fcfs(int n)
{
    clear();
    cout << "\nEnter Burst Time:";
    for (int i = 0; i < n; ++i)
    {
        cout << "\np" << i + 1 << ":";
        cin >> bt[i];
        p[i] = i + 1;
    }

    wt[0] = 0;

    for (int i = 1; i < n; ++i)
        wt[i] = bt[i - 1] + wt[i - 1];

    for (int i = 0; i < n; ++i)
        tat[i] = bt[i] + wt[i];

    cout << "Processes  " << " Burst time  "
        << " Waiting time  " << " Turn around time\n";

    int total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; ++i)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << i + 1 << "\t\t" << bt[i] << "\t    "
            << wt[i] << "\t\t  " << tat[i] << "\n";
    }

    fcfs_avg_wt = (float)total_wt / (float)n;
    fcfs_avg_ta = (float)total_tat / (float)n;

    cout << "\nAverage waiting time = " << fcfs_avg_wt;
    cout << "\nAverage turn around time = " << fcfs_avg_ta;
}

void sjf(int n)
{
    int total = 0, pos, temp;
    clear();
    cout << "\nEnter Burst Time:";
    for (int i = 0; i < n; ++i)
    {
        cout << "\np" << i + 1 << ":";
        cin >> bt[i];
        p[i] = i + 1;
    }

    for (int i = 0; i < n; ++i)
    {
        pos = i;
        for (int j = i + 1; j < n; ++j)
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

    for (int i = 1; i < n; ++i)
    {
        wt[i] = 0;
        for (int j = 0; j < i; ++j)
            wt[i] += bt[j];

        total += wt[i];
    }

    total = 0;

    cout << "\nProcess     Burst Time    Waiting Time      Turnaround Time";
    for (int i = 0; i < n; ++i)
    {
        tat[i] = bt[i] + wt[i];
        total += tat[i];
        cout << "\np" << p[i] << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i];
    }
    
    sjf_avg_ta = (float)total / (float)n;
    sjf_avg_wt = (float)total / (float)n;

    cout << "\nAverage Waiting Time = " << sjf_avg_wt;
    cout << "\nAverage Turnaround Time = "<< sjf_avg_ta;
}

void srtf(int n)
{
    int a[10], x[10];
    int completion[10];
    int smallest, count = 0, time;
    double avg = 0, tt = 0, end;

    clear();

    for (int i = 0; i < n; ++i)
    {
        cout << "\nEnter arrival time of process: ";
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cout << "\nEnter burst time of process: ";
        cin >> bt[i];
    }

    for (int i = 0; i < n; ++i)
    {
        x[i] = bt[i];
    }

    bt[9] = 9999;
    for (time = 0; count != n; ++time)
    {
        smallest = 9;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] <= time && bt[i] < bt[smallest] && bt[i]>0)
                smallest = i;
        }
        bt[smallest]--;

        if (bt[smallest] == 0)
        {
            count++;
            end = time + 1;
            completion[smallest] = end;
            wt[smallest] = end - a[smallest] - x[smallest];
            tat[smallest] = end - a[smallest];
        }
    }
    cout << "Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\tCompletion Time\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "p" << i + 1 << "\t\t" << x[i] << "\t\t" << a[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\t\t" << completion[i] << endl;
        avg += wt[i];
        tt += tat[i];
    }

    srtf_avg_wt = avg / n;
    srtf_avg_ta = tt / n;

    cout << "\n\nAverage waiting time = " << srtf_avg_wt << "\n";
    cout << "Average Turnaround time = " << srtf_avg_ta << "\n";
}

int main()
{

    int n = 0;
    cout << "\nEnter number of processes: ";
    cin >> n;
    
    if (n > 10 || n <= 0)
    {
        cout << "\nInvalid number of processes (valid = 1...10)\n Setting it to 3\n";
        n = 3;
    }
    
    cout << "\n--------------------------------------\n";
    cout << "                  FCFS                \n";
    cout << "--------------------------------------\n";
    fcfs(n);

    cout << "\n--------------------------------------\n";
    cout << "                   SJF                \n";
    cout << "--------------------------------------\n";   
    sjf(n);

    cout << "\n--------------------------------------\n";
    cout << "                  SRTF                \n";
    cout << "--------------------------------------\n";
    srtf(n);
    
    cout << "\n--------------------------------------\n";
    cout << "               Results                \n";
    cout << "--------------------------------------\n";
    cout << "\n\t\tAVG WT\t\tAVG TA";
    cout << "\nFCFS\t\t" << fcfs_avg_wt << "\t\t" << fcfs_avg_ta;
    cout << "\nSJF\t\t" << sjf_avg_wt << "\t\t" << sjf_avg_ta;
    cout << "\nSRTF\t\t" << srtf_avg_wt << "\t\t" << srtf_avg_ta;
    return 0;
}
