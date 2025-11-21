# 🎡 Jogo Roda a Roda em C

Este projeto implementa uma versão interativa do jogo "Roda a Roda" (semelhante ao Wheel of Fortune), desenvolvida em Linguagem C.

O jogo utiliza manipulação de arquivos binários para gerenciar os dados:
* `PALAVRAS.DAT`: Armazena pistas e as palavras secretas.
* `PREMIOS.DAT`: Armazena os valores de prêmios sorteáveis.

---

## ⚙️ Recursos do Menu

O menu principal oferece opções de gerenciamento e de jogo:

* **1. Gravar dados:** Cadastra novas pistas e palavras no sistema.
* **3. Cadastro default de premios:** Cria os valores de prêmios padrão, incluindo as ações especiais.
* **5. Jogar:** Inicia uma partida do Roda a Roda para 3 jogadores.

---

## 🎲 Mecânica do Jogo

O jogo roda com 3 jogadores, seguindo estas regras:

1.  **Sorteio:** A cada rodada, o jogador "roda" e um valor de prêmio é sorteado.
2.  **Passa a Vez / Perde Tudo:**
    * Se for sorteado **R$ 0.00**, a vez é passada (**Passa a Vez**).
    * Se for sorteado **R$ 0.01**, o saldo do jogador é zerado (**Perde Tudo**) e a vez é passada.
3.  **Acerto de Letra:** Se a letra estiver na palavra, o valor do prêmio é adicionado ao saldo do jogador pelo número de ocorrências, e ele joga novamente.
4.  **Chute Final:** Quando faltam **3 ou menos letras** para a palavra, o jogador tem 5 segundos para chutar a palavra inteira e vencer a rodada.

---

## 💻 Como Compilar e Executar

O código foi otimizado para ambientes Windows (devido ao uso de `getch()`, `system("cls")` e `Sleep()`).

1.  **Compilar (usando GCC):**
    ```bash
    gcc pj_rodaroda.c -o rodaroda
    ```
2.  **Executar:**
    ```bash
    ./rodaroda
    ```
3.  **Pré-jogo:** Certifique-se de usar as **Opções 3** e **1** do menu para preencher os arquivos de dados antes de selecionar a **Opção 5 (Jogar)**.
