#include "proceso.h"

proceso::proceso(){
    
}

proceso::proceso(string t, int a, int ti, int prio, int rti){
    this->tag = t;
    this->ar_time = a;
    this->time = ti;
    this->priority_queue = prio;
    this->remaining_time = rti;
}

void proceso::set_tag(string tag){
    this->tag = tag;
}
void proceso::set_ar_time(int ar_time){
    this->ar_time = ar_time;
}
void proceso::set_time(int time){
    this->time = time;
}
void proceso::set_priority_queue(int priority){
    this->priority_queue = priority;
}
void proceso::set_ct(int ct){
    this->ct = ct;
}
void proceso::set_wt(int wt){
    this->wt = wt;
}
void proceso::set_tat(int tat){
    this->tat = tat;
}
void proceso::set_rt(int rt){
    this->rt = rt;
}
void proceso::set_remaining_time(int r){ 
    this->remaining_time = r; 
}




string proceso::get_tag(){
    return this->tag;
}
int proceso::get_ar_time(){
    return this->ar_time;
}
int proceso::get_time(){
    return this->time;
}
int proceso::get_priority_queue(){
    return this->priority_queue;
}
int proceso::get_ct(){
    return this->ct;
}
int proceso::get_wt(){
    return this->wt;
}
int proceso::get_tat(){
    return this->tat;
}
int proceso::get_rt(){
    return this->rt;
}
int proceso::get_remaining_time(){ 
    return this->remaining_time;
}