#include <iostream>
using namespace std;
class Torneio{
	private:
		int* vet;
		int capacidade;
		int tamanho;
	public:
		Torneio(int cap){
			capacidade=cap;
			tamanho=0;
			vet=new int[capacidade];
			for (int i = 0; i <capacidade; i++)
			{
				vet[i]=-1;
			}
		}
		~Torneio(){
			delete []vet;
		}
		int GetPrimeiraFolha()
		{
			return (capacidade)/2;
		};
	
		void insere(int dado){
			int primeiro=GetPrimeiraFolha();
			if(vet[(capacidade-1)]!=-1)
			{
				cout<<"cheio"<<endl;
			}
			else if(vet[(capacidade-1)]==-1)
			{
				vet[(primeiro + tamanho)]=dado;
				tamanho++;
				if(vet[(capacidade-1)]!=-1)
				{
					Organiza();
				}
			}
		};
		int UltimoPai()
		{
			return (capacidade/2)-1;
		};
		void Organiza()
		{
			int pai=UltimoPai();
			int maior=0;
			for (int i =pai; i >= 0; i--)
			{
				
				if(capacidade-1!=0)
				{
					maior=(i*2+1);
					if(((i*2+2)<(capacidade)) and (vet[maior]< vet[(i*2+2)]))
					{
						maior=(i*2+2);
					}
					vet[i]=vet[maior];
				}
			}
		}
		int Rvencedor()
		{
			int vencedor=-1;
			vencedor=vet[0];
			for (int i = GetPrimeiraFolha(); i < capacidade; i++)
			{
				if(vet[i]== vencedor)
				{
					vet[i]= 0 ;
				}
			}
			Organiza();
			return vencedor;
		}
		void imprime()
		{
			for (int i = 0; i < capacidade; i++)
			{
				cout<<"["<<vet[i]<<"]"<<" ";
			}
			cout<< endl;
		} 
			
};
int main()
{
	Torneio gui(5);
	int n;
	for (int i = 0; i < 4; i++)
	{
		cin>>n;
		gui.insere(n);
	}
	gui.imprime();
	cout<<gui.Rvencedor()<<endl;
	gui.imprime();
	cout<<gui.Rvencedor()<<endl;
	return 0;
};
