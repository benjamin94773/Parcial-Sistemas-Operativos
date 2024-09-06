#include "colaConfig.h"


void colaConfig::set_type(string type){
    this->type = type;
}
void colaConfig::set_quantum(int quantum){
    this->quantum = quantum;
}

string colaConfig::get_type(){
    return this->type;
}
int colaConfig::get_quantum(){
    return this->quantum;
}