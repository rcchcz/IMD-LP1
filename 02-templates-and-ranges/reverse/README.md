# Reverse

Implemente uma função chamada reverse que inverte a ordem de cada elemento em um range \[first, last), a assinatura da função é:
```c++
template < typename Itr >
void reverse( Itr first, Itr last );
```
Observe que a função __não retorna__ um novo range, ao invés disso ela modifica os elementos do range recebido.

## Parâmetros
- first, last - os ponteiros apontando para o inicio e "fim" do range a ser considerado.
