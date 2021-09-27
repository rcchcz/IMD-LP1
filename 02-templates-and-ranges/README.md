[![Work in Repl.it](https://classroom.github.com/assets/work-in-replit-14baed9a392b3a25080506f3b7b6d57f295ec2978f6f33ec97e36a161684cbe9.svg)](https://classroom.github.com/online_ide?assignment_repo_id=4918828&assignment_repo_type=AssignmentRepo)
﻿# Lista de Exercício sobre Ranges e Funções Templates

Essa lista de exercícios tem por objetivo o desenvolvimento de uma biblioteca de funções que operam sobre **ranges**, i.e. um par de ponteiros que definem um intervalo fechado-aberto sobre uma coleção, e que são implementadas na forma de **templates**. A programação com template ou _gabarito_ em C++ permite que você programe uma função sem especificar o tipo de dados sobre o qual a função vai trabalhar. Dessa forma é possível, por exemplo, criar uma função de ordenação que ordenda qualquer coleção de informações, como inteiros, strings, frutas ou monstros.

Mais detalhes sobre cada função a ser implementada pode ser encontrada de maneira unificada no documento em PDF que se encontra [aqui](https://github.com/selan-ufrn/lp1-2021.1-exercicios-ranges/tree/master/docs).


# Resolvendo as questões

Nessa tarefa resolvi utilizar uma organização de conteúdo diferente da tarefa anterior, em virtude de alguns problemas encontrados quando era necessário atualizar algum exercício. Sempre que uma alteração era necessária, era preciso alterar cada repositório de estudante individualmente, de forma manual ou via _script_. Infelizmente o GitHub Classroom (GHC) não oferece um mecanismo integrado para alterar todos os repositórios dentro de uma turma de uma só vez.

Sendo assim, este repositório que será acompanhado pelo GHC será denominado de agora em diante de repositório **Soluções**. Já a lista completa de exercícios está localizada em um _repositório externo_ chamado de [**Exercícios**](https://github.com/selan-ufrn/lp1-2021.1-exercicios-ranges). Dentro do repositório **Exercícios** você vai perceber que cada questão está organizada em uma pasta individual. 

A vantagem desse novo esquema organizacional, separando as questões das soluções, é que se for necessário atualizar algum exercício eu o farei _uma vez_ no repositório **Exercícios** e vocês simplesmente baixam a nova atualização com comandos simples como `git pull`. Para continuarmos a nos beneficiar do sistema de acompanhamento de código e troca de mensagens via _pull request_ com o _branch_ `feedback` ou via a criação de _issues_, você continuará a trabalhar no repositório **Soluções** que é monitorado pelo GHC. Portanto o procedimento (de integração) a ser seguido é o seguinte:

1. Clone o repositório **Exercícios** na sua máquina.
2. Clone o repositório **Soluções** (este repo) na sua máquina.
3. Copie a pasta `test_manager` do repo local **Exercícios** para a raiz do repo local **Soluções**.
3. Para cada exercício que você for resolver faça:
    + Copie a pasta do referido exercício do repo local **Exercícios** para o repo local **Soluções**.
    + Resolva o exercício em questão.
    + Quando finalizar (ou se quiser tirar uma dúvida) adicione a pasta do exercício (`git add <pasta>`) ao repositório local **Soluções**.
    + Faça o _commit_ da pasta com as alterações para o repo **Soluções** no GitHub.
    + Pronto, agora você pode utilizar _pull request_ em `feedback` para se comunicar ou abrir alguma _issue_, casa queira tirar dúvidas sobre o exercício em questão.
    
Ao final desse processo, todas as pastas de **Exercícios** terão sido copiadas e "_comitadas_" para o repo **Soluções** no GHC. Essas serão as pastas com as suas soluções.

## Como funciona o processo de atualização (se necessária)

Vamos supor agora que foi feito uma atualização ou correção de erro no exercício `copy`. O procedimento para atualizar seus repositórios é o seguinte:
1. Entre na sua pasta local do repo **Exercícios** e faça `git pull github master` (assumindo que o nome do repo remoto é `github`).
2. Copie, com cuidado para não perder o que já foi feito, a pasta `copy` para o repo local **Soluções**.
3. Continue trabalhando normalmente no repo local **Soluções**
4. Quando estiver satisfeito, suba suas alterações via _commit_ e  `push github master` (assumindo que o nome do repo remoto é `gitbub`). Note que esse `push` é feito para repo remoto **Soluções** e não no **Exercícios** (que, aliás, vocês nem teriam permissão para alterar).

Para compilar e executar use um dos formatos que seguem.

## Usando `cmake`
Nesta lista, todos os exercícios serão de implementação de função. Todos os testes individuais estão no arquivo `src/main.cpp`.

A compilação e execução das questões pode ser feita usando `cmake`. Por exemplo, se quisermos compilar a questão `copy`, a partir da pasta principal do repo local **Soluções** faça:

```
cd copy
mkdir build
cd build
cmake ..
cmake --build .
```
A compilação gera um executável com o nome `run_tests` dentro da pasta `build`. No __windows__ esse executável fica na pasta `Debug`.

Logo após a compilação, para executar o programa gerado use os comandos:

No linux:
```
./run_tests
```
No windows:
```
.\Debug\run_tests.exe
```

## Usando compilação manual com g++

É possível compilar o programa "na mão" (i.e. sem o `cmake`) usando o `g++`. Para isso use o comando abaixo a partir do diretório da questão específica. Mais uma vez, usando a questão `copy` como exemplo teríamos:
```
cd copy
g++ ../test_manager/src/test_manager.cpp src/main.cpp -I./include -I../test_manager/include -o run_tests
```
Neste caso, independente se é windows ou linux, o executável é gerado no diretório corrente, bastando executá-lo depois, como explicado acima.
