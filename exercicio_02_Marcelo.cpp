#include <iostream>
#include <vector>
#include <string>


using namespace std;



class ItemSet {
private:
    vector<string> items;

public:
    // Método para inserir um item no conjunto, se ele não existir
    void inserir(const string& s) {
        if (!contem(s)) {
            items.push_back(s);
        }
    }

    // Método para excluir um item do conjunto, se ele existir
    void excluir(const string& s) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (*it == s) {
                items.erase(it);
                break;
            }
        }
    }

    // Método para verificar se um item existe no conjunto
    bool contem(const string& s) const {
        for (const string& item : items) {
            if (item == s) {
                return true;
            }
        }
        return false;
    }

    // Método para exibir os itens do conjunto
    void exibir() const {
        cout << "Itens no conjunto:" << endl;
        for (const string& item : items) {
            cout << "- " << item << endl;
        }
    }
};

int main() {
    ItemSet conjunto;

    conjunto.inserir("item1");
    conjunto.inserir("item2");
    conjunto.inserir("item3");
    conjunto.inserir("item1"); // Não deve ser inserido novamente
    conjunto.inserir("item4");

    conjunto.exibir();

    conjunto.excluir("item2");
    conjunto.excluir("item5"); // Não deve causar erro, pois "item5" não está no conjunto

    conjunto.exibir();

    return 0;
}
