#ifndef LISTAORDENADA_H
#define LISTAORDENADA_H

#include "Nodulo.hh"
#include "Sublista.hh"
#include <fstream>
#include <vector>

class ListaPrincipal {
protected:
    Nodulo *                inicio;
    Categoria               categoria;
    unsigned int            tamanho;
    std::vector<Sublista *> sublistas;

    void pushBack(Nodulo &nodulo);
    void pushOrdenado(Nodulo &nodulo);
    void emplaceSublistas(Nodulo &nodulo);
    void removerSublistas(Nodulo &nodulo);

    void popBack();
    void removerUtil(const unsigned int indice);
    void emplaceArquivoLer(std::ifstream &arquivo);

public:
    ListaPrincipal(const Categoria &categoria);
    ListaPrincipal(const Categoria &categoria, std::ifstream &arquivo);
    ~ListaPrincipal();

    Nodulo *                 getInicio();
    std::vector<Sublista *> &sublistasGet();

    Nodulo *buscar(const unsigned int indice);

    bool vazia() const;
    void imprimir() const;

    void push(Nodulo &nodulo);

    void sublistaEmplace(const Categoria &categoria);
    void emplace(const Dados &dados);
    void emplace(std::ifstream &arquivo);
    void remover(const unsigned int indice);
};

#endif //LISTAORDENADA_H
