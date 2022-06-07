#include "Menu.hh"

Menu::Menu(ListaPrincipal &lista)
    : lista(lista){};

void Menu::desenhar() {
    std::cout << "MENU\n"
              << "1. Incluir\n"
              << "2. Excluir\n"
              << "3. Buscas\n"
              << "4. Relatorio\n"
              << "5. Sair\n";
}
unsigned int Menu::lerOpcao() {
    unsigned int opcao = 0;
    std::cin >> std::ws;
    std::cin >> opcao;
    return opcao;
}
Dados Menu::lerDados() {
    Dados dados{};
    std::cout << "Informe os dados: \n";
    std::cout << "Modelo: ";
    std::cin >> std::ws >> dados.modelo;
    std::cout << "Marca: ";
    std::cin >> std::ws >> dados.marca;
    std::cout << "Tipo: ";
    std::cin >> std::ws >> dados.tipo;
    std::cout << "Ano: ";
    std::cin >> std::ws >> dados.ano;
    std::cout << "KM: ";
    std::cin >> std::ws >> dados.km;
    std::cout << "Potencia do Motor: ";
    std::cin >> std::ws >> dados.potencia_do_motor;
    std::cout << "Combustivel: ";
    std::cin >> std::ws >> dados.combustivel;
    std::cout << "Cambio: ";
    std::cin >> std::ws >> dados.cambio;
    std::cout << "Direcao: ";
    std::cin >> std::ws >> dados.direcao;
    std::cout << "Cor: ";
    std::cin >> std::ws >> dados.cor;
    std::cout << "Portas: ";
    std::cin >> std::ws >> dados.portas;
    std::cout << "Placa: ";
    std::cin >> std::ws >> dados.placa;

    return dados;
}

void Menu::listarBuscas() {
    auto buscas = this->lista.sublistasGet();
    if (!buscas.empty()) {
        for (unsigned int i = 0; i < buscas.size(); ++i) {
            std::cout << i + 1 << ". ";
            categoriaPrint(buscas[i]->categoria);
            std::cout << '\n';
        }
    } else {
        std::cout << "Nao ha buscas.\n";
    }
}

void Menu::opcaoUm() {
    try {
        this->lista.emplace(this->lerDados());
    } catch (std ::exception &e) {
        std::cerr << "Falha ao inserir: " << e.what() << "\n";
    }
}
void Menu::opcaoDois() {
    try {
        unsigned int indice = 0;
        std::cout << "Informe o indice: ";
        indice = this->lerOpcao();
        this->lista.remover(indice - 1);
    } catch (std ::exception &e) {
        std::cerr << "Falha ao remover: " << e.what() << "\n";
    }
}
void Menu::opcaoTres() {
    try {
        unsigned int indice = 0;
        this->listarBuscas();
        std::cout << "Selecione uma busca: ";
        indice = this->lerOpcao();
        std::cout << "Categoria ";
        categoriaPrint(this->lista.sublistasGet()[indice - 1]->categoria);
        std::cout << '\n';
        this->lista.sublistasGet()[indice - 1]->imprimir();
    } catch (std ::exception &e) {
        std::cerr << "Falha ao buscar: " << e.what() << "\n";
    }
}
void Menu::opcaoQuatro() {
    try {
        std::cout << "Lista Principal: \n";
        this->lista.imprimir();
    } catch (std ::exception &e) {
        std::cerr << "Falha ao exibir relatorio: " << e.what() << "\n";
    }
}

bool Menu::processarOpcao(const unsigned int opcao) {
    bool sair = false;
    switch (opcao) {
    case 1:
        opcaoUm();
        break;
    case 2:
        opcaoDois();
        break;
    case 3:
        opcaoTres();
        break;
    case 4:
        opcaoQuatro();
        break;
    case 5:
        sair = true;
        break;
    }
    return sair;
}

void Menu::executar() {
    bool         sair = false;
    unsigned int opcao = 0;
    while (!sair) {
        this->desenhar();
        opcao = this->lerOpcao();
        sair = this->processarOpcao(opcao);
    }
}
