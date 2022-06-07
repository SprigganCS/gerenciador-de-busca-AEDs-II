#include "Nodulo.hh"

void categoriaPrint(const Categoria &categoria) {

    switch (categoria) {
    case Categoria::MODELO:
        std::cout << "Modelo";
        break;
    case Categoria::MARCA:
        std::cout << "Marca";
        break;
    case Categoria::TIPO:
        std::cout << "Tipo";
        break;
    case Categoria::ANO:
        std::cout << "Ano";
        break;
    case Categoria::KM:
        std::cout << "KM";
        break;
    case Categoria::POTENCIA:
        std::cout << "Potencia do Motor";
        break;
    case Categoria::COMBUSTIVEL:
        std::cout << "Combustivel";
        break;
    case Categoria::CAMBIO:
        std::cout << "Cambio";
        break;
    case Categoria::DIRECAO:
        std::cout << "Direcao";
        break;
    case Categoria::COR:
        std::cout << "Cor";
        break;
    case Categoria::PORTAS:
        std::cout << "Portas";
        break;
    case Categoria::PLACA:
        std::cout << "Placa";
        break;
    }
}

std::stringstream &operator>>(std::stringstream &ss, Dados &dados) {
    ss >> dados.modelo;
    ss >> dados.marca;
    ss >> dados.tipo;
    ss >> dados.ano;
    ss >> dados.km;
    ss >> dados.potencia_do_motor;
    ss >> dados.combustivel;
    ss >> dados.cambio;
    ss >> dados.direcao;
    ss >> dados.cor;
    ss >> dados.portas;
    ss >> dados.placa;
    return ss;
}
std::ostream &operator<<(std::ostream &os, const Dados &dados) {
    os << dados.modelo
       << ' ' << dados.marca
       << ' ' << dados.tipo
       << ' ' << dados.ano
       << ' ' << dados.km
       << ' ' << dados.potencia_do_motor
       << ' ' << dados.combustivel
       << ' ' << dados.cambio
       << ' ' << dados.direcao
       << ' ' << dados.cor
       << ' ' << dados.portas
       << ' ' << dados.placa;
    return os;
}

Nodulo::Nodulo()
    : dados(), proximo(nullptr){};

Nodulo::Nodulo(Dados dados, Nodulo *proximo)
    : dados(dados), proximo(proximo){};

const Dados &Nodulo::getDados() const {
    return this->dados;
}

Nodulo *Nodulo::getProximo() const {
    return this->proximo;
}

void Nodulo::setProximo(Nodulo *proximo) {
    this->proximo = proximo;
}

bool Nodulo::temMaiorPrecedencia(const Categoria &categoria, const Nodulo &outro) {
    bool prioridade = false;
    switch (categoria) {
    case Categoria::MODELO:
        prioridade = this->getDados().modelo <= outro.getDados().modelo;
        break;
    case Categoria::MARCA:
        prioridade = this->getDados().marca <= outro.getDados().marca;
        break;
    case Categoria::TIPO:
        prioridade = this->getDados().tipo <= outro.getDados().tipo;
        break;
    case Categoria::ANO:
        prioridade = this->getDados().ano <= outro.getDados().ano;
        break;
    case Categoria::KM:
        prioridade = this->getDados().km <= outro.getDados().km;
        break;
    case Categoria::POTENCIA:
        prioridade = this->getDados().potencia_do_motor <= outro.getDados().potencia_do_motor;
        break;
    case Categoria::COMBUSTIVEL:
        prioridade = this->getDados().combustivel <= outro.getDados().combustivel;
        break;
    case Categoria::CAMBIO:
        prioridade = this->getDados().cambio <= outro.getDados().cambio;
        break;
    case Categoria::DIRECAO:
        prioridade = this->getDados().direcao <= outro.getDados().direcao;
        break;
    case Categoria::COR:
        prioridade = this->getDados().cor <= outro.getDados().cor;
        break;
    case Categoria::PORTAS:
        prioridade = this->getDados().portas <= outro.getDados().portas;
        break;
    case Categoria::PLACA:
        prioridade = this->getDados().placa <= outro.getDados().placa;
        break;
    }
    return prioridade;
}

std::stringstream &operator>>(std::stringstream &ss, Nodulo &nodulo) {
    ss >> nodulo.dados;
    return ss;
}
std::ostream &operator<<(std::ostream &os, const Nodulo &nodulo) {
    os << nodulo.dados;
    return os;
}

NoduloSub::NoduloSub(Nodulo &dados, NoduloSub *proximo)
    : dados(dados), proximo(proximo){};

const Nodulo &NoduloSub::getDados() const {
    return this->dados;
}

NoduloSub *NoduloSub::getProximo() const {
    return this->proximo;
}
void NoduloSub::setProximo(NoduloSub *proximo) {
    this->proximo = proximo;
}

bool NoduloSub::temMaiorPrecedencia(const Categoria &categoria, const NoduloSub &outro) {
    return this->dados.temMaiorPrecedencia(categoria, outro.getDados());
}
