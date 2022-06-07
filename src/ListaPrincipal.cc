#include "ListaPrincipal.hh"

ListaPrincipal::ListaPrincipal(const Categoria &categoria)
    : inicio(nullptr), categoria(categoria), tamanho(0){};

ListaPrincipal::ListaPrincipal(const Categoria &categoria, std::ifstream &arquivo)
    : ListaPrincipal::ListaPrincipal(categoria) {
    this->emplace(arquivo);
}

ListaPrincipal::~ListaPrincipal() {
    for (auto sublista : this->sublistas) {
        delete sublista;
    }
    this->sublistas.clear();
    while (!this->vazia()) {
        this->popBack();
    }
}

void ListaPrincipal::pushBack(Nodulo &nodulo) {
    nodulo.setProximo(this->inicio);
    this->inicio = &nodulo;
}
void ListaPrincipal::pushOrdenado(Nodulo &nodulo) {
    if (!this->vazia()) {
        Nodulo *posicao = this->inicio;
        while (posicao->getProximo() != nullptr && !nodulo.temMaiorPrecedencia(this->categoria, *posicao->getProximo())) {
            posicao = posicao->getProximo();
        }
        nodulo.setProximo(posicao->getProximo());
        posicao->setProximo(&nodulo);
    }
}
void ListaPrincipal::emplaceSublistas(Nodulo &nodulo) {
    for (auto sublista : sublistas) {
        sublista->emplace(nodulo);
    }
}
void ListaPrincipal::removerSublistas(Nodulo &nodulo) {
    for (auto sublista : sublistas) {
        sublista->remover(nodulo);
    }
}

void ListaPrincipal::emplaceArquivoLer(std::ifstream &arquivo) {
    std::string linha;
    while (getline(arquivo, linha)) {
        if (linha[0] != '#') { // Ignora comentários.
            std::stringstream ss(linha);

            Dados dados_buffer = {};
            ss >> dados_buffer;
            this->emplace(dados_buffer);
        }
    }
}
void ListaPrincipal::popBack() {
    Nodulo *nodulo = this->inicio;
    this->inicio = this->inicio->getProximo();
    removerSublistas(*nodulo);
    delete nodulo;
}
void ListaPrincipal::removerUtil(const unsigned int indice) {
    if (indice == 0) {
        this->popBack();
    } else if (indice < this->tamanho) {
        Nodulo *anterior = buscar(indice - 1);
        Nodulo *nodulo = anterior->getProximo();
        anterior->setProximo(nodulo->getProximo());
        removerSublistas(*nodulo);
        delete nodulo;
    } else {
        throw std::out_of_range("Indice fora do alcance!");
    }
}

Nodulo *ListaPrincipal::getInicio() {
    return this->inicio;
}
Nodulo *ListaPrincipal::buscar(const unsigned int indice) {
    Nodulo *nodulo = nullptr;
    if (indice < this->tamanho) {
        nodulo = this->inicio;
        for (unsigned int i = 0; i < indice; ++i) {
            nodulo = nodulo->getProximo();
        }
    } else {
        throw std::out_of_range("Indice fora do alcance!");
    }
    return nodulo;
}

bool ListaPrincipal::vazia() const {
    return this->inicio == nullptr;
}
void ListaPrincipal::imprimir() const {
    if (!this->vazia()) {
        Nodulo *     nodulo = this->inicio;
        unsigned int i = 1;
        while (nodulo != nullptr) {
            std::cout << i << ". " << *nodulo << '\n';
            nodulo = nodulo->getProximo();
            ++i;
        }
    } else {
        std::cout << "Lista vazia." << '\n';
    }
}

void ListaPrincipal::push(Nodulo &nodulo) {
    if (this->vazia() || nodulo.temMaiorPrecedencia(this->categoria, *this->inicio)) {
        this->pushBack(nodulo);
    } else {
        this->pushOrdenado(nodulo);
    }
    this->emplaceSublistas(nodulo);
    ++this->tamanho;
}

std::vector<Sublista *> &ListaPrincipal::sublistasGet() {
    return this->sublistas;
}
void ListaPrincipal::sublistaEmplace(const Categoria &categoria) {
    Sublista *sublista = new Sublista(categoria, *this);
    this->sublistas.push_back(sublista);
}
void ListaPrincipal::emplace(const Dados &dados) {
    Nodulo *nodulo = new Nodulo(dados);
    this->push(*nodulo);
}
void ListaPrincipal::emplace(std::ifstream &arquivo) {
    if (arquivo.is_open()) {
        this->emplaceArquivoLer(arquivo);
        arquivo.close();
    } else {
        throw std::ifstream::failure("Arquivo nao esta aberto.");
    }
}

void ListaPrincipal::remover(const unsigned int indice) {
    if (!this->vazia()) {
        removerUtil(indice);
    } else {
        throw std::underflow_error("Lista vazia!");
    }
}
