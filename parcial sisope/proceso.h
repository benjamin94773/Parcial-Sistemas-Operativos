#ifndef PROCESO_H
#define PROCESO_H

#include <string>

using namespace std;


class proceso{
    private:
        string tag;
        int ar_time = 0;
        int time = 0;
        int priority_queue = -1;
        int ct = 0;
        int wt = 0;
        int tat = 0;
        int rt = -1;
        int remaining_time = 0;

    public:
        proceso();
        proceso(string t, int a, int ti, int prio, int rti);
        void set_tag(string tag);
        void set_ar_time(int ar_time);
        void set_time(int time);
        void set_priority_queue(int priority);
        void set_ct(int ct);
        void set_wt(int wt);
        void set_tat(int tat);
        void set_rt(int rt);
        void set_remaining_time(int rem);

        string get_tag();
        int get_ar_time();
        int get_time();
        int get_priority_queue();
        int get_ct();
        int get_wt();
        int get_tat();
        int get_rt();
        int get_remaining_time();

};




#endif