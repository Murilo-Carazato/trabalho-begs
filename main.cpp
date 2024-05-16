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
    char telefone[13];
    int codigo_cidade;
};

struct Paciente
{
    int codigo;

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
        cout << "Insira a Unidade Federal da cidade (Siglas): ";
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

void lerDadosCID(struct CID CID[], int &contador)
{

    int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++)
    {
        cout << "\n\nCodigo do CID " << (i + 1) << ": ";
        cin >> CID[i].codigo;
        if (CID[i].codigo > 0)
        {
        }
        else
            saida = 0;
    }
    contador = i - 1;

    // imprimirEstruturaPaciente(CID, contador);
}

// void imprimirEstruturaPaciente(struct Estrutura Estrutura[], int contador)
// {
//     cout << "\n\nLista dos Registros" << endl;
//     for (int i = 0; i < contador; i++)
//     {

//         cout << "valores: " << Estrutura[i].codigo << endl;
//     }
//         cout << "qnt: " << contador << endl;
// }

void imprimirEstruturaPaciente(struct Paciente Paciente[], int contador)
{
    cout << "\n\nLista dos Registros" << endl;
    for (int i = 0; i < contador; i++)
    {

        cout << "valores: " << Paciente[i].codigo << endl;
    }
    cout << "qnt: " << contador << endl;
}

void imprimirEstruturaMedico(struct Medico Medico[], int contador)
{
    cout << "\n\nLista dos Registros" << endl;
    for (int i = 0; i < contador; i++)
    {

        cout << "valores: " << Medico[i].codigo << endl;
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
        }
        else
            saida = 0;
    }
    contador = i - 1;

    // imprimirMedicamento(Medicamento, contador);
}

void lerDadosPacientes(struct Paciente Paciente[], int &contador)
{

    int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++)
    {
        cout << "\n\nCodigo do Paciente " << (i + 1) << ": ";
        cin >> Paciente[i].codigo;
        if (Paciente[i].codigo > 0)
        {
        }
        else
            saida = 0;
    }
    contador = i - 1;

    // imprimirEstruturaPaciente(Paciente, contador);
}

void lerDadosMedicos(struct Medico Medico[], int &contador)
{

    int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++)
    {
        cout << "\n\nCodigo do Medico " << (i + 1) << ": ";
        cin >> Medico[i].codigo;
        if (Medico[i].codigo > 0)
        {
        }
        else
            saida = 0;
    }
    contador = i - 1;

    // imprimirEstruturaPaciente(Paciente, contador);
}

// ERRADO, FAZER COM BUSCA BINARIA OU SERIAL
void verificarSeCPFRepetiu(struct Paciente S[], int contadorS, struct Paciente T[], int contadorT)
{
    for (int i = 0; i < contadorS; i++)
    {
        for (int j = 0; j < contadorT; j++)
        {
            if (S[i].CPF == T[j].CPF)
            {
                cout << "CPF repetido: " << S[i].CPF << endl;
            }
        }
    }
}

void verificarSeCodigoRepetiu(struct Medico S[], int contadorS, struct Medico T[], int contadorT)
{
    bool codigoRepetido = false;

    for (int i = 0; i < contadorS; i++)
    {
        for (int j = 0; j < contadorT; j++)
        {
            if (S[i].codigo == T[j].codigo)
            {
                cout << "Código repetido no arquivo: " << S[i].codigo << endl;
                codigoRepetido = true;
            }
        }
    }

    if (!codigoRepetido)
    {
        cout << "Nenhum código repetido encontrado." << endl;
    }
}

void incluirMedico(struct Medico S[], int contadorS, struct Medico T[], int contadorT, struct Medico A[], int &contadorA)
{
    int i = 0, j = 0, k = 0; // i (contador de S) j (contador de T) k (contador de A)
    for (; i < contadorS && j < contadorT; k++)
    {
        if (S[i].codigo < T[j].codigo)
        {
            A[k].codigo = S[i].codigo;
            // strcpy (A[k].nome,S[i].nome);
            // strcpy (A[k].endereco,S[i].endereco);
            // strcpy (A[k].cidade,S[i].cidade);
            // strcpy (A[k].uf,S[i].uf);
            i++;
        }
        else
        {
            A[k].codigo = T[j].codigo;
            // strcpy (A[k].nome,T[j].nome);
            // strcpy (A[k].endereco,T[j].endereco);
            // strcpy (A[k].cidade,T[j].cidade);
            // strcpy (A[k].uf,T[j].uf);
            j++;
        }
        while (i < contadorS)
        {
            A[k].codigo = S[i].codigo;
            // strcpy (A[k].nome,S[i].nome);
            // strcpy (A[k].endereco,S[i].endereco);
            // strcpy (A[k].cidade,S[i].cidade);
            // strcpy (A[k].uf,S[i].uf);
            i++;
            k++;
        }
        while (j < contadorT)
        {
            A[k].codigo = T[j].codigo;
            // strcpy (A[k].nome,T[j].nome);
            // strcpy (A[k].endereco,T[j].endereco);
            // strcpy (A[k].cidade,T[j].cidade);
            // strcpy (A[k].uf,T[j].uf);
            j++;
            k++;
        }
        contadorA = k;
    }
}

void incluirPaciente(struct Paciente S[], int contadorS, struct Paciente T[], int contadorT, struct Paciente A[], int &contadorA)
{
    int i = 0, j = 0, k = 0; // i (contador de S) j (contador de T) k (contador de A)
    for (; i < contadorS && j < contadorT; k++)
    {
        if (S[i].codigo < T[j].codigo)
        {
            A[k].codigo = S[i].codigo;
            // strcpy (A[k].nome,S[i].nome);
            // strcpy (A[k].endereco,S[i].endereco);
            // strcpy (A[k].cidade,S[i].cidade);
            // strcpy (A[k].uf,S[i].uf);
            i++;
        }
        else
        {
            A[k].codigo = T[j].codigo;
            // strcpy (A[k].nome,T[j].nome);
            // strcpy (A[k].endereco,T[j].endereco);
            // strcpy (A[k].cidade,T[j].cidade);
            // strcpy (A[k].uf,T[j].uf);
            j++;
        }
    }
    while (i < contadorS)
    {
        A[k].codigo = S[i].codigo;
        // strcpy (A[k].nome,S[i].nome);
        // strcpy (A[k].endereco,S[i].endereco);
        // strcpy (A[k].cidade,S[i].cidade);
        // strcpy (A[k].uf,S[i].uf);
        i++;
        k++;
    }
    while (j < contadorT)
    {
        A[k].codigo = T[j].codigo;
        // strcpy (A[k].nome,T[j].nome);
        // strcpy (A[k].endereco,T[j].endereco);
        // strcpy (A[k].cidade,T[j].cidade);
        // strcpy (A[k].uf,T[j].uf);
        j++;
        k++;
    }
    contadorA = k;
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

    struct Medicamento medicamentos[2];
    struct CID cids[2];
    struct Paciente pacientes[20], arqSPaciente[20], arqTPaciente[20], arqAPaciente[25];
    struct Medico medicos[20], arqSMedico[20], arqTMedico[20], arqAMedico[25];

    int opcao, quantidade;
    Cidade *cidade;
    Especialidade *especialidade;

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
        cout << "12. Ler dados dos pacientes\n";
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
            int contadorCID;
            lerDadosCID(cids, contadorCID);
            break;
        case 4:
            int contadorMedicamentos;
            lerDadosMedicamentos(medicamentos, contadorMedicamentos);
            break;
        case 5:
            int contadorSMedico, contadorTMedico, contadorAMedico;
            lerDadosMedicos(arqSMedico, contadorSMedico);
            // imprimirEstruturaMedico(arqSMedico, contadorSMedico);
            lerDadosMedicos(arqTMedico, contadorTMedico);
            // imprimirEstruturaMedico(arqTMedico, contadorTMedico);

            verificarSeCodigoRepetiu(arqSMedico, contadorSMedico, arqTMedico, contadorTMedico);

            incluirMedico(arqSMedico, contadorSMedico, arqTMedico, contadorTMedico, arqAMedico, contadorAMedico);
            imprimirEstruturaMedico(arqAMedico, contadorAMedico);
            break;
        case 6:
            int contadorS, contadorT, contadorA;
            lerDadosPacientes(arqSPaciente, contadorS);
            // imprimirEstruturaPaciente(arqS, contadorS);
            lerDadosPacientes(arqTPaciente, contadorT);
            // imprimirEstruturaPaciente(arqT, contadorT);

            verificarSeCPFRepetiu(arqSPaciente, contadorS, arqTPaciente, contadorT);

            incluirPaciente(arqSPaciente, contadorS, arqTPaciente, contadorT, arqAPaciente, contadorA);
            imprimirEstruturaPaciente(arqAPaciente, contadorA);
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
        case 12:
            int contadorPacientes;
            lerDadosPacientes(pacientes, contadorPacientes);
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
