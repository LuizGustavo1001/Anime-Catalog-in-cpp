#include <iostream>
#include <fstream>

using namespace std;

struct anime{
	int numeracao;
	string nomeAnime;
	int numEpisodios;
	int numTemporadas;
	int anoLancamento;
	int anoFinalizacao;
	string generoPrincipal;    
	string status;
};

class noh{
	friend class listaDupla;
	private: 
		noh* proximo;
		noh* anterior;
		anime categorias;

	public:
		noh(anime i);
};

noh::noh(anime i){
	proximo 	= NULL;
	anterior 	= NULL;
	categorias 	= i; 
}

class listaDupla{
	private:
		noh* primeiro;
		noh* ultimo;
		int tamanhoLista;

	public:
		listaDupla();
		~listaDupla();
		bool listaVazia();
		
		void insereAnimeVazia(anime info);
		void insereAnimeInicio(anime info);
		void insereAnimeFim(anime info);
		void sobrescreveAnimePosicaoDesejada(int posicaoDesejada, anime dados);
		
		void removeAnimeInicio();
		void removeAnimeFim();
		void removeAnimePosicaoDesejada(int posicaoDesejada);
		void removeAnime(int opcao,int numeracaoDesejada, string nomeDesejado);
		
		void procuraAnimeNome(string nomeDesejado);
		void procuraAnimeStatus(int sD);
		void procuraAnimeAno(int opcao, int anoDesejado);
		void procuraAnimePorNumTemp(int numTempDesejado);
		
		void imprimeAnime(noh* aux);
		void imprimeCatalogoPorGenero(string generoDesejado);
		
		void imprimeCatalogo();
		void imprimeIntervaloCatalogo(int inicio, int fim);
		
		void preencherVetor(anime catalogo[]);
		
		void salvarArquivo();
		
		int menores(int opcao);
		int maiores(int opcao);
};

// construtor
listaDupla::listaDupla(){
	primeiro 		= NULL;
	ultimo 			= NULL;
	tamanhoLista 	= 0;
}

// destrutor
listaDupla::~listaDupla(){
	while(! listaVazia()){
		removeAnimeInicio();
	}
	tamanhoLista = 0;
}

bool listaDupla::listaVazia(){
	return (tamanhoLista == 0);
}

// insere anime em uma lista vazia
void listaDupla::insereAnimeVazia(anime info){
	noh* novoAnime = new noh(info);
	
	primeiro = novoAnime;
	ultimo = novoAnime;
	tamanhoLista++;
}

// insere anime no início da lista
void listaDupla::insereAnimeInicio(anime info){
	if(listaVazia()){
		insereAnimeVazia(info);
	}else{
		noh* novoAnime = new noh(info);
		novoAnime->proximo = primeiro;
		primeiro->anterior = novoAnime;
		primeiro = novoAnime;
		tamanhoLista++;
	}
}

// insere anime no fim da lista
void listaDupla::insereAnimeFim(anime info){
	if(listaVazia()){
		insereAnimeVazia(info);
	}else{
		noh* novoAnime = new noh(info);
		
		novoAnime->anterior = ultimo;
		ultimo->proximo = novoAnime;
		ultimo = novoAnime;
		
		tamanhoLista++;
	}
}

// sobrescreve um anime na posição desejada
void listaDupla::sobrescreveAnimePosicaoDesejada(int posicaoDesejada, anime dados){
	noh* anime = primeiro;
	
	while(anime->categorias.numeracao != posicaoDesejada){
		anime = anime->proximo;
	}
	anime->categorias = dados;
}

void listaDupla::removeAnimeInicio(){
	if(listaVazia()){
		cout << "Erro, impossivel remover em uma lista vazia\n";
	}else{
	if(tamanhoLista == 1){
		// existe apenas 1 anime na lista -> deixar lista vazia
		primeiro 		= nullptr;
		ultimo 			= nullptr;
		tamanhoLista	= 0;
	}else{
		noh* anime = primeiro;
		primeiro = primeiro->proximo;
		primeiro->anterior = nullptr;

		delete anime;
		tamanhoLista--;
		}
	}
}

// remove anime no fim da lista
void listaDupla::removeAnimeFim(){
	if(listaVazia()){
		cout << "Erro, impossivel remover em uma lista vazia\n";
	}else{
		if(tamanhoLista==1){
			// existe apenas 1 anime na lista -> deixar lista vazia
			primeiro		= nullptr;
			ultimo 			= nullptr;
			tamanhoLista 	= 0;

		}else{
			noh* anime = ultimo;
			ultimo = ultimo->anterior;
			ultimo->proximo = nullptr;

			delete anime;
			tamanhoLista--;
		}
	}
}

// remove anime em uma posição desejada
void listaDupla::removeAnimePosicaoDesejada(int posicaoDesejada){
	if(listaVazia()){
		cout << "Erro: Catalogo vazio\nRetornando ao comeco do codigo\n";
	}else{
		noh* anime = primeiro;
		int posicaoAnime = 0;

		// encontrar a posição do anime selecionado
		while((posicaoAnime != posicaoDesejada) and (anime != nullptr)){
			anime = anime->proximo;
			posicaoAnime++;
		}

		// remover anime, caso posição seja válida
		if(anime != nullptr){
			if(posicaoDesejada == 0){
				removeAnimeInicio();
			}else if(posicaoDesejada == tamanhoLista){
				removeAnimeFim();
			}else{
				anime = primeiro;
				posicaoAnime = 0;
				while(posicaoAnime != posicaoDesejada){
					anime->anterior = anime;
					anime = anime->proximo;
					posicaoAnime++;
				}
				anime->anterior->proximo = anime->proximo;
				ultimo->proximo = NULL;

				delete anime;
				tamanhoLista--;
			}
		}
	}
}

// função para remover anime
void listaDupla::removeAnime(int opcao, int numeracaoDesejada, string nomeDesejado){
	noh* anime = primeiro;
	int posicaoAnime = 0;
	switch(opcao){
		case 1:{ // remove por nome
			while(anime != nullptr and anime->categorias.nomeAnime != nomeDesejado){
				anime = anime->proximo;
				posicaoAnime++;
			}
			if(anime == nullptr){
				cout << "Erro: anime com nome desejado nao encontrado no catalogo\nRetornando ao comeco do codigo\n";
			}else{
				imprimeAnime(anime);

				cout << "Deseja mesmo remover?\n";
				cout << "1)Sim\n2)Nao\n";
				cout << "Resposta(1 ou 2): ";

				int respostaSalvarRemocaoNome;
				cin >> respostaSalvarRemocaoNome;
				
				switch(respostaSalvarRemocaoNome){
					case 1:{ // salvar na lista e .csv
						removeAnimePosicaoDesejada(posicaoAnime);
						cout << "\nAnime removido com sucesso do catalogo\nRetornando ao comeco do codigo\n";
						salvarArquivo();
						break;
					}
					case 2:{ //nao salvar
						cout << "Anime acima nao removido do catalogo\nRetornando ao comeco do codigo\n";
						break;
					}
					default:{
						cout << "Erro: resposta fora do intervalo, retornando ao comeco do codigo\n";
						break;
					}
				}
			}
			break;
		}
		case 2:{ // remove por numeração do anime
			while(anime->categorias.numeracao != numeracaoDesejada){
				anime = anime->proximo;
				posicaoAnime++;
			}
			if(anime == nullptr){
				cout << "Erro: anime com nome desejado nao encontrado no catalogo\nRetornando ao comeco do codigo\n";
			}else{
				imprimeAnime(anime);
					
				cout << "Deseja mesmo remover?\n";
				cout << "1)Sim\n2)Nao\n";
				cout << "Resposta(1 ou 2): ";

				int respostaSalvarRemocaoNome;
				cin >> respostaSalvarRemocaoNome;
				
				switch(respostaSalvarRemocaoNome){
					case 1:{// salvar na lista e .csv
						removeAnimePosicaoDesejada(posicaoAnime);
						cout << "\nAnime Removido com sucesso do catalogo\nRetornando ao comeco do codigo\n";
						salvarArquivo();
						break;
					}
					case 2:{//nao salvar
						cout << "Anime acima nao removido do catalogo\nRetornando ao comeco do codigo\n";
						break;
					}
					default:{
						cout << "Erro: resposta fora do intervalo, retornando ao comeco do codigo\n";
						break;
					}
				}
			}
			break;
		}
	}
}

void listaDupla::imprimeCatalogo(){
	noh* anime = primeiro;
	while(anime != NULL){
		imprimeAnime(anime);
		anime = anime->proximo;
	}
}

void listaDupla::imprimeAnime(noh* anime){
	cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << anime->categorias.numeracao << " - " << anime->categorias.nomeAnime << endl;

	cout << "- Temporadas: " 		<< anime->categorias.numTemporadas		<< endl;
	cout << "- Episodios: "			<< anime->categorias.numEpisodios 		<< endl;
	cout << "- Lancamento: " 		<< anime->categorias.anoLancamento 		<< endl;
	cout << "- Finalizacao: " 		<< anime->categorias.anoFinalizacao 	<< endl;
	cout << "- GeneroPrincipal: " 	<< anime->categorias.generoPrincipal 	<< endl;
	cout << "- Status: " 			<< anime->categorias.status 			<< endl;
	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
}

void listaDupla::imprimeIntervaloCatalogo(int inicio, int fim){
	
	noh*animeInicio = primeiro;
	int posicaoAnimeInicio = 0;
		
	noh* animeFim = primeiro;
	int posicaoAnimeFim = 0;
	
	// encontrar o anime do inicio do intervalo
	while(posicaoAnimeInicio != inicio){
		animeInicio = animeInicio->proximo;
		posicaoAnimeInicio++;
	}
	
	// encontrar o anime do fim do intervalo
	while(posicaoAnimeFim != fim){
		animeFim = animeFim->proximo;
		posicaoAnimeFim++;
	}
	
	// imprime animes dentro do intervalo
	while(animeInicio != animeFim){
		imprimeAnime(animeInicio);
		animeInicio = animeInicio->proximo;
	}
}

// procura e imprime anime pelo nome selecionado
void listaDupla::procuraAnimeNome(string nomeDesejado){
	noh* anime = primeiro;
	
	// procura anime com o nome selecioado
	while(anime != nullptr and anime->categorias.nomeAnime != nomeDesejado){
		anime = anime->proximo;
	}
	if(anime == nullptr){
		cout << "\nErro: anime nao se encontra na lista, tente digitar de outra forma\n";
	}else{
		// imprime o anime
		cout << "\nAnime encontrado na posicao " << anime->categorias.numeracao << " do catalogo\n";
		imprimeAnime(anime); 
	}
}

// procura e imprime anime pelo status selecionado
void listaDupla::procuraAnimeStatus(int statusSelecionado){
	string statusDesejado;
	if(statusSelecionado == 1){
		statusDesejado = "Em Andamento";
	}else{
		statusDesejado = "Finalizado";
	}
			
	noh* anime = primeiro;
	while(anime != nullptr){
		if(anime->categorias.status == statusDesejado){
			imprimeAnime(anime);
		}
		anime = anime->proximo;
	}
}

// procura e imprime anime pelo ano selecionado
void listaDupla::procuraAnimeAno(int opcao,int anoDesejado){
	noh* anime = primeiro;
	int quantidade = 0;
	switch(opcao){
		case 1:{ // ano de lancamento
			while(anime != nullptr){
				if(anime->categorias.anoLancamento == anoDesejado){
					imprimeAnime(anime);
					quantidade++;
				}
				anime = anime->proximo;
			}
			if(quantidade == 0){
				cout << "\nErro: Nenhum anime com o ano de lancamento desejado esta cadastrado no catalogo";
				cout << "\nRetornando ao comeco do codigo\n";
			}
			break;
		}
		case 2:{ // ano de finalizacao
			while(anime != nullptr){
				if(anime->categorias.anoFinalizacao == anoDesejado){
					imprimeAnime(anime);
					quantidade++;
				}
				anime = anime->proximo;
			}
			if(quantidade == 0){
				cout << "\nErro: Nenhum anime com o ano de lancamento desejado esta cadastrado no catalogo";
				cout << "\nRetornando ao comeco do codigo\n";
			}
			break;
		}
		default:{
			cout << "\nErro: opcao fora do intervalo valido";
			cout << "\n Retornando ao comeco do codigo\n";
			break;
		}
	}
}

// procura e imprime anime pelo número de temporadas selecionado
void listaDupla::procuraAnimePorNumTemp(int numTempDesejado){
	noh* anime = primeiro;
	int quantidade = 0;
	
	while(anime != nullptr){
		if(anime->categorias.numTemporadas == numTempDesejado){
			imprimeAnime(anime);
			quantidade++;
		}else{
			anime = anime->proximo;
		}
	}
	if(quantidade == 0){
		cout << "\nErro: Nenhum anime com o Numero de Temporadas desejado esta cadastrado no catalogo";
		cout << "\nRetornando ao comeco do codiggo\n";
	}
}

// procura e imprime anime pelo gênero selecionado
void listaDupla::imprimeCatalogoPorGenero(string generoDesejado){
	noh* anime = primeiro;
	int quantidade = 0;
	
	while(anime != nullptr){
		if(anime->categorias.generoPrincipal == generoDesejado){
			imprimeAnime(anime);
			quantidade++;
		}
		anime = anime->proximo;
	}
	if(quantidade == 0){
		cout << "\nErro: nenhum anime com o genero desejado foi encontrado na tabela, tente escrever de uma outra forma ou procurar outro genero\n";
	}
	
}

// preenche atributos de um objeto
void listaDupla::preencherVetor(anime catalogo[]){
	noh* temp = primeiro;
	for(int i=0; i<tamanhoLista ; i++){
		catalogo[i] = temp->categorias;
		temp = temp->proximo;
	}
}

// retorna o menor valor de uma categoria de um anime
int listaDupla::menores(int opcao){
	noh* anime = primeiro;
	int menor;

	switch(opcao){
		case 1:{ // ano lancamento
			menor = anime->categorias.anoLancamento;
			while(anime != nullptr){
				if(anime->categorias.anoLancamento < menor){
					menor = anime->categorias.anoLancamento;
				}
				anime = anime->proximo;
			}
			break;
		}
		case 2:{ // ano finalizacao
			menor = anime->categorias.anoFinalizacao;
			while(anime != nullptr){
				if((anime->categorias.anoFinalizacao < menor) and (anime->categorias.anoFinalizacao != 0)){
					menor = anime->categorias.anoFinalizacao;
				}
				anime = anime->proximo;
			}
			break;
		}
		case 3:{ // número temporadas
			menor = anime->categorias.numTemporadas;
			while(anime != nullptr){
				if(anime->categorias.numTemporadas < menor){
					menor = anime->categorias.numTemporadas;
				}
				anime = anime->proximo;
			}
			break;
		}
	}
		return menor;
}

// retorna o maior valor de uma categoria de um anime
int listaDupla::maiores(int opcao){
	noh* anime;
	int maior;
	
	switch(opcao){
		case 1:{ // ano lançamento
			anime = primeiro;
			maior = anime->categorias.anoLancamento;
			while(anime != nullptr){
				if(anime->categorias.anoLancamento > maior){
					maior = anime->categorias.anoLancamento;
				}
				anime = anime->proximo;
			}
			break;
		}
		case 2:{ // ano finalização
			anime = primeiro;
			maior = anime->categorias.anoFinalizacao;
			while(anime != nullptr){
				if(anime->categorias.anoFinalizacao > maior){
					maior = anime->categorias.anoFinalizacao;
				}
				anime = anime->proximo;
			}
			break;
		}
		case 3:{ // número temporadas
			anime = primeiro;
			maior = anime->categorias.numTemporadas;
			while(anime != nullptr){
				if(anime->categorias.numTemporadas > maior){
					maior = anime->categorias.numTemporadas;
				}
				anime = anime->proximo;
			}
			break;
		}
	}
		return maior;
}

// salva alterações na lista no arquivo .csv	
void listaDupla::salvarArquivo(){
	noh* anime = primeiro;
	int posicao = 1;
	ofstream saida ("Catalogo.csv");
	
	saida << "# Numeracao Nome Número_Temporadas Número_Episódios Ano_Lançamento Ano_Finalização Gênero_Principal Status" << endl;
	saida << "OBS:(anoFinalizacao=0 sera quando o anime ainda nao estiver finalizado)" << endl;
	
	while(anime != nullptr){
		saida << posicao << ";";
		saida << '"' << anime->categorias.nomeAnime << '"' << ";";

		saida << anime->categorias.numTemporadas << ";";
		saida << anime->categorias.numEpisodios << ";";
		saida << anime->categorias.anoLancamento << ";";
		saida << anime->categorias.anoFinalizacao << ";";

		saida << '"' << anime->categorias.generoPrincipal << '"' << ";";
		saida << '"' << anime->categorias.status << '"';

		saida << endl;
		anime = anime->proximo;
		posicao++;
	}
}

void trocarValores(anime &elemento1, anime &elemento2);
int quickSortPartição(anime animes[], int menor, int maior, string objeto);
void quickSort(anime animes[], int menor, int maior, string categoria);
void mensagemErro();
void menu_ptbr();
void erro_Variavel(int tipoVariavel);
void carregaDados(anime& i, string arquivoCSV, listaDupla& lista, int& tam);


int main(){
	listaDupla listaPrincipal;
	anime categorias;

	int tamanho = 0;
	string arquivoCSV = "Catalogo.csv";

	carregaDados(categorias, arquivoCSV, listaPrincipal, tamanho);

	int resposta;

	do{
		menu_ptbr();
		
		cin >> resposta;
		if(cin.fail()){
			erro_Variavel(1);
		}else{
			switch(resposta){
				case 1:{ // intervalo
					cout << "\n1)Alfabetica\n2)Ultimos lancamentos\n3)Genero\n4)Sem Filtro\n";
					cout << "Resposta(1, 2, 3 ou 4): ";

					int respostaIntervalo;
					cin >> respostaIntervalo;
					if(cin.fail()){
						erro_Variavel(1);
					}else{
						if(respostaIntervalo <= 0 or respostaIntervalo > 4){
							mensagemErro();
						}else{
							listaDupla listaAux;
							anime *vetorOrdenacao = new anime[tamanho];
					
							listaPrincipal.preencherVetor(vetorOrdenacao);

							switch(respostaIntervalo){
								case 1:{ // alfabética
									quickSort(vetorOrdenacao, 0 , tamanho-2, "nome");
									for (int i = 0; i < tamanho-1; i++){
										listaAux.insereAnimeFim(vetorOrdenacao[i]);
									}
									cout << "\nCatalogo ordenado por ordem alfabetica\n";

									break;
								}
								case 2:{ // últimos lancamentos
									quickSort(vetorOrdenacao, 0, tamanho-2, "lancamento");
									for(int i=0; i< tamanho-1 ; i++){
										listaAux.insereAnimeFim(vetorOrdenacao[i]);
									}
									cout << "\nCatalogo ordenado por ultimos lancamentos\n";

									break;
								}
								case 3:{ // gênero
									quickSort(vetorOrdenacao, 0, tamanho-2, "genero");
									for(int i=0; i<tamanho-1; i++){
										listaAux.insereAnimeFim(vetorOrdenacao[i]);
									}
									cout << "\nCatalogo ordenado por genero\n";

									break;
								}
								case 4:{ // Apenas imprimir
									int respostaIntervaloSemFiltro;
									cout << "\nCatalogo nao ordenado por escolha do usuario\n";
									cout << "1)Todo o catalogo sem filtro\n2)Intervalo do catalogo sem filtro\n";
									cout << "Resposta(1 ou 2): ";
									
									cin >> respostaIntervaloSemFiltro;
									if(cin.fail()){
										erro_Variavel(1);
									}else{
										switch(respostaIntervaloSemFiltro){
											case 1:{ // todo o catálogo
												listaPrincipal.imprimeCatalogo();
												break;
											}
											case 2:{ // apenas intervalo
												int comecoIntervalo;
												int fimIntervalo;
												
												cout << "Intervalo(Minimo = 1 e Maximo = " << tamanho-1 << ")\n";
								
												cout << "Inicio: ";
												cin >> comecoIntervalo;
												if(cin.fail()){
													erro_Variavel(1);
												}else{
													cout << "Fim: ";
													cin >> fimIntervalo;
													if(cin.fail()){
														erro_Variavel(1);
													}else{
														if((comecoIntervalo < 0) or (comecoIntervalo >= tamanho) or (fimIntervalo < comecoIntervalo) or (fimIntervalo >= tamanho)){
															mensagemErro();
														}else{
															listaPrincipal.imprimeIntervaloCatalogo(comecoIntervalo-1, fimIntervalo);
														}
													}
												}
												break;
											}
											default:{
												mensagemErro();
												
												break;
											}
										}
									}
									break;
								}
							delete[] vetorOrdenacao;
							}	
							if(respostaIntervalo != 4){ 
								// será utilizada uma lista auxiliar para a impressão
								// lista auxiliar -> facilitar a filtragem do catálogo
								cout << "\n1)Imprimir todo o catalogo \n2)Imprimir um intervalo determinado\n";
								cout << "Resposta: ";

								int respostaImprimir;
								cin >> respostaImprimir;
								if(cin.fail()){
									erro_Variavel(1);
								}else{
									switch(respostaImprimir){
										case 1:{ // imprimir todo catálogo
											listaAux.imprimeCatalogo();
											break;
										}
										case 2:{ // imprime intervalo catálogo
											int comecoIntervalo;
											int fimIntervalo;
											cout << "Intervalo(Minimo = 1 e Maximo = " << tamanho-1 << ")\n";
							
											cout << "Inicio: ";
											cin >> comecoIntervalo;
							
											cout << "Fim: ";
											cin >> fimIntervalo;
							
											if((comecoIntervalo < 0) or (comecoIntervalo >= tamanho) or (fimIntervalo < comecoIntervalo) or (fimIntervalo >= tamanho)){
												mensagemErro();
											}else if(comecoIntervalo == fimIntervalo){							//imprimir somente 1 posicao
												listaAux.imprimeIntervaloCatalogo(comecoIntervalo-1, fimIntervalo);
											}else{
												listaAux.imprimeIntervaloCatalogo(comecoIntervalo-1,fimIntervalo);
											}
											break;
										}
										default:{
											mensagemErro();
											break;
										}
									}
								}
							}
						}
					}	
					break;
				}
				case 2:{ // filtrar
					cout << "\n1)Nome\n2)Ano de Lancamento\n3)Ano de Finalizacao\n4)Genero\n5)Numero de Temporadas\n6)Status\n";
					cout << "Resposta(1, 2, 3, 4, 5 ou 6 ): "; 

					int respostaFiltrar;
					cin >> respostaFiltrar;
					
					switch(respostaFiltrar){
						case 1:{ // nome
							cout << "\nNome: ";
							cin.ignore();
							getline(cin, categorias.nomeAnime);
							
							listaPrincipal.procuraAnimeNome(categorias.nomeAnime);
							
							break;
							}
						case 2:{ // ano de lancamento
							cout << "\nAno de lancamento\n";
							int menorAnoLancamento = listaPrincipal.menores(1);
							int maiorAnoLancamento = listaPrincipal.maiores(1);
							
							cout << "Minimo = " << menorAnoLancamento << " Maior = " << maiorAnoLancamento << endl;
							cout << "Resposta: ";
							
							cin >> categorias.anoLancamento;
							if(cin.fail()){
								erro_Variavel(1);
							}else{
								if((categorias.anoLancamento <= maiorAnoLancamento) and (categorias.anoLancamento > 0)){
									listaPrincipal.procuraAnimeAno(1, categorias.anoLancamento);
								}else{
									mensagemErro();
								}
							}
							break;
						}
						case 3:{ // ano de finalizacao
							cout << "\nAno de finalizacao:\n";
							int menorAnoFinalizacao = listaPrincipal.menores(2);
							int maiorAnoFinalizacao = listaPrincipal.maiores(2);
							cout << "(Minimo = (0 se em andamento) ou " << menorAnoFinalizacao << " | Maior = " << maiorAnoFinalizacao << ")" << endl;
							cout << "Resposta: ";
							
							cin >> categorias.anoFinalizacao;
							if(cin.fail()){
								erro_Variavel(1);
							}else{
								if((categorias.anoFinalizacao <= maiorAnoFinalizacao) and(categorias.anoFinalizacao >=0)){
									listaPrincipal.procuraAnimeAno(2, categorias.anoFinalizacao);
								}else{
									mensagemErro();
								}
							}
							break;
						}
						case 4:{ // gênero
							cout << "\nGenero: ";
							
							cin.ignore();
							getline(cin,categorias.generoPrincipal);
							
							listaPrincipal.imprimeCatalogoPorGenero(categorias.generoPrincipal);
							
							break;
						}
						case 5:{ // número temporadas
							cout << "\nNumero de temporadas\n";
							int menorNumTemp = listaPrincipal.menores(3);
							int maiorNumTemp = listaPrincipal.maiores(3);
							cout << "Minimo = " << menorNumTemp << " Maior = " << maiorNumTemp << endl;
							
							int respostaTemporadas;
							cin >> respostaTemporadas;
							if(cin.fail()){
								erro_Variavel(1);
							}else{
								cout << "Numero de Temporadas: ";
								
								cin >> categorias.numTemporadas;
								if(cin.fail()){
									erro_Variavel(1);
								}else{
									listaPrincipal.procuraAnimePorNumTemp(categorias.numTemporadas);
								}
							}
							break;
						}
						case 6:{ // status
							cout << "\n1)Em Andamento\n2)Finalizado\n";
							cout << "Resposta(1 ou 2): ";

							int respostaStatus;
							cin >> respostaStatus;
							if(cin.fail()){
								erro_Variavel(1);
							}else{
								if(respostaStatus == 1 or respostaStatus == 2){
									listaPrincipal.procuraAnimeStatus(respostaStatus);
								}else{
									mensagemErro();
								}
							}
							break;
						}
						default:{
							mensagemErro();
							break;
						}
					}
					break;
				}
				case 3:{  // escrever / sobrescrever
					int respostaMudanca;
					cout << "\n1)Escrever \n2)Sobrescrever\n";
					cout << "Resposta(1 ou 2): ";

					cin >> respostaMudanca;
					if(cin.fail()){
						erro_Variavel(1);
					}else{
						switch(respostaMudanca){
							case 1:{ // escrever
								cout << "\nQuantos novos animes deseja escrever?\n";
								cout << "Resposta: ";

								int respostaEscrever;
								cin >> respostaEscrever;
								if(cin.fail()){
									erro_Variavel(1);
								}else{
									if(respostaEscrever < 0){
									mensagemErro();
									}else{
										for(int i = 0; i < respostaEscrever; i++){
											cout << "\nEscreva os dados do "<< i+1 <<"o anime(ate o momento da insercao): \n";;
											categorias.numeracao = tamanho+i+2;

											cout << "Nome:";
											cin.ignore();
											getline(cin, categorias.nomeAnime);

											cout <<"Temporadas: ";
											cin >> categorias.numTemporadas;

											cout << "Episodios: ";
											cin >> categorias.numEpisodios;

											cout << "Ano de Lancamento: ";
											cin >> categorias.anoLancamento;

											cout << "Ano de Finalizacao(=0 se Em Andamento): ";
											cin >> categorias.anoFinalizacao;

											cout << "Genero Principal: ";
											cin.ignore();
											getline(cin, categorias.generoPrincipal);
											
											if(categorias.anoFinalizacao == 0){
												categorias.status = "Em Andamento";
											}else{
												categorias.status = "Finalizado";
											}

											cout << "\nDeseja salvar as alteracoes?\n";
											cout << "1)Sim\n2)Nao\n";
											cout << "Resposta(1 ou 2): ";

											int respostaAlteracoes;
											cin >> respostaAlteracoes;
											if(cin.fail()){
												erro_Variavel(1);
											}else{
												switch(respostaAlteracoes){
													case 1:{ // Salvar
														listaPrincipal.insereAnimeFim(categorias);
														tamanho++;
														
														listaPrincipal.salvarArquivo();
														cout << "Anime " << i+1 << " inserido\n";          
														break;
													}
													case 2:{ // não Salvar
														cout << "\nResposta nao salva\n";
														break;
													}
													default:{
														mensagemErro();
														break;
													}
												}
											}
										}
									}
								}
								break;
							}  
							case 2:{ // sobrescrever	
								cout << "Qual posicao sera sobrescrevida?\n";
								cout << "Minimo = 1 | Maximo = " << tamanho-1 << endl;
								cout << "Resposta: ";

								int posicaoDesejada;
								cin >> posicaoDesejada;
								if(cin.fail()){
										erro_Variavel(1);
								}else{
									if((posicaoDesejada >= 1) and (posicaoDesejada < tamanho)){
										cout << "Insira os dados do anime(ate o momento da insercao):\n";
											
										categorias.numeracao = tamanho+2;
			
										cout << "Nome:";
										cin.ignore();
										getline(cin, categorias.nomeAnime);
			
										cout <<"Temporadas: ";
										cin >> categorias.numTemporadas;
										
										if(cin.fail()){
											erro_Variavel(1);
										}else{
											cout << "Episodios: ";
											cin >> categorias.numEpisodios;
											
											if(cin.fail()){
												erro_Variavel(1);
											}else{
												cout << "Ano de Lancamento: ";
												cin >> categorias.anoLancamento;
												
												if(cin.fail()){
													erro_Variavel(1);
												}else{
													cout << "Ano de Finalizacao(=0 se Em Andamento): ";
													cin >> categorias.anoFinalizacao;
													
													if(cin.fail()){
														erro_Variavel(1);
													}else{
														cout << "Genero Principal: ";
														cin.ignore();
														getline(cin, categorias.generoPrincipal);
														
														if(categorias.anoFinalizacao == 0){
															categorias.status = "Em Andamento";
														}else{
															categorias.status = "Finalizado";
														}
														int respostaSalvar;
														
														cout << "\nSalvar as alteracoes?\n";
														cout << "1)Sim \n2)Nao\n";
														cout << "Resposta(1 ou 2): ";
															
														cin >> respostaSalvar;
														if(cin.fail()){
															erro_Variavel(1);
														}else{
															if(respostaSalvar== 1){ // salvar na lista e .csv
															listaPrincipal.sobrescreveAnimePosicaoDesejada(posicaoDesejada, categorias);
																
															listaPrincipal.salvarArquivo();
															cout << "\nAnime sobrescrito na posicao " << posicaoDesejada << " do catalogo\n";
																
															}else if(respostaSalvar==2){ // não salvar
																cout << "\nResposta nao salva\nRetornando ao comeco do codigo\n";
															}else{
																mensagemErro();
															}
														}
													}
												}
											}	
										}
									}else{
										mensagemErro();
									}
								}
								break;
							}
							default:{
								mensagemErro();
								break;
							}
						}
					}
					break;
				}
				case 4:{ // remover anime
					cout << "Remover:\n";
					cout << "1)Nome \n2)Numeracao\n";
					cout << "Resposta(1 ou 2): ";

					int respostaRemover;
					cin >> respostaRemover;
					if(cin.fail()){
						erro_Variavel(1);
					}else{
						switch(respostaRemover){
							case 1:{ // remover anime pelo nome do próprio
								cout << "Nome: ";
								cin.ignore();
								getline(cin, categorias.nomeAnime);
								categorias.numeracao = 1;
								
								listaPrincipal.removeAnime(1, categorias.numeracao, categorias.nomeAnime);
								break;
								}
							case 2:{ // remover anime pela numeração no catálogo
								cout << "Numeracao: ";
								cin >> categorias.numeracao;
								if(cin.fail()){
									erro_Variavel(1);
								}else{
									if((categorias.numeracao <= tamanho) and (categorias.numeracao > 0)){
										categorias.nomeAnime = "a"; // nome padrão 
										listaPrincipal.removeAnime(2, categorias.numeracao, categorias.nomeAnime);
									}else{
										cout << "\nErro: numeracao fora do intervalo do catalogo, retornando ao comeco do codigo\n";
									}
								}
								break;
							}
							default:{
								mensagemErro();
								break;
							}
						}
					}
					break;
				}
				case 5:{ // encerrar programa
					cout << "\nPrograma Finalizado\n";
					break;
				}
				default:{
					mensagemErro();
					break;
				}
			} 
		}

	}while(resposta!= 5);
	return 0;
}

// Mensagem de erro genérica
void mensagemErro(){
	cout << "\nErro: resposta FORA do intervalo permitido\n";
	cout << "Retornando ao comeco do codigo\n";
}

// interface em Português Brasil
void menu_ptbr(){
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << "|\n|				<CATALOGO DE ANIMES>\n";
	cout << "|\n|1) Mostrar um Intervalo de animes" << endl;
	cout << "|2) Buscar animes por algum filtro" << endl;
	cout << "|3) Escrever/Sobrescrever dados" << endl;
	cout << "|4) Remover Dados" << endl;
	cout << "|5) Encerrar o Programa\n|";
	cout << endl << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	cout << "-> Resposta (1 ate 5): ";
}

// função para retornar uma mensagem de erro para quando o usuário digitar o valor de uma variável sendo diferente do requerido pelo programa
void erro_Variavel(int tipoVariavel){
	cin.clear();
	cin.ignore(10000, '\n');

	cout << "\nErro: Tipo de variavel escrito invalido -> CORRETO: ";
	switch(tipoVariavel){
		case 1:{
			cout << "'INT'\n";
			break;
		}
		case 2:{
			cout << "'STRING'\n";
			break;
		}
		case 3:{
			cout << "'BOOL'\n";
			break;
		}
	}
	cout << endl;
}

// Função para trocar dois elementos de posição
void trocarValores(anime &elemento1, anime &elemento2){
	anime listaTroca = elemento1;
	elemento1 = elemento2;
	elemento2 = listaTroca;
}

// partição da função de ordernar a lista
int quickSortPartição(anime animes[], int menor, int maior, string objeto){
	string valorSelecionado;
	if(objeto == "generoPrincipal"){
		valorSelecionado = animes[maior].generoPrincipal;
	}else if(objeto == "anoLancamento"){
		valorSelecionado = animes[maior].anoLancamento;
	}else{
		valorSelecionado = animes[maior].nomeAnime;
	}

	int i = menor - 1;
	for (int j = menor; j <= maior - 1; j++) {
        string atual;
        if (objeto == "generoPrincipal"){
            atual = animes[j].generoPrincipal;
		}else if (objeto == "anoLancamento"){
            atual = to_string(animes[j].anoLancamento);
		}else{
            atual = animes[j].nomeAnime;
		}
        if (atual < valorSelecionado) {
            i++;
            trocarValores(animes[i], animes[j]);
        }
    }
	trocarValores(animes[i + 1], animes[maior]);
	return (i + 1);
}

// função para ordernar a lista baseando-se em uma categoria
void quickSort(anime animes[], int menor, int maior, string categoria){
	if(categoria == "genero" or categoria == "lancamento" or categoria == "nome"){
		if (menor < maior){
			int pivo;
			if(categoria == "genero"){
				pivo = quickSortPartição(animes, menor, maior, "generoPrincipal");
			}else if(categoria == "lancamento"){
				pivo = quickSortPartição(animes, menor, maior, "anoLancamento");
			}else{
				pivo = quickSortPartição(animes, menor, maior, "nomeAnime");
			}
			quickSort(animes, menor, pivo - 1, categoria);
			quickSort(animes, pivo + 1, maior, categoria);
		}		
	}else{
		cout << "Erro: Nenhuma categoria válida foi selecionada" << endl;
	}
}

void carregaDados(anime& i, string arquivoCSV, listaDupla& lista, int& tam){
	// função para recuperar os dados armazenados no arquivo .csv
	ifstream entrada(arquivoCSV);

	if(entrada){
		string linha;

		// descartar as 2 linhas de introdução
		getline(entrada, linha);
		getline(entrada, linha);

	}else{
		cout << "\nErro: Nao foi possivel abrir o arquivo\n ";
	}

	while(entrada){
		string lixo;

		entrada >> i.numeracao;
		entrada.ignore(1, ';');
		getline(entrada, lixo , '"');
		getline(entrada, i.nomeAnime, '"');
		
		entrada.ignore(1, ';');
		entrada >>i.numTemporadas;
		entrada.ignore(1, ';');

		entrada >> i.numEpisodios;
		entrada.ignore(1, ';');

		entrada >> i.anoLancamento;
		entrada.ignore(1, ';');

		entrada >> i.anoFinalizacao;
		entrada.ignore(1, ';');

		getline(entrada, lixo, '"');
		getline(entrada, i.generoPrincipal , '"');
		entrada.ignore(1, ';');
		
		getline(entrada, lixo, '"');
		getline(entrada, i.status , '"');

		tam++;
		lista.insereAnimeFim(i);
	}
	
		lista.removeAnimeFim(); // erro
	}
