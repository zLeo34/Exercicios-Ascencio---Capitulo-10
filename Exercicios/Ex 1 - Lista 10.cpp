#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define N 4  
#define MESES 12

struct Vendedor {
    int codigo;
    float vendas[MESES];
};

struct Vendedor vendedores[N];
int total_vendedores = 0;

void cadastrar_vendedor() {
    if (total_vendedores >= N) {
        printf("Limite de vendedores atingido.\n");
        system("pause");
        return;
    }

    int codigo;
    printf("Digite o codigo do vendedor: ");
    scanf("%d", &codigo);

    
    for (int i = 0; i < total_vendedores; i++) {
        if (vendedores[i].codigo == codigo) {
            printf("Codigo ja cadastrado.\n");
            system("pause");
            return;
        }
    }

    vendedores[total_vendedores].codigo = codigo;
    for (int i = 0; i < MESES; i++) {
        vendedores[total_vendedores].vendas[i] = 0;
    }

    total_vendedores++;
    printf("Vendedor cadastrado com sucesso.\n");
    system("pause");
}

void cadastrar_venda() {
    int codigo, mes;
    float valor;

    printf("Digite o codigo do vendedor: ");
    scanf("%d", &codigo);
    printf("Digite o mes (1-12): ");
    scanf("%d", &mes);
    printf("Digite o valor da venda: ");
    scanf("%f", &valor);

    if (mes < 1 || mes > 12) {
        printf("Mes invalido.\n");
        system("pause");
        return;
    }

    for (int i = 0; i < total_vendedores; i++) {
        if (vendedores[i].codigo == codigo) {
            if (vendedores[i].vendas[mes - 1] != 0) {
                printf("Venda ja cadastrada para esse vendedor neste mes.\n");
                system("pause");
                return;
            }
            vendedores[i].vendas[mes - 1] = valor;
            printf("Venda cadastrada com sucesso.\n");
            system("pause");
            return;
        }
    }

    printf("Vendedor nao encontrado.\n");
    system("pause");
}

void consultar_venda_mes() {
    int codigo, mes;

    printf("Digite o codigo do vendedor: ");
    scanf("%d", &codigo);
    printf("Digite o mes (1-12): ");
    scanf("%d", &mes);

    if (mes < 1 || mes > 12) {
        printf("Mes invalido.\n");
        system("pause");
        return;
    }

    for (int i = 0; i < total_vendedores; i++) {
        if (vendedores[i].codigo == codigo) {
            printf("Venda do vendedor %d no mes %d: %.2f\n", codigo, mes, vendedores[i].vendas[mes - 1]);
            system("pause");
            return;
        }
    }

    printf("Vendedor nao encontrado.\n");
    system("pause");
}

void total_vendas_vendedor() {
    int codigo;
    float total = 0;

    printf("Digite o codigo do vendedor: ");
    scanf("%d", &codigo);

    for (int i = 0; i < total_vendedores; i++) {
        if (vendedores[i].codigo == codigo) {
            for (int j = 0; j < MESES; j++) {
                total += vendedores[i].vendas[j];
            }
            printf("Total de vendas do vendedor %d: %.2f\n", codigo, total);
            system("pause");
            return;
        }
    }

    printf("Vendedor nao encontrado.\n");
    system("pause");
}

void vendedor_mais_vendeu_mes() {
    int mes;
    printf("Digite o mes (1-12): ");
    scanf("%d", &mes);

    if (mes < 1 || mes > 12) {
        printf("Mes invalido.\n");
        system("pause");
        return;
    }

    int melhor_vendedor = -1;
    float maior_venda = 0;

    for (int i = 0; i < total_vendedores; i++) {
        if (vendedores[i].vendas[mes - 1] > maior_venda) {
            maior_venda = vendedores[i].vendas[mes - 1];
            melhor_vendedor = vendedores[i].codigo;
        }
    }

    if (melhor_vendedor != -1) {
        printf("Vendedor que mais vendeu no mes %d: %d com %.2f\n", mes, melhor_vendedor, maior_venda);
    } else {
        printf("Nenhuma venda registrada nesse mes.\n");
    }

    system("pause");
}

void mes_com_mais_vendas() {
    float total_vendas[MESES] = {0};
    int melhor_mes = 0;
    float maior_venda = 0;

    for (int i = 0; i < total_vendedores; i++) {
        for (int j = 0; j < MESES; j++) {
            total_vendas[j] += vendedores[i].vendas[j];
        }
    }

    for (int i = 0; i < MESES; i++) {
        if (total_vendas[i] > maior_venda) {
            maior_venda = total_vendas[i];
            melhor_mes = i + 1;
        }
    }

    printf("Mes com mais vendas: %d com total de %.2f\n", melhor_mes, maior_venda);
    system("pause");
}

int main() {
    int opcao;

    while (1) {
        system("cls"); 
        printf("\nMenu:\n");
        printf("1. Cadastrar vendedor\n");
        printf("2. Cadastrar venda\n");
        printf("3. Consultar vendas de um vendedor em um mes\n");
        printf("4. Consultar total de vendas de um vendedor\n");
        printf("5. Consultar vendedor que mais vendeu em um mes\n");
        printf("6. Consultar mes com mais vendas\n");
        printf("7. Finalizar programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar_vendedor();
                break;
            case 2:
                cadastrar_venda();
                break;
            case 3:
                consultar_venda_mes();
                break;
            case 4:
                total_vendas_vendedor();
                break;
            case 5:
                vendedor_mais_vendeu_mes();
                break;
            case 6:
                mes_com_mais_vendas();
                break;
            case 7:
                printf("Finalizando programa...\n");
                system("pause");
                return 0;
            default:
                printf("Opcao invalida.\n");
                system("pause");
        }
    }
}

