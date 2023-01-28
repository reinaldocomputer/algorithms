#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

class Time{
public:
    int minutos;
    int segundos;
    int milesimos;

    Time(){
        this->minutos=0;
        this->segundos=0;
        this->milesimos=0;
    }

    Time(int minutos, int segundos, int milesimos){
        this->minutos = minutos;
        this->segundos = segundos;
        this->milesimos = milesimos;
    }
    bool operator < (const Time &b) const{
        if( this->minutos < b. minutos) return true;
        if( this->minutos == b.minutos && this->segundos < b.segundos) return true;
        if( this->minutos == b.minutos && this->segundos == b.segundos && this->milesimos < b.milesimos) return true;
    }
    void print(){
        cout << "("<<minutos<<":"<<segundos<<":"<<milesimos<<")";
    }
};


class Pilot{
public:
    int numero;
    vector<Time> voltas;
    Time melhorVolta;
    Time tempoTotal;

    Pilot(int numero, vector<Time> voltas){
        this->numero = numero;
        this->voltas = voltas;
        this->melhorVolta =  buildMelhorVolta();
        this->tempoTotal = buildTempoTotal();
    }

    void times(){
        cout << "Piloto número: " << this->numero << endl;
        cout << "Voltas: " << endl;
        for(int i=0;i<voltas.size();i++){
            voltas[i].print();
        }
        cout << endl;
    }

    Time buildMelhorVolta(){
        Time best = voltas[0];
        for(auto v:this->voltas){
            if(v < best){
                best = v;
            }
        }
        return best;
    }
    Time buildTempoTotal(){
        Time tempoTotal;
        for(auto t:voltas){
            tempoTotal.minutos+=t.minutos;
            tempoTotal.segundos+=t.segundos;
            tempoTotal.milesimos+=t.milesimos;
        }
    }
};

class Sprint{
    public:
    vector<Pilot> pilotos;
    pair<int, Time> melhorVolta;
    multimap<Time, Pilot> top10;


    Sprint(vector<Pilot> pilotos){
        this->pilotos = pilotos;
        this->melhorVolta = buildMelhorVolta();
        for(auto p:pilotos){
            top10.insert(make_pair(p.tempoTotal, p));
        }
    }

    pair<int, Time> buildMelhorVolta(){
        Time melhorvolta = pilotos[0].melhorVolta;
        int piloto = pilotos[0].numero;

        for(auto p:this->pilotos){
            if(p.melhorVolta < melhorvolta){
                melhorvolta = p.melhorVolta;
                piloto = p.numero;
            }
        }
        return make_pair(piloto, melhorvolta);
    }

    int hasExtraPonto(){
        int ranking = 1;
        for(auto it:top10){
            if(ranking <= 10){
                if(it.second.numero == melhorVolta.first){
                    return it.second.numero;
                }
            }
            ranking++;
        }

        return -1;
    }
};
 
void solution(vector<Pilot> &pilotos){
    Sprint cs(pilotos); // current sprint
    cout << "melhor lap:" << endl;
    cout << "piloto: " <<  cs.melhorVolta.first << endl;
    cout << "melhor volta: ";
    cs.melhorVolta.second.print();
    cout << endl;

    cout << "hasExtraPonto: " << cs.hasExtraPonto() << endl;
}


int main() {
 
    int N, V;
    cin >> N >> V;
    
    vector<Pilot> pilotos;
    while(N--){
        int pilot; cin >> pilot;
        vector<Time> voltas;
        for(int i=0; i < V; i++){
            int minutos, segundos, milesimos;
            scanf("%d:%d:%d", &minutos, &segundos, &milesimos);
            voltas.push_back(Time(minutos, segundos, milesimos));
        }
        pilotos.push_back(Pilot(pilot, voltas));
    }
    solution(pilotos);
    return 0;
}