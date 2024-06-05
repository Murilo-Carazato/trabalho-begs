// Murilo Carazato de Oliveira
// Murilo Henrique Felicio Vantini

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

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
    int codigo;
    char cpf_paciente[11];
    int cod_medico;
    char horario[5];
    Data data;
    int cod_CID;
    int cod_medicamento;
    int qtde_medicamento;
};

void lerDadosCidades(Cidade cidade[], int &contador)
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
    contador = i - 1;
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
            cout << "Insira a descricao da especialidade: ";
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
            cout << "\n\n Descricao do CID: ";
            cin >> CID[i].descricao;
        }
        else
            saida = 0;
    }
    contador = i - 1;
}

void imprimirEstruturaPaciente(struct Paciente Paciente[], int contador)
{
    cout << "\n\nLista dos Registros" << endl;
    for (int i = 0; i < contador; i++)
    {

        cout << "\n CPF do paciente(" << i + 1 << "): " << Paciente[i].CPF << endl;
    }
}

void imprimirEstruturaMedico(struct Medico Medico[], int contador)
{
    cout << "\n\nLista dos Registros" << endl;
    for (int i = 0; i < contador; i++)
    {

        cout << "\n Codigo do medico(" << i + 1 << "): " << Medico[i].codigo << endl;
    }
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
            cout << "\n\n Descricao do Medicamento: ";
            cin >> Medicamento[i].descricao;
            cout << "\n\n Quantidade em estoque: ";
            cin >> Medicamento[i].quant_estoque;
            cout << "\n\n Estoque minimo: ";
            cin >> Medicamento[i].estoque_minimo;
            cout << "\n\n Estoque maximo: ";
            cin >> Medicamento[i].estoque_maximo;
            cout << "\n\n Preco unitario: ";
            cin >> Medicamento[i].preco_unitario;
        }
        else
            saida = 0;
    }
    contador = i - 1;
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

bool codigoJaAdicionadoMedico(int codigo, Medico A[], int contadorA)
{
    for (int i = 0; i < contadorA; i++)
    {
        if (A[i].codigo == codigo)
        {
            cout << "\n Nao foi possivel inserir medico, pois codigo repetiu." << endl;
            return true;
        }
    }
    return false;
}

bool CPFJaAdicionadoPaciente(char *CPF, Paciente A[], int contadorA)
{
    for (int i = 0; i < contadorA; i++)
    {
        if (strcmp(A[i].CPF, CPF) == 0)
        {
            cout << "\n Nao foi possivel inserir paciente, pois CPF repetiu." << endl;
            return true;
        }
    }
    return false;
}

bool verificarSeCPFPacienteRepetiu(struct Paciente Paciente[], string cpf, int index)
{

    for (int i = 0; i < index; i++)
    {
        if (cpf == Paciente[i].CPF)
        {
            cout << "\n\n Paciente encontrado, insercao cancelada";
            return true;
        }
    }

    return false;
}

void lerDadosPacientes(struct Paciente Paciente[], int &contador)
{

    int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++)
    {
        cout << "\n\n Codigo do Paciente " << (i + 1) << ": ";
        cin >> Paciente[i].codigo;
        if (Paciente[i].codigo > 0)
        {
            cout << "\nCPF do Paciente " << (i + 1) << ": ";
            cin >> Paciente[i].CPF;

            if (!verificarSeCPFPacienteRepetiu(Paciente, Paciente[i].CPF, i))
            {
                cout << "\nNome: ";
                cin >> Paciente[i].nome;
                cout << "\nCodigo da cidade: ";
                cin >> Paciente[i].codigo_cidade;
                cout << "\nEndereco: ";
                cin >> Paciente[i].endereco;
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
            cout << "\n\n Medico Encontrado";
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
        cout << "\n\nCodigo do medico " << (i + 1) << ": ";
        cin >> medico[i].codigo;

        if (medico[i].codigo > 0)
        {
            if (!verificarSeCodigoMedicoRepetiu(medico, medico[i].codigo, i))
            {
                cout << "Nome: " << endl;
                cin >> medico[i].nome;
                cout << "Codigo especialidade: " << endl;
                cin >> medico[i].codigo_especialidade;
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

void incluirMedico(Medico S[], int contadorS, Medico T[], int contadorT, Medico A[], int &contadorA)
{
    Medico aux[40];
    int i = 0, j = 0, k = 0;

    while (i < contadorS && j < contadorT)
    {
        if (S[i].codigo < T[j].codigo)
        {
            if (!codigoJaAdicionadoMedico(S[i].codigo, aux, k))
            {
                aux[k++] = S[i];
            }
            i++;
        }
        else
        {
            if (!codigoJaAdicionadoMedico(T[j].codigo, aux, k))
            {
                aux[k++] = T[j];
            }
            j++;
        }
    }

    while (i < contadorS)
    {
        if (!codigoJaAdicionadoMedico(S[i].codigo, aux, k))
        {
            aux[k++] = S[i];
        }
        i++;
    }

    while (j < contadorT)
    {
        if (!codigoJaAdicionadoMedico(T[j].codigo, aux, k))
        {
            aux[k++] = T[j];
        }
        j++;
    }

    for (int i = 0; i < k; i++)
    {
        A[i] = aux[i];
    }
    contadorA = k;
}

void incluirPaciente(struct Paciente S[], int contadorS, struct Paciente T[], int contadorT, struct Paciente A[], int &contadorA)
{
    Paciente aux[40];
    int i = 0, j = 0, k = 0;

    while (i < contadorS && j < contadorT)
    {
        if (S[i].codigo < T[j].codigo)
        {
            if (!CPFJaAdicionadoPaciente(S[i].CPF, aux, k))
            {
                aux[k++] = S[i];
            }
            i++;
        }
        else
        {
            if (!CPFJaAdicionadoPaciente(T[j].CPF, aux, k))
            {
                aux[k++] = T[j];
            }
            j++;
        }
    }

    while (i < contadorS)
    {
        if (!CPFJaAdicionadoPaciente(S[i].CPF, aux, k))
        {
            aux[k++] = S[i];
        }
        i++;
    }

    while (j < contadorT)
    {
        if (!CPFJaAdicionadoPaciente(T[j].CPF, aux, k))
        {
            aux[k++] = T[j];
        }
        j++;
    }

    for (int i = 0; i < k; i++)
    {
        A[i] = aux[i];
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

    cout << "\n\nLista dos registros de paciente apos exclusao: " << endl;
    for (int i = 0; i < contA; i++)
    {
        cout << "\nCodigo: " << A[i].codigo;
        // cout << "\tNome: " << A[i].nome;
        // cout << "\tEndereco: " << A[i].endereco;
        // cout << "\tCodigo_Cidade: " << A[i].codigo_cidade;
        cout << "\tCPF: " << A[i].CPF;
    }
}

void agendarConsulta(Consulta consulta[], int &contadorConsulta, Paciente pacientes[], int &contadorPaciente, Medico medicos[], int &contadorMedico, CID cids[], int &contadorCid, Medicamento medicamentos[], int &contadorMedicamento)
{
    int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++)
    {
        cout << "\n\nCodigo da consulta " << (i + 1) << ": ";
        cin >> consulta[i].codigo;
        if (consulta[i].codigo > 0)
        {

            // Procura paciente
            cout << "CPF do paciente: ";
            cin >> consulta[i].cpf_paciente;
            bool pacienteEncontrado = false;
            for (int j = 0; j < contadorPaciente; j++)
            {
                if (strcmp(consulta[i].cpf_paciente, pacientes[j].CPF) == 0)
                {
                    cout << "CPF do paciente encontrado: " << pacientes[j].CPF << " Codigo do paciente: " << pacientes[j].codigo << endl;
                    pacienteEncontrado = true;
                    break;
                }
            }
            if (!pacienteEncontrado)
            {
                cout << "\n Paciente nao encontrado." << endl;
                break;
            }

            // Procura medico
            cout << "codigo do medico: ";
            cin >> consulta[i].cod_medico;
            bool medicoEncontrado = false;
            for (int j = 0; j < contadorMedico; j++)
            {
                if (consulta[i].cod_medico == medicos[j].codigo)
                {
                    cout << "Nome do medico encontrado: " << medicos[j].nome << endl;
                    medicoEncontrado = true;
                    break;
                }
            }
            if (!medicoEncontrado)
            {
                cout << "\n Medico nao encontrado." << endl;
                break;
            }

            cout << "Insira o dia ";
            cin >> consulta[i].data.dia;
            cout << "Insira o mes ";
            cin >> consulta[i].data.mes;
            cout << "Insira o ano ";
            cin >> consulta[i].data.ano;

            // Procura CID
            cout << "codigo do CID: ";
            cin >> consulta[i].cod_CID;
            bool cidEncontrado = false;
            for (int j = 0; j < contadorCid; j++)
            {
                if (consulta[i].cod_CID == cids[j].codigo)
                {
                    cout << "Descricao do CID encontrado: " << cids[j].descricao << endl;
                    cidEncontrado = true;
                    break;
                }
            }
            if (!cidEncontrado)
            {
                cout << "\n Cid nao encontrado." << endl;
                break;
            }

            // Procura Medicamento
            cout << "codigo do medicamento: ";
            cin >> consulta[i].cod_medicamento;

            bool medicamentoEncontrado = false;
            for (int j = 0; j < contadorMedicamento; j++)
            {
                if (consulta[i].cod_medicamento == medicamentos[j].codigo)
                {
                    medicamentoEncontrado = true;

                    cout << "Medicamento encontrado: " << medicamentos[j].descricao << endl;
                    cout << "Quantidade do medicamento que foi usado: ";
                    cin >> consulta[i].qtde_medicamento;

                    if (consulta[i].qtde_medicamento > medicamentos[j].quant_estoque)
                    {
                        cout << "Quantidade de medicamento no estoque e insuficiente. (estoque: " << medicamentos[j].quant_estoque << ")" << endl;
                        i--;
                    }
                    else
                    {
                        medicamentos[j].quant_estoque = medicamentos[j].quant_estoque - consulta[i].qtde_medicamento;
                        cout << "Quantidade de medicamento disponivel em estoque apos a utilizacao de medicamentos: " << medicamentos[j].quant_estoque << endl;
                        break;
                    }

                    break;
                }
            }
            if (!medicamentoEncontrado)
            {
                cout << "\n Medicamento nao encontrado." << endl;
                break;
            }
        }
        else
            saida = 0;
    }
    contadorConsulta = i - 1;
}

void consultarMedicamento(Medicamento Medicamento[], int &contador)
{
    int cod;
    cout << "Insira o codigo do medicamento que deseja buscar: ";
    cin >> cod;

    for (int i = 0; i < contador; i++)
    {
        if (cod == Medicamento[i].codigo)
        {
            cout << "\n\n Medicamento encontrado\n";
            cout << "\t Codigo: " << Medicamento[i].codigo;
            cout << "\t Descricao: " << Medicamento[i].descricao;
            cout << "\t Quantidade em estoque: " << Medicamento[i].quant_estoque;
            cout << "\t Estoque minimo: " << Medicamento[i].estoque_minimo;
            cout << "\t Estoque maximo: " << Medicamento[i].estoque_maximo;
            cout << "\t Preco unitario: " << Medicamento[i].preco_unitario;
            cout << "\t Valor total em estoque: " << Medicamento[i].preco_unitario * Medicamento[i].quant_estoque << endl;
        }
        else
        {
            if (i == contador - 1)
            {
                cout << "\n\n Medicamento nao encontrado! " << endl;
            }
        }
    }
}

void verificarEstoqueMinimo(Medicamento Medicamento[], int &contador)
{
    float totalDaCompra = 0;
    for (int i = 0; i < contador; i++)
    {
        if (Medicamento[i].quant_estoque < Medicamento[i].estoque_minimo)
        {
            int quantidadeASerComprada = Medicamento[i].estoque_maximo - Medicamento[i].quant_estoque;

            totalDaCompra += quantidadeASerComprada * Medicamento[i].preco_unitario;

            cout << "\n\n Medicamento com estoque abaixo do minimo\n";
            cout << "\t Codigo: " << Medicamento[i].codigo;
            cout << "\t Descricao: " << Medicamento[i].descricao;
            cout << "\t Quantidade em estoque: " << Medicamento[i].quant_estoque;
            // cout << "\t Estoque minimo: " << Medicamento[i].estoque_minimo;
            cout << "\t Estoque maximo: " << Medicamento[i].estoque_maximo;
            // cout << "\t Preco unitario: " << Medicamento[i].preco_unitario;
            cout << "\t Quantidade a ser comprada: " << quantidadeASerComprada;
            cout << "\t Valor da compra do medicamento " << Medicamento[i].descricao << ": " << quantidadeASerComprada * Medicamento[i].preco_unitario;
        }
        else
        {
            if (i == contador - 1)
            {
                cout << "\n\n Nenhum medicamento com estoque abaixo do minimo\n";
            }
        }
    }
    cout << "\t Valor total da compra: " << totalDaCompra;
}

void calcularValorTotalConsultas(Consulta Consulta[], int &contadorConsulta, Medicamento Medicamento[], int &contadorMedicamento)
{
    const float valorBrutoConsulta = 100;
    float valorLiquidoConsulta = 0;
    float totalDaCompra = 0;

    for (int i = 0; i < contadorConsulta; i++)
    {
        for (int j = 0; j < contadorMedicamento; j++)
        {
            if (Consulta[i].cod_medicamento == Medicamento[j].codigo)
            {

                totalDaCompra += Consulta[i].qtde_medicamento * Medicamento[j].preco_unitario;
                cout << "\t Custo dos medicamentos: " << totalDaCompra;
            }
        }
        valorLiquidoConsulta += valorBrutoConsulta + totalDaCompra;
        cout << "\n\n Valor total da consulta: " << valorLiquidoConsulta;
    }
}

void buscarMedicoPeloCodigo(struct Medico Medico[], Especialidade Especialidade[], int &contEspecialidade, int &contMedico)
{
    int cod;

    cout << "Insira o cod que deseja buscar: ";
    cin >> cod;

    bool MedicoEncontrado = false;
    for (int i = 0; i < contMedico; i++)
    {
        if (cod == Medico[i].codigo)
        {
            cout << "\n\n Medico encontrado\n";
            cout << "\tCodigo: " << Medico[i].codigo;
            cout << "\tNome: " << Medico[i].nome << endl;
            for (int j = 0; j < contEspecialidade; j++)
            {

                if (Medico[i].codigo_especialidade == Especialidade[j].codigo)
                {
                    cout << "\tEspecialidade: " << Especialidade[j].descricao;
                    j = contEspecialidade;
                    i = contMedico;
                }
                else
                {
                    if (j == contEspecialidade - 1)
                    {
                        cout << "\n\n Especialidade nao encontrada! " << endl;
                    }
                }
            }
            MedicoEncontrado = true;
            break;
        }
    }
    if (!MedicoEncontrado)
    {
        cout << "\n\n Medico com cod: " << cod << " nao existe.\n";
    }
}

void buscarPacientePeloCpf(struct Paciente paciente[], Cidade cidade[], int &contCidade, int &contPaciente)
{
    char cpf[11];

    cout << "Insira o CPF que deseja buscar: ";
    cin >> cpf;

    bool pacienteEncontrado = false;
    for (int i = 0; i < contPaciente; i++)
    {
        if (strcmp(cpf, paciente[i].CPF) == 0)
        {
            cout << "\n\n Paciente encontrado\n";
            cout << "\tCodigo: " << paciente[i].codigo;
            cout << "\tNome: " << paciente[i].nome;
            for (int j = 0; j < contCidade; j++)
            {
                if (paciente[i].codigo_cidade == cidade[j].codigo)
                {
                    cout << "\tCidade: " << cidade[j].nome;
                    cout << "\tUF: " << cidade[j].UF << endl;
                    j = contCidade;
                    i = contPaciente;
                }
                else
                {
                    if (j == contCidade - 1)
                    {
                        cout << "\n\n Cidade nao encontrada! " << endl;
                    }
                }
            }
            pacienteEncontrado = true;
            break;
        }
    }
    if (!pacienteEncontrado)
    {
        cout << "\n\n Paciente com CPF: " << cpf << " nao existe.\n";
    }
}

void buscarCIDPeloCodigo(struct CID Cid[], int &contCid)
{
    int cod;
    cout << "Insira o cod do CID que deseja buscar: ";
    cin >> cod;

    bool CidEncontrado = false;
    for (int i = 0; i < contCid; i++)
    {
        if (cod == Cid[i].codigo) // Compara se chars sao iguais
        {
            cout << "\n\n CID encontrado: ";
            cout << "\tCodigo: " << Cid[i].codigo;
            cout << "\tDescricao: " << Cid[i].descricao;

            CidEncontrado = true;
            break;
        }
    }
    if (!CidEncontrado)
    {
        cout << "\n\n Cid com cod: " << cod << " nao existe.\n";
    }
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
        cout << "\n\n Cidade nao encontrada";
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
        cout << "\nDescricao: " << especialidade[i].descricao << endl;
    }
    else
        cout << "\n\n Especialidade nao encontrada";
}

void buscarMedicamentoPeloCodigo(struct Medicamento Medicamento[], int &contMedicamento)
{
    int cod;
    cout << "Insira o cod do Medicamento que deseja buscar: ";
    cin >> cod;

    bool MedicamentoEncontrado = false;
    for (int i = 0; i < contMedicamento; i++)
    {
        if (cod == Medicamento[i].codigo)
        {
            cout << "\n\n Medicamento encontrado\n";
            cout << "\tCodigo: " << Medicamento[i].codigo;
            cout << "\tDescricao: " << Medicamento[i].descricao;

            MedicamentoEncontrado = true;
            break;
        }
    }
    if (!MedicamentoEncontrado)
    {
        cout << "\n\n Medicamento com cod: " << cod << " nao existe.\n";
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    struct Medicamento medicamentos[20];
    struct CID cids[20];
    struct Paciente pacientes[20], arqSPaciente[20], arqTPaciente[20], arqAPaciente[25];
    struct Medico medicos[20], arqSMedico[20], arqTMedico[20], arqAMedico[25];

    int opcao, quantidade;
    struct Cidade cidades[20];
    struct Especialidade especialidades[20];
    struct Consulta consultas[20];

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Ler dados das cidades\n";
        cout << "2. Ler dados das especialidades medicas\n";
        cout << "3. Ler dados dos CIDs\n";
        cout << "4. Ler dados dos medicamentos\n";
        cout << "5. Incluir novo medico\n";
        cout << "6. Incluir novo paciente\n";
        cout << "7. Excluir paciente\n";
        cout << "8. Agendar consulta\n";
        cout << "9. Consultar dados de um medicamento\n";
        cout << "10. Verificar medicamentos abaixo do estoque minimo\n";
        cout << "11. Calcular valor total arrecadado com consultas\n";
        cout << "12. Buscar uma cidade\n";
        cout << "13. Buscar uma especialidade\n";
        cout << "14. Buscar um paciente pelo CPF\n";
        cout << "15. Buscar um medico pelo codigo\n";
        cout << "16. Buscar CID pelo codigo\n";
        cout << "17. Buscar medicamento pelo codigo\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            int contadorCidades;
            lerDadosCidades(cidades, contadorCidades);
            break;
        case 2:
            int contadorEspecialidades;
            lerDadosEspecialidades(especialidades, contadorEspecialidades);
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

            incluirMedico(arqSMedico, contadorSMedico, arqTMedico, contadorTMedico, arqAMedico, contadorAMedico);

            imprimirEstruturaMedico(arqAMedico, contadorAMedico);
            break;
        case 6:
            int contadorS, contadorT, contadorAPaciente;
            lerDadosPacientes(arqSPaciente, contadorS);
            lerDadosPacientes(arqTPaciente, contadorT);

            incluirPaciente(arqSPaciente, contadorS, arqTPaciente, contadorT, arqAPaciente, contadorAPaciente);
            imprimirEstruturaPaciente(arqAPaciente, contadorAPaciente);
            break;
        case 7:
            int arqT[20], contadorTExclusao;
            for (contadorTExclusao = 0; contadorTExclusao < 20 && arqT[contadorTExclusao - 1] >= 0; contadorTExclusao++)
            {
                cout << "\nInforme o codigo do paciente a ser excluido (finalize com -1): ";
                cin >> arqT[contadorTExclusao];
            }
            contadorTExclusao--;
            excluirPaciente(arqAPaciente, contadorAPaciente, arqT, contadorTExclusao, arqAPaciente, contadorAPaciente);
            break;
        case 8:
            int contadorConsulta;
            agendarConsulta(consultas, contadorConsulta, arqAPaciente, contadorAPaciente, arqAMedico, contadorAMedico, cids, contadorCID, medicamentos, contadorMedicamentos);
            break;
        case 9:
            consultarMedicamento(medicamentos, contadorMedicamentos);
            break;
        case 10:
            verificarEstoqueMinimo(medicamentos, contadorMedicamentos);
            break;
        case 11:
            calcularValorTotalConsultas(consultas, contadorConsulta, medicamentos, contadorMedicamentos);
            break;
        case 12:
            int codigoCidade;
            cout << "Insira o codigo da cidade que deseja buscar: ";
            cin >> codigoCidade;
            buscarCidade(cidades, codigoCidade);
            break;
        case 13:
            int codigoEspecialidades;
            cout << "Insira o codigo da especialidade que deseja buscar: ";
            cin >> codigoEspecialidades;
            buscarEspecialidade(especialidades, codigoEspecialidades);
            break;
        case 14:
            buscarPacientePeloCpf(arqAPaciente, cidades, contadorCidades, contadorAPaciente);
            break;
        case 15:
            buscarMedicoPeloCodigo(arqAMedico, especialidades, contadorEspecialidades, contadorAMedico);
            break;
        case 16:
            buscarCIDPeloCodigo(cids, contadorCID);
            break;
        case 17:
            buscarMedicamentoPeloCodigo(medicamentos, contadorMedicamentos);
            break;
        case 0:
            cout << "Saindo...\n";
            break;
        default:
            cout << "Opcao invalida!\n";
            break;
        }
    } while (opcao != 0);

    return 0;
}