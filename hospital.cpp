#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Cidade
{
    int codigo;
    char nome[35];
    char UF[2];
};

struct Especialidade
{
    int codigo;
    char descricao[50];
};

struct Medico
{
    int codigo;
    char nome[35];
    int codigo_especialidade;
    char endereco[35];
    char telefone[11];
    int codigo_cidade;
};

struct Paciente
{
    char CPF[11];
    char nome[35];
    char endereco[35];
    int codigo_cidade;
};

struct CID
{
    int codigo;
    char descricao[50];
};

struct Medicamento
{
    int codigo;
    char descricao[50];
    int quant_estoque;
    int estoque_minimo;
    int estoque_maximo;
    float preco_unitario;
};

struct Data
{
    int dia;
    int mes;
    int ano;
};
struct Consulta
{
    char cpf_paciente[11];
    int cod_medico;
    char horario[5];
    Data data;
    int cod_CID;
    int cod_medicamento;
    int qtde_medicamento;
};

void lerDadosCidades(Cidade cidade[], int quantidade)
{
    for (int i = 0; i < quantidade; i++)
    {
        cout << "Insira o código da cidade: ";
        cin >> cidade[i].codigo;
        cout << "Insira o nome da cidade: ";
        cin >> cidade[i].nome;
        cout << "Insira a Unidade Federal da cidade (em siglas): ";
        cin >> cidade[i].UF;
    }
}

void lerDadosEspecialidades(Especialidade especialidade[], int quantidade)
{
    for (int i = 0; i < quantidade; i++)
    {
        cout << "Insira o código da especialidade médica: ";
        cin >> especialidade[i].codigo;
        cout << "Insira a descrição da especialidade: ";
        cin >> especialidade[i].descricao;
    }
}

void lerDadosCID()
{
    // Implemente a função para ler os dados dos CIDs
}

void lerDadosMedicamentos()
{
    // Implemente a função para ler os dados dos medicamentos
}

void incluirMedico(Medico medico[], int quantidade)
{
    for (int i = 0; i < quantidade; i++)
    {
        int codigo;
        cout << "Insira o código do médico: ";
        cin >> codigo;

        // Busca serial do codigo do médico
        int i = 0;
        for (; i < 10 && codigo > medico[i].codigo; i++)
            ;
        if (codigo == medico[i].codigo)
        {
            cout << "\n\n Médico já cadastrado";
            cout << "\nCodigo do médico: " << medico[i].codigo;
            cout << "\tNome: " << medico[i].nome;
            cout << "\tEndereco: " << medico[i].endereco;
            cout << "\tCódigo da cidade: " << medico[i].codigo_cidade;
            cout << "\nCódigo da especialidade: " << medico[i].codigo_especialidade;
            cout << endl;
            cout << "Por favor, preencha novamente com outro código";
            i--;
        }
        //Se e somente se não existir o código digitado, um novo médico sera adicionado
        else
        {
            medico[i].codigo = codigo;
            cout << "Insira o nome: ";
            cin >> medico[i].nome;
            cout << "Insira o código da especialidade do(a) Dr(a) " << medico[i].nome << ": ";
            cin >> medico[i].codigo_especialidade;
            cout << "Insira o endereço: ";
            cin >> medico[i].endereco;
            cout << "Insira o telefone (seguindo o padrão: 18997885522): ";
            cin >> medico[i].telefone;
            cout << "Insira o código da cidade onde reside: ";
            cin >> medico[i].codigo_cidade;
        }
    }
}

void incluirPaciente()
{
    // Implemente a função para incluir um novo paciente
}

void excluirPaciente()
{
    // Implemente a função para excluir um paciente
}

void agendarConsulta()
{
    // Implemente a função para agendar uma consulta
}

void consultarMedicamento()
{
    // Implemente a função para consultar os dados de um medicamento
}

void verificarEstoqueMinimo()
{
    // Implemente a função para verificar os medicamentos abaixo do estoque mínimo
}

void calcularValorTotalConsultas()
{
    // Implemente a função para calcular o valor total arrecadado com consultas
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int opcao, quantidade;
    Cidade *cidade;
    Especialidade *especialidade;
    Medico *medico;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Ler dados das cidades\n";
        cout << "2. Ler dados das especialidades médicas\n";
        cout << "3. Ler dados dos CIDs\n";
        cout << "4. Ler dados dos medicamentos\n";
        cout << "5. Incluir novo médico\n";
        cout << "6. Incluir novo paciente\n";
        cout << "7. Excluir paciente\n";
        cout << "8. Agendar consulta\n";
        cout << "9. Consultar dados de um medicamento\n";
        cout << "10. Verificar medicamentos abaixo do estoque mínimo\n";
        cout << "11. Calcular valor total arrecadado com consultas\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            system("cls");
            cout << "Quantas cidades deseja inserir? ";
            cin >> quantidade;
            lerDadosCidades(cidade, quantidade);
            break;
        case 2:
            system("cls");
            cout << "Quantas especialidades deseja inserir? ";
            cin >> quantidade;
            lerDadosEspecialidades(especialidade, quantidade);
            break;
        case 3:
            lerDadosCID();
            break;
        case 4:
            lerDadosMedicamentos();
            break;
        case 5:
            system("cls");
            cout << "Quantos médicos deseja inserir? ";
            cin >> quantidade;
            incluirMedico(medico, quantidade);
            break;
        case 6:
            incluirPaciente();
            break;
        case 7:
            excluirPaciente();
            break;
        case 8:
            agendarConsulta();
            break;
        case 9:
            consultarMedicamento();
            break;
        case 10:
            verificarEstoqueMinimo();
            break;
        case 11:
            calcularValorTotalConsultas();
            break;
        case 0:
            cout << "Saindo...\n";
            break;
        default:
            cout << "Opção inválida!\n";
            break;
        }
    } while (opcao != 0);

    return 0;
}
