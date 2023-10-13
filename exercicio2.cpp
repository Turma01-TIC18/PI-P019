#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class ItemSet {
private:
    vector<string> conjuntos;

public:
    
    ItemSet() {}
    
    ItemSet(const ItemSet& other) {
        conjuntos = other.conjuntos;
    }
    
    ItemSet& operator=(const ItemSet& other) {
        if (this != &other) {
            conjuntos = other.conjuntos;
        }
        return *this;
    }

    void inserirItens(const string& s) {
        if (find(conjuntos.begin(), conjuntos.end(), s) == conjuntos.end()) {
            conjuntos.push_back(s);
        }
    }

    void mostrarItens() {
        cout << "Itens no conjunto:" << endl;
        for (const string& item : conjuntos) {
            cout << item << endl;
        }
    }

};

int main() {
    ItemSet conjuntoA;
    conjuntoA.inserirItens("Gol1");
    conjuntoA.inserirItens("Gol2");

    conjuntoA.mostrarItens();

    ItemSet conjuntoB;
    conjuntoB.inserirItens("Bola1");
    conjuntoB.inserirItens("Bola2");

    conjuntoB.mostrarItens();


    return 0;
}
