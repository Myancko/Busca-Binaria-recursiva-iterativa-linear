#include <iostream>
#include <string>
#include <time.h>
#include <chrono>

using namespace std;
int BuscaIterativa(int *vet,int procura, int fim)
{
  int inicio = 0;
  int meio = 0;
    string str = "num achei ;-;";

    meio = (inicio + fim) / 2;

    while(inicio <= fim)
    {
        if (procura == vet[meio])
        {
          cout << "O elemento esta na posição: ";
          return meio;
        }
        else
        {
            if (procura < vet[meio])
            {
                fim = meio - 1;
            }
            else
            {
                inicio = meio + 1;
                
            }
        }
        meio = (inicio + fim) / 2;
    }
    return -1;
}
int BuscaRecursiva(int *vet, int fim, int inicio, int procura)
{
  if(inicio <=fim)
  {
    int meio = 0;
    meio = (inicio + fim) / 2;
        if (procura == vet[meio])
        {
          cout << meio;
          return meio;
        }
        else
        {
            if (procura < vet[meio])
            {
                return BuscaRecursiva(vet, meio - 1, inicio, procura);
            }
            else
            {
                return BuscaRecursiva(vet, fim, meio + 1, procura);
            }
        }
    }
  else
    cout << "-1";
    return -1;
}

int main()
{ 
  auto start = chrono::high_resolution_clock::now();

  int iterativo = 0;
  int escolha = 0;
  int EscolharTipoDeBusca = 0;
  int vet[100000];
  //https://www.educative.io/edpresso/how-to-find-the-length-of-an-array-in-cpp
  int vetSize = *(&vet + 1) - vet; 
  int procura = 0;
  int inicio = 0;
  int fim = vetSize;


  for(int a = 0; a <vetSize; a++)
    {
        vet[a] = a;
        //cout << vet [a] << " ";
    }
    cout<<"Voce deseja fazer a busca recursiva, iterativa ou linear?\nDigite 1 para Recursiva.\nDigite 2 para Iterativa\nDigite 3 para linear\n>>> ";
    cin >> escolha;
    //escolha = 0; //DIGITA O NUMEROAQ PARA DISCONTAR O TEMPO DE ESCOLHA
    if (escolha == 1)
    {
      cout << "Função Recursiva\nDigite o numero que voce deseja procurar no vetor de " << vetSize << " posiçoes\n>>> ";
      cin >> procura;
      //procura = 999998; //DIGITA O NUMEROAQ PARA DISCONTAR O TEMPO DE ESCOLHA
      BuscaRecursiva(vet, fim, inicio, procura);
      auto end = chrono::high_resolution_clock::now();

      chrono::duration<float> duration = end - start;

      cout <<"\ntempo de execução:"<<duration.count() << "s\n" << "o tempo que voce ficou para do escolhendo tambem conta :(";
    }
    else if (escolha == 2)
    {
      cout << "Função Iterativa\nDigite o numero que voce deseja procurar no vetor de " << vetSize << " posiçoes\n>>> ";
      cin >> procura;
      //procura = 0; DIGITA O NUMEROAQ PARA DISCONTAR O TEMPO DE ESCOLHA
      cout << BuscaIterativa(vet, procura, vetSize);
      iterativo = 1;
      auto end = chrono::high_resolution_clock::now();

      chrono::duration<float> duration = end - start;

      cout <<"\ntempo de execução:"<<duration.count() << "s\n" << "o tempo que voce ficou para do escolhendo tambem conta :(";
    }
    else if(escolha == 3)
    {
      cout << "Função linear\nDigite o numero que voce deseja procurar no vetor de " << vetSize << " posiçoes\n>>> ";
      cin >> procura;

      for (int x = 0; x <= fim; x++)
      {
        if (vet[x] == procura)
        {
          cout << vet[x] << "\n";
          auto end = chrono::high_resolution_clock::now();

          chrono::duration<float> duration = end - start;

          cout <<"\ntempo de execução:"<<duration.count() << "s\n" << "o tempo que voce ficou para do escolhendo tambem conta :(";
          return vet[x];
        }
      }
      cout << "n achei";
      return -1;
    }
    else
    {
      cout << "VALOR INVALIDO";
      return -1;
    }
}
// numero usado = 999998 
//busca iterativa = 0.0157276s / 0.0180279s / 0.0180279s / 0.0582048s
//busca recursiva = 0.0190662s / 0.0561319s / 0.00617358s / 0.00541706s
//busca normal = 0.0558545s / 0.00955864 / 0.0199144s / 0.00998343