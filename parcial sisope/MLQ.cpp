#include "proceso.h"
#include "colaConfig.h"   

#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <set>


vector<colaConfig> configurar_colas() {
    int num_colas;
    string type;
    int quantum;
    cin >> num_colas;
    vector<colaConfig> colas(num_colas);
    for (int i = 0; i < num_colas; i++) {
        cin >> type;
        colas[i].set_type(type);
        if (colas[i].get_type() == "RR") {
            cin >> quantum;
            colas[i].set_quantum(quantum);
        } else {
            colas[i].set_quantum(0); 
        }
    }

    return colas;
}

vector<proceso> read() {
    string proces;
    int arTime;
    int buTime;
    int priority;
    vector<proceso> ans;
    proceso procesos;
    cin >> proces >> arTime >> buTime >> priority;
      
    while(proces[0] != '0'){
        procesos.set_tag(proces);
        procesos.set_ar_time(arTime);
        procesos.set_time(buTime);
        procesos.set_remaining_time(buTime);
        procesos.set_priority_queue(priority);

        ans.push_back(procesos);
        cin >> proces >> arTime >> buTime >> priority;
    }
    return ans;
    
}


void round_robin(queue<proceso*> &procesos, int quantum, int &tiempo_actual){
    if(!procesos.empty()){
        proceso* tmp = procesos.front();
        procesos.pop();

        if(tmp->get_rt() == -1){
            tmp->set_rt(tiempo_actual);
        }

        int minimo = min(quantum, tmp->get_remaining_time());
        tmp->set_remaining_time(tmp->get_remaining_time() - minimo);
        tiempo_actual += minimo;

        if(tmp->get_remaining_time() > 0){
            procesos.push(tmp);
        }else{
            tmp->set_ct(tiempo_actual);
            tmp->set_tat(tmp->get_ct() - tmp->get_ar_time());
            tmp->set_wt(tmp->get_tat() - tmp->get_time());
        }
    }
}
void fcfs(queue<proceso*> &procesos, int &tiempo_actual){
    if (!procesos.empty()) {
        proceso* tmp = procesos.front();
        procesos.pop();

        if(tmp->get_rt() == -1){
            tmp->set_rt(tiempo_actual);
        }

        tiempo_actual = max(tiempo_actual, tmp->get_ar_time()) + tmp->get_time();
        tmp->set_ct(tiempo_actual);
        tmp->set_tat(tmp->get_ct() - tmp->get_ar_time());
        tmp->set_wt(tmp->get_tat() - tmp->get_time());
    }
}

void mlq(vector<proceso>& procesos, vector<colaConfig>& colas) {
    vector<queue<proceso*>> cola_listas(colas.size()); 
    int tiempo_actual = 0;
    set<string> procesos_en_cola;  

    for (int i = 0; i < procesos.size(); i++) {
        int prioridad = procesos[i].get_priority_queue() - 1; 
        if (prioridad >= 0 && prioridad < cola_listas.size()) {
            cola_listas[prioridad].push(&procesos[i]);
            procesos_en_cola.insert(procesos[i].get_tag()); 
        }
    }

    for (int i = 0; i < colas.size(); i++) {
        while (!cola_listas[i].empty()) {
            if (colas[i].get_type() == "RR") {
                round_robin(cola_listas[i], colas[i].get_quantum(), tiempo_actual);
            } else if (colas[i].get_type() == "FCFS") {
                fcfs(cola_listas[i], tiempo_actual);
            }
        }
    }

    cout << "Tag\tAT\tBT\tCT\tWT\tTAT\tRT\n";
    for (auto& p : procesos) {
        cout << p.get_tag() << "\t"
             << p.get_ar_time() << "\t"
             << p.get_time() << "\t"
             << p.get_ct() << "\t"
             << p.get_wt() << "\t" 
             << p.get_tat() << "\t"
             << p.get_rt() << endl;
    }
    float CTProm = 0;
    float WTProm = 0;
    float TATProm = 0;
    float RTProm = 0;
    for (int w = 0; w < procesos.size(); w++){
        CTProm += procesos[w].get_ct();
        WTProm += procesos[w].get_wt();
        TATProm += procesos[w].get_tat();
        RTProm += procesos[w].get_rt();
    }
    int pro = procesos.size();
    cout << "CT Promedio: " << CTProm/pro << endl;
    cout << "WT Promedio: " << WTProm/pro << endl;
    cout << "TAT Promedio: " << TATProm/pro << endl;
    cout << "RT Promedio: " << RTProm/pro << endl;
}




int main(){
    vector<colaConfig> colas = configurar_colas();
    vector<proceso> procesos = read(); 
    mlq(procesos, colas);
    
    
    
    return 0;
}