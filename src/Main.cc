#include <fstream>
#include <iostream>
#include <sstream>

#include "ListaPrincipal.hh"
#include "Menu.hh"

int main() {
    std::ifstream   arquivo("./input/BD-veiculos.txt");
    ListaPrincipal *lista = new ListaPrincipal(Categoria::PLACA, arquivo);

    lista->sublistaEmplace(Categoria::ANO);
    lista->sublistaEmplace(Categoria::CAMBIO);
    lista->sublistaEmplace(Categoria::COMBUSTIVEL);

    Menu menu(*lista);
    menu.executar();

    delete lista;
    return 0;
}
