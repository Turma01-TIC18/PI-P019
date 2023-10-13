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




















    ItemSet operator-(const ItemSet& other) const {
        ItemSet result = *this;
        for (const string& item : other.conjuntos) {
            auto it = find(result.conjuntos.begin(), result.conjuntos.end(), item);
            if (it != result.conjuntos.end()) {
                result.conjuntos.erase(it);
            }
        }
        return result;
    }
   
    ItemSet operator!=(const ItemSet& other) const {
        ItemSet result = *this - other; 
        ItemSet temp = other - *this;   
        result.conjuntos.insert(result.conjuntos.end(), temp.conjuntos.begin(), temp.conjuntos.end());
        return result;
    }

};

int main() {
    ItemSet conjuntoA;
    conjuntoA.inserirItens("Gol1");
    conjuntoA.inserirItens("Gol2");
    conjuntoA.inserirItens("Gol2");

    conjuntoA.mostrarItens();

    ItemSet conjuntoB;
    conjuntoB.inserirItens("Gol1");
    conjuntoB.inserirItens("Bola2");

    conjuntoB.mostrarItens();

    ItemSet conjuntoC;
    conjuntoC.inserirItens("Bola1");
    conjuntoC.inserirItens("Bola2");

    conjuntoC.mostrarItens();

    ItemSet resultado = conjuntoB - conjuntoA; 



    cout << "Subtração de (B - A)" << endl;
    resultado.mostrarItens();

    ItemSet resultado2 = conjuntoB != conjuntoA;

    cout << "Diferença de (B <> A)" << endl;

    resultado2.mostrarItens();


    return 0;
}
