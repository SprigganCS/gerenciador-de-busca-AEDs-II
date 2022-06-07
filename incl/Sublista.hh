#ifndef SUBLISTA_H
#define SUBLISTA_H

#include "Nodulo.hh"

class ListaPrincipal;

class Sublista {
private:
    NoduloSub *  inicio;
    unsigned int tamanho;

    void pushBack(NoduloSub &nodulo);
    void pushOrdenado(NoduloSub &nodulo);
    void popBack();
    void removerUtil(const Nodulo &dados);

public:
    Categoria categoria;
    Sublista(const Categoria &categoria);
    Sublista(const Categoria &categoria, ListaPrincipal &lista);
    ~Sublista();

    bool vazia() const;
    void imprimir() const;

    void push(NoduloSub &nodulo);
    void push(ListaPrincipal &lista);
    void emplace(Nodulo &dados);
    void remover(const Nodulo &dados);
};

#include "ListaPrincipal.hh"

#endif // SUBLISTA_H
