// INcluindo bibliotecas
#include <stdio.h>
#include <string.h>

// Variáveis globais
#define MAX_TERRITORIOS 5

// local onde ficara armazenado os dados do territorio
struct territorio {
    char nome[30];
    char cor[10];
    int tropas;
    int numeroTerritorio;
};

// Função para limpar o buffer de entrada
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// funcão principal
int main() {
    // declaração de variaveis 
    struct territorio maximoTerritorios[MAX_TERRITORIOS];
    int totalTerritorios = 0;
    int opcao;

// utilizo o do para caso o usuario escolha 0 encerrar o programa
    do {    
        printf("\n====================================\n");
        printf("WAR\n");
        printf("Escolha uma Opção:\n");
        printf("1 - Criar territorio\n");
        printf("2 - Ver territorios\n");
        printf("3 - Sair\n");
        printf("Digite apenas números: \n");
        scanf("%d", &opcao);
        limparBufferEntrada(); // garante que o Enter não atrapalhe depois

        // local onde vai ser executado de acordo com  a escolha do usuario
        switch (opcao) {
        case 1:
        // verifica de o total de territorios não excedeu o maximo antes de executar
            if (totalTerritorios < MAX_TERRITORIOS) {
                printf("========== CADASTRO DO TERRITORIO %d ==========\n", totalTerritorios + 1);

                printf("Digite o nome do território: ");
                // fgets tem a mesma finalidade que o scanf, a diferença é que ele também capta espaços
                fgets(maximoTerritorios[totalTerritorios].nome, sizeof(maximoTerritorios[totalTerritorios].nome), stdin);

                printf("Digite a cor do exército (EX: AZUL, VERDE): ");
                fgets(maximoTerritorios[totalTerritorios].cor, sizeof(maximoTerritorios[totalTerritorios].cor), stdin);

                // Remove o '\n' do final das strings
                maximoTerritorios[totalTerritorios].nome[strcspn(maximoTerritorios[totalTerritorios].nome, "\n")] = '\0';
                maximoTerritorios[totalTerritorios].cor[strcspn(maximoTerritorios[totalTerritorios].cor, "\n")] = '\0';

                printf("Digite o número de tropas: ");
                scanf("%d", &maximoTerritorios[totalTerritorios].tropas);
                limparBufferEntrada(); // limpa o Enter

                // Isso faz com que cada territorio tenha seu proprio numero
                maximoTerritorios[totalTerritorios].numeroTerritorio = totalTerritorios + 1;
                totalTerritorios++;
                printf("Território cadastrado com sucesso!\n");
            } else {
                printf("Limite máximo de territórios atingido!\n");
            }
            printf("\nPressione Enter para continuar...");
            // getchar faz com que o sistema só continue o processo caso o usuario aperte enter
            getchar();
            break;
        
        case 2: 
        // verifica se há ao menos 1 territorio cadastrado
            if (totalTerritorios == 0) {
                printf("\nVocê ainda não cadastrou nenhum território!");
            } else {
                // exibição dos territorios
                printf("\n=== MAPA DO MUNDO ===\n");
                printf("ESTADO ATUAL:\n\n");
                for (int i = 0; i < totalTerritorios; i++) {
                    printf("TERRITORIO: %d\nNome: %s \nCor: %s \nTropas: %d\n\n",
                        maximoTerritorios[i].numeroTerritorio,
                        maximoTerritorios[i].nome,
                        maximoTerritorios[i].cor,
                        maximoTerritorios[i].tropas);
                }
            }
            printf("\nPressione Enter para continuar...");
            getchar();
            break;

        case 3:
        // saindo do sistema
            printf("Saindo do sistema...\n");
            break;

        default:
        // tratamento caso o usuario coloque uma opção invalida
            printf("\nOpção inválida! Tente novamente\n");
            printf("\nPressione Enter para continuar...");
            getchar();
            break;
        }

        // caso o usuario coloque 3 no switch, o sistema encerra o programa
    } while (opcao != 3);

    return 0; // Fim do programa
}
