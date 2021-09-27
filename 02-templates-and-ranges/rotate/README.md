# Rotate

Implemente uma função chamada rotate que recebe um range \[first,last), um _iterator_ n_first neste range e faz uma rotação à esquerda
dos elementos no range recebido de forma que n_first se torne o primeiro elemento do e n_first-1 se torna o último elemento. A função
deve retornar um iterator que aponta para a nova posição que se encontra o primeiro elemento do range antes da rotação.
```c++
template < typename Itr >
Itr rotate ( Itr first , Itr n_first , Itr last );
```

## Parâmetros
- first, last - os ponteiros apontando para o inicio e "fim" do range a ser considerado.
- n_first - o elemento que deve aparecer no inicio do range após a rotação

## Retorno
Um iterator para a posição onde se encontra o primeiro elemento do range antes da rotação