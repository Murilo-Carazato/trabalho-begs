#include <iostream>
#include <vector>
#include <string.h>
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

void lerDadosCidades(Cidade cidade[], int &contCidade)
{
    int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++)
    {
        cout << "\n\nCodigo da cidade " << (i + 1) << ": ";
        cin >> cidade[i].codigo;

        if (cidade[i].codigo > 0)
        {
            cout << "Insira o nome da cidade: ";
            cin >> cidade[i].nome;
            cout << "Insira a Unidade Federal da cidade (Siglas): ";
            cin >> cidade[i].UF;
        }
        else
            saida = 0;
    }
    contCidade = i - 1;
}

void lerDadosEspecialidades(Especialidade especialidade[], int &contador)
{
    int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++)
    {
        cout << "\n\nCodigo da especialidade " << (i + 1) << ": ";
        cin >> especialidade[i].codigo;

        if (especialidade[i].codigo > 0)
        {
            cout << "Insira a descrição da especialidade: ";
            cin >> especialidade[i].descricao;
        }
        else
            saida = 0;
    }
    contador = i - 1;
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

void imprimirEstruturaPaciente(struct Paciente paciente[], int contador)
{
    cout << "\n\nLista dos Registros" << endl;
    for (int i = 0; i < contador; i++)
    {

        cout << "codigo: " << paciente[i].codigo << endl;
        cout << "CPF: " << paciente[i].CPF << endl;
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

void verificarSeCPFRepetiuNosArrays(struct Paciente S[], int contadorS, struct Paciente T[], int contadorT)
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

void verificarSeCodigoMedicoRepetiuNosArrays(struct Medico S[], int contadorS, struct Medico T[], int contadorT)
{

    int vetUnicos[20]; // Array para guardar os códigos únicos dos dois arrays
    int indexUnicos = 0;

    bool repetido;

    // Verificar códigos únicos em S
    for (int i = 0; i < contadorS; i++)
    {
        repetido = false;
        for (int j = 0; j < contadorT; j++)
        {
            if (S[i].codigo == T[j].codigo)
            {
                repetido = true;
                break;
            }
        }
        if (!repetido)
        {
            vetUnicos[indexUnicos++] = S[i].codigo;
        }
    }

    // Verificar códigos únicos em T
    for (int i = 0; i < contadorT; i++)
    {
        repetido = false;
        for (int j = 0; j < contadorS; j++)
        {
            if (T[i].codigo == S[j].codigo)
            {
                repetido = true;
                break;
            }
        }
        if (!repetido)
        {
            vetUnicos[indexUnicos++] = T[i].codigo;
        }
    }

    // Imprimir os resultados
    cout << "Códigos únicos nos arrays S e T:" << endl;
    for (int i = 0; i < indexUnicos; i++)
    {
        cout << vetUnicos[i] << endl;
    }
}

bool verificarSeCPFPacienteRepetiu(struct Paciente Paciente[], string cpf, int index)
{

    for (int i = 0; i < index; i++)
    {
        if (strcmp(Paciente[i].CPF, cpf) == 0)
        {
            cout << "\n\n Paciente Encontrado";
            return true;
        }
    }

    return false;
}

void lerDadosPacientes(struct Paciente paciente[], int &contador)
{

    int i = 0;
    char cpf[11];
    for (int saida = 1; i < 20 && saida != 0; i++)
    {
        cout << "\n\nCodigo do paciente " << (i + 1) << ": ";
        cin >> paciente[i].codigo;
        if (paciente[i].codigo > 0)
        {
            cout << "\n CPF: ";
            cin >> cpf;
            if (!verificarSeCPFPacienteRepetiu(paciente, cpf, i))
            {
                strcpy(paciente[i].CPF, cpf);
                cout << "CPF n repetiu: ";
                cout << "\nNome: ";
                cin >> paciente[i].nome;
                cout << "\nCodigo da cidade: ";
                cin >> paciente[i].codigo_cidade;
                cout << "\nEndereco: ";
                cin >> paciente[i].endereco;
            }
            else
            {
                i--;
            }
        }
        else
            saida = 0;
    }
    contador = i - 1;
}

bool verificarSeCodigoMedicoRepetiu(struct Medico Medico[], int cod, int index)
{

    for (int i = 0; i < index; i++)
    {
        if (cod == Medico[i].codigo)
        {
            cout << "\n\n Médico Encontrado";
            cout << "\nCodigo: " << Medico[i].codigo;
            cout << "\tNome: " << Medico[i].nome;
            cout << "\tCodigo da especialidade: " << Medico[i].codigo_especialidade;
            cout << "\tEndereco: " << Medico[i].endereco;
            cout << "\tTelefone: " << Medico[i].telefone;
            cout << "\tCodigo da cidade: " << Medico[i].codigo_cidade;
            return true;
        }
    }

    return false;
}

void lerDadosMedicos(struct Medico medico[], int &contador)
{

    int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++)
    {
        cout << "\n\nCodigo do médico " << (i + 1) << ": ";
        cin >> medico[i].codigo;

        if (medico[i].codigo > 0)
        {
            if (!verificarSeCodigoMedicoRepetiu(medico, medico[i].codigo, i))
            {
                cout << "codigo n repetiu: ";
                // cout << "Nome do médico: ";
                // cin >> medico[i].nome;
                // cout << "Codigo da especialidade: ";
                // cin >> medico[i].codigo_especialidade;
                // cout << "Endereco: ";
                // cin >> medico[i].endereco;
                // cout << "Telefone: ";
                // cin >> medico[i].telefone;
                // cout << "Codigo da cidade: ";
                // cin >> medico[i].codigo_cidade;
            }
            else
            {
                i--;
            }
        }
        else
            saida = 0;
    }
    contador = i - 1;

    // imprimirEstruturaPaciente(Paciente, contador);
}

void incluirMedico(Medico S[], int contadorS, Medico T[], int contadorT, Medico A[], int &contadorA)
{
    int i = 0, j = 0, k = 0;
    while (i < contadorS && j < contadorT)
    {
        if (S[i].codigo < T[j].codigo)
        {
            A[k].codigo = S[i].codigo;
            i++;
        }
        else
        {
            A[k].codigo = T[j].codigo;
            j++;
        }
        k++;
    }

    while (i < contadorS)
    {
        A[k].codigo = S[i].codigo;
        i++;
        k++;
    }

    while (j < contadorT)
    {
        A[k].codigo = T[j].codigo;
        j++;
        k++;
    }
    contadorA = k;
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

void excluirPaciente(struct Paciente S[], int contS, int T[], int contT, struct Paciente A[], int &contA)
{
    int i = 0, j = 0, k = 0; // i (contador de S) j (contador de T) k (contador de A)
    for (; j < contT; i++)
    {
        if (S[i].codigo != T[j])
        {
            A[k].codigo = S[i].codigo;
            strcpy(A[k].nome, S[i].nome);
            strcpy(A[k].endereco, S[i].endereco);
            strcpy(A[k].CPF, S[i].CPF);
            A[k].codigo_cidade = S[i].codigo;
            k++;
        }
        else
        {
            j++;
        }
    }
    while (i < contS)
    {
        A[k].codigo = S[i].codigo;
        strcpy(A[k].nome, S[i].nome);
        strcpy(A[k].endereco, S[i].endereco);
        strcpy(A[k].CPF, S[i].CPF);
        A[k].codigo_cidade = S[i].codigo;
        i++;
        k++;
    }
    contA = k;
    cout << "\n\nLista dos registros de paciente após exclusão: " << endl;
    for (int i = 0; i < contA; i++)
    {
        cout << "\nCodigo: " << A[i].codigo;
        cout << "\tNome: " << A[i].nome;
        cout << "\tEndereco: " << A[i].endereco;
        cout << "\tCodigo_Cidade: " << A[i].codigo_cidade;
        cout << "\tCPF: " << A[i].CPF;
    }
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
void buscarCidade(struct Cidade cidade[], int cod)
{
    int i = 0;
    for (; i < 10 && cod > cidade[i].codigo; i++)
        ;
    if (cod == cidade[i].codigo)
    {
        cout << "\n\n Cidade encontrada";
        cout << "\nNome da cidade: " << cidade[i].nome;
        cout << "\nUF: " << cidade[i].UF << endl;
    }
    else
        cout << "\n\n Cidade não encontrada";
}

void buscarPacientePeloCpf(struct Paciente paciente[], Cidade cidade[], int &contCidade, int &contPaciente)
{
    char cpf[11];
    int i = 0;
    cout << "Insira o CPF que deseja buscar: ";
    cin >> cpf;
    cout << "\ncontPaciente: " << contPaciente;
    cout << "\ncontCidade: " << contCidade;

    for (; i < contPaciente; i++)
        ;
    if (strcmp(paciente[i].CPF, cpf) == 0) // Compara se chars são iguais
    {
        cout << "\n\n Paciente encontrado\n";
        cout << "\tCodigo: " << paciente[i].codigo;
        cout << "\tNome: " << paciente[i].nome;
        for (int j = 0; j < contCidade; j++)
        {
            if (paciente[i].codigo_cidade == cidade[j].codigo)
            {
                cout << "\tCidade: " << cidade[j].nome;
                cout << "\tUF: " << cidade[j].UF;
                j = contCidade;
                i = contPaciente;
            }
        }
    }
    else
        cout << "\n\n Paciente com CPF: " << cpf << " não existe.\n";
}

void buscarEspecialidade(struct Especialidade especialidade[], int cod)
{
    int i = 0;
    for (; i < 10 && cod > especialidade[i].codigo; i++)
        ;
    if (cod == especialidade[i].codigo)
    {
        cout << "\n\n Especialidade encontrada";
        cout << "\nCodigo da especialidade: " << especialidade[i].codigo;
        cout << "\nDescrição: " << especialidade[i].descricao;
    }
    else
        cout << "\n\n Especialidade não encontrada";
}
int main()
{
    setlocale(LC_ALL, "Portuguese");

    struct Medicamento medicamentos[2];
    struct CID cids[2];
    struct Paciente pacientes[20], arqSPaciente[20], arqTPaciente[20], arqAPaciente[25];
    struct Medico medicos[20], arqSMedico[20], arqTMedico[20], arqAMedico[25];

    int opcao, quantidade;
    int contadorS, contadorT, contadorA;
    struct Cidade cidades[20];
    struct Especialidade especialidades[20];

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
        cout << "12. Buscar uma cidade\n";
        cout << "13. Buscar uma especialidade\n";
        cout << "14. Buscar um paciente pelo CPF\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            system("cls");
            int contadorCidades;
            lerDadosCidades(cidades, contadorCidades);
            break;
        case 2:
            system("cls");
            cout << "Quantas especialidades deseja inserir? ";
            cin >> quantidade;
            lerDadosEspecialidades(especialidades, quantidade);
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
            lerDadosMedicos(arqTMedico, contadorTMedico);

            // verificarSeCodigoMedicoRepetiuNosArrays(arqSMedico, contadorSMedico, arqTMedico, contadorTMedico);

            incluirMedico(arqSMedico, contadorSMedico, arqTMedico, contadorTMedico, arqAMedico, contadorAMedico);
            imprimirEstruturaMedico(arqAMedico, contadorAMedico);
            break;
        case 6:
            lerDadosPacientes(arqSPaciente, contadorS);
            lerDadosPacientes(arqTPaciente, contadorT);

            incluirPaciente(arqSPaciente, contadorS, arqTPaciente, contadorT, arqAPaciente, contadorA);
            imprimirEstruturaPaciente(arqAPaciente, contadorA);
            break;
        case 7:
            int arqT[20];
            for (contadorT = 0; contadorT < 20 && arqT[contadorT - 1] >= 0; contadorT++)
            {
                cout << "\nInforme o codigo do paciente a ser excluido (finalize com -1): ";
                cin >> arqT[contadorT];
            }
            contadorT--;
            excluirPaciente(arqSPaciente, contadorS, arqT, contadorT, arqAPaciente, contadorA);
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
            int codigoCidade;
            cout << "Insira o código da cidade que deseja buscar: ";
            cin >> codigoCidade;
            buscarCidade(cidades, codigoCidade);
            break;
        case 13:
            int codigo;
            cout << "Insira o código da especialidade que deseja buscar";
            cin >> codigo;
            buscarEspecialidade(especialidades, codigo);
            break;
        case 14:
            buscarPacientePeloCpf(pacientes, cidades, contadorCidades, contadorA);
            break;
        case 0:
            cout << "\nSaindo...\n";
            break;
        default:
            cout << "\nOpção inválida!\n";
            break;
        }
    } while (opcao != 0);

    return 0;
}
