#ifndef COLA_CONFIG_H
#define COLA_CONFIG_H

#include <string>
#include <vector>
#include "proceso.h"

using namespace std;

class colaConfig{
    private:
        string type;
        int quantum;    
    public:
        void set_type(string type);
        void set_quantum(int quantum);

        string get_type();
        int get_quantum();
};


#endif