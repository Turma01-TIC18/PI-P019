#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class ItemSet {
private:
    vector<string> items;

public:
    ItemSet() {
        // O construtor inicializa o vector vazio.
    }

    void inserir(const string &item) {
        if (find(items.begin(), items.end(), item) == items.end()) {
            items.push_back(item);
        }
    }

    void excluir(const string &item) {
        auto it = find(items.begin(), items.end(), item);
        if (it != items.end()) {
            items.erase(it);
        }
    }

    void mostraItens() {
        cout << "Itens no conjunto:\n";
        for (const string &item : items) {
            cout << item << "\n";
        }
    }
};

int main() {
    ItemSet conjunto;

    conjunto.inserir("Item 10");
    conjunto.inserir("Item 20");
    conjunto.inserir("Item 10"); 

    conjunto.mostraItens();

    conjunto.excluir("Item 20");

    conjunto.mostraItens();

    return 0;
}
