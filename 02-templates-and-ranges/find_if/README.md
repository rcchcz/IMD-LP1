# Find_if

Implemente uma função chamada find_if que recebe um range \[first,last) e retorna um iterator para o primeiro elemento no range em que
um determinado _predicado_ é verdadeiro. Se o _predicado_ for falso em todos os elementos a função deve retonar o _iterator_ last.

Assim a função deve realizar uma _busca linear_, o _predicado_ a ser testado é passado como parâmetro, dessa forma a função tem o protótipo:
```c++
template < typename Itr , typename Predicate >
Itr find_if ( Itr first , Itr last , Predicate p )
```

## Parâmetros
- first, last - os ponteiros apontando para o inicio e "fim" do range a ser considerado.
- p - uma função que retorna true quando uma determinada condição é satisfeita ou falso caso contrário. A assinatura da função
deve ser ``bool p( const Type &a)``.

Na função p o tipo `Type` deve ser o mesmo tipo apontado por Itr, de forma que p possa ser usada como `p(*it1)`. Use essa função para
testar se um valor no range satisfaz o _predicado p_. Por exemlo, se você quer testar se o elemento apontado por \*it1 satisfaz p
voce usaria ``p(*it1)``.

De forma mais concreta, se sua função ``find_if`` vai testar elementos de um ``std::vector<string>``, sua função p deve ser:
```c++
bool p(const string &b)
```
Desta forma, quando a função ``find_if`` for testar os elementos ela não precisa se preocupar se são strings.


## Retorno
Um iterator apontando para o primeiro elemento do range que satisfaz p.