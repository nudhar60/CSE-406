#include <iostream>
using namespace std;

struct Process {
    string id;
    int at, bt, priority, ct, tat, wt;
};

int main() {
    Process p[5] = {
        {"P1", 0, 11, 2},
        {"P2", 5, 28, 0},
        {"P3", 12, 2, 3},
        {"P4", 2, 10, 1},
        {"P5", 0, 16, 4}
    };

    bool done[5] = {false};
    int time = 0, count = 0;

    while (count < 5) {
        int idx = -1, best = 999;
        for (int i = 0; i < 5; i++) {
            if (!done[i] && p[i].at <= time && p[i].priority < best) {
                best = p[i].priority;
                idx = i;
            }
        }
        if (idx != -1) {
            time += p[idx].bt;
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            done[idx] = true;
            count++;
        } else time++;
    }

    cout << "ID\tAT\tBT\tPri\tCT\tTAT\tWT\n";
    for (int i = 0; i < 5; i++)
        cout << p[i].id << "\t" << p[i].at << "\t" << p[i].bt << "\t"
             << p[i].priority << "\t" << p[i].ct << "\t"
             << p[i].tat << "\t" << p[i].wt << "\n";

              return 0;

}
