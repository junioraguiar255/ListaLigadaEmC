
#include<stdio.h>
#include<stdlib.h>

struct no{ // CRIAMOS NOSSO NÓ PARA ESTUDO
	
int num;
struct no *prox;// PTR PARA APONTAR PARA O NOSSO PROX ELEMENTO DA LISTA
};
typedef struct no No; // RENOMEAMOS NOSSO NÓ PARA SIMPLIFICAR A CHAMADA DO NOSSO NÓ

No* criaNo(){ //FUNÇÃO PARA CRIAR UM NÓ SEM NECESSITAR ESCREVER O CÓDIGO DE ALOCAÇÃO DINAMICA TODA VEZ.
	No *novo =(No*) malloc (sizeof(No)); // NOSSO CÓDIGO DE ALOCAÇÃO DO NÓ
	return novo; //RETORNA O NOVO NÓ CRIADO.
}
No* insereInicio(No* Cabeca,int dado){ // FUNÇÃO PARA INSERIR O NÓ NO INICIO
	No *novo_no=criaNo(); //NOVO NÓ NA FUNÇÃO
	novo_no->num=dado; //NOVO NÓ RECEBE O DADO POR PARÂMETRO
	if(Cabeca == NULL){//VERIFICA SE A LISTA ESTÁ VAZIA
		Cabeca=novo_no;//SE A CABEÇA ESTIVER VAZIA NOVO NÓ SERÁ A CABEÇA
		novo_no->prox=NULL;// LOGICAMENTE ELA VAI APONTAR PARA NULL JÁ QUE É O PRIMEIRO 
		//E UNICO ELEMENTO NA LISTA
	}else // ENTRA AQUI SE JÁ TIVER ELEMENTOS NA LISTA
	{
		novo_no->prox=Cabeca; // SE A LISTA ESTIVER COM ELEMENTOS, A NOVA LISTA APONTARA 
		//PARA A ATUAL CABEÇA.
		Cabeca=novo_no;// E O NOVO NÓ CRIADO POR ESTE METODO SERÁ O CABEÇA DA NOSSA LISTA 
	}
	return Cabeca; // RETORNAMOS O CABEÇA DA LISTA, É O QUE NÃO PODEMOS PERDER
}
No* insereFim(No* Cabeca, int dado){ // FUNÇÃO PARA INSERIR NO FIM
	// FUNÇÃO PARA INSERIR NÓ NO FIM DA LISTA
	No *novo = criaNo(); //CRIAMOS O NÓ DESTA FUNÇÃO
	novo->num=dado; // ESTE NOVO NÓ RECEBE O DADO ENVIADO POR PARÂMETRO.
	if(Cabeca==NULL){ // VERIFICA SE A LISTA ESTÁ VAZIA
		novo->prox=NULL; // ESTE NOVO NÓ APONTARÁ PARA NULL POIS SERA O PRIMEIRO
		Cabeca=novo;// SE A LISTA ESTIVER VAZIA , ESTE NÓ SERÁ O NOSSO CABEÇA
	}else{ //CASO A LISTA NÃO ESTEJA VAZIA
		No* aux=Cabeca; // O NOSSO AUX RECEBERÁ O ENDEREÇO DA NOSSA CABEÇA
		while(aux->prox!=NULL){ // FAREMOS O LOOP ATÉ ENCONTRAR O NÓ QUE APONTE PARA NULL
			aux=aux->prox; // INCREMENTO PARA O PROXIMO NÓ CASO O NÓ NÃO APONTE PARA NULL
		}
		novo->prox=NULL; // CHEGA AQUI APÓS ENCONTRAR O ULTIMO NÓ, 
		//O NÓ CRIADO AQUI APONTARÁ PARA NULL.
		aux->prox=novo; // O NÓ QUE APONTAVA PARA NULL E ERA O ULTIMO AGORA APONTARÁ
		//PARA O NO CRIADO NESTA FUNÇÃO
	// O NÓ CRIADO AQUI SERÁ O NOSSO ULTIMO NÓ
	}
	return Cabeca; //RETORNAMOS A CABEÇA DA LISTA
}
void imprime(No* Cabeca){ // NA FUNÇÃO QUE ESCREVE A NOSSA LISTA,
// SÓ RECEMOS A CABEÇA DA LISTA
	No *aux=Cabeca; // DEVEMOS TER UM PTR AUXILIAR PARA A COPIA DO ENDEREÇO DO NOSSO CABEÇA
	while(aux!=NULL){ // ESSA FUNÇÃO WHILE IRÁ FUNCIONAR ATÉ ENCONTRAR O ULTIMO NÓ QUE APONTA
	// PARA NULO
		printf("%d ",aux->num);// ESCREVE OS ELEMENTOS DE CADA NÓ ATÉ UMA LISTA APONTAR PARA NULL
		aux=aux->prox; // INCREMENTO DA FUNÇÃO WHILE
	}
}
No* criaListaNula(void){ // PRECISAMOS DESTA FUNÇÃO PARA CRIAR A PRIMEIRA LISTA NULA
	return NULL; // RETORNA O VALOR NULL PARA A LISTA
	
}
No* removeInicio(No* Cabeca){ // FUNÇÃO QUE REMOVE O NOSSO CABEÇA
	No *aux;
	if(Cabeca==NULL){ //FUNÇÃO QUE VERIFICA SE A LISTA ESTÁ VAZIA
		return 0;
	}else{ // CASO A LISTA NÃO ESTEJA VAZIA
		aux = Cabeca; // O NOSSO PONTEIRO AUX RECEBE O ENDEREÇO DE NOSSA CABEÇA PARA APÓS TUDO 
		// NÃO PERDER O ENDEREÇO DESTE PRÓXIMO ANTIGO CABEÇA.
		Cabeca=Cabeca->prox; // CABEÇA RECEBE O ENDEREÇO DO NÓ QUE ESTE CABEÇA APONTA, "O SEGUNDO ELEMENTO 
		// DA NOSSA LISTA AGORA SERÁ O NOSSO CABEÇA.
		free(aux);// EXCLUIMOS O NOSSO ANTIGO CABEÇA
	}
	return Cabeca; // RETORNA COMO CABEÇA O ANTIGO SEGUNDO ELEMENTO DA LISTA
}

No* removeDado(No* Cabeca, int dado){ // FUNÇÃO PARA REMOVER UM DADO
	No *ptr,*anterior; // PRECISAMOS DE UM PTR PARA ARMAZENAR O ENDEREÇO
	// DO NÓ ANTERIOR DESTÉ DADO REMOVIDO
	if(Cabeca==NULL){ // PRECISAMOS VERIFICAR SE EXISTE LISTA
		return 0; // SE N EXISTIR LISTA RETORNA 0
	} else // SE EXISTIR A LISTA
	{
		ptr=Cabeca; // PTR RECEBE O ENDEREÇO DA NOSSA CABECA
		anterior=NULL; // ESTE PTR SERVIRÁ PARA ARMAZENAR O ENDEREÇO DO NÓ ANTERIOR
		while(ptr != NULL){ // ENQUANTO PTR FOR DIFERENTE DE NULO
			if(ptr->num==dado){ // SE O VALOR DESTE PTR FOR = AO DADO
				if(ptr==anterior){// VERIFICA SE ESTA ARMAZENADO NO CABECA
					
					Cabeca = Cabeca->prox;// NOSSO CABECA SERÁ O ENDEREÇO DO 2º NO
					free(ptr); // REMOVEMOS NOSSO CABECA DA MEMORIA
                    return 2; // RETORNA 2 É O CABEÇA E REMOVE
				}else // SE NÃO FOR NOSSO CABECA
				{
					anterior->prox = ptr->prox; // O ANTERIOR NESTE LOOP SEMPRE ARMAZENA O 
					// ENDEREÇO DO NOSSO NO ANTERIOR, AQUI ELE RECEBE O ENDEREÇO DO NÓ APOS
					// O NÓ QUE VAI SER EXCLUIDO.
					free(ptr); // REMOVEMOS ESTE NÓ
					return 1; // NÃO É NOSSO CABEÇA E RETORNA 1
				}
				
			}else // ENTRARÁ NESTE LOOP ATÉ ENCONTRAR O VALOR ENVIADO POR PARÂMETRO
			{
				anterior = ptr; // ANTERIOR SEMPRE RECEBE O ENDEREÇO DO NO ANTERIOR
				ptr = ptr->prox; // RECEBE O VALOR DO PROXIMO NÓ
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