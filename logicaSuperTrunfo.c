#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

// Função para exibir o menu com opção de excluir uma escolha já feita
void exibirMenu(int excluir) {
    printf("\nEscolha um atributo para comparação:\n");
    if (excluir != 1) printf("1 - População\n");
    if (excluir != 2) printf("2 - Área\n");
    if (excluir != 3) printf("3 - PIB\n");
    if (excluir != 4) printf("4 - Número de Pontos Turísticos\n");
    if (excluir != 5) printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
}

// Função para retornar o nome do atributo para exibição
const char* nomeAtributo(int op) {
    switch (op) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Número de Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Atributo inválido";
    }
}

int main() {
    // Cadastro das Cartas: (utilize o código do primeiro desafio)
    
    // Declaração de variáveis para a primeira carta
    char estado1;
    char codigo1[4];
    char nomeCidade1[50];
    int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidadePopulacional1;
    float pibPerCapita1;

    // Declaração de variáveis para a segunda carta
    char estado2;
    char codigo2[4];
    char nomeCidade2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidadePopulacional2;
    float pibPerCapita2;

    // Entrada de dados para a primeira carta
    printf("Insira os dados da Carta 1:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Código da Carta (ex: A01): ");
    scanf("%s", codigo1);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]%*c", nomeCidade1); // Lê string com espaços
    printf("População: ");
    scanf("%d", &populacao1);
    printf("Área (em km²): ");
    scanf("%f", &area1);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // Cálculos para a primeira carta
    // Densidade Populacional = População / Área
    densidadePopulacional1 = populacao1 / area1;
    // PIB per Capita = (PIB em unidades de reais) / População
    // PIB é dado em bilhões, então multiplicamos por 1,000,000,000
    pibPerCapita1 = (pib1 * 1000000000) / populacao1;

    // Entrada de dados para a segunda carta
    printf("\nInsira os dados da Carta 2:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Código da Carta (ex: B02): ");
    scanf("%s", codigo2);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]%*c", nomeCidade2); // Lê string com espaços
    printf("População: ");
    scanf("%d", &populacao2);
    printf("Área (em km²): ");
    scanf("%f", &area2);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    densidadePopulacional2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;

    // Exibição dos dados da primeira carta
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);

    // Exibição dos dados da segunda carta
    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);

    // Comparação de Cartas:
    // Desenvolva a lógica de comparação entre duas cartas.
    // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.

    // Exemplo:
    // if (populacaoA > populacaoB) {
    //     printf("Cidade 1 tem maior população.\n");
    // } else {
    //     printf("Cidade 2 tem maior população.\n");
    // }

    // Exibição dos Resultados:
    // Após realizar as comparações, exiba os resultados para o usuário.
    // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.

    // Menu Interativo
    int attr1 = 0, attr2 = 0;

    // Escolha do primeiro atributo
    do {
        exibirMenu(0);
        scanf("%d", &attr1);
        if(attr1 < 1 || attr1 > 5)
            printf("Opção inválida. Tente novamente.\n");
    } while(attr1 < 1 || attr1 > 5);

    // Escolha do segundo atributo (diferente do primeiro)
    do {
        exibirMenu(attr1);
        scanf("%d", &attr2);
        if(attr2 < 1 || attr2 > 5)
            printf("Opção inválida. Tente novamente.\n");
        else if(attr2 == attr1)
            printf("Você já escolheu esse atributo. Escolha outro.\n");
    } while(attr2 < 1 || attr2 > 5 || attr2 == attr1);

    // Função lambda (com switch) para obter o valor do atributo escolhido para cada carta
    float valorA1, valorA2, valorB1, valorB2;

    valorA1 = (attr1 == 1) ? (float)populacao1 :
              (attr1 == 2) ? area1 :
              (attr1 == 3) ? pib1 :
              (attr1 == 4) ? (float)pontosTuristicos1 :
              densidadePopulacional1;

    valorA2 = (attr1 == 1) ? (float)populacao2 :
              (attr1 == 2) ? area2 :
              (attr1 == 3) ? pib2 :
              (attr1 == 4) ? (float)pontosTuristicos2 :
              densidadePopulacional2;

    valorB1 = (attr2 == 1) ? (float)populacao1 :
              (attr2 == 2) ? area1 :
              (attr2 == 3) ? pib1 :
              (attr2 == 4) ? (float)pontosTuristicos1 :
              densidadePopulacional1;

    valorB2 = (attr2 == 1) ? (float)populacao2 :
              (attr2 == 2) ? area2 :
              (attr2 == 3) ? pib2 :
              (attr2 == 4) ? (float)pontosTuristicos2 :
              densidadePopulacional2;

    // Exibe atributos e valores
    printf("\nComparação entre %s e %s\n", nomeCidade1, nomeCidade2);
    printf("%s:\n  %s = %.2f\n  %s = %.2f\n", nomeAtributo(attr1), nomeCidade1, valorA1, nomeCidade2, valorA2);
    printf("%s:\n  %s = %.2f\n  %s = %.2f\n", nomeAtributo(attr2), nomeCidade1, valorB1, nomeCidade2, valorB2);

    // Comparação com regras: para densidade, menor vence, para outros maior vence
    int vencedorA = (attr1 == 5) ? ((valorA1 < valorA2) ? 1 : (valorA2 < valorA1) ? 2 : 0)
                                : ((valorA1 > valorA2) ? 1 : (valorA2 > valorA1) ? 2 : 0);

    int vencedorB = (attr2 == 5) ? ((valorB1 < valorB2) ? 1 : (valorB2 < valorB1) ? 2 : 0)
                                : ((valorB1 > valorB2) ? 1 : (valorB2 > valorB1) ? 2 : 0);

    // Soma dos valores para decisão final (sempre maior soma vence)
    float soma1 = valorA1 + valorB1;
    float soma2 = valorA2 + valorB2;

    printf("\nSoma dos valores:\n  %s = %.2f\n  %s = %.2f\n", nomeCidade1, soma1, nomeCidade2, soma2);

    printf("\nResultado final: %s\n",
           (soma1 > soma2) ? nomeCidade1 :
           (soma2 > soma1) ? nomeCidade2 : "Empate!");

    return 0;
}
