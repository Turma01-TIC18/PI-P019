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


     ItemSet operator+(const ItemSet& other) const {
        ItemSet result = *this; 

        for (const string& item : other.conjuntos) {
 
            if (find(result.conjuntos.begin(), result.conjuntos.end(), item) == result.conjuntos.end()) {
                result.conjuntos.push_back(item);
            }
        }

        return result;
    }



    ItemSet operator-(const ItemSet& other) const {
        //Implementar
    }
   
    ItemSet operator!=(const ItemSet& other) const {
        //Implementar
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
    conjuntoC.inserirItens("Jogador1");
    conjuntoC.inserirItens("Jogador2");

    ItemSet resultado = conjuntoB + conjuntoC;

    cout << "\nConjunto A:\n";
    conjuntoA.mostrarItens();

    cout << "\nResultado de A = B + C:\n";
    resultado.mostrarItens();


return 0;
}

