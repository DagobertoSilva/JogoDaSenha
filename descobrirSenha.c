#include <stdio.h>      // Biblioteca para entrada e saída: printf(), scanf(), sprintf()
#include <stdlib.h>     // Biblioteca para rand(), srand()
#include <time.h>       // Biblioteca para time(), usada para gerar números aleatórios diferentes


int main() {

    /*
     * ============================================================
     * 1. DECLARAÇÃO DAS VARIÁVEIS
     * ============================================================
     */

    int senha, i, j;

    // Define o menor valor possível para a senha.
    // Como queremos uma senha de 3 dígitos, começamos em 100.
    int minimo = 100;

    // Define o maior valor possível para a senha.
    int maximo = 999;

    // Armazena o número digitado pelo jogador.
    int tentativa;


    /*
     * Essas duas variáveis armazenam a quantidade de números
     * encontrados durante a comparação da tentativa com a senha.
     */

    // Quantidade de dígitos que existem na senha,
    // independentemente de estarem na posição correta.
    int caracteresCertos;

    // Quantidade de dígitos que estão exatamente
    // na mesma posição da senha.
    int caracteresNasPosicoesCorretas;


    /*
     * ============================================================
     * 2. VETORES DE CARACTERES
     * ============================================================
     *
     * A senha inicialmente é um número inteiro.
     *
     * Exemplo:
     *
     *     senha = 527
     *
     * Para comparar cada dígito individualmente, vamos transformar:
     *
     *     527
     *
     * em:
     *
     *     "527"
     *
     * Por isso usamos arrays de char.
     *
     * Cada array precisa ter 4 posições:
     *
     *     [5][2][7][\0]
     *
     * Os três primeiros espaços armazenam os dígitos.
     * O último armazena '\0', que indica o fim da string.
     */

    char Charsenha[4];
    char Chartentativa[4];


    /*
     * ============================================================
     * 3. INICIALIZAÇÃO DO GERADOR DE NÚMEROS ALEATÓRIOS
     * ============================================================
     *
     * srand() define uma "semente" para o rand().
     *
     * time(NULL) fornece o horário atual.
     *
     * Dessa forma, cada vez que o programa for executado,
     * teremos uma sequência diferente de números aleatórios.
     */

    srand(time(NULL));


    /*
     * ============================================================
     * 4. GERAÇÃO DA SENHA
     * ============================================================
     *
     * A expressão:
     *
     *     rand() % (maximo - minimo + 1)
     *
     * gera valores entre 0 e 899.
     *
     * Depois adicionamos 100:
     *
     *     100 + valor
     *
     * Resultado:
     *
     *     100 até 999
     *
     * Exemplo:
     *
     *     rand() % 900 → 527
     *
     *     100 + 527 → 627
     */

    senha = minimo + rand() % (maximo - minimo + 1);


    /*
     * ============================================================
     * 5. EVITAR SENHAS COM TRÊS DÍGITOS IGUAIS
     * ============================================================
     *
     * Aqui verificamos se a senha é:
     *
     *     111
     *     222
     *     333
     *     ...
     *     999
     *
     * Se for uma dessas, geramos outra senha.
     */



while (
    senha / 100 == (senha / 10) % 10 ||
    senha / 100 == senha % 10 ||
    (senha / 10) % 10 == senha % 10
) {
    senha = minimo + rand() % (maximo - minimo + 1);
}

    /*
     * ============================================================
     * 6. CONVERTER A SENHA DE INT PARA STRING
     * ============================================================
     *
     * sprintf() transforma o número inteiro em texto.
     *
     * Exemplo:
     *
     *     senha = 527
     *
     * Depois:
     *
     *     Charsenha = "527"
     *
     * Isso permite acessar cada dígito individualmente:
     *
     *     Charsenha[0] → '5'
     *     Charsenha[1] → '2'
     *     Charsenha[2] → '7'
     *     Charsenha[3] → '\0'
     */

    sprintf(Charsenha, "%d", senha);


    /*
     * ============================================================
     * 7. TELA INICIAL DO JOGO
     * ============================================================
     */

    printf("====================================\n");
    printf("       JOGO DA SENHA\n");
    printf("====================================\n");


    /*
     * ============================================================
     * 8. LAÇO PRINCIPAL DO JOGO
     * ============================================================
     *
     * O do...while garante que o jogador tenha pelo menos
     * uma oportunidade de fazer uma tentativa.
     *
     * O jogo continuará enquanto:
     *
     *     tentativa != senha
     *
     * Ou seja:
     *
     *     enquanto o jogador NÃO acertar.
     */

    do {

        /*
         * Zera os contadores antes de analisar
         * uma nova tentativa.
         *
         * Isso é importante porque cada tentativa
         * precisa começar novamente do zero.
         */

        caracteresCertos = 0;
        caracteresNasPosicoesCorretas = 0;


        /*
         * ========================================================
         * 9. SOLICITAR UMA TENTATIVA
         * ========================================================
         */

        printf("\nDigite 1 para desistir e revelar a senha.\n");
        printf("Digite sua tentativa: ");

        scanf("%d", &tentativa);


        /*
         * ========================================================
         * 10. OPÇÃO DE DESISTIR
         * ========================================================
         *
         * Se o jogador digitar 1, o programa revela a senha
         * e termina.
         *
         * Exemplo:
         *
         *     tentativa = 1
         */

        if (tentativa == 1) {

            printf("\n====================================\n");
            printf("SENHA: %d\n", senha);
            printf("Voce desistiu!\n");
            printf("====================================\n");

            // Encerra o programa.
            return 0;
        }


        /*
         * ========================================================
         * 11. CONVERTER A TENTATIVA PARA STRING
         * ========================================================
         *
         * Assim como fizemos com a senha, transformamos:
         *
         *     527
         *
         * em:
         *
         *     "527"
         *
         * Isso permite comparar:
         *
         *     Chartentativa[0]
         *     Chartentativa[1]
         *     Chartentativa[2]
         *
         * com:
         *
         *     Charsenha[0]
         *     Charsenha[1]
         *     Charsenha[2]
         */

        sprintf(Chartentativa, "%d", tentativa);


        /*
         * ========================================================
         * 12. VERIFICAR POSIÇÕES CORRETAS
         * ========================================================
         *
         * Aqui verificamos se o dígito da tentativa está
         * exatamente na mesma posição da senha.
         *
         * Exemplo:
         *
         * SENHA:
         *
         *     527
         *
         * TENTATIVA:
         *
         *     597
         *
         * Comparação:
         *
         * posição 0:
         *
         *     5 == 5
         *
         *     SIM → posição correta
         *
         * posição 1:
         *
         *     9 == 2
         *
         *     NÃO
         *
         * posição 2:
         *
         *     7 == 7
         *
         *     SIM → posição correta
         *
         * Resultado:
         *
         *     2 posições corretas
         */

        for (i = 0; i < 3; i++) {

            /*
             * Comparamos o caractere da tentativa
             * com o caractere da senha na MESMA posição.
             */

            if (Chartentativa[i] == Charsenha[i]) {

                caracteresNasPosicoesCorretas++;
            }
        }


        /*
         * ========================================================
         * 13. CONTROLAR OS DÍGITOS JÁ UTILIZADOS
         * ========================================================
         *
         * Esse vetor é muito importante.
         *
         * Ele evita contar o mesmo dígito da senha
         * mais de uma vez.
         *
         * Inicialmente:
         *
         *     usado = {0, 0, 0}
         *
         * Podemos pensar:
         *
         *     posição 0 → ainda não usada
         *     posição 1 → ainda não usada
         *     posição 2 → ainda não usada
         *
         * Quando uma posição da senha for utilizada,
         * colocamos:
         *
         *     usado[j] = 1
         */

        int usado[3] = {0, 0, 0};


        /*
         * ========================================================
         * 14. PROCURAR DÍGITOS DA TENTATIVA NA SENHA
         * ========================================================
         *
         * Temos dois loops.
         *
         * O primeiro percorre os dígitos da tentativa.
         *
         * O segundo procura cada dígito dentro da senha.
         *
         * Exemplo:
         *
         * SENHA:
         *
         *     527
         *
         * TENTATIVA:
         *
         *     752
         *
         * Para o primeiro dígito da tentativa:
         *
         *     '7'
         *
         * procuramos:
         *
         *     '7' == '5'? NÃO
         *     '7' == '2'? NÃO
         *     '7' == '7'? SIM
         *
         * Então encontramos um número certo.
         */

        for (i = 0; i < 3; i++) {

            /*
             * Agora percorremos cada posição da senha.
             */

            for (j = 0; j < 3; j++) {

                /*
                 * Existem DUAS condições:
                 *
                 * 1. O dígito precisa ser igual.
                 *
                 * 2. A posição da senha ainda não pode ter
                 *    sido utilizada.
                 */

                if (Chartentativa[i] == Charsenha[j] &&
                    usado[j] == 0) {


                    /*
                     * Encontramos um dígito que existe na senha.
                     *
                     * Portanto, incrementamos a quantidade
                     * de caracteres certos.
                     */

                    caracteresCertos++;


                    /*
                     * Marcamos essa posição como utilizada.
                     *
                     * Isso impede que ela seja usada novamente
                     * por outro dígito da tentativa.
                     */

                    usado[j] = 1;


                    /*
                     * Como já encontramos uma correspondência
                     * para Chartentativa[i], podemos parar
                     * de procurar na senha e passar para
                     * o próximo dígito da tentativa.
                     */

                    break;
                }
            }
        }


        /*
         * ========================================================
         * 15. MOSTRAR O RESULTADO DA TENTATIVA
         * ========================================================
         */

        printf("\n------------------------------------\n");

        // Mostra o número que o jogador digitou.
        printf("TENTATIVA: %d\n", tentativa);

        // Mostra quantos dígitos existem na senha.
        printf("Numeros certos: %d\n", caracteresCertos);

        // Mostra quantos estão na posição exata.
        printf("Posicoes corretas: %d\n",
               caracteresNasPosicoesCorretas);

        printf("------------------------------------\n");


        /*
         * O programa volta para o início do do...while
         * caso a tentativa esteja errada.
         *
         * Se tentativa == senha, o loop termina.
         */

    } while (tentativa != senha);


    /*
     * ============================================================
     * 16. JOGADOR ACERTOU A SENHA
     * ============================================================
     *
     * Se chegamos aqui, significa que:
     *
     *     tentativa == senha
     *
     * Portanto, o jogador acertou.
     */

    printf("\n====================================\n");
    printf("       PARABENS!\n");
    printf("====================================\n");

    printf("Voce acertou a senha!\n");

    // Mostra a última tentativa.
    printf("TENTATIVA: %d\n", tentativa);

    // Mostra a senha.
    printf("SENHA: %d\n", senha);


    /*
     * ============================================================
     * 17. FINALIZAÇÃO DO PROGRAMA
     * ============================================================
     *
     * return 0 indica que o programa terminou normalmente.
     */

    return 0;
}