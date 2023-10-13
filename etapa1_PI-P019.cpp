#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ItemSet {
    public:
        void inserir(string s) {
            
            if (find(itens.begin(), itens.end(), s) == itens.end()) {
                itens.push_back(s);
            }
        }

        void verificarEIncluir() {

            for (string& s : itens) {

                if (s.find('s') == string::npos) {                    
                    s = "s" + s;                    
                    size_t apos = 0;

                    while (apos < s.length() - 1) {

                        if (s.find(s[apos], apos + 1) != string::npos) {

                            s.erase(apos, 1);

                        } 
                        else {
                            apos++;

                        }
                    }
                }
            }
        }

        void verificarEExcluir() {

            for (string& s : itens) {
                size_t apos = s.find('s');

                if (apos != string::npos) {                    
                    s.erase(apos, 1);                    
                    size_t rep_pos = 0;

                    while (rep_pos < s.length() - 1) {

                        if (s.find(s[rep_pos], rep_pos + 1) != string::npos) {
                            s.erase(rep_pos, 1);

                        } 
                        else {
                            rep_pos++;

                        }
                    }
                }
            }
        }

        void removerRepeticoes() {
            
            for (string& s : itens) {                
                size_t apos = 0;

                while (apos < s.length() - 1) {

                    if (s.find_first_of(s[apos], apos + 1) != string::npos) {
                        s.erase(apos, 1);

                    } 
                    else {
                        apos++;

                    }
                }
            }
        }

        vector<string> getItens() const {
            return itens;

        }

    private:
        vector<string> itens;

};


int main() {

    ItemSet itemSet;

  
    string str1 = "item1";
    string str2 = "item2";
    string str3 = "item3";
    string str4 = "item2";
    string str5 = "novosItem";
    string str6 = "items2";

    itemSet.inserir(str1);
    itemSet.inserir(str2);
    itemSet.inserir(str3);
    itemSet.inserir(str4);
    itemSet.inserir(str5);

    itemSet.verificarEIncluir();

    vector<string> itens = itemSet.getItens();

    cout << "Itens com incluso de 's':\n";

    for (const string& item : itens) {
        cout << item << endl;

    }

    itemSet.verificarEExcluir();
    itens = itemSet.getItens();
    cout << "\nItens com exclusao de 's':\n";

    for (const string& item : itens) {
        cout << item << endl;

    }

    itemSet.removerRepeticoes();
    itens = itemSet.getItens();

    cout << "\nItens com remocao de repeticoes:\n";

    for (const string& item : itens) {
        cout << item << endl;

    }

    return 0;
}
