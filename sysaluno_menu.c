#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno {
    int matricula;
    char nome[120]; 
    int idade;
    float renda;
};

void pedirDados(struct aluno *novoAluno);
void listarAlunos(struct aluno *alunos, int qtdAlunos);
void editarAluno(struct aluno *alunos, int qtdAlunos);
void removerAluno(struct aluno *alunos, int *qtdAlunos);
void limparTela();

int main(){
    struct aluno *alunos;
    alunos = (struct aluno *)malloc(10 * sizeof(struct aluno));
    int qtd_alunos = 0;

    char menu[] = ">>> SysAluno <<<\n1 - Add Aluno\n2 - Listar Alunos\n3 - Atualizar Aluno\n4 - Remover Aluno\n\n0 - Sair\n>>> ";
    int opcao;
    printf("%s", menu);
    scanf("%d", &opcao);

    while (opcao != 0){
        if (opcao ==1) {
            struct aluno novoAluno;
            pedirDados(&novoAluno);
            alunos[qtd_alunos] = novoAluno;
            qtd_alunos++;
        } else if (opcao == 2) {
            listarAlunos(alunos, qtd_alunos);
        } else if (opcao == 3) {
            editarAluno(alunos, qtd_alunos);
        } else if (opcao == 4) {
            removerAluno(alunos, &qtd_alunos);
        }  
        printf("%s", menu);
        scanf("%d", &opcao);
        // limparTela();
        } 
        
    }


/* void limparTela() {
    system("cls");
}*/

void pedirDados(struct aluno *novoAluno){
    printf("Matricula: ");
    scanf("%d", &novoAluno->matricula);// &: pq matricula é inteiro

    printf("Nome: ");
    scanf(" %120[^\n]", novoAluno->nome); // sem & porque o conteudo que vai para novoAluno é um vetor de char
}

void listarAlunos(struct aluno *alunos, int qtdAlunos){
    printf("---- Alunos Cadastrados ----\n");

    for (int i = 0; i < qtdAlunos; i++){
        printf("%d - %s\n", alunos[i].matricula, alunos[i].nome);
    }
    printf("-----------------------------------------------------------\n");
}

void editarAluno(struct aluno *alunos, int qtdAlunos){
    int matricula;
    printf("Digite a matricula do aluno que deseja editar: ");
    scanf("%d", &matricula);

    int encontrado = 0;
    for (int i = 0; i < qtdAlunos; i++) {
        if (alunos[i].matricula == matricula) {
            printf("Novos dados para o aluno %s:\n", alunos[i].nome);
            pedirDados(&alunos[i]);
            encontrado = 1;
        }else if (!encontrado) {
        printf("Aluno com matricula %d não encontrado.\n", matricula);
        }
    }

}

void removerAluno(struct aluno *alunos, int *qtdAlunos){
    int matricula;
    printf("Digite a matricula do aluno que deseja remover: ");
    scanf("%d", &matricula);

    int encontrado = 0;
    for (int i = 0; i < *qtdAlunos; i++) {
        if (alunos[i].matricula == matricula) {
            encontrado = 1;
            
            for (int j = i; j < (*qtdAlunos - 1); j++) { 
                alunos[j] = alunos[j + 1];
            }
            (*qtdAlunos)--;
            printf("Aluno com matricula %d removido com sucesso.\n", matricula);
        }
    }

    if (!encontrado) {
        printf("Aluno com matricula %d não encontrado.\n", matricula);
    }
}

// não consegui fazer 
// void buscarAlunoPorMatricula

// não consegui fazer 
// void buscarAlunoPorNome