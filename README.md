### **Gerador de Labirintos em C++**

# Gerador de Labirintos

Um projeto em C++ que gera labirintos aleatórios diretamente no terminal. Ideal para aprender e praticar conceitos de programação de sistemas e algoritmos.

-----

## 💡 Sobre o Projeto

Este programa é um gerador de labirintos interativo, construído do zero em C++. Ele utiliza o **algoritmo de Backtracking Recursivo** para criar labirintos "perfeitamente conectados", ou seja, sem becos sem saída isolados ou ciclos redundantes.

O objetivo deste projeto é servir como uma ferramenta de aprendizado, permitindo que desenvolvedores explorem conceitos fundamentais como:

* **Estruturas de Dados:** Uso de `std::vector` para matrizes 2D e `std::stack` para o algoritmo de backtracking.
* **Algoritmos:** Implementação de um gerador de labirintos.
* **Programação de Sistemas:** Entendimento de alocação de memória e passagem de dados por referência.

-----

## 🚀 Como Usar

O projeto é compilado e executado via terminal. Siga os passos abaixo:

1.  **Clone o repositório:**

    ```bash
    git clone [URL_DO_SEU_REPOSITORIO]
    cd [pasta_do_projeto]
    ```

2.  **Compile o código:**
    Use um compilador C++ moderno, como o G++. A flag `-std=c++17` é recomendada.

    ```bash
    g++ -std=c++17 -o labirinto main.cpp
    ```

3.  **Execute o programa:**

    ```bash
    ./labirinto
    ```

    O labirinto será gerado e exibido diretamente no seu terminal.

-----

## 🎨 Exemplo de Saída

A saída do programa no terminal será algo parecido com isto:

```
█████████████████████████████████████████
█     █ █ █         █ █     █ █   █   █ █
█ ███ █ █ █ ███████ █ █ ███ █ █ ███ █ █ █
█ █ █ █ █   █   █   █ █   █ █   █ █ █   █
█ █ █ █ █ ███ █ █ ███ █ █ █ █ ███ █ █████
█ █   █   █   █ █ █   █ █   █   █ █ █   █
█ █ █████ █ █ █ █ █ ███ █████ █ █ █ █ ███
█ █   █   █ █   █ █   █ █   █ █ █ █ █   █
█ ███ █ ███ █ ███ ███ █ █ ███ █ █ █ ███ █
█ █   █ █   █ █     █ █ █ █   █   █   █ █
█ █ ███ █ ███ █ ███ █ █ █ ███ █ █████ █ █
█ █ █   █ █   █ █   █ █ █ █ █ █   █ █ █ █
█ █ █ ███ █ ███ █ ███ ███ █ █ █ ███ █ █ █
█   █   █   █   █ █   █   █ █   █   █   █
█████████████████████████████████████████
```