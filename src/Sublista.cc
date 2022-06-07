#include "Sublista.hh"

Sublista::Sublista(const Categoria &categoria)
    : inicio(nullptr), tamanho(0), categoria(categoria){};

Sublista::Sublista(const Categoria &categoria, ListaPrincipal &lista)
    : Sublista(categoria) {
    this->push(lista);
}
Sublista::~Sublista() {
    while (!this->vazia()) {
        this->popBack();
    }
}

void Sublista::pushBack(NoduloSub &nodulo) {
    nodulo.setProximo(this->inicio);
    this->inicio = &nodulo;
}
void Sublista::pushOrdenado(NoduloSub &nodulo) {
    if (!this->vazia()) {
        NoduloSub *posicao = this->inicio;
        while (posicao->getProximo() != nullptr && !nodulo.temMaiorPrecedencia(this->categoria, *posicao->getProximo())) {
            posicao = posicao->getProximo();
        }
        nodulo.setProximo(posicao->getProximo());
        posicao->setProximo(&nodulo);
    }
}

void Sublista::popBack() {
    NoduloSub *removido = this->inicio;
    this->inicio = this->inicio->getProximo();
    delete removido;
}

void Sublista::removerUtil(const Nodulo &dados) {
    NoduloSub *anterior = this->inicio, *removido = nullptr;
    while (anterior->getProximo() != nullptr && &anterior->getProximo()->getDados() != &dados) {
        anterior = anterior->getProximo();
    }
    if (anterior->getProximo() != nullptr) {
        removido = anterior->getProximo();
        anterior->setProximo(removido->getProximo());
        delete removido;
    }
}

bool Sublista::vazia() const {
    return this->inicio == nullptr;
}
void Sublista::imprimir() const {
    if (!this->vazia()) {
        NoduloSub *  nodulo = this->inicio;
        unsigned int i = 1;
        while (nodulo != nullptr) {
            std::cout << i << ". " << nodulo->getDados() << '\n';
            nodulo = nodulo->getProximo();
            ++i;
        }
    } else {
        std::cout << "Lista vazia." << '\n';
    }
}

void Sublista::push(NoduloSub &nodulo) {
    if (this->vazia() || nodulo.temMaiorPrecedencia(this->categoria, *this->inicio)) {
        this->pushBack(nodulo);
    } else {
        this->pushOrdenado(nodulo);
    }
}
void Sublista::push(ListaPrincipal &lista) {
    Nodulo *nodulo = lista.getInicio();
    while (nodulo != nullptr) {
        this->emplace(*nodulo);
        nodulo = nodulo->getProximo();
    }
}

void Sublista::emplace(Nodulo &dados) {
    NoduloSub *nodulo = new NoduloSub(dados);
    this->push(*nodulo);
}

void Sublista::remover(const Nodulo &dados) {
    if (!this->vazia()) {
        if (&this->inicio->getDados() == &dados) {
            this->popBack();
        } else {
            this->removerUtil(dados);
        }
    } else {
        throw std::underflow_error("Sublista vazia.");
    }
}
