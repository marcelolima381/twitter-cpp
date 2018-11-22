# TwitterCpp

## Resumo
O projeto se trata de um trabalho prático do curso Programação e Desenvolvimento de Software 2 da 
Universidade Federal de Minas Gerais. O tema escolhido foi um Twitter que foi desenvolvido em C++ com um banco 
de dados MySQL.

## Dependências
```terminal
> sudo apt install g++
> sudo apt install build-essential
> sudo apt install mysql
> sudo apt install libmysqlcppconn-dev
> sudo apt install libmysqlclient15-dev //necessário em certas distros
```
> O conector MySQL/C++ também pode ser encontrado no link: https://dev.mysql.com/downloads/connector/cpp/

Configure na *AbstractConnection.cpp* o endereço do seu banco de dados, usuário, senha e schema 
(este deve ser criado com o script SQL na raiz do projeto)

## Execução
Na pasta *2018-2-grupo19/cmake-build-debug* encontra-se os arquivos *Makefile* e o executável *2018-2-grupo19*.
Para compilar novamente o projeto, basta digitar: *make*. Para executar: *./2018-2-grupo19*.
**O projeto deve ser utilizado em um ambiente Linux compatível com as dependências citadas acima (Ubuntu, por exemplo)**

Recomenda-se o uso da IDE CLion, da Jetbrains para fazer qualquer modificaço no projeto, já que o mesmo foi
integralmente desenvolvido nesse ambiente.
> Link para download do CLion: https://www.jetbrains.com/clion/download/

## Relatório
No nosso CRC, pensamos numa classe central que seria o Feed, responsável por fazer a função de interface com o usuário 
e a correlação das outras classes, como Usuário e Tweet, onde o Feed demandaria as funções dessas classes, por exemplo 
e assim elas iriam se complementando e trabalhando juntas. As classes “Menção”, que são as Userstags na modelagem, 
Comentários e as Hashtags seriam classes menores apenas para complementar as funções do Tweet como conhecemos, sendo 
criadas para fazer parte de uma classe, como uma de suas variáveis ou como um de seus vetores principais.

Identificamos que, para trabalharmos com uma grande quantidade de usuários, tweets, comentários, curtidas, que 
demandavam uma grande quantidade de dados para serem armazenados e uma necessidade de organização e pesquisa mais 
facilitada. Devido a isso, preferimos utilizar um Banco de Dados em vez de arquivos-texto ou binários, pois além 
desses fatores mencionados, a utilização simultânea de dados é possível e o “id” das variáveis eram gerados 
automaticamente. As funções do Banco de Dados também permitiam pesquisa, escrita e, principalmente, atualização 
de dados facilitada, nos permitindo ter mais tempo para implementar as demais utilidades do Twitter.

Banco de Dados selecionado foi o MySQL e na sua modelagem percebemos que uma tabela para todas as classes criadas 
no CRC era necessário, menos o Feed, que posteriormente tratamos apenas como uma das diversas interfaces 
(“telas”) criadas. Surgiu, também, a necessidade de criar uma tabela para Folowee, pois não tínhamos como ir 
adicionamos inúmeros elementos na tabela de usuários para representar quem ele segue, cada linha nova é utilizada 
para representar uma nova conta e adicionar inúmeras colunas era inviável. Além disso, os Likes do Tweet e os 
Likes do Comentário demandaram uma nova tabela pelo mesmo motivo de Folowee, são dados que são referentes a 
uma classe, mas que não tem número definido de ocorrências, logo era necessário armazenar o id do usuário que 
curtiu o comentário ou o tweet em num lugar diferente.

Para a implementação do sistema propriamente dito, começamos com as classes e seus getters e setters, que são 
funções básicas mas necessárias. Depois disso, começamos a seguir nossa Users Stories para ter uma base de como 
começar a implementar e no que focar primeiro, seguindo também uma lógica do próprio usuário, que começa na 
tela de Login, depois vai pro seu feed, onde tem acesso aos tweets de quem segue e pode selecionar uma ação 
específica como tweetar, ver seu perfil, entre outras. Com isso, decidimos que as interfaces seriam responsáveis 
por printar dados e receber comandos dos usuários, consequentemente, todas teriam que processar os comandos 
e exibir alguma coisa, surgindo então funções básicas para uma classe, que seria especializada em cada tela 
propriamente dita.

Cada tela por sua vez, ao processar a informação deveria, a partir do usuário que logado, demandar ações 
das classes definidas no CRC e na Modelagem do Banco de Dados, que seriam responsáveis por, a partir da 
opção selecionada, pesquisar, ou inserir um novo dado no Banco de Dados e retornar algo para ser mostrado 
nas interfaces. Com isso surgiu a ideia da classe Sessão, responsável por armazenar o usuário logado para 
servir de referência para as demais classes. A classe base AbstractConnection também surgiu a partir dessa 
logística, pois ela é responsável pela função e os ponteiros que abrem e fecham a conexão com o banco de 
dados, acabando com diversos códigos repetidos no sistema. 
