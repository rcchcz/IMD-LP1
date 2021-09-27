# Sort

Implemente uma função chamada sort, que recebe e ordena os elementos de um range \[first,last). A função também deve receber como parâmetro
uma função comp usada para comparar dois elementos no range. A assinatura da função deve ser:
```c++
template < typename Itr , typename Comparison >
void sort ( Itr first , Itr last , Comparison comp );
```

## Parâmetros
- first, last - os ponteiros apontando para o inicio e "fim" do range a ser considerado.
- cmp - uma função que retorna true se o elemento é menor do que o segundo, ou falso caso contrário. A assinatura da função de comparação
deve ser ``bool cmp( const Type &a, const Type &b)``.

Na furnção cmp o tipo `Type` deve ser o mesmo tipo de Itr, de forma que a função de comparação possa ser usada como `cmp(*it1,*it2)`. Use essa função para
comparar os valores ao invés dos operadores usuais, por exemplo se você quer saber se o elemento apontado por \*it1 é menor do que o elemento apontado por \*it2
ao invés de fazer ``*it < *it2`` voce usaria ``cmp(*it1,*it2)``.

De forma mais concreta, se sua função ``sort`` vai comparar elementos de um ``std::vector<string>``, sua função cmp deve ser:
```c++
bool cmp(const string &a,  const string &b)
```
Desta forma, quando a função ``sort`` for comparar os elementos ela não precisa se preocupar se são strings.
