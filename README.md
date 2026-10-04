# 🎮 Jogo da Senha em C

## 📌 Sobre o projeto

O **Jogo da Senha** é um projeto desenvolvido em **linguagem C** no qual o computador gera aleatoriamente uma senha numérica de **3 dígitos** e o jogador precisa descobrir essa senha por meio de tentativas.

A cada tentativa, o programa realiza duas análises:

1. Verifica **quantos dígitos da tentativa aparecem na senha**;
2. Verifica **quantos desses dígitos estão na posição correta**.

O jogador pode continuar tentando até acertar a senha ou pode digitar `1` para desistir e revelar a senha.

Este projeto foi desenvolvido com finalidade **educacional**, permitindo praticar conceitos fundamentais de programação em C, como variáveis, estruturas condicionais, estruturas de repetição, arrays, strings, conversão de tipos de dados e geração de números pseudoaleatórios.

---



# 🎯 Objetivos

## Objetivo geral

Desenvolver um jogo simples de adivinhação em linguagem C utilizando conceitos fundamentais da programação estruturada.

## Objetivos específicos

- Gerar uma senha aleatória de três dígitos;
- Permitir que o usuário informe tentativas pelo terminal;
- Converter números inteiros para strings;
- Comparar os dígitos da tentativa com os dígitos da senha;
- Identificar dígitos que existem na senha;
- Identificar dígitos que estão na posição correta;
- Evitar que uma mesma posição da senha seja contabilizada mais de uma vez;
- Utilizar estruturas de repetição para permitir várias tentativas;
- Permitir que o jogador encerre a partida voluntariamente.

---

# 🎮 Funcionamento do jogo

O funcionamento geral do programa segue esta sequência:

```text
┌───────────────────────────────┐
│          INÍCIO               │
└──────────────┬────────────────┘
               │
               ▼
┌───────────────────────────────┐
│ Inicializa o gerador aleatório│
│ com srand(time(NULL))         │
└──────────────┬────────────────┘
               │
               ▼
┌───────────────────────────────┐
│ Gera uma senha entre 100 e 999│
└──────────────┬────────────────┘
               │
               ▼
┌───────────────────────────────┐
│ Verifica senhas com 3 dígitos │
│ iguais                         │
└──────────────┬────────────────┘
               │
               ▼
┌───────────────────────────────┐
│ Converte a senha para string  │
└──────────────┬────────────────┘
               │
               ▼
┌───────────────────────────────┐
│ Solicita a tentativa do       │
│ jogador                       │
└──────────────┬────────────────┘
               │
               ▼
        ┌──────────────┐
        │ Digitou 1 ?  │
        └──────┬───────┘
          SIM  │  NÃO
           │   │
           ▼   ▼
     Revela a   Converte a
      senha     tentativa
       │            │
       │            ▼
       │   ┌──────────────────┐
       │   │ Compara posições │
       │   └────────┬─────────┘
       │            │
       │            ▼
       │   ┌──────────────────┐
       │   │ Procura dígitos  │
       │   │ existentes       │
       │   └────────┬─────────┘
       │            │
       │            ▼
       │   ┌──────────────────┐
       │   │ Mostra resultado │
       │   └────────┬─────────┘
       │            │
       │            ▼
       │     ┌──────────────┐
       │     │ Acertou?     │
       │     └──────┬───────┘
       │       NÃO  │  SIM
       │        │   │
       │        │   ▼
       │        │  VITÓRIA
       │        │
       │        └────────► Nova tentativa
       │
       ▼
      FIM
```

---

# 📜 Regras implementadas

De acordo com o código atual, o jogo possui as seguintes regras:

### 🔐 Senha

A senha é um número inteiro entre:

```text
100
```

e

```text
999
```

Portanto, a senha possui exatamente três dígitos.

### 🚫 Senhas com três dígitos iguais

O código verifica explicitamente as seguintes combinações:

```text
111
222
333
444
555
666
777
888
999
```

Caso uma delas seja sorteada, o programa gera uma nova senha.



### 🎯 Tentativas

O jogador informa uma tentativa pelo teclado.

O programa então compara a tentativa com a senha.

### 🏳️ Desistência

Quando o usuário informa:

```text
1
```

o programa considera que o jogador desistiu, revela a senha e encerra a execução.

### 🏆 Vitória

O jogo termina normalmente quando:

```c
tentativa == senha
```

---

# 🧱 Estrutura do código

O programa está organizado dentro da função:

```c
int main()
```

Sua execução pode ser dividida em etapas:

```text
1. Inclusão das bibliotecas
2. Declaração das variáveis
3. Criação dos arrays de caracteres
4. Inicialização do gerador aleatório
5. Geração da senha
6. Verificação de senhas proibidas
7. Conversão da senha para string
8. Exibição da interface inicial
9. Início do loop principal
10. Leitura da tentativa
11. Verificação da opção de desistência
12. Conversão da tentativa para string
13. Verificação das posições corretas
14. Verificação dos dígitos existentes
15. Exibição do resultado
16. Verificação de vitória
17. Encerramento do programa
```

---

# 📚 Bibliotecas utilizadas

O código utiliza três bibliotecas:

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
```

## `stdio.h`

A biblioteca `stdio.h` é utilizada para entrada e saída de dados.

No projeto, aparecem:

```c
printf()
scanf()
sprintf()
```

### `printf()`

Utilizada para exibir informações no terminal.

Exemplo:

```c
printf("Digite sua tentativa: ");
```

### `scanf()`

Utilizada para receber a tentativa do jogador.

```c
scanf("%d", &tentativa);
```

### `sprintf()`

Utilizada para converter um número inteiro para uma sequência de caracteres.

```c
sprintf(Charsenha, "%d", senha);
```

---

# 🎲 Geração de números aleatórios

O programa utiliza:

```c
srand(time(NULL));
```

antes de chamar `rand()`.

## `srand()`

A função `srand()` inicializa a sequência utilizada pelo gerador pseudoaleatório.

Neste projeto:

```c
srand(time(NULL));
```

usa o horário atual como semente.

Isso faz com que diferentes execuções do programa normalmente produzam diferentes sequências de números.

## `time(NULL)`

A função:

```c
time(NULL)
```

obtém o horário atual utilizado como semente.

## `rand()`

A função:

```c
rand()
```

gera um número pseudoaleatório.

No projeto, ela é utilizada desta forma:

```c
senha = minimo + rand() % (maximo - minimo + 1);
```

Considerando:

```c
minimo = 100;
maximo = 999;
```

temos:

```text
maximo - minimo + 1
999 - 100 + 1
900
```

Logo:

```c
rand() % 900
```

produz um valor entre `0` e `899`.

Somando `100`:

```text
0 + 100 = 100
899 + 100 = 999
```

Portanto, a senha fica entre:

```text
100 e 999
```

---

# 🔤 Arrays de caracteres

O programa declara:

```c
char Charsenha[4];
char Chartentativa[4];
```

Embora a senha tenha três dígitos, são necessárias quatro posições.

Isso ocorre porque uma string em C termina com o caractere especial:

```text
'\0'
```

Por exemplo, a senha:

```text
527
```

fica representada como:

```text
┌───────┬───────┬───────┬────────┐
│  '5'  │  '2'  │  '7'  │ '\0'   │
└───────┴───────┴───────┴────────┘
    0       1       2       3
```

Portanto:

```c
Charsenha[0]
```

contém:

```text
'5'
```

```c
Charsenha[1]
```

contém:

```text
'2'
```

```c
Charsenha[2]
```

contém:

```text
'7'
```

e:

```c
Charsenha[3]
```

contém:

```text
'\0'
```

---

# 🔄 Conversão de `int` para `string`

A senha é inicialmente armazenada como:

```c
int senha;
```

Por exemplo:

```text
senha = 527
```

Depois o código executa:

```c
sprintf(Charsenha, "%d", senha);
```

A representação passa a ser:

```text
"527"
```

Isso é necessário porque o programa deseja comparar os dígitos individualmente.

Assim:

```c
Charsenha[0]
Charsenha[1]
Charsenha[2]
```

podem ser comparados separadamente.

A mesma operação é realizada para a tentativa:

```c
sprintf(Chartentativa, "%d", tentativa);
```

---

# 🔁 Estrutura `do...while`

O núcleo do jogo é:

```c
do {
    ...
} while (tentativa != senha);
```

A condição significa:

```text
Enquanto tentativa for diferente da senha,
continue executando o jogo.
```

Podemos representar:

```text
tentativa != senha
       │
       ├── SIM ──► continua jogando
       │
       └── NÃO ─► encerra o loop
```

A estrutura `do...while` é adequada porque o jogador precisa realizar uma tentativa antes que o programa possa verificar se acertou.

---

# 🔢 Variáveis de contagem

Antes de cada tentativa, os contadores são reiniciados:

```c
caracteresCertos = 0;
caracteresNasPosicoesCorretas = 0;
```

## `caracteresCertos`

Armazena a quantidade de dígitos da tentativa que também são encontrados na senha.

## `caracteresNasPosicoesCorretas`

Armazena a quantidade de dígitos que possuem exatamente a mesma posição na tentativa e na senha.

---

# 📍 Verificação das posições corretas

A primeira comparação utiliza:

```c
for (i = 0; i < 3; i++) {

    if (Chartentativa[i] == Charsenha[i]) {

        caracteresNasPosicoesCorretas++;
    }
}
```

O ponto importante é:

```c
Chartentativa[i] == Charsenha[i]
```

O mesmo índice é utilizado nos dois arrays.

Exemplo:

```text
Senha:       5 2 7
             ↑ ↑ ↑
Posição:     0 1 2

Tentativa:   5 9 7
             ↑ ↑ ↑
Posição:     0 1 2
```

Comparações:

```text
5 == 5 → SIM
9 == 2 → NÃO
7 == 7 → SIM
```

Resultado:

```text
Posições corretas: 2
```

---

# 🔎 Verificação dos dígitos existentes

Depois de verificar as posições corretas, o programa procura os dígitos da tentativa dentro da senha.

Para isso utiliza dois loops:

```c
for (i = 0; i < 3; i++) {

    for (j = 0; j < 3; j++) {

        ...
    }
}
```

O primeiro `for` percorre a tentativa.

O segundo `for` percorre a senha.

Podemos visualizar assim:

```text
Tentativa
   │
   ├── [0]
   ├── [1]
   └── [2]
         │
         ▼
       comparar
         │
         ▼
Senha
   ├── [0]
   ├── [1]
   └── [2]
```

---

# 🚫 Vetor `usado`

O código possui:

```c
int usado[3] = {0, 0, 0};
```

Esse vetor serve para marcar quais posições da senha já foram utilizadas em uma correspondência.

Inicialmente:

```text
usado[0] = 0
usado[1] = 0
usado[2] = 0
```

O valor `0` significa que a posição ainda não foi utilizada.

Quando uma correspondência é encontrada:

```c
usado[j] = 1;
```

A posição fica marcada.

Isso é importante para evitar que uma mesma posição da senha seja contabilizada repetidamente quando existem dígitos repetidos.

---

# ✅ Condição para encontrar um dígito

A condição utilizada é:

```c
if (Chartentativa[i] == Charsenha[j] &&
    usado[j] == 0)
```

Existem duas condições simultâneas.

### Primeira condição

```c
Chartentativa[i] == Charsenha[j]
```

O dígito da tentativa precisa ser igual ao dígito analisado da senha.

### Segunda condição

```c
usado[j] == 0
```

A posição da senha ainda precisa estar disponível.

Somente quando as duas condições são verdadeiras acontece:

```c
caracteresCertos++;
```

e:

```c
usado[j] = 1;
```

---

# 🛑 Uso do `break`

Depois de encontrar uma correspondência:

```c
break;
```

interrompe o `for` interno.

Isso ocorre porque o dígito atual da tentativa já encontrou sua correspondência e não precisa continuar procurando.

---

# 🏳️ Sistema de desistência

O código possui uma opção especial:

```c
if (tentativa == 1)
```

Quando isso acontece:

```c
printf("SENHA: %d\n", senha);
printf("Voce desistiu!\n");
```

A senha é exibida e o programa termina utilizando:

```c
return 0;
```

---

# 🏆 Condição de vitória

Depois das tentativas, o programa verifica:

```c
} while (tentativa != senha);
```

Quando:

```text
tentativa == senha
```

a condição:

```c
tentativa != senha
```

passa a ser falsa.

Consequentemente, o `do...while` termina.

O programa então exibe:

```text
====================================
       PARABENS!
====================================
Voce acertou a senha!
TENTATIVA: ...
SENHA: ...
```

---

# 🖥️ Exemplo de execução

Uma possível execução do programa é:

```text
====================================
       JOGO DA SENHA
====================================

Digite 1 para desistir e revelar a senha.
Digite sua tentativa: 123

------------------------------------
TENTATIVA: 123
Numeros certos: 1
Posicoes corretas: 0
------------------------------------

Digite 1 para desistir e revelar a senha.
Digite sua tentativa: 527

------------------------------------
TENTATIVA: 527
Numeros certos: 3
Posicoes corretas: 3
------------------------------------

====================================
       PARABENS!
====================================
Voce acertou a senha!
TENTATIVA: 527
SENHA: 527
```

O resultado exato depende da senha aleatória gerada pelo programa.

---

# 🧮 Exemplo de comparação

Considere:

```text
Senha:     527
Tentativa: 597
```

### Comparação das posições

```text
Posição 0:
5 == 5 → correto

Posição 1:
9 == 2 → incorreto

Posição 2:
7 == 7 → correto
```

Portanto:

```text
Posições corretas = 2
```

Como os dígitos `5` e `7` também aparecem na senha:

```text
Números certos = 2
```

---

# 🧩 Conceitos de programação praticados

Este projeto reúne vários conceitos fundamentais de C.

## Variáveis

```c
int senha;
int tentativa;
int minimo;
int maximo;
```

## Arrays

```c
char Charsenha[4];
char Chartentativa[4];
```

e:

```c
int usado[3];
```

## Strings

Manipulação de sequências de caracteres por meio de arrays `char`.

## Estruturas condicionais

```c
if (...)
```

utilizadas para tomar decisões.

## Estrutura de repetição

```c
for (...)
```

utilizada para percorrer os caracteres.

## Estrutura `do...while`

Utilizada para manter o jogo funcionando até o acerto.

## Conversão de dados

Utilização de:

```c
sprintf()
```

para converter números inteiros em strings.

## Números pseudoaleatórios

Utilização de:

```c
rand()
srand()
time()
```

## Controle de índices

Uso de:

```c
i
j
```

para acessar posições dos arrays.

## Controle de elementos utilizados

Uso do array:

```c
usado[]
```

para evitar reutilização de posições da senha.

---

# 📂 Estrutura recomendada do projeto

Uma organização simples para o repositório é:

```text
JogoDaSenha/
│
├── README.md
│
├── main.c
│
└── .gitignore
```

Caso o projeto cresça, pode ser organizado da seguinte maneira:

```text
JogoDaSenha/
│
├── README.md
├── .gitignore
│
├── src/
│   └── main.c
│
└── docs/
```

---

# ⚙️ Como compilar

## GCC no Windows

No terminal, estando na pasta do projeto:

```bash
gcc main.c -o jogo
```

Depois execute:

```bash
.\jogo.exe
```

## Linux

```bash
gcc main.c -o jogo
./jogo
```

---

# 🔧 Melhorias futuras

O código atual já implementa o funcionamento principal do jogo, mas pode ser evoluído.

## 1. Validar a entrada do usuário

O programa poderia verificar se a tentativa realmente possui três dígitos.

Por exemplo:

```text
12    → inválido
99    → inválido
123   → válido
1000  → inválido
```

---

## 2. Garantir definitivamente que a senha seja válida

Atualmente o código verifica uma senha com três dígitos iguais apenas uma vez.

Uma melhoria seria repetir o sorteio até encontrar uma senha que atenda à regra.

---

## 3. Separar números certos de posições erradas

Atualmente:

```text
Números certos
```

representa os dígitos encontrados na senha, incluindo aqueles que estejam em posições corretas.

Uma futura versão poderia mostrar:

```text
Números certos: 3
Posições corretas: 1
Posições erradas: 2
```

---

## 4. Contador de tentativas

Adicionar uma variável para registrar:

```text
Tentativa 1
Tentativa 2
Tentativa 3
...
```

e mostrar quantas tentativas foram necessárias para vencer.

---

## 5. Sistema de pontuação

A pontuação poderia considerar a quantidade de tentativas.

Exemplo:

```text
Poucas tentativas → maior pontuação
Muitas tentativas  → menor pontuação
```

---

## 6. Níveis de dificuldade

Poderiam ser criados diferentes níveis:

```text
Fácil       → 2 dígitos
Médio       → 3 dígitos
Difícil     → 4 dígitos
Muito difícil → 5 dígitos
```

---

## 7. Histórico de partidas

Uma evolução interessante seria salvar os resultados em arquivo.

Exemplo:

```text
histórico.txt
```

Com informações como:

```text
Tentativas: 5
Resultado: Vitória
```

Essa melhoria permitiria praticar **manipulação de arquivos em C**.

---

# 📖 Valor educacional do projeto

Embora seja um programa pequeno, o Jogo da Senha permite praticar vários fundamentos que aparecem em projetos maiores.

A lógica pode ser resumida em:

```text
              PROBLEMA
                  │
                  ▼
          GERAR UMA SENHA
                  │
                  ▼
          RECEBER TENTATIVA
                  │
                  ▼
             COMPARAR
             /       \
            /         \
           ▼           ▼
      DÍGITOS       POSIÇÕES
      EXISTENTES    CORRETAS
           \         /
            \       /
             ▼     ▼
          MOSTRAR RESULTADO
                  │
                  ▼
             ACERTOU?
              /    \
            NÃO    SIM
             │      │
             ▼      ▼
         NOVA      FIM
       TENTATIVA
```

O projeto trabalha principalmente a capacidade de **transformar uma regra de um problema em uma sequência de operações que o computador consiga executar**.

---

# 📌 Resumo técnico

| Elemento | Utilização |
|---|---|
| `stdio.h` | Entrada e saída |
| `stdlib.h` | Geração pseudoaleatória |
| `time.h` | Semente baseada no horário |
| `int` | Armazenamento dos números |
| `char[]` | Representação dos números como strings |
| `sprintf()` | Conversão de `int` para string |
| `printf()` | Exibição no terminal |
| `scanf()` | Entrada da tentativa |
| `srand()` | Inicialização do gerador aleatório |
| `rand()` | Geração de números pseudoaleatórios |
| `if` | Estruturas de decisão |
| `for` | Repetição para comparação |
| `do...while` | Repetição principal do jogo |
| `break` | Interrupção da busca |
| `usado[]` | Controle das posições já utilizadas |
| `return 0` | Encerramento normal do programa |

---

# 📄 Licença

Este projeto foi desenvolvido para **fins educacionais e de aprendizado em programação**.

O código pode ser utilizado como material de estudo, adaptado e expandido para fins acadêmicos e de prática em linguagem C.

---

## 👨‍💻 Autores

**Dagoberto Silva**

**Lariza Fernandes**

Projeto educacional de programação em C.
