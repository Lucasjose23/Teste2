
#include <sstream>
using namespace std;
//template <class ELEM>

template <class Elem>
class Listas
{
private:
	int TAM;
	struct  no
	{
		Elem info;
		no *prox;
	} *L;

public:
	Listas();//construtor
	~Listas();//destrutor
	void insere(Elem);//insere elementos
	Elem remove(Elem);//remove
	string mostra();

};
template <class Elem>
Listas<Elem>::Listas()
{

}

template <class Elem>
Listas<Elem>::~Listas()
{

}
template <class Elem>
void Listas<Elem>::insere(Elem x)
{
	no *aux = new no();//criada a variavel aux e alocada na memoria
	aux->info = x;//a informaçao ja é guardada nela
	if ((L == NULL) || (x < L->info))//se tiver apenas 1 elemnto e for menor que ele  ou nenhum
	{
		aux->prox = L;
		L = aux;

	}
	else//se for maior que o primeiro
	{
		no *P = L;//aux que recebe o inicio
		while ((P->prox) && (x>P->prox->info))//enqwuanto o proximo for diferente de null e o x for maior que a informaçao deste proximo(para uma posiçao antes)
			P = P->prox;
		aux->prox = P->prox;
		P->prox = aux;
	}
}
template <class Elem>
Elem Listas<Elem>::remove(Elem x)
{
	no *P = L;//variavel aux que começa do inicio da fila
	if (x < L->info)//se for menor qwue o primeiro da lista
		return 0;
	else
	{

		if (x == L->info)//se for igual o primeiro da lista
		{


			L = P->prox;//o inicio vai passsar a ser o proximo
			Elem z = P->info;
			delete P;
			return z;
		}
		else//se for maior que o primeiro
		{
			while ((P->prox) && (x > P->prox->info))//enqwuanto o proximo for diferente de null e o x for maior que a informaçao deste proximo(para uma posiçao antes)
				P = P->prox;
			if ((P->prox) && (x == P->prox->info))//se o proximo  for diferente de null e for igual a x
			{
				no* aux = P->prox;
				P->prox = aux->prox;
				Elem z = aux->info;
				delete aux;//remove o proximo
				return z;

			}

		}
	}

}
template <class Elem>
string Listas<Elem>::mostra()
{
	no *aux = L;
	ostringstream S;
	S << "[";
	while (aux)
	{
		S << aux->info;
		aux = aux->prox;
		if (aux)
		{
			S << ",";
		}
	}
	S << "]";
	return S.str();
}
