#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void LimparTela(){
    system("cls || clear");
}

struct Vendas_Gerais{
    char Nome[500];
    float Preco;
    int Quantidade;
    int Carrinho;
};

void RealizarCompra(struct Vendas_Gerais *Vendas, int quantidadeComprada) {
    if (quantidadeComprada > 0 && quantidadeComprada <= Vendas->Quantidade) {
        Vendas->Quantidade -= quantidadeComprada;
        printf("Compra realizada com sucesso!\n");
    } else if (quantidadeComprada <= 0) {
        printf("Quantidade inválida para compra.\n");
    } else {
        printf("Quantidade insuficiente em estoque.\n");
    }
}

float calcularValorTotal(float N1, int N2) {

    float total;
    total =  N1 * N2;

     return total;
}
void Carrinho(struct Vendas_Gerais *Vendas, int quantidadeCompra){
    int carrinho;

    carrinho = quantidadeCompra;
    printf("Carrinho: %d", carrinho);
}


void Consultar_Estoque(struct Vendas_Gerais *Vendas){
    printf("Quantidade em Estoque: %d\n",Vendas->Quantidade);
}



int main(){

    setlocale(LC_ALL, "portuguese");
    struct Vendas_Gerais Vendas;
    strcpy(Vendas.Nome, "Relogio Tasione");
    Vendas.Preco = 160.90;
    Vendas.Quantidade = 35;
    Vendas.Carrinho;

    int opcao;
    int quantidadeComprada = 0;

    do{
        printf("\nMenu de Relogios:\n");
        printf("1 - Tasione\n");
        printf("2 - Consultar carrinho\n");
        printf("3 - Consultar Estoque\n");
        printf("4 - Valor Total\n\n");
        printf("Escolha a opção: ");
        scanf("%d", &opcao);

        LimparTela();

           switch (opcao){
           case 1:
            printf("Informe a quantidade a ser comprada: ");
            scanf("%d", &quantidadeComprada);
            RealizarCompra(&Vendas, quantidadeComprada);
            break;
            case 2:
            Carrinho(&Vendas,quantidadeComprada);
            break;
            case 3:
            Consultar_Estoque(&Vendas);
            break;
            case 4:
            printf("Valor Total a Pargar: %.2f",calcularValorTotal(Vendas.Preco,quantidadeComprada));
            break;
           default:
           printf("Codigo Invalido! ");
            break;
           } 
    } while (opcao != 4);

    return 0;
}