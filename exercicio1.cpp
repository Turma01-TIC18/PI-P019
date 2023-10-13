#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ItemSet{
        
    public:
    vector<string> itens;
    
    /*vector<string> getItens() {
        return itens;
    };*/
    void inserir(string _item) {
        int posicao = ProcItem(_item);
        if(posicao == -1) {
            itens.push_back(_item);
        }else {
            cout << "Valor não encontrado!" << endl;
        }
        
    }
    void excluir(string _item) {
        int posicao = ProcItem(_item);
        if(posicao != -1){
            itens.at(posicao).erase();
        }else {
            cout << "Valor não encontrado!" << endl;
        }
    }

    int ProcItem(string _item) {
        int i = 0;
        for(auto it=itens.begin(); it!=itens.end(); it++, i++) {
            if(*it == _item) {
                return i;
            }
        }
        return -1;
    }
    void imprimir() {
        for(auto it=itens.begin(); it!=itens.end(); it++) {
            cout << *it << endl;            
        }
        
    }
};

int main() {
    ItemSet conjuntos;

    conjuntos.inserir("Item A");
    
    conjuntos.inserir("Item B");
    
    conjuntos.inserir("Item C");
    conjuntos.imprimir();

    cout << "--------------------";
    conjuntos.excluir("Item A");
    conjuntos.excluir("Item C");
    conjuntos.imprimir();
    cout << "--------------------";
    conjuntos.inserir("Item D");
    conjuntos.imprimir();

    
    
    return 0;

}