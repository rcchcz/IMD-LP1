# Unique

Implemente uma função chamada unique, que recebe um range \[first,last) e reordena os elementos no range de forma que elementos no novo
range são únicos, isto é, eles aparecem no range apenas uma vez. Dessa forma, elementos repetidos, se existirem, devem ser removidos no 
range resultante. A ordem relativa dos elementos originais __devem ser preservadas__, veja o exemplo abaixo:
```c++
#include <iostream>  // std::cout, std::endl
#include <iterator>  // std::begin(), std::end()
int main() {
    int Vet[] {2, 1, 4, 2, 5, 4, 5, 2, 1, 6 };   // Vetor original
    int Expected[] { 2, 1, 4, 5, 6 };            // Vetor esperado.

    // Chamar a funcao unique().
    int * new_last = graal::unique( std::begin(Vet), std::end(Vet), std::equal_to<int>() );

    // Validando o resultado...
    int * it { std::begin(Vet) } ;               // Comeco do vetor-original.
    int * it_expected { std::begin(Expected) } ; // Comeco do vetor-esperado.
    while ( it != new_last ) {                   // Percorrer o novo range
        assert( *it == *it_expected );           // Verificar se valores sao iguais.
        it++;                                    // Avancar no vetor-resultado.
        it_expected++:                           // Avancar no vetor-resposta.
    }
    return 0;
}
```
A função deve retornar um iterator para o endereço logo após o último elemento do range processado. A assinatura deve ser:
```c++
template < typename Itr , typename Equal >
Itr unique ( Itr first , Itr last , Equal eq );
```
Observe que a função não deve criar um novo range, mas sim __modificar__ os elementos do range recebido e retornar um "novo final", se for o caso.

## Parâmetros
- first, last - os ponteiros apontando para o inicio e "fim" do range a ser considerado.
- eq - uma função que retorna true se o elemento é igual ao segundo, ou falso caso contrário. A assinatura da função de comparação
deve ser ``bool eq( const Type &a, const Type &b)``.

Na furnção eq o tipo `Type` deve ser o mesmo tipo apontado por Itr, de forma que a função de comparação possa ser usada como `eq(*it1,*it2)`. Use essa função para
comparar os valores ao invés dos operadores usuais, por exemplo se você quer saber se o elemento apontado por \*it1 é igual ao elemento apontado por \*it2
ao invés de fazer ``*it == *it2`` voce usaria ``eq(*it1,*it2)``.

De forma mais concreta, se sua função ``unique`` vai processar elementos de um ``std::vector<string>``, sua função eq deve ser:
```c++
bool eq(const string &a,  const string &b)
```
Desta forma, quando a função ``unique`` for comparar os elementos ela não precisa se preocupar se são strings.

## Retorno
Um iterator para o elemento logo após o último elemento do range após o processamento.