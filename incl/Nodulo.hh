#ifndef NODULOCARRO_H
#define NODULOCARRO_H
#include <fstream>
#include <iostream>
#include <sstream>

enum class Categoria { MODELO,
                       MARCA,
                       TIPO,
                       ANO,
                       KM,
                       POTENCIA,
                       COMBUSTIVEL,
                       CAMBIO,
                       DIRECAO,
                       COR,
                       PORTAS,
                       PLACA };

void categoriaPrint(const Categoria &categoria);

struct Dados {
    std::string  modelo;
    std::string  marca;
    std::string  tipo;
    unsigned int ano;
    unsigned int km;
    double       potencia_do_motor;
    std::string  combustivel;
    std::string  cambio;
    std::string  direcao;
    std::string  cor;
    unsigned int portas;
    std::string  placa;

    friend std::stringstream &operator>>(std::stringstream &ss, Dados &dados);
    friend std::ostream &     operator<<(std::ostream &os, const Dados &dados);
};

class Nodulo {
private:
    Dados   dados;
    Nodulo *proximo;

public:
    Nodulo();
    Nodulo(Dados dados, Nodulo *proximo = nullptr);

    const Dados &getDados() const;
    Nodulo *     getProximo() const;

    void setProximo(Nodulo *proximo);
    bool temMaiorPrecedencia(const Categoria &categoria, const Nodulo &outro);

    friend std::stringstream &operator>>(std::stringstream &ss, Nodulo &nodulo);
    friend std::ostream &     operator<<(std::ostream &os, const Nodulo &nodulo);
};

class NoduloSub {
private:
    Nodulo &   dados;
    NoduloSub *proximo;

public:
    NoduloSub(Nodulo &dados, NoduloSub *proximo = nullptr);
    const Nodulo &getDados() const;
    NoduloSub *   getProximo() const;
    void          setProximo(NoduloSub *proximo);
    bool          temMaiorPrecedencia(const Categoria &categoria, const NoduloSub &outro);
};

#endif // NODULOCARRO_H
