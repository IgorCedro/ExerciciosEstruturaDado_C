#define ex1
#include<stdio.h>
#include<locale.h>

#ifdef ex1
//Estrutura de dados, declarado como variável global.
struct cadastro{
        char nome[30];
        char end[90];
        char cidade[40];
        char estado[3];
        char cep[9];
};
struct cadastro usuario[10];
int cont=0;

void entrada()
{
    //Entrada dos dados do usuário

    printf("Digite seu NOME: \n");
    scanf("%s",&usuario[cont].nome);

    printf("Digite seu ENDEREÇO: \n");
    scanf("%s",&usuario[cont].end);

    printf("Digite sua CIDADE: \n");
    scanf("%s",&usuario[cont].cidade);

    printf("Digite seu ESTADO (sigla): \n");
    scanf("%s",&usuario[cont].estado);

    printf("Digite seu CEP: \n");
    scanf("%s",&usuario[cont].cep);

    cont++;
}
void lista()
{
    for(int i = 0; i < cont; i++)
    {
        printf("_______________________________________\n");
        printf("Usuário %d \n", i+1);
        printf("\n");//Pula a linha
        printf("O NOME do %d- usuário é: %s \n", i+1, usuario[i].nome);
        printf("O ENDEREÇO do %d- usuário é: %s \n", i+1, usuario[i].end);
        printf("A CIDADE do %d- usuário é: %s \n", i+1, usuario[i].cidade);
        printf("O ESTADO do %d- usuário é: %s \n", i+1, usuario[i].estado);
        printf("O CEP do %d- usuário é: %s \n", i+1, usuario[i].cep);
        printf("_______________________________________\n");
        printf("\n");//Pula a linha
    }
}
void sair()
{
    exit(0);
}
main()
{
/*
1.  Escreva um programa com a estrutura de dados abaixo. Defina um vetor de
    estruturas de 4 elementos. Receba os dados pelo teclado em uma funcao
    e imprima-os no video em uma funcao. Utilize vetor de estruturas.
    Faça um menu com uma opcao para saida do programa.
		estrutura: nome, end, cidade, estado, cep
*/

    setlocale(LC_ALL, "Portuguese");

    //Declaração de variáveis
    int continuar, op;

    //Loop para repetir o programa
    do
    {
        do
        {
            printf("_______________________________________\n");
            printf("                 MENU                  \n");
            printf("\n");//Pula a linha
            printf("1 – Receber todos os dados. \n");
            printf("2 – Imprimir todos os dados na tela. \n");
            printf("3 - Sair. \n");
            printf("_______________________________________\n");
            scanf("%d",&op);

            printf("\n");//Pula a linha

            if(op < 1 || op > 3)
            {
                system("cls");//Limpa a tela
                printf("Opção Inválida, digite novamente. \n");
                printf("\n");//Pula a linha
            }
        }
        while(op < 1 || op > 3);

        switch(op)
        {
            case 1:
                system("cls");//Limpa a tela
                entrada();
                system("cls");//Limpa a tela
                break;
            case 2:
                system("cls");//Limpa a tela
                lista();
                break;
            case 3:
                system("cls");//Limpa a tela
                sair();
                break;
        }

        printf("\n");//Pula a linha
    }
    while(op != 3);//Programa reinicia se a variaver 'continuar' ter valor 1
}
#endif

#ifdef ex2
//Estrutura de dados, declarado como variável global.
struct ficha{
        char nome[30];
        float peso;
        float altura;
        float imc;
};
struct ficha pacientes[10];
int cont=0;

entrada()
{
    //Entrada dos dados do paciente

    printf("Digite o NOME do paciente: \n");
    scanf("%s",&pacientes[cont].nome);

    do
    {
        printf("Digite o PESO do paciente: \n");
        scanf("%f",&pacientes[cont].peso);
    }
    while(pacientes[cont].peso < 0);

    do
    {
        printf("Digite a ALTURA do paciente: \n");
        scanf("%f",&pacientes[cont].altura);
    }
    while(pacientes[cont].altura < 0);

    cont++;
}
lista()
{
    for(int i = 0; i < cont; i++)
    {
        printf("_______________________________________\n");
        printf("PACIENTE %d \n", i+1);
        printf("\n");//Pula a linha
        printf("O NOME do %d- paciente é: %s \n", i+1, pacientes[i].nome);
        printf("O PESO do %d- paciente é: %.2f \n", i+1, pacientes[i].peso);
        printf("A ALTURA do %d- paciente é: %.2f \n", i+1, pacientes[i].altura);
        printf("_______________________________________\n");
        printf("\n");//Pula a linha
    }
}
calculo()
{
    for(int i = 0; i < cont; i++)
    {
        //Cálculo do IMC
        pacientes[i].imc = pacientes[i].peso / (pacientes[i].altura * pacientes[i].altura);

        //Exibição do IMC
        printf("_______________________________________\n");
        printf("PACIENTE %d \n", i+1);
        printf("\n");//Pula a linha
        printf("O IMC do %d- paciente é: %.2f \n", i+1, pacientes[i].imc);

        //Classificando o IMC
        if(pacientes[i].imc < 17)
        {
            printf("Situação: Muito Abaixo do Peso \n");
        }
        else if(pacientes[i].imc < 18.5)
        {
            printf("Situação: Abaixo do Peso \n");
        }
        else if(pacientes[i].imc < 25)
        {
            printf("Situação: Peso Normal \n");
        }
        else if(pacientes[i].imc < 30)
        {
            printf("Situação: Acima do Peso \n");
        }
        else if(pacientes[i].imc < 35)
        {
            printf("Situação: Obesidade I \n");
        }
        else if(pacientes[i].imc < 40)
        {
            printf("Situação: Obesidade II (Severa) \n");
        }
        else
        {
            printf("Situação: Obesidade III (Mórbida) \n");
        }

        printf("_______________________________________\n");
        printf("\n");//Pula a linha
    }
}
sair()
{
    exit(0);
}
main()
{
/*
2.  Escreva um programa com a estrutura de dados abaixo. Defina um vetor de
    estrutura de 4 elementos. Receba dados via teclado e imprima-os no video.
    Faça um menu com as seguintes opcoes:
    1 - receber todos os dados
    2 - imprime todos os dados
    3 - calcula o IMC de todas as pessoas.
    4 - sair
        Calculo do IMC = peso/(altura*altura).
        estrutura: nome, peso, altura
*/

    setlocale(LC_ALL, "Portuguese");

    //Declaração de variáveis
    int continuar, op;

    //Loop para repetir o programa
    do
    {
        do
        {
            printf("_______________________________________\n");
            printf("                 MENU                  \n");
            printf("\n");//Pula a linha
            printf("1 – Receber todos os dados. \n");
            printf("2 – Imprimir todos os dados na tela. \n");
            printf("3 - Calculcar o IMC de todos os pacientes. \n");
            printf("4 - Sair. \n");
            printf("_______________________________________\n");
            scanf("%d",&op);

            printf("\n");//Pula a linha

            if(op < 1 || op > 4)
            {
                system("cls");//Limpa a tela
                printf("Opção Inválida, digite novamente. \n");
                printf("\n");//Pula a linha
            }
        }
        while(op < 1 || op > 4);

        switch(op)
        {
            case 1:
                system("cls");//Limpa a tela
                entrada();
                system("cls");//Limpa a tela
                break;
            case 2:
                system("cls");//Limpa a tela
                lista();
                break;
            case 3:
                system("cls");//Limpa a tela
                calculo();
                break;
            case 4:
                sair();
                break;
        }

        printf("\n");//Pula a linha
    }
    while(op != 4);//Programa reinicia se a variaver 'continuar' ter valor 1
}
#endif
