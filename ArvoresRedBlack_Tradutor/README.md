# Tradutor Inglês-Português.
Lucas Martins Soares

---
## Apresentação
Esse tradutor é um trabalho da disciplina de algoritmos e estruturas de dados 2 do curso de engenharia de computação no CEFET-MG campus Divinópolis para o aprendizado do funcionamento e da utilização da estrutura red-black-tree. Durante a execução é solicitado para usuário informar a frase que será traduzida. As palavras dessa frase são separadas e buscadas individualmente em uma árvore Red-Black. Em seguida os resultados encontrados são retornados para o usuário.

## Desenvolvimento
Para o desenvolvimento da árvore Red-Black foi usado como matérial de consulta o livro Algoritmos de Thomas H. Cormen<a href="#cormen"><sup>[1]</sup></a> e o site CodesDope<a href="#codesdope"><sup>[2]</sup></a>. Para popular a base dados com palavras em Inglês, foi utilizado a tabela com as 3 mil palavras mais populares do idioma segundo o site EnglishExperts<a href="#englishexperts"><sup>[3]</sup></a>.

## Utilização
Para executar a aplicação, abra o terminal e digite os seguintes comandos:
```shell
git clone https://github.com/lucasmsoares96/tradutor_RB.git
cd tradutor_RB
make
```
E em seguida informa a frase que deseja traduzir:

<img src="ArvoresRedBlack_Tradutor/tradutor.GIF" width="700">

## Propriedades De Árvores Red-Black<a href="#cormen"><sup>[1]</sup></a>
Em seu livro "Algoritmos", Thomas H. Cormen define a árvore vermelho-preto como uma árvore de busca binária com um bit extra de armazenamento por nó: sua cor (que pode ser VERMELHA ou PRETA). Restringindo as cores dos nós em qualquer caminho simples da raiz até uma folha, as árvores vermelho-preto asseguram que o comprimento de nenhum desses caminhos seja maior que duas vezes o de qualquer outro, de modo que a árvore é aproximadamente balanceada.

Uma árvore vermelho-preto é uma árvore de busca binária que satisfaz as seguintes propriedades vermelho-preto:

1. Todo nó é vermelho ou preto.
1. A raiz é preta.
1. Toda folha ( NIL ) é preta.
1. Se um nó é vermelho, então os seus filhos são pretos.
1. Para cada nó, todos os caminhos simples do nó até folhas descendentes contêm o mesmo número de nós pretos.

## Inserção
As operações de inserção e remoção, quando executadas em uma árvore vermelho-preto com n chaves, demoram o tempo `O(lg n)`. 

Segua a baixo uma animação para ilustrar o funcionamento do processo de inserção da árvore Red Black<a href="#print"><sup>[5]</sup></a>. Neste exemplo é inserida a sequência de números ordenada de 10 até 29 para obtermos o pior caso da estrutura.

<p align="center">
  <img src="ArvoresRedBlack_Tradutor/red_black.gif" width="500">
</p>

## Rotações

Sempre que são realizadas operações de inserção e remoção as propriedades da árvore vermelho-preto podem ser violadas. Para restabelecer essas propriedades devemos mudar as cores de alguns nós e realizar rotações.

<p align="center">
  <img src="https://www.codesdope.com/staticroot/images/ds/rb16.gif" width="150">
</p>

## AVL vs Red-Black<a href="#avlvsrb"><sup>[4]</sup></a>
O site GeeksforGeeks aponta as seguintes diferenças entre as árvores balanceadas AVL e RB.

1. Árvores AVL fornecem pesquisas mais rápidas do que Red Black Trees porque são mais estritamente equilibradas.
1. As Red Black Trees fornecem inserção e remoção mais rápidas do operações de que as árvores AVL, pois menos rotações são feitas devido ao balanceamento relativamente relaxado.
1. As árvores AVL armazenam fatores de equilíbrio ou alturas com cada nó, portanto, requer armazenamento para um número inteiro por nó, enquanto a Red Black Tree requer apenas 1 bit de informação por nó.
1. Árvores Red Black são usadas na maioria das bibliotecas de linguagem como map , multimap , multiset em C ++, enquanto árvores AVL são usadas em bancos de dados onde recuperações mais rápidas são necessárias


---
## Referências:

[1] <a id="cormen" href="https://www.amazon.com/Introduction-Algorithms-3rd-MIT-Press/dp/0262033844/ref=sr_1_1?dchild=1&keywords=Introduction+to+Algorithms&qid=1613858932&sr=8-1">Thomas H. Cormen: Introduction to Algorithms, 3rd Edition (The MIT Press)</a><br/>
[2] <a id="codesdope" href="https://www.codesdope.com/course/data-structures-red-black-trees/">CodesDope: Red-Black Trees</a><br/>
[3] <a id="englishexperts" href="https://www.englishexperts.com.br/forum/3-000-palavras-mais-comuns-em-ingles-t20108.html">English Experts: 3000 Palavras Mais Comuns em Inglês</a><br/>
[4] <a id="avlvsrb" href="https://www.geeksforgeeks.org/red-black-tree-vs-avl-tree/">GeeksforGeeks: Red Black Tree vs AVL Tree </a><br/>
[5] <a id="print" href="https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/">GeeksforGeeks: Print Binary Tree in 2-Dimensions</a><br/>
