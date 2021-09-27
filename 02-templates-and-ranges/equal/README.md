# Equal

Implemente duas funções sobrecarregadas[1] chamadas equal. A primeira versão deve receber um range \[first,last), e um ponteiro(iterator) para outro
range first2; a função deve retornar verdadeio se todos os elementos do primeiro range são iguais aos do range \[rist2, first2+(last1-first1)), e falso 
caso contrário. A segunda versão da função equal deve receber dois ranges \[first,last) e \[first2,last2); retornando verdadeiro quando todos os elementos do 
range1 são iguais aos do range2 e falso caso contrário.

De forma análoga às questões anteriores a função deve receber uma função para comparar os elementos no range, a assinatura das funções deve ser:
```c++
template < typename Itr , typename Equal >
bool equal ( Itr first , Itr last , Itr first2 , Equal eq )
template < typename Itr , typename Equal >
bool equal ( Itr first , Itr last , Itr first2 , Itr last2 , Equal eq )
```

## Parâmetros
- first, last - os ponteiros apontando para o inicio e "fim" do range a ser considerado.
- fist2, last2 - o range(ou inicio do range) que deve ser levado em consideração para a comparação.
- eq - uma função que retorna true se o elemento é igual ao segundo, ou falso caso contrário. A assinatura da função de comparação
deve ser ``bool eq( const Type &a, const Type &b)``.

Na furnção eq o tipo `Type` deve ser o mesmo tipo apontado por Itr, de forma que a função de comparação possa ser usada como `eq(*it1,*it2)`. Use essa função para
comparar os valores ao invés dos operadores usuais, por exemplo se você quer saber se o elemento apontado por \*it1 é igual ao elemento apontado por \*it2
ao invés de fazer ``*it == *it2`` voce usaria ``eq(*it1,*it2)``.

De forma mais concreta, se sua função ``equal`` vai comparar elementos de um ``std::vector<string>``, sua função eq deve ser:
```c++
bool eq(const string &a,  const string &b)
```
Desta forma, quando a função ``equal`` for comparar os elementos ela não precisa se preocupar se são strings.


## Retorno
Verdadeiro se os ranges são iguais, falso caso contrário

## Notas
[1](https://www.w3schools.com/cpp/cpp_function_overloading.asp). Sobrecarga de funções é uma funcionalidade de c++(e praticamente todas as linguagens com paradigma orientado à objetos) que permite que uma função
tenha o mesmo nome, mas com diferentes assinaturas em termos de seus parâmetros 