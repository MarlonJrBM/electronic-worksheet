Trabalho Prático da discplina Programação Modular, do Departamento de Ciência da Computação da Universidade Federal de Minas Gerais - 2014/1. 
Especificação do TP:

Implemente uma planilha eletrônica simples em C++ que atenda aos seguintes requisitos:

1. Células podem possuir valores reais e strings

2. Células podem possuir fórmulas envolvendo os seguintes operadores: +, -, *, /.

3. Expressões de uma fórmula podem ser escritas em uma notação pós-fixada. Exemplo: =5 B1 +

4. Expressões podem incluir as funções somatório (=SUM) e média (=AVG). Exemplo: =SUM(A1:A10)

5. Como usual, alterações em uma célula devem ser propagadas para células que "usam" seus valores.

6. Planilhas podem ter um número máximo de linhas e colunas.

7. Deve ser possível salvar e recuperar planilhas em disco, em um formato próprio.

8. A aplicação deve usar o framework Qt, para construção de interfaces gráficas.

9. No projeto da aplicação, deve haver uma separação clara entre classes de apresentação (interface),
lógica (planilha) e persistência.


Instruções para Entrega:

* Demonstração em sala de aula (de preferência em um laptop) ou em um laboratório

* Algumas planilhas de teste serão fornecidas.

* Envio de fontes pelo Moodle.

* Documento de 2 páginas (máximo) que documente a arquitetura da implementação (principais
classes, "camadas", principais relacionamentos entre classes etc).


Critérios de Avaliação:

1. Funcionamento correto (4 pts)
2. Uso correto de conceitos de OO (separação em camadas) (5 pts)
3. Qualidade da interface gráfica e utilização dos recursos do Qt (3 pts)
4. Documentação (3 pts)
