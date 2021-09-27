# Partition

Implemente uma função chamada partition, que recebe um range \[first,last). e reordena o range de forma que os elementos que satisfazem um determinado
_predicado_ fiquem antes de elementos cujo mesmo _predicado_ não seja satisfeito.

A função deve retornar um ponteiro(ou iterator) apontando para o endereço logo após o último elemento para qual o _predicado_ é verdadeiro. A assinatura
da função deve ser:
```c++
template < typename Itr , typename Predicate >
Itr partition ( Itr first , Itr last , Predicate p );
```

## Parâmetros
- first, last - os ponteiros apontando para o inicio e "fim" do range a ser considerado.
- p - uma função que retorna true quando uma determinada condição é satisfeita ou falso caso contrário. A assinatura da função
deve ser ``bool p( const Type &a)``.

Na função p o tipo `Type` deve ser o mesmo tipo apontado por Itr, de forma que p possa ser usada como `p(*it1)`. Use essa função para
testar se um valor no range satisfaz o _predicado p_. Por exemlo, se você quer testar se o elemento apontado por \*it1 satisfaz p
voce usaria ``p(*it1)``.

De forma mais concreta, se sua função ``partition`` vai testar elementos de um ``std::vector<string>``, sua função p deve ser:
```c++
bool p(const string &b)
```
Desta forma, quando a função ``partition`` for testar os elementos ela não precisa se preocupar se são strings.


## Retorno
Um iterator apontando para o elemento logo após o último elemento no range reordenado que satisfaz o predicado.