#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Cidade
{
    int codigo;
    string nome;
    string UF;
};

struct Especialidade
{
    int codigo;
    string descricao;
};

struct Medico
{
    int codigo;
    string nome;
    int codigo_especialidade;
    string endereco;
    string telefone;
    int codigo_cidade;
};

struct Paciente
{
    string CPF;
    string nome;
    string endereco;
    int codigo_cidade;
};

struct CID
{
    int codigo;
    string descricao;
};

struct Medicamento
{
    int codigo;
    string descricao;
    int quant_estoque;
    int estoque_minimo;
    int estoque_maximo;
    float preco_unitario;
};

struct Consulta
{
    string cpf_paciente;
    int cod_medico;
    string data;
    string horario;
    int cod_CID;
    int cod_medicamento;
    int qtde_medicamento;
};

vector<Cidade> cidades;
vector<Especialidade> especialidades;
vector<Medico> medicos;
vector<Paciente> pacientes;
vector<CID> cids;
vector<Medicamento> medicamentos;
vector<Consulta> consultas;

void lerDadosCidades()
{
    // Implemente a função para ler os dados das cidades
}

void lerDadosEspecialidades()
{
    // Implemente a função para ler os dados das especialidades médicas
}

void lerDadosCID()
{
    // Implemente a função para ler os dados dos CIDs
}

void imprimirMedicamentos(struct Medicamento Medicamento[], int contador)
{
    for (int i = 0; i < contador; i++)
    {

        cout << "valores: " << Medicamento[i].codigo << endl;
    }
        cout << "qnt: " << contador << endl;
    
}

void lerDadosMedicamentos(struct Medicamento Medicamento[], int &contador)
{

    int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++)
    {
        cout << "\n\nCodigo do Medicamento " << (i + 1) << ": ";
        cin >> Medicamento[i].codigo;
        if (Medicamento[i].codigo > 0)
        {
            // cout << "Nome: ";
            // cin >> cli[i].nome;
            // cout << "Endereco: ";
            // cin >> cli[i].endereco;
            // cout << "Cidade: ";
            // cin >> cli[i].cidade;
            // cout << "Estado: ";
            // cin >> cli[i].uf;
        }
        else
            saida = 0;
    }
    contador = i - 1;

    imprimirMedicamentos(Medicamento, contador);
}



void incluirMedico()
{
    // Implemente a função para incluir um novo médico
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
    struct Medicamento medicamentos[2];

    int opcao;
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
            lerDadosCidades();
            break;
        case 2:
            lerDadosEspecialidades();
            break;
        case 3:
            lerDadosCID();
            break;
        case 4:
            int contadorMedicamentos;
            lerDadosMedicamentos(medicamentos, contadorMedicamentos);
            break;
        case 5:
            incluirMedico();
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
