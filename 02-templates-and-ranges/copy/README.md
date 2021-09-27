# Copy

Implemente uma função chamada _copy_ que recebe um range \[first,last) e copia os valores do range dentro de um novo range
que inicia em _d\_first_. Assuma que o range que inicia em _d\_first_ tem memória suficiente para armazenar os elementos a serem
copiados. Por isso, a função __não deve__ alocar memória. A função deve retornar um iterator apontando para o "fim" do range prenchido,
que é a posição de memória logo após o último elemento iniciando em _d\_first_. A assinatura da função é:
 
```c++
template < typename Itr >
Itr copy ( Itr first , Itr last , Itr d_first );
```

## Parâmetros
- first, last - os ponteiros apontando para o inicio e "fim" do range a ser considerado.
- d_first - o inicio do range onde os elementos devem ser copiados.

## Retorno
Um iterator apontado para a posição logo após o último elemento do _range_ cópia.