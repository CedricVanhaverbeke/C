#include "containers.h"

void vul_in_zoveelste_map_beeld_van_sleutel_aan_met_set_van_drie(vector<map<string,stack<set<string>>>> & v, int index, string sleutel, string eerste,string tweede,string derde){
    set<string> s = {eerste, tweede, derde};
    /* LET HIER OP: DE MOVE is superbelangrijk. Anders maak je een kopie van de set die je net gemaakt hebt. */
    v[index][sleutel].push(move(s));
}

// Geen idee waarom ze het zo moeilijk wouden maken. Deze manier is eleganter:
bool zoveelste_map_beeldt_woord_af_op_stack_waarvan_bovenste_dit_element_bevat(vector<map<string,stack<set<string>>>> & v, int index,string woord, string element){
    set<string>::iterator it = v[index][woord].top().begin();
    while(it != v[index][woord].top().end()){
        if(*it == element){
            return true;
        }
        it++;
    }
    return false;
}

int main(void){
    vector<map<string,stack<set<string> > > > v(5);
    vul_in_zoveelste_map_beeld_van_sleutel_aan_met_set_van_drie(v,0,"noot","do","re","mi");
    bool waar = zoveelste_map_beeldt_woord_af_op_stack_waarvan_bovenste_dit_element_bevat(v, 0, "noot", "fa");
    if(waar){
        cout << "Joepie";
    } else {
        cout << ":(";
    }
    return 0;
}