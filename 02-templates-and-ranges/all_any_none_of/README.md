# all_of, any_of e none_of

Implemente três funções all_of, any_of e none_of. Todas as três funções recebem um range \[first,last), um _predicado_ p. A função all_of retorna
verdadeiro quando o _predicado_ p é verdadeiro para __todos os elementos__ do range. A função any_of retorna true quando o _predicado_ p é verdadeiro
para __pelo menos um elemento__ do range. A função none_of retorna verdadeiro se o _predicado_ p é __falso para todos os elementos no range__.

As assinaturas das funções devem ser:
```c++
template <typename Itr , typename Predicate >
bool all_of ( Itr first , Itr last , Predicate p );
template <typename Itr , typename Predicate >
bool any_of ( Itr first , Itr last , Predicate p );
template <typename Itr , typename Predicate >
bool none_of ( Itr first , Itr last , Predicate p );
```

## Parâmetros
- first, last - os ponteiros apontando para o inicio e "fim" do range a ser considerado.
- cmp - uma função que retorna true se o elemento é menor do que o segundo, ou falso caso contrário. A assinatura da função de comparação
deve ser ``bool cmp( const Type &a, const Type &b)``.
- p - uma função que retorna true quando uma determinada condição é satisfeita ou falso caso contrário. A assinatura da função
deve ser ``bool p( const Type &a)``.

Na função p o tipo `Type` deve ser o mesmo tipo apontado por Itr, de forma que p possa ser usada como `p(*it1)`. Use essa função para
testar se um valor no range satisfaz o _predicado p_. Por exemlo, se você quer testar se o elemento apontado por \*it1 satisfaz p
voce usaria ``p(*it1)``.

De forma mais concreta, se sua função ``any/none/all_off`` vai testar elementos de um ``std::vector<string>``, sua função p deve ser:
```c++
bool p(const string &b)
```
Desta forma, quando a função testar os elementos ela não precisa se preocupar se são strings.

## Retorno
- all_of: retorna verdadeiro se todos os elementos do range satisfazem p, falso caso contrário
- any_of: retorna verdadeiro se ao menos um elemento do range satisfaz p, falso caso contrário
- none_of: retorna verdadeiro se todos os elementos do range __não__ satisfazem p, falso caso contrário

## Complexidade
Linear, no máximo last - first aplicações de p