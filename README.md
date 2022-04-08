# Exercicio2-ED1

Objetivo: Treinar uso de strings, structs e alocação dinâmica!

Implemente um programa, no arquivo exercicio2.c, que defina um tipo estruturado Aluno com os seguintes campos: 
char* nome; int matricula; float p1; float p2; float p3;

Seu programa deve alocar espaço dinâmico para os alunos de uma Turma. A turma (definida como um vetor de ponteiros para Alunos)
deve ser alocada da seguinte forma: Aluno** turma = (Aluno**) malloc (n * sizeof(Aluno*));
Onde n é o número de alunos, que deve ser informado pelo teclado.

As informações dos alunos (nome, matrícula, etc.) também devem ser fornecidas pelo teclado. Cada “aluno” deve ser alocado dinamicamente,
assim como o seu nome. Depois que a turma (vetor de ponteiros para alunos) for carregada, imprima todos os dados (um aluno por linha).

Para completar seu programa, implemente as seguintes funções:
• void imprime_aprovados (int n, Aluno** turma); //Imprime na tela os alunos aprovados. O aluno é aprovado quando a média das 3 provas for 
maior ou igual a 5; n é o números de alunos na turma.
• float media_turma (int n, Aluno** turma); //Retorna a média da turma inteira; n é o número de alunos da turma.

Despois que os dados dos alunos aparecerem na tela, espera-se a lista de alunos aprovados seguido pela média da turma.
