#include <iostream>

#include "ListaPrincipal.hh"

class Menu {
private:
    ListaPrincipal &lista;

    void         desenhar();
    unsigned int lerOpcao();
    bool         processarOpcao(const unsigned int opcao);
    Dados        lerDados();
    void         listarBuscas();

    void opcaoUm();
    void opcaoDois();
    void opcaoTres();
    void opcaoQuatro();

public:
    Menu(ListaPrincipal &Lista);
    void executar();
};
