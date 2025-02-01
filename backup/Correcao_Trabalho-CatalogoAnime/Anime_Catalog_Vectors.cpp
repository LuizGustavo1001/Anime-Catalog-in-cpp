//Grupo: João Pedro Oliveira de Jesus Machado, Miguel Adriano Braga, Luiz Gustavo De Almeida Lopes
//Tema CATALOGO DE ANIMES

#include <iostream>
#include <fstream>
using namespace std;

struct Catalogo{
	int numeracao;
	string nome;
	int numTemporadas;
	int numEpisodios;
	int anoLancamento;
	int anoFinalizacao;
	string generoPrincipal;
	string status;
};

// Função para busca binária pelo nome do anime
int buscaBinariaNome(Catalogo vet[], int tamanho, string nomeDesejado){
	int menor = 0;
	int maior = tamanho-1;

	while (menor <= maior) {
		int media = menor + (maior - menor) / 2;
		// Verifica se o nome do meio é igual ao nome buscado
		if (vet[media].nome == nomeDesejado){
			return media;
			menor = maior+1;
			}
		// Se o nome no meio for menor, ignora a metade esquerda
		if (vet[media].nome < nomeDesejado){
			menor = media + 1;
			}
		// Se o nome no meio for maior, ignora a metade direita
		else{
			maior = media - 1;
			}
		}
	// Retorna -1 se o nome não for encontrado
	return -1;
}

void imprimirAnime(int pos, Catalogo v[]){
	cout << endl << v[pos].numeracao << "-> ";
	cout << "Anime: " << v[pos].nome << "; ";
	cout << "Temporadas: " << v[pos].numTemporadas << "; ";
	cout << "Episodios: " << v[pos].numEpisodios << "; ";
	cout << "Lancamento: " << v[pos].anoLancamento << "; ";
	cout << "Finalizacao: " << v[pos].anoFinalizacao << "; ";
	cout << "Genero: " << v[pos].generoPrincipal << "; ";
	cout << "O anime esta " << v[pos].status << endl;
}

// Função para busca binária pelo ano de lançamento do anime
void buscaBinariaAno(Catalogo vet[], int tamanho, int anoBusca) {
	int menor = 0;
	int maior = tamanho - 1;
	int cont = 0;

	while (menor <= maior) {
		int media = menor + (maior - menor) / 2;

		// Verifica se o ano de lançamento no meio é igual ao ano buscado
		if (vet[media].anoLancamento == anoBusca) {
			// Encontra todos os animes com o mesmo ano de lançamento
			int esquerda = media;
			int direita = media;
	
			// Expande para a esquerda
			while (esquerda >= 0 && vet[esquerda].anoLancamento == anoBusca) {
				cont++;
				imprimirAnime(esquerda, vet);
				esquerda--;
				}

			// Expande para a direita
			while (direita < tamanho && vet[direita].anoLancamento == anoBusca) {
				if (direita != media) {  // Evita duplicar a impressão do elemento central
					cont++;
					imprimirAnime(direita,vet);
					}
					direita++;
					}
					return;  // Sai da função após encontrar e exibir todos os animes com o ano buscado
				}

		// Se o ano no meio for maior, ignora a metade direita (já que é decrescente)
		if (vet[media].anoLancamento > anoBusca) {
			menor = media + 1;
			}
		// Se o ano no meio for menor, ignora a metade esquerda
		else {
			maior = media - 1;
			}
		}

	if (cont == 0) {
		cout << "Ano nao encontrado!\n";
		}
}

// Função para trocar dois elementos
void trocar(Catalogo &a, Catalogo &b){
	Catalogo aux = a;
	a = b;
	b = aux;
}


// Partição do Quick Sort Genero
int particaoGenero(Catalogo vet[], int menor, int maior){
	string aux = vet[maior].generoPrincipal;
	int i = menor - 1;
	for (int j = menor; j <= maior - 1; j++){
		if (vet[j].generoPrincipal < aux){
			i++;
			trocar(vet[i], vet[j]);
			}
		}
		trocar(vet[i + 1], vet[maior]);
		return (i + 1);
}

// Função Quick Sort Genero
void quickSortGenero(Catalogo vet[], int menor, int maior){
	if (menor < maior){
		int pivo = particaoGenero(vet, menor, maior);
		quickSortGenero(vet, menor, pivo - 1);
		quickSortGenero(vet, pivo + 1, maior);
		}
}

// Partição do Quick Sort Nome
int particaoNome(Catalogo vet[], int menor, int maior){
	string aux = vet[maior].nome;
	int i = menor - 1;
	for (int j = menor; j <= maior - 1; j++) {
		if (vet[j].nome < aux) {
			i++;
			trocar(vet[i], vet[j]);
			}
		}
		trocar(vet[i + 1], vet[maior]);
		return (i + 1);
}

// Função Quick Sort Nome
void quickSortNome(Catalogo vet[], int menor, int maior){
	if (menor < maior){
		int pivo = particaoNome(vet, menor, maior);
		quickSortNome(vet, menor, pivo - 1);
		quickSortNome(vet, pivo + 1, maior);
		}
}

// Partição do Quick Sort para ordenar pelo ano de lançamento (decrescente)
int particaoPorAnoLancamento(Catalogo vet[], int menor, int maior){
	int pivo = vet[maior].anoLancamento;  
	int i = menor - 1;

	for (int j = menor; j <= maior - 1; j++) {
		if (vet[j].anoLancamento > pivo) { 
			i++;
			trocar(vet[i], vet[j]);
			}
		}
		trocar(vet[i + 1], vet[maior]);
		return (i + 1);
}

// Função Quick Sort para ordenar pelo ano de lançamento
void quickSortAnoLancamento(Catalogo vet[], int menor, int maior){
	if (menor < maior){
		int pivo = particaoPorAnoLancamento(vet, menor, maior);
		quickSortAnoLancamento(vet, menor, pivo - 1);
		quickSortAnoLancamento(vet, pivo + 1, maior);
		}
}

// Partição do Quick Sort para ordenar pelo numero de temporadas (decrescente)
int particaoPorNumTemp(Catalogo vet[], int menor, int maior){
	int pivo = vet[maior].numTemporadas;  
	int i = menor - 1;

	for (int j = menor; j <= maior - 1; j++) {
		if (vet[j].numTemporadas > pivo){ 
			i++;
			trocar(vet[i], vet[j]);
			}
		}
		trocar(vet[i + 1], vet[maior]);
		return (i + 1);
}

// Função Quick Sort para ordenar pelo numero de temporadas
void quickSortNumTemp(Catalogo vet[], int menor, int maior){
	if (menor < maior){
		int pivo = particaoPorNumTemp(vet, menor, maior);
		quickSortNumTemp(vet, menor, pivo - 1);
		quickSortNumTemp(vet, pivo + 1, maior);
		}
}

// Partição do Quick Sort para ordenar pelo Ano de Finalizacao (decrescente)
int particaoPorAnoFinalizacao(Catalogo vet[], int menor, int maior) {
	int pivo = vet[maior].anoFinalizacao;  
	int i = menor - 1;

	for (int j = menor; j <= maior - 1; j++){
		if (vet[j].anoFinalizacao > pivo){
			i++;
			trocar(vet[i], vet[j]);
			}
		}
		trocar(vet[i + 1], vet[maior]);
		return (i + 1);
}

// Função Quick Sort para ordenar pelo Ano de Finalizacao
void quickSortAnoFinalizacao(Catalogo vet[], int menor, int maior){
	if (menor < maior){
		int pivo = particaoPorAnoFinalizacao(vet, menor, maior);
		quickSortAnoFinalizacao(vet, menor, pivo - 1);
		quickSortAnoFinalizacao(vet, pivo + 1, maior);
		}
}

// Partição do Quick Sort Status
int particaoStatus(Catalogo vet[], int menor, int maior){
	string aux = vet[maior].status;
	int i = menor - 1;
	for (int j = menor; j <= maior - 1; j++){
		if (vet[j].status < aux){
			i++;
			trocar(vet[i], vet[j]);
			}
		}
		trocar(vet[i + 1], vet[maior]);
		return (i + 1);
}

// Função Quick Sort Status
void quickSortStatus(Catalogo vet[], int menor, int maior){
	if (menor < maior) {
		int pivo = particaoStatus(vet, menor, maior);
		quickSortStatus(vet, menor, pivo - 1);
		quickSortStatus(vet, pivo + 1, maior);
		}
}



void procuraGenero(int gen, int tam, Catalogo vet[]){
	switch(gen){
		case 1:{
			for(int i=0; i< tam-1; i++){
				if(vet[i].generoPrincipal == "Acao"){
					imprimirAnime(i, vet);
					}
				}
			
			break;
			}
		case 2:{
			for(int i=0; i< tam-1; i++){
				if(vet[i].generoPrincipal == "Aventura"){
					imprimirAnime(i, vet);
					}
				}
			
			break;
			}
		case 3:{
			for(int i=0; i< tam-1; i++){
				if(vet[i].generoPrincipal == "Comedia"){
					imprimirAnime(i, vet);
					}
				}
			
			break;
			}
		case 4:{
			for(int i=0; i< tam-1; i++){
				if(vet[i].generoPrincipal == "Comida"){
					imprimirAnime(i, vet);
					}
				}
			
			break;
			}
		case 5:{
			for(int i=0; i< tam-1; i++){
				if(vet[i].generoPrincipal == "Corrida"){
					imprimirAnime(i, vet);
					}
				}
			
			break;
			}
		case 6:{
			for(int i=0; i< tam-1; i++){
				if(vet[i].generoPrincipal == "Drama"){
					imprimirAnime(i, vet);
					}
				}
			
			break;
			}
		case 7:{
			for(int i=0; i< tam-1; i++){
				if(vet[i].generoPrincipal == "Esporte"){
					imprimirAnime(i, vet);
					}
				}
			
			break;
			}
		case 8:{
			for(int i=0; i< tam-1; i++){
				if(vet[i].generoPrincipal == "Romance"){
					imprimirAnime(i, vet);
					}
				}
			
			break;
			}
		case 9:{
			for(int i=0; i< tam-1; i++){
				if(vet[i].generoPrincipal == "Slice of Life"){
					imprimirAnime(i, vet);
					}
				}
			
			break;
			}
		case 10:{
			for(int i=0; i< tam-1; i++){
				if(vet[i].generoPrincipal == "Supernatural"){
					imprimirAnime(i, vet);
					}
				}
			
			break;
			}
		case 11:{
			for(int i=0; i< tam-1; i++){
				if(vet[i].generoPrincipal == "Terror"){
					imprimirAnime(i, vet);
					}
				}
			}
		default:{
			cout << "Genero nao listado no catalogo, voltando ao comeco do catalogo\n ";
			break;
			}
		}
	}

int menorNumTemp(Catalogo vet[], int tam){
	int menor= vet[1].numTemporadas;
	for(int i=0; i<tam-1; i++){
		if(vet[i].numTemporadas < menor){
			menor = vet[i].numTemporadas;
		}
}
	return menor;
}


int maiorNumTemp(Catalogo vet[], int tam){
	int maior = vet[1].numTemporadas;
	for(int i=0; i<tam-1; i++){
		if(vet[i].numTemporadas > maior){
			maior = vet[i].numTemporadas;
		}
}	
	return maior;
}

void procuraNumTemp(int nT,int tam, Catalogo vet[]){
	int contador=0;
	for(int i=0; i<tam-1 ; i++){
		if(vet[i].numTemporadas == nT){
			imprimirAnime(i, vet);
			contador++;
			}
		}
		if(contador==0){
			cout << "\n Nenhum anime cadastrado com " << nT << " temporadas\n";
			}
}

int menorAnoFinalizacao(Catalogo vet[], int tam){
	int menor = vet[1].anoFinalizacao;
		for(int i=0; i<tam-1; i++){
			if((vet[i].anoFinalizacao !=0)and(vet[i].anoFinalizacao < menor) ){
				menor = vet[i].anoFinalizacao;
				}
			}	
	return menor;
}

int maiorAnoFinalizacao(Catalogo vet[], int tam){
	int maior = vet[1].anoFinalizacao;
		for(int i=0; i<tam-1; i++){
			if(vet[i].anoFinalizacao > maior){
				maior = vet[i].anoFinalizacao;
				}
			}
	return maior;
}

void procuraAnoFinalizacao(int resp, int tam, Catalogo vet[]){
	int contador=0;
	for(int i=0; i<tam-1; i++){
		if(vet[i].anoFinalizacao == resp){
			imprimirAnime(i, vet);
			contador++;
			}
		}
	if(contador==0){
			cout << "\n Nenhum anime cadastrado com " << resp << " sendo o ano de finalizacao\n";
		}
}

void procuraStatus(int rS, int tam, Catalogo vet[]){
	if(rS == 1 ){ // Em Andamento
		for(int i=0; i<tam-1; i++){
			if(vet[i].status == "Em Andamento"){
				imprimirAnime(i, vet);
				}
			}
		}else{ //Finalizado
			for(int i=0; i<tam-1; i++){
				if(vet[i].status == "Finalizado"){
					imprimirAnime(i, vet);
					}
				}
			}
}


void menu(){
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

void mensagemErro(){

	cout << "Erro: reposta fora do intervalo, retornando ao comeco do codigo\n";
}

int main () {
	int tamanho=40;
	Catalogo *anime = new Catalogo[tamanho];
	
	ifstream entrada ("lista.csv");
	//Preenchendo o "vetor anime" com os dados fornecidos pelo arquivo "lista.csv"
	 if (entrada) {
		string linha;
		getline(entrada, linha); 
		getline(entrada, linha);// Lê e descarta a primeira linha (cabeçalho)
	}
		int contador=0;
		char delimitador = ';';
		char delimitador2= '"';
		string lixo;
		while(entrada && contador < tamanho){
			
			entrada >> anime[contador].numeracao;
			getline(entrada , lixo , delimitador);
			getline(entrada , lixo , delimitador2);
			
			getline(entrada,anime[contador].nome, delimitador2);
			getline(entrada , lixo , delimitador);
		
			entrada >> anime[contador].numTemporadas;
		
			getline(entrada , lixo , delimitador);
			entrada >> anime[contador].numEpisodios;
		
			getline(entrada , lixo , delimitador);
			entrada >> anime[contador].anoLancamento;
		
			getline(entrada , lixo , delimitador);
			entrada >> anime[contador].anoFinalizacao;
		
			getline(entrada , lixo , delimitador);
			getline(entrada , lixo , delimitador2);
			getline(entrada , anime[contador].generoPrincipal , delimitador2);
		
			getline(entrada , lixo , delimitador);
			getline(entrada , lixo , delimitador2);
			getline(entrada , anime[contador].status , delimitador2);
			contador++;
		
			//Se o contador chegar ao tamanho do vetor anime, será necessário redimensionar o vetor anime
			if(contador==tamanho){
				int tamanhoNovo = tamanho+5;
				Catalogo *vetorAux= new Catalogo[tamanhoNovo];
				//Preenchendo o vetorAux com os valores do vetor anime
				for(int i=0; i<tamanho; i++){
					vetorAux[i]=anime[i];
					}
					//direcionar o vetor anime para o vetorAux redimensionado
				delete[] anime;
				anime = vetorAux;
				tamanho = tamanhoNovo;
				}
			}
			tamanho = contador-1; // correção do tamanho
			int respostaMenu;
	
	do{
		menu();
		cin >> respostaMenu;
		switch(respostaMenu){
			case 1:{ //Intervalo de animes
				char respostaOrdenacao;
				
				cout << "Deseja ordenar por:\n";
				cout << "\na)Alfabetica\nl)Ultimos lancamentos\ng)Genero\nz)Nenhum filtro\n";
				cout << "Resposta(a, l, g ou z): ";
				
				cin >> respostaOrdenacao;
				if(respostaOrdenacao == 'a' or respostaOrdenacao == 'l' or respostaOrdenacao == 'g' or respostaOrdenacao == 'z'){
					Catalogo *vetorAux= new Catalogo[tamanho+1];
						//Preenchendo o vetorAux2 com os valores do catalogo
						for(int i=0; i<tamanho; i++){
							vetorAux[i]=anime[i];
							}
							
					switch(respostaOrdenacao){
						case 'a':{ //Nome
							quickSortNome(vetorAux, 0, tamanho - 1);
							cout << "Ordenado por nome com sucesso\n";
							break;
						}
						case 'l':{ // lancamentos
							quickSortAnoLancamento(vetorAux, 0, tamanho - 1);
							cout << "Ordenado por ultimos lancamentos com sucesso\n";
							break;
						}
						case 'g':{
							quickSortGenero(vetorAux, 0, tamanho-1);
							cout << "Ordenado por genero principal com sucesso\n";
							break;
							}
						case 'z':{
							cout << "Catalogo nao ordenado por escolha do usuario\n";
							break;
						}
						default:{
							mensagemErro();
							break;
						}
					}
					char respostaIntervalo;
				
					cout << "\nt) Todo o catalogo\ni) Selecionar o intervalo\n";
					cout << "Resposta(t ou i): "; 
				
					cin >> respostaIntervalo;
				
					if((respostaIntervalo == 't') or (respostaIntervalo == 'i')){
						switch(respostaIntervalo){
						case 't':{ // todo o catalogo
							cout <<" Todo o catalogo: \n";
							for(int i=0; i<tamanho; i++ ){
								imprimirAnime(i,vetorAux);
								}
							break;
						}
						case 'i':{ // intervalo desejado
							int intervaloInicial,intervaloFinal;

							cout  << "Insira o intervalo desejado (2 valores): " << endl;
							cout << "Valor Minimo = 1 e Valor Maximo = " << contador-1 << endl;

							cout << "Inicio: ";
							cin >> intervaloInicial;
							cout << "Fim: ";
							cin >> intervaloFinal;

							if(intervaloInicial!=intervaloFinal and intervaloInicial>=0 and intervaloInicial<contador and intervaloFinal>intervaloInicial and intervaloFinal<contador){
								for(int i=intervaloInicial-1; i<intervaloFinal ;i++){
									imprimirAnime(i,vetorAux);
									}
								}else if(intervaloInicial==intervaloFinal){
									imprimirAnime(intervaloInicial, vetorAux);	
									}else{
										mensagemErro();
									}

						break;
					}
					default:{
						mensagemErro();
						break;
					}
					}
						}
					}else{
						mensagemErro(); 
						}
				break;
			}
			case 2:{ // filtrar
				int respostaFiltro;

				cout << "Filtro:"; 
				cout << "\n1)Nome\n2)Ano de Lancamento\n3)Genero\n4)Numero de Temporadas\n5)Ano de Finalizacao\n6)Status\n";
				cout << "Resposta(1, 2, 3, 4, 5 ou 6 ): ";

				cin >> respostaFiltro;
				
				Catalogo *vetorAux= new Catalogo[tamanho+1];
				//Preenchendo o vetorAux2 com os valores do catalogo
				for(int i=0; i<tamanho; i++){
					vetorAux[i]=anime[i];
					}

				switch(respostaFiltro){
					case 1:{ // Nome
						quickSortNome(vetorAux, 0, tamanho - 1);
						string nomeAnimeDesesjado;
						cout << "Insira o nome do Anime desejado: ";

						cin.ignore();
						getline(cin, nomeAnimeDesesjado);
						
						int posAnimeDesejado;
						posAnimeDesejado = buscaBinariaNome(vetorAux, tamanho, nomeAnimeDesesjado);

						if(posAnimeDesejado != -1){
							imprimirAnime(posAnimeDesejado, vetorAux);
							}else{
							cout << "Erro: nome nao encontrado no catalogo, retornando ao comeco do codigo\n";
								}

						break;
					}
					case 2:{ // ano lancamento 
						quickSortAnoLancamento(vetorAux,0,tamanho-1);
						cout << "Insira o ano de lancamento que desejada: " << endl;
						int anoBusca;
						cin>>anoBusca;
						buscaBinariaAno(vetorAux, tamanho, anoBusca); // imprimir imbutido na busca binaria de ano de lancamento
						break;
					}
					case 3:{ // genero
						quickSortGenero(vetorAux, 0, tamanho-1);
						int generoDesejado;
						
						cout << "1)Acao\n2)Aventura\n3)Comedia\n4)Comida\n5)Corrida\n6)Drama\n7)Esporte\n8)Romance\n9)Slice of Life\n10)Super Natural\n11)Terror\n";
						
						cin >> generoDesejado;
						
						procuraGenero(generoDesejado, tamanho, vetorAux);
						
						break;
						}
					case 4:{ // numero de temporadas 
						quickSortNumTemp(vetorAux, 0, tamanho-1);
						int menor = menorNumTemp(anime, tamanho);
						int maior = maiorNumTemp(anime,tamanho);
						int respostaTemp;

						cout << "Numero de temporadas ";
						cout << "(Menor: " << menor << " e Maior: " << maior << "):" << endl;
						cin >> respostaTemp;
						if((respostaTemp >= menor) and (respostaTemp <= maior)  ){
							procuraNumTemp(respostaTemp, tamanho, anime);
							}else{
								cout << "Erro: numero de temporadas fora do intervalo, retornando ao comeco do codigo\n";
								}
						break;
					}
					case 5:{//ano de finalizacao
						quickSortAnoFinalizacao(vetorAux, 0, tamanho-1);
						int menorFinalizacao = menorAnoFinalizacao(anime,tamanho);
						int maiorFinalizacao = maiorAnoFinalizacao(anime,tamanho);
						int respostaAnoFinalizacao;

						cout << "Ano de finalizacao ";
						cout << "(Menor: " << menorFinalizacao << " e Maior: " << maiorFinalizacao << "):" << endl;
						cin >> respostaAnoFinalizacao;

						if((respostaAnoFinalizacao >= menorFinalizacao) and (respostaAnoFinalizacao <= maiorFinalizacao)){
							procuraAnoFinalizacao(respostaAnoFinalizacao, tamanho, anime);	
							}else{
								cout << "Erro: ano de finalizacao fora do intervalo, retornando ao comeco do codigo\n";		
								}


						break;
					} 
					case 6:{ // status
						quickSortStatus(vetorAux, 0, tamanho-1);
						int respostaStatus;

						cout << "Status: \n";
						cout << "1)Em Andamento\n2)Finalizado\n";
						cout << "Resposta (1 ou 2): ";
						
						cin >> respostaStatus;

						if((respostaStatus == 1) or (respostaStatus == 2)){
							procuraStatus(respostaStatus, tamanho, anime);
							}else{
								mensagemErro();
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
			case 3:{ // Modificar
				int respostaModificar=0;

				cout << "1)Escrever dados" << endl << "2)Sobrescrever dados " << endl;
				cout << "Resposta (1 ou 2): ";

				cin >> respostaModificar;

				switch(respostaModificar){
					case 1:{ // escrever dados
						int respostaE=0;

						cout << "Quantos novos dados deseja escrever?\n";
						cout << "Resposta: ";
						
						cin >> respostaE;
							if(respostaE==1){
								cout << "Insira os dados do anime\n";
								}else{
									cout << "Insira os dados dos " << respostaE << " animes\n";
									}

							for(int i=0; i<respostaE ; i++){
								string novoNome;
								cout << "Nome: ";
								cin.ignore();
								getline(cin, novoNome);

								int novoNumTemp;
								cout << "Numero de temporadas: ";
								cin >> novoNumTemp; 

								int novoNumEp;
								cout << "Numero de episodios: ";
								cin >> novoNumEp;

								int novoAnoLancamento;
								cout << "Ano de lancamento: ";
								cin >> novoAnoLancamento;

								int novoAnoFinalizacao;
								cout << "Ano de finalizacao(Em Andamento=0): ";
								cin >> novoAnoFinalizacao;

								string novoGenero;
								cout << "Genero principal: ";
								cin.ignore();
								getline(cin, novoGenero);

								string novoStatus;
								cout << "Status(Finalizado ou Em Andamento): ";
								getline(cin, novoStatus);
								int respostaAlteracoes;

								cout << "Deseja salvar as alteracoes feitas?" << endl;
								cout << "1)Sim\n2)Nao\n";
								cout << "Resposta (1 ou 2): ";

								cin >> respostaAlteracoes;
								switch(respostaAlteracoes){
									case 1:{
										//int tamanhoAntigo = tamanho; // para fins de preencher as novas posicoes eh necessario saber o tamanho antigo do catalogo
										int tamanhoNovo = tamanho+1; //aumentar o tamanho do catalogo para se adaptar aos novos dados que serao inseridos
						
										Catalogo *vetorAux2= new Catalogo[tamanhoNovo];
										//Preenchendo o vetorAux2 com os valores do catalogo
										for(int i=0; i<tamanho; i++){
											vetorAux2[i]=anime[i];
											}
											delete[] anime;
											anime = vetorAux2;
											tamanho = tamanhoNovo;
											
											anime[tamanho-1].numeracao = tamanho;
											anime[tamanho-1].nome = novoNome;
											anime[tamanho-1].numTemporadas = novoNumTemp;
											anime[tamanho-1].numEpisodios = novoNumEp;
											anime[tamanho-1].anoLancamento = novoAnoLancamento;
											anime[tamanho-1].anoFinalizacao = novoAnoFinalizacao;
											anime[tamanho-1].generoPrincipal = novoGenero;
											anime[tamanho-1].status = novoStatus;
											ofstream saida ("lista.csv"); // preenchendo o catalogo com os novos dados inseridos pelo usuario

											//int contadorE2=0;// contador para saber quando devera parar de escrever dados na saida

											saida << "# Numeracao Nome Numero_Temporadas Numero_Episodios Ano_Lancamento Ano_Finalizacao Genero_Principal Status\n";
											saida << "OBS:(anoFinalizacao= 0 sera quando o anime ainda nao estiver finalizado)\n";
											
											int contadorE = 0;
											
											while(contadorE<tamanho){
											saida << anime[contadorE].numeracao << ";";
											saida << '"' << anime[contadorE].nome << '"'<< ";";
											saida << anime[contadorE].numTemporadas << ";";
											saida << anime[contadorE].numEpisodios << ";";
											saida << anime[contadorE].anoLancamento << ";";
											saida << anime[contadorE].anoFinalizacao << ";";
											saida << '"' << anime[contadorE].generoPrincipal << '"' << ";"; 
											saida << '"' << anime[contadorE].status << '"' << endl;
											contadorE++;
											}
											cout << "Catalogo atualizado com sucesso\n";
											contador++;
										break;
									}
									case 2:{
										cout << "Catalogo nao atualizado\n";
										break;
									}
									default:{
										mensagemErro();
										break;
									}
								}
								
								}
						break;
					}case 2:{ // sobrescrever dados
						int numeracaoDesejada=0;
						
						for(int i=0; i<tamanho; i++){
							imprimirAnime(i, anime);
							}
						
						cout << endl << "Qual numeracao do catalogo deseja sobrescrever? " << endl;
						cout << "Resposta (1 ate " << tamanho << "):"; 

						cin >> numeracaoDesejada;

						cout << "Insira os dados anime\n";
						//declarando as variaveis que vao armazanar os dados escritos pelo usuario para sobrescrever os ja existentes
						
						string nomeAux;
						cout << "Nome: ";
						cin.ignore();
						getline(cin, nomeAux);
						
						int numTemporadasAux;
						cout << "Numero de temporadas: ";
						cin >> numTemporadasAux;
						
						int numEpisodiosAux; 
						cout << "Numero de episodios: ";
						cin >> numEpisodiosAux;
						
						int anoLancamentoAux;
						cout << "Ano de lancamento: ";
						cin >> anoLancamentoAux;
						
						int anoFinalizacaoAux;
						cout << "Ano de finalizacao(Em Andamento=0): ";
						cin >> anoFinalizacaoAux;
						
						string generoPrincipalAux;
						cout << "Genero principal: ";
						cin.ignore();
						getline(cin, generoPrincipalAux);
						
						string statusAux;
						cout << "Status(Finalizado ou Em Andamento): ";
						getline(cin, statusAux);

						int respostaSalvar;

						cout << endl << "Deseja salvar as alteracoes?\n";
						cout << "1)Sim\n2)Nao\n";
						cout << "Resposta(1 ou 2): ";

						cin >> respostaSalvar;

						switch(respostaSalvar){
							case 1:{
								for(int i=0; i<tamanho; i++){
									if(anime[i].numeracao==numeracaoDesejada){
										anime[i].nome=nomeAux;
										anime[i].numTemporadas=numTemporadasAux;
										anime[i].numEpisodios=numEpisodiosAux;
										anime[i].anoLancamento=anoLancamentoAux;
										anime[i].anoFinalizacao=anoFinalizacaoAux;
										anime[i].generoPrincipal=generoPrincipalAux;
										anime[i].status=statusAux;
										
										int contadorS=0;

										ofstream saida ("lista.csv");
										saida << "# Numeracao;Nome;Número Temporadas;Número Episódios;Ano Lançamento;Ano_Finalização Gênero_Principal Status" << endl;
										saida << "OBS:(anoFinalizacao= 0 sera quando o anime ainda nao estiver finalizado)" << endl;

										while(contadorS<tamanho){
											saida << anime[contadorS].numeracao << ";";
											saida << '"' << anime[contadorS].nome << '"'<< ";";
											saida <<  anime[contadorS].numTemporadas << ";";
											saida << anime[contadorS].numEpisodios << ";";
											saida << anime[contadorS].anoLancamento << ";";
											saida << anime[contadorS].anoFinalizacao << ";";
											saida << '"' << anime[contadorS].generoPrincipal << '"' << ";"; 
											saida << '"' << anime[contadorS].status << '"' << endl;
											contadorS++;
											}

										}
									}
									contador++;
								cout << "Valores Atualizados com Sucesso!" << endl;
								break;
							}		
							case 2:{
								cout << "Resposta nao salva, catalogo retornando ao antigo!" << endl;
								break;
							}	
							default:{
								mensagemErro();
								break;
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
			case 4:{ //Remover elemento
				string respostaRemover;
				
				cout << "\nQual o nome do anime que deseja remover?\n";
				cout << "->Resposta(Precisa estar na mesma formatacao do catalogo): ";
				
				cin.ignore();
				getline(cin, respostaRemover);
				bool estaPresente = false;
				while(! estaPresente){
					for(int i=0; i<tamanho ; i++){
						if(anime[i].nome == respostaRemover){
							estaPresente = true; 
							}
						}
					}
				if(estaPresente){
					int respostaSalvar2;

					cout << "Deseja salvar as alteracoes?\n"<< endl;
					cout << "1)Sim\n2)Nao\n";
					cout << "Resposta(1 ou 2):";

					cin >> respostaSalvar2;
					switch(respostaSalvar2){
						case 1:{
							int novoTamanho=tamanho-1; // novo tamanho do catalogo removendo um anime dele
							
							Catalogo *auxRemover = new Catalogo[novoTamanho]; // declarando o novo catalogo com uma posicao a menos
							
							int contadorRemover=0;
							for(int i=0; i<novoTamanho+1 ;i++){
								if(anime[i].nome != respostaRemover){
									auxRemover[contadorRemover]=anime[i];
										contadorRemover++;
										}
									}
								delete[] anime;
								tamanho = novoTamanho; 
								anime = auxRemover;
								ofstream saida ("lista.csv");
								int contadorR2=0;
								
								saida << "# Numeracao Nome Número_Temporadas Número_Episódios Ano_Lançamento Ano_Finalização Gênero_Principal Status" << endl;
								saida << "OBS:(anoFinalizacao=0 sera quando o anime ainda nao estiver finalizado)" << endl;
								while(contadorR2<tamanho){
									saida << anime[contadorR2].numeracao << ";";
									saida << '"' << anime[contadorR2].nome << '"'<< ";";
									saida << anime[contadorR2].numTemporadas << ";";
									saida << anime[contadorR2].numEpisodios << ";";
									saida <<  anime[contadorR2].anoLancamento << ";";
									saida << anime[contadorR2].anoFinalizacao << ";";
									saida << '"' << anime[contadorR2].generoPrincipal << '"' << ";"; 
									saida << '"' << anime[contadorR2].status << '"' << endl;
									contadorR2++;
									}
								contador--;
								cout << "Catalogo atualizado com sucesso, retornando ao comeco do codigo\n";
							break;
						}
						case 2:{
							cout << "Alteracoes nao salvas, retornando ao comeco do codigo\n";
							break;
						}
						default: {
							mensagemErro(); 
							break;
						}
					}
					
						}else{
							cout << "Erro: nome nao presente no catalogo, retornando ao comeco do codigo\n"; 
							}
			break;
			}
			case 5:{
				cout << "\nPrograma finalizado\n";
				break;
			}
			default:{
				mensagemErro();
				break;
			}
		}
	}while(respostaMenu != 5);
	
	return 0;
}
