#include <iostream>
#define M 14
#include <cstdlib>
#include <ctime>
using namespace std;
void imprimecampo(int matp[M][M])
{
    for (int k = 0; k < (M - 4); k++) {
    cout << "   " << k << "";
  }
  cout << endl;
  for (int i = 3; i < (M - 1); i++) {
    cout << i - 3 << "";
    for (int j = 3; j < (M - 1); j++) {
      if(matp[i][j]!=4 && matp[i][j]!=5 && matp[i][j]!=6)
      cout << " [ ]";
      else
        if(matp[i][j]==4)
      cout << "    ";
      else
      if(matp[i][j]==5 || matp[i][j]==6)
          cout << " [B]";
          
    }
    cout << endl;
  }
  
}
void preenchecampoparaimprimir(int matp[M][M],int f,int v[0])
{
  int l,c;
  cout<<endl;
  cout<<"Jogador "<<f<<" é a sua vez"<<endl<<"Digite a linha aperte enter e digite a coluna"<<endl;
  cin>>l;
  cin>>c;
  l=l+3;
  c=c+3;
if(matp[l][c]==0 || matp[l][c]==9){
  matp[l][c]=4;
  cout<<"Jogador "<<f<<" você é bem ruizim de mira e não acertou nada!"<<endl<<"Você continua com "<<v[0]<<" ponto(s)"<<endl;
}
  else
  if(matp[l][c]==1){
    
        matp[l][c] = 5;  
   
        matp[l - 1][c] = 4;
        matp[l + 1][c] = 4;
        matp[l][c - 1] = 4;
        matp[l][c + 1] = 4;
        matp[l-1][c-1] = 4;
        matp[l+1][c-1] = 4;
        matp[l-1][c+1] = 4;
        matp[l+1][c+1] = 4;
        
        v[0]=v[0]+4;
  
        cout<<"Parabéns jogador "<<f<<" você afundou um Heineken e ganhou 4 pontos"<<endl<<"Agora você tem "<<v[0]<<" pontos"<<endl;
  }
  
  if(matp[l][c]==2){
      matp[l][c]=5;
      if(matp[l][c+1]!=5 && matp[l+1][c]!=5 && matp[l][c-1]!=5 && matp[l-1][c]!=5){
      v[0]=v[0]+1;
      cout<<"Ta pertooo jogador "<<f<<" você acertou uma parte de barco"<<endl<<"Agora você tem "<<v[0]<<" ponto(s)"<<endl;
      }
      if(matp[l][c+1]==5 || matp[l+1][c]==5 || matp[l][c-1]==5 || matp[l-1][c]==5){
          if(matp[l][c+1]==5 || matp[l][c-1]==5){
                if(matp[l][c-1]==5)
                c=c-1;
                matp[l - 1][c] = 4;
                matp[l + 1][c] = 4;
                matp[l- 1][c + 1] = 4;
                matp[l + 1][c + 1] = 4;
                matp[l][c - 1] = 4;
                matp[l][c + 2] = 4;
                matp[l-1][c-1] = 4;
                matp[l+1][c-1] = 4;
                matp[l-1][c+2] = 4;
                matp[l+1][c+2] = 4;
              v[0]=v[0]+3;
              cout<<"Parabéns jogador "<<f<<" você afundou um Brahma na horizontal e ganhou 3 pontos"<<endl<<"Agora você tem "<<v[0]<<" pontos"<<endl;
          }
               if(matp[l+1][c]==5 || matp[l-1][c]==5){
                if(matp[l-1][c]==5)
                l=l-1;
        
                matp[l-1][c-1] = 4;
                matp[l][c-1] = 4;
                matp[l+1][c-1] = 4;
                matp[l+2][c-1] = 4;
                matp[l-1][c + 1] = 4;
                matp[l][c + 1] = 4;
                matp[l+1][c+1] = 4;
                matp[l+2][c+1] = 4;
                matp[l-1][c] = 4;
                matp[l+2][c] = 4;
                
               v[0]=v[0]+3;
               cout<<"Parabéns jogador "<<f<<" você afundou um Brahma na vertical e ganhou 3 pontos"<<endl<<"Agora você tem "<<v[0]<<" pontos"<<endl;
          }
         
      

      
  }
 }
 else
 if(matp[l][c]==3){
     if(matp[l][c+1]==3 || matp[l][c+2]==3 || matp[l][c-1]==3 || matp[l][c-2]==3){
         matp[l][c]=6;
if(matp[l][c+1]!=6 || matp[l][c+2]!=6 || matp[l][c-1]!=6 || matp[l][c-2]!=6) {
      v[0]=v[0]+1;
      cout<<"Ta pertooo jogador "<<f<<" você acertou uma parte de barco"<<endl<<"Agora você tem "<<v[0]<<" ponto(s)"<<endl;
      }}
      if(matp[l+1][c]==3 || matp[l+2][c]==3 || matp[l-1][c]==3 || matp[l-2][c]==3){
          matp[l][c]=6;
      if((matp[l+1][c]!=6 && matp[l+2][c]!=6) || (matp[l-1][c]!=6 && matp[l-2][c]!=6) || (matp[l+1][c]!=6 && matp[l-1][c]!=6)){
          v[0]=v[0]+1;
      cout<<"Ta pertooo jogador "<<f<<" você acertou uma parte de barco"<<endl<<"Agora você tem "<<v[0]<<" ponto(s)"<<endl;
      }}
          if((matp[l][c+1]==6 && matp[l][c+2]==6) || (matp[l][c-1]==6 && matp[l][c-2]==6) || (matp[l][c+1]==6 && matp[l][c-1]==6)){
              matp[l][c]=6;
              if(matp[l][c+1]==6 && matp[l][c-1]==6)
                c=c-1;
                else
                  if(matp[l][c-1]==6 && matp[l][c-2]==6)
                    c=c-2;
                  
                  
              matp[l][c - 1] = 4;
              matp[l + 1][c] = 4;
              matp[l + 1][c + 1] = 4;
              matp[l + 1][c + 2] = 4;
              matp[l][c + 3] = 4;
              matp[l - 1][c] = 4;
              matp[l - 1][c + 1] = 4;
              matp[l - 1][c + 2] = 4;
              matp[l+1][c-1]=4;
              matp[l+1][c+3]=4;
              matp[l-1][c-1]=4;
              matp[l-1][c+3]=4;        
                
                
               v[0]=v[0]+2;
               
               cout<<"Parabéns jogador "<<v[0]<<" você afundou um lokal na horizontal e ganhou 2 pontos"<<endl<<"Agora você tem "<<v[0]<<" pontos"<<endl;
    
          }
          
          
          
          
               if((matp[l+1][c]==6 && matp[l+2][c]==6) || (matp[l-1][c]==6 && matp[l-2][c]==6) || (matp[l+1][c]==6 && matp[l-1][c]==6)) {
                 matp[l][c]=6;  
                 if(matp[l+1][c]==6 && matp[l-1][c]==6)
                    l=l-1;
                  if(matp[l-1][c]==6 && matp[l-2][c]==6)
                    l=l-2;
                  
                  
              matp[l - 1][c] = 4;
              matp[l][c - 1] = 4;
              matp[l + 1][c-1] = 4;
              matp[l + 2][c - 1] = 4;
              matp[l + 3][c] = 4;
              matp[l][c + 1] = 4;
              matp[l + 1][c + 1] = 4;
              matp[l + 2][c + 1] = 4;
              matp[l-1][c+1]=4;
              matp[l+3][c+1]=4;
              matp[l-1][c-1]=4;
              matp[l+3][c-1]=4;
              v[0]=v[0]+2;
              cout<<"Parabéns jogador "<<f<<" você afundou um Lokal na vertical e ganhou 2 pontos"<<endl<<"Agora você tem "<<v[0]<<" pontos"<<endl;
      }

      
  }
  cout<<endl;
  cout<<"              TABULEIRO  "<<f<<"     "<<endl;
     
     
     
     

 
}
void preencheCAMPO(int matp[M][M],int i1, int i2, int i3) {

  for (int a = 0; a < M; a++)
    for (int b = 0; b < M; b++) {
      matp[a][b] = 9;
    }
  int a, b;
  for (int i = 0; i < i1;) // barco 1
  {
    a = rand() % M;
    b = rand() % M;

    if (a > 2 && a < M - 1 && b > 2 && b < M - 1) {

      if (matp[a][b] > 1 && matp[a - 1][b] > 1 && matp[a + 1][b] > 1 &&
          matp[a][b - 1] > 1 && matp[a][b + 1] > 1 &&  matp[a-1][b-1] >1 && matp[a+1][b-1] > 1 && matp[a-1][b+1] > 1 && matp[a+1][b+1] > 1) {
        matp[a][b] = 1;
        matp[a - 1][b] = 0;
        matp[a + 1][b] = 0;
        matp[a][b - 1] = 0;
        matp[a][b + 1] = 0;
        matp[a-1][b-1] = 0;
        matp[a+1][b-1] = 0;
        matp[a-1][b+1] = 0;
        matp[a+1][b+1] = 0;
        
        i++;
      }
    }
  }

  for (int i = 0; i < i2;) // barco 2
  {
    int x = rand() % 2, y=rand() % 2;
    a = rand() % M;
    b = rand() % M;
 
    if (matp[a][b] > 2) {
        if (x==y) // horizontal
        {
          if (a > 2 && a < M - 2 && b > 2 && b < M - 2) {
            if (matp[a][b] > 2 && matp[a][b+1] > 2 &&
                matp[a-1][b] > 2 && matp[a+1][b] > 2 &&
                matp[a - 1][b + 1] > 2 && matp[a + 1][b + 1] > 2 &&
                matp[a][b-1] > 2 && matp[a][b + 2] > 2 && matp[a-1][b-1]>2 && matp[a-1][b+2]>2 && matp[a+1][b-1]>2 && matp[a+1][b+2]>2) {
                
                matp[a][b] = 2;
                matp[a][b + 1] = 2;

                matp[a - 1][b] = 0;
                matp[a + 1][b] = 0;
                matp[a - 1][b + 1] = 0;
                matp[a + 1][b + 1] = 0;
                matp[a][b - 1] = 0;
                matp[a][b + 2] = 0;
                matp[a-1][b-1] = 0;
                matp[a+1][b-1] = 0;
                matp[a-1][b+2] = 0;
                matp[a+1][b+2] = 0;
                i++;
              }
          }
        }

        else // vertical
        {
          if (a > 2 && a < M - 2 && b > 2 && b < M - 2) {
            if (matp[a][b] >2 && matp[a + 1][b] >2 &&
                matp[a-1][b] > 2 && matp[a+2][b] > 2 &&
                matp[a][b-1] > 2 && matp[a][b+1] > 2 &&
                matp[a+1][b - 1] >2 && matp[a+1][b + 1] >2 && matp[a-1][b-1] >2  &&
                matp[a-1][b + 2] >2 && matp[a+1][b+2] > 2 && matp[a+1][b]>2) {
    
                matp[a][b] = 2;
                matp[a + 1][b] = 2;

                matp[a - 1][b] = 0;
                matp[a + 2][b] = 0;
                matp[a][b - 1] = 0;
                matp[a][b + 1] = 0;
                matp[a + 1][b - 1] = 0;
                matp[a + 1][b + 1] = 0;
                matp[a-1][b-1] = 0;
                matp[a+1][b-1] = 0;
                matp[a-1][b+2] = 0;
                matp[a+1][b+2] = 0;
                i++;
              }
          }
        }
      
    }
  }

  for (int i = 0; i < i3;) // barco 3
  {
    int x = rand() % 3;
    a = rand() % M;
    b = rand() % M;
    if (matp[a][b] > 3) {
      if (x = 1) // horizontal
      {
        if (a > 2 && a < M - 3) {
          if (b > 2 && b < M - 3) {

            if (matp[a][b - 1] > 3 && matp[a - 1][b] > 3 &&
                matp[a - 1][b + 1] > 3 && matp[a - 1][b + 2] > 3 &&
                matp[a][b + 3] > 3 && matp[a + 1][b] > 3 &&
                matp[a + 1][b + 1] > 3 && matp[a + 1][b + 2] > 3 &&
                matp[a][b] > 3 && matp[a][b + 1] > 3 && matp[a][b + 2] > 3 && matp[a-1][b-1]>3 && matp[a+1][b-1]>3 && matp[a-1][b+3]>3 && matp[a+1][b+3]>3) {

              matp[a][b] = 3;
              matp[a][b + 1] = 3;
              matp[a][b + 2] = 3;

              matp[a][b - 1] = 0;
              matp[a + 1][b] = 0;
              matp[a + 1][b + 1] = 0;
              matp[a + 1][b + 2] = 0;
              matp[a][b + 3] = 0;
              matp[a - 1][b] = 0;
              matp[a - 1][b + 1] = 0;
              matp[a - 1][b + 2] = 0;
              matp[a+1][b-1]=0;
              matp[a+1][b+3]=0;
              matp[a-1][b-1]=0;
              matp[a-1][b+3]=0;
              i++;
            }
          }
        }
      }
      if (x = 2) // vertical
      {
        if (a > 2 && a < M - 3) {
          if (b > 2 && b < M - 3) {

            if (matp[a - 1][b] > 3 && matp[a][b - 1] > 3 &&
                matp[a + 1][b - 1] > 3 && matp[a + 2][b - 1] > 3 &&
                matp[a + 3][b] > 3 && matp[a + 2][b + 1] > 3 &&
                matp[a + 1][b + 1] > 3 && matp[a][b + 1] > 3 &&
                matp[a][b] > 3 && matp[a+1][b]>3 && matp[a+2][b]>3 && matp[a+3][b-1]>3 && matp[a-1][b-1]>3 && matp[a+3][b+1]>3 && matp[a-1][b+1]>3 ) {

              matp[a][b] = 3;
              matp[a + 1][b] = 3;
              matp[a + 2][b] = 3;

              matp[a - 1][b] = 0;
              matp[a][b - 1] = 0;
              matp[a + 1][b-1] = 0;
              matp[a + 2][b - 1] = 0;
              matp[a + 3][b] = 0;
              matp[a][b + 1] = 0;
              matp[a + 1][b + 1] = 0;
              matp[a + 2][b + 1] = 0;
              matp[a-1][b+1]=0;
              matp[a+3][b+1]=0;
              matp[a-1][b-1]=0;
              matp[a+3][b-1]=0;
              i++;
            }
          }
        }
      }
    }
  }
}

int main() {
    srand(time(NULL));
    for(int w=0;w<200;w++){
  int matp[M][M],mat[M][M];
  int y,h, v[0],v1[0],a=1,b=2;
  v[0]=0;
  v1[0]=0;
  cout << "BEM VINDO A BATALHA NAVAL!!!"<< "\n"<<endl<< "Digite a dificuldade do jogo em: "<<endl<<endl<<"fácil(1)"<<endl<<"médio(2)"<<endl<<"díficil(3)"<<endl;
  cin >> y;
  imprimecampo(mat);
  if(y==1){
  preencheCAMPO(matp,2,2,2);
  preencheCAMPO(mat,2,2,2);
  }
  else
    if(y==2){
      preencheCAMPO(matp,3,2,1);
      preencheCAMPO(mat,3,2,1);
    }
      else
      if(y==3){
        preencheCAMPO(matp,4,1,1);
        preencheCAMPO(mat,4,1,1);
      }
      for(int x=0;x<201;x++){
  preenchecampoparaimprimir(matp,a,v);
  imprimecampo(matp);
  if(v[0]==24){
  cout<<"Queeee isssooooo jogador 1 você simplesmente afundou tudo e ganhou o jogo. Parabéns!"<<endl;
  break;
  }
  preenchecampoparaimprimir(mat,b,v1);
  imprimecampo(mat);
  if(v1[0]==24){
  cout<<"Queeee isssooooo jogador 2 você simplesmente afundou tudo e ganhou o jogo. Parabéns!"<<endl;
  break;
  }
  
      }
      cout<<"Digite 1 para jogar novamente ou 2 para sair do jogo"<<endl;
      cin>>h;
      cout<<endl;
      if(h==2)
      break;
}

      
  return 0;
}










