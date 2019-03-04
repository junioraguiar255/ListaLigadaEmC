
#include<stdio.h>
#include<stdlib.h>

struct no{ // CRIAMOS NOSSO N� PARA ESTUDO
	
int num;
struct no *prox;// PTR PARA APONTAR PARA O NOSSO PROX ELEMENTO DA LISTA
};
typedef struct no No; // RENOMEAMOS NOSSO N� PARA SIMPLIFICAR A CHAMADA DO NOSSO N�

No* criaNo(){ //FUN��O PARA CRIAR UM N� SEM NECESSITAR ESCREVER O C�DIGO DE ALOCA��O DINAMICA TODA VEZ.
	No *novo =(No*) malloc (sizeof(No)); // NOSSO C�DIGO DE ALOCA��O DO N�
	return novo; //RETORNA O NOVO N� CRIADO.
}
No* insereInicio(No* Cabeca,int dado){ // FUN��O PARA INSERIR O N� NO INICIO
	No *novo_no=criaNo(); //NOVO N� NA FUN��O
	novo_no->num=dado; //NOVO N� RECEBE O DADO POR PAR�METRO
	if(Cabeca == NULL){//VERIFICA SE A LISTA EST� VAZIA
		Cabeca=novo_no;//SE A CABE�A ESTIVER VAZIA NOVO N� SER� A CABE�A
		novo_no->prox=NULL;// LOGICAMENTE ELA VAI APONTAR PARA NULL J� QUE � O PRIMEIRO 
		//E UNICO ELEMENTO NA LISTA
	}else // ENTRA AQUI SE J� TIVER ELEMENTOS NA LISTA
	{
		novo_no->prox=Cabeca; // SE A LISTA ESTIVER COM ELEMENTOS, A NOVA LISTA APONTARA 
		//PARA A ATUAL CABE�A.
		Cabeca=novo_no;// E O NOVO N� CRIADO POR ESTE METODO SER� O CABE�A DA NOSSA LISTA 
	}
	return Cabeca; // RETORNAMOS O CABE�A DA LISTA, � O QUE N�O PODEMOS PERDER
}
No* insereFim(No* Cabeca, int dado){ // FUN��O PARA INSERIR NO FIM
	// FUN��O PARA INSERIR N� NO FIM DA LISTA
	No *novo = criaNo(); //CRIAMOS O N� DESTA FUN��O
	novo->num=dado; // ESTE NOVO N� RECEBE O DADO ENVIADO POR PAR�METRO.
	if(Cabeca==NULL){ // VERIFICA SE A LISTA EST� VAZIA
		novo->prox=NULL; // ESTE NOVO N� APONTAR� PARA NULL POIS SERA O PRIMEIRO
		Cabeca=novo;// SE A LISTA ESTIVER VAZIA , ESTE N� SER� O NOSSO CABE�A
	}else{ //CASO A LISTA N�O ESTEJA VAZIA
		No* aux=Cabeca; // O NOSSO AUX RECEBER� O ENDERE�O DA NOSSA CABE�A
		while(aux->prox!=NULL){ // FAREMOS O LOOP AT� ENCONTRAR O N� QUE APONTE PARA NULL
			aux=aux->prox; // INCREMENTO PARA O PROXIMO N� CASO O N� N�O APONTE PARA NULL
		}
		novo->prox=NULL; // CHEGA AQUI AP�S ENCONTRAR O ULTIMO N�, 
		//O N� CRIADO AQUI APONTAR� PARA NULL.
		aux->prox=novo; // O N� QUE APONTAVA PARA NULL E ERA O ULTIMO AGORA APONTAR�
		//PARA O NO CRIADO NESTA FUN��O
	// O N� CRIADO AQUI SER� O NOSSO ULTIMO N�
	}
	return Cabeca; //RETORNAMOS A CABE�A DA LISTA
}
void imprime(No* Cabeca){ // NA FUN��O QUE ESCREVE A NOSSA LISTA,
// S� RECEMOS A CABE�A DA LISTA
	No *aux=Cabeca; // DEVEMOS TER UM PTR AUXILIAR PARA A COPIA DO ENDERE�O DO NOSSO CABE�A
	while(aux!=NULL){ // ESSA FUN��O WHILE IR� FUNCIONAR AT� ENCONTRAR O ULTIMO N� QUE APONTA
	// PARA NULO
		printf("%d ",aux->num);// ESCREVE OS ELEMENTOS DE CADA N� AT� UMA LISTA APONTAR PARA NULL
		aux=aux->prox; // INCREMENTO DA FUN��O WHILE
	}
}
No* criaListaNula(void){ // PRECISAMOS DESTA FUN��O PARA CRIAR A PRIMEIRA LISTA NULA
	return NULL; // RETORNA O VALOR NULL PARA A LISTA
	
}
No* removeInicio(No* Cabeca){ // FUN��O QUE REMOVE O NOSSO CABE�A
	No *aux;
	if(Cabeca==NULL){ //FUN��O QUE VERIFICA SE A LISTA EST� VAZIA
		return 0;
	}else{ // CASO A LISTA N�O ESTEJA VAZIA
		aux = Cabeca; // O NOSSO PONTEIRO AUX RECEBE O ENDERE�O DE NOSSA CABE�A PARA AP�S TUDO 
		// N�O PERDER O ENDERE�O DESTE PR�XIMO ANTIGO CABE�A.
		Cabeca=Cabeca->prox; // CABE�A RECEBE O ENDERE�O DO N� QUE ESTE CABE�A APONTA, "O SEGUNDO ELEMENTO 
		// DA NOSSA LISTA AGORA SER� O NOSSO CABE�A.
		free(aux);// EXCLUIMOS O NOSSO ANTIGO CABE�A
	}
	return Cabeca; // RETORNA COMO CABE�A O ANTIGO SEGUNDO ELEMENTO DA LISTA
}

No* removeDado(No* Cabeca, int dado){ // FUN��O PARA REMOVER UM DADO
	No *ptr,*anterior; // PRECISAMOS DE UM PTR PARA ARMAZENAR O ENDERE�O
	// DO N� ANTERIOR DEST� DADO REMOVIDO
	if(Cabeca==NULL){ // PRECISAMOS VERIFICAR SE EXISTE LISTA
		return 0; // SE N EXISTIR LISTA RETORNA 0
	} else // SE EXISTIR A LISTA
	{
		ptr=Cabeca; // PTR RECEBE O ENDERE�O DA NOSSA CABECA
		anterior=NULL; // ESTE PTR SERVIR� PARA ARMAZENAR O ENDERE�O DO N� ANTERIOR
		while(ptr != NULL){ // ENQUANTO PTR FOR DIFERENTE DE NULO
			if(ptr->num==dado){ // SE O VALOR DESTE PTR FOR = AO DADO
				if(ptr==anterior){// VERIFICA SE ESTA ARMAZENADO NO CABECA
					
					Cabeca = Cabeca->prox;// NOSSO CABECA SER� O ENDERE�O DO 2� NO
					free(ptr); // REMOVEMOS NOSSO CABECA DA MEMORIA
                    return 2; // RETORNA 2 � O CABE�A E REMOVE
				}else // SE N�O FOR NOSSO CABECA
				{
					anterior->prox = ptr->prox; // O ANTERIOR NESTE LOOP SEMPRE ARMAZENA O 
					// ENDERE�O DO NOSSO NO ANTERIOR, AQUI ELE RECEBE O ENDERE�O DO N� APOS
					// O N� QUE VAI SER EXCLUIDO.
					free(ptr); // REMOVEMOS ESTE N�
					return 1; // N�O � NOSSO CABE�A E RETORNA 1
				}
				
			}else // ENTRAR� NESTE LOOP AT� ENCONTRAR O VALOR ENVIADO POR PAR�METRO
			{
				anterior = ptr; // ANTERIOR SEMPRE RECEBE O ENDERE�O DO NO ANTERIOR
				ptr = ptr->prox; // RECEBE O VALOR DO PROXIMO N�
			}
			
		} return 0;
	}
	
}

No* buscaDado(No* Cabeca, int dado){
	No* aux;
	if(Cabeca==NULL){
		return NULL;
	}
	aux = Cabeca;
	while(aux!= NULL){
		if(aux->num==dado){
			return(aux);
		}else {
			aux = aux->prox;
		}
	}
	return NULL;
}


int main(){
	No *Cabeca,*aux;
	int ret;
	Cabeca=criaListaNula();
	Cabeca = insereInicio(Cabeca,10);
	Cabeca = insereInicio(Cabeca,20);
	Cabeca = insereInicio(Cabeca,30);
	Cabeca=insereFim(Cabeca,50);
	Cabeca = insereInicio(Cabeca,80);
	printf("Imprimindo lista completa \n");
    imprime(Cabeca);
    Cabeca = removeDado(Cabeca,80);

    switch(ret)    	
	{
	case 0:
		printf("\n Valor nao encontrado ou lista limpa");
		break;
    case 1:
		printf("\nRemoveu e nao e nosso cabeca");
		break;
	case 2:
		printf("\n removeu e era nosso cabeca");	
		break;
    default:
	printf("\n ERROR - funcao retornou valor n esperado");
		break;
	}
	printf("\nApos remocao do 20 \n ");
    imprime(Cabeca);
    aux = buscaDado(Cabeca,50);
    if(aux != NULL)
	printf("\n Tentamos e Achamos o %d ",aux->num);
else
{
	printf("\n nao achamos este valor");
}
		
    
    
    
	
	
	
return 0;
}