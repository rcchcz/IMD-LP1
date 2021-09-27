# Find

Implemente uma função chamada find que recebe um range \[first,last), um valor, e retorna um _iterator_ para o primeiro elemento no range
que é igual ao valor recebido por parâmetro. Se o valor não for encontrado no range, a função deve retornar o iterator last.

O teste de igualdade é feito através de uma função recebida por parâmetro, que retorna verdadeiro quando dois elementos recebidos por parâmetro
são iguais. A assinatura da função find deve ser:

```c++
template < typename Itr , typename T , typename Equal >
Itr find ( Itr first , Itr last , const T & value , Equal eq )
```

## Parâmetros
- first, last - os ponteiros apontando para o inicio e "fim" do range a ser considerado.
- value - o valor a ser comparado na função
- eq - uma função que retorna true se o elemento é igual ao segundo, ou falso caso contrário. A assinatura da função de comparação
deve ser ``bool eq( const Type &a, const Type &b)``.

Na furnção eq o tipo `Type` deve ser o mesmo tipo apontado por Itr, de forma que a função de comparação possa ser usada como `eq(*it1,*it2)`. Use essa função para
comparar os valores ao invés dos operadores usuais, por exemplo se você quer saber se o elemento apontado por \*it1 é igual ao elemento apontado por \*it2
ao invés de fazer ``*it == *it2`` voce usaria ``eq(*it1,*it2)``.

De forma mais concreta, se sua função ``find`` vai comparar elementos de um ``std::vector<string>``, sua função eq deve ser:
```c++
bool eq(const string &a,  const string &b)
```
Desta forma, quando a função ``find`` for comparar os elementos ela não precisa se preocupar se são strings.


## Retorno
Um iterator(ou ponteiro) para o primeiro elemento que satisfaz a função eq().

## Complexidade
Linear, no máximo last - first aplicações de eq