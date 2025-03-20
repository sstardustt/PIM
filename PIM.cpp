#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Estruturas para Frutas e Legumes
struct Item 
{
    string nome;
    double preco;
    int quantidade;
};

// Função para exibir menu
void menu_exibicao() 
{
    cout << "----------------------------------------------------------" << endl;
    cout << "\t\t\tHORTI FRUTI" << endl;
    cout << "----------------------------------------------------------" << endl;
}

// Função para mostrar os itens
void mostrarItens(const vector<Item>& itens) 
{
    for (size_t i = 0; i < itens.size(); ++i) 
    {
        cout << "[" << i + 1 << "] " << itens[i].nome << " - R$" << itens[i].preco << " (Quantidade: " << itens[i].quantidade << ")" << endl;
    }
}

// Função para excluir cadastro
void excluirItem(vector<Item>& itens) 
{
    menu_exibicao();
    cout << "ITENS DISPONIVEIS PARA EXCLUIR: " << endl;
    mostrarItens(itens);

    int selec;
    cout << "Digite o numero do item que deseja excluir: \n---->";
    cin >> selec;

    if (selec > 0 && selec <= itens.size()) 
    {
        itens.erase(itens.begin() + selec - 1);
        cout << "Item excluído com sucesso!" << endl;
    } 
    else 
    {
        cout << "Opcao invalida!" << endl;
    }
}

// Função para adicionar frutas ou legumes
void adicionarItem(vector<Item>& itens) 
{
    Item novoItem;
    cout << "Digite o nome do item: ";
    cin >> novoItem.nome;
    cout << "Digite o preço do item: ";
    cin >> novoItem.preco;
    cout << "Digite a quantidade do item: ";
    cin >> novoItem.quantidade;

    itens.push_back(novoItem);
    cout << "Item adicionado com sucesso!" << endl;
}

// Função para realizar compras
void realizarCompras(vector<Item>& frutas, vector<Item>& legumes) 
{
    menu_exibicao();
    double total = 0.0;
    char continuar;

    do 
    {
        cout << "FRUTAS DISPONIVEIS: " << endl;
        mostrarItens(frutas);
        cout << "LEGUMES DISPONIVEIS: " << endl;
        mostrarItens(legumes);

        int selec;
        cout << "Digite a opcao que deseja selecionar: \n---->";
        cin >> selec;

        if (selec == 0) break;

        if (selec >= 1 && selec <= frutas.size()) 
        {
            int quantidade;
            cout << "Digite a quantidade: ";
            cin >> quantidade;
            total += quantidade * frutas[selec - 1].preco;
        } 
        else if (selec > frutas.size() && selec <= frutas.size() + legumes.size()) 
        {
            int quantidade;
            cout << "Digite a quantidade: ";
            cin >> quantidade;
            total += quantidade * legumes[selec - 1 - frutas.size()].preco;
        } 
        else 
        {
            cout << "Opcao invalida!" << endl;
        }

        cout << "Deseja continuar comprando? (s/n): ";
        cin >> continuar;
    } 
    while (continuar == 's');

    cout << "TOTAL A PAGAR: R$" << total << endl;

    // Chama a função de pagamento
    string formaPagamento;
    cout << "Escolha a forma de pagamento (dinheiro/cartao): ";
    cin >> formaPagamento;

    if (formaPagamento == "dinheiro") 
    {
        cout << "Pagamento realizado com sucesso em dinheiro!" << endl;
    } 
    else if (formaPagamento == "cartao") 
    {
        cout << "Pagamento realizado com sucesso no cartão!" << endl;
    } 
    else 
    {
        cout << "Forma de pagamento inválida!" << endl;
    }
}

// Função de estoque
void estoque(vector<Item>& frutas, vector<Item>& legumes) 
{
    menu_exibicao();
    cout << "FRUTAS DISPONIVEIS: " << endl;
    mostrarItens(frutas);
    cout << "LEGUMES DISPONIVEIS: " << endl;
    mostrarItens(legumes);
}

// Função de login
bool funcionario_login() 
{
    string nome_fun, sobrenome, anoNasc, noFav;
    cout << "Insira o nome do funcionario: \n---->";
    cin >> nome_fun;
    cout << "Insira o sobrenome do funcionario: \n---->";
    cin >> sobrenome;
    cout << "Insira o ano de nascimento do funcionario: \n---->";
    cin >> anoNasc;
    cout << "Insira o numero favorito do funcionario: \n---->";
    cin >> noFav;

    string usuario = nome_fun + sobrenome + anoNasc;
    string senha = nome_fun + sobrenome + noFav;

    cout << "O usuario e: " << usuario << endl;
    cout << "A senha temporaria do usuario e: " << senha << endl;

    string input_usuario, input_senha;
    cout << "Insira o usuario: \n---->";
    cin >> input_usuario;
    cout << "Insira a senha: \n---->";
    cin >> input_senha;

    if (input_usuario == usuario && input_senha == senha) 
    {
        cout << "Login bem-sucedido!" << endl;
        return true;
    } 
    else 
    {
        cout << "Login falhou! Tente novamente." << endl;
        return false;
    }
}

// Função principal
int main() 
{
    menu_exibicao();
    while (!funcionario_login());

    // Inicializa frutas e legumes
    vector<Item> frutas = 
    {
        {"Banana", 2.7, 200},
        {"Maca", 2.0, 200},
        {"Laranja", 1.7, 200},
        {"Limão", 5.1, 200},
        {"Abacaxi", 6.5, 200}
    };

    vector<Item> legumes = 
    {
        {"Cebola", 3.2, 100},
        {"Cenoura", 3.5, 100},
        {"Alho", 3.2, 100},
        {"Alho-poro", 2.1, 100},
        {"Chuchu", 2.9, 100}
    };

    // Menu principal
    int opcao;
    do 
    {
        cout << "\nEscolha uma opcao:\n";
        cout << "[1] Compras\n";
        cout << "[2] Estoque\n";
        cout << "[3] Excluir Item (Frutas Ou Legumes)\n";
        cout << "[4] Adicionar Item\n";
        cout << "[5] Sair\n";
        cout << "Digite a opcao desejada: ";
        cin >> opcao;

        switch (opcao) 
        {
            case 1:
                realizarCompras(frutas, legumes);
                break;
            case 2:
                estoque(frutas, legumes);
                break;
            case 3: 
            {
                int tipo;
                cout << "Deseja excluir uma fruta ou legume? (1 - Fruta, 2 - Legume): ";
                cin >> tipo;
                if (tipo == 1) 
                {
                    excluirItem(frutas);
                } 
                else if (tipo == 2) 
                {
                    excluirItem(legumes);
                } 
                else 
                {
                    cout << "Opcao inválida!" << endl;
                }
                break;
            }
            case 4: 
            {
                int tipo;
                cout << "Deseja adicionar uma fruta ou legume? (1 - Fruta, 2 - Legume): ";
                cin >> tipo;
                if (tipo == 1) 
                {
                    adicionarItem(frutas);
                }
                else if (tipo == 2) 
                {
                    adicionarItem(legumes);
                }
                else 
                {
                    cout << "Opcao inválida!" << endl;
                }
                break;
            }
            case 5:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao inválida!" << endl;
                break;
        }
    } 
    while (opcao != 5);

    return 0;
}