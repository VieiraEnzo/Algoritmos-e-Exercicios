//Matrix
//Multiplicação e Exponensiação de Matrizes
//Utilizado principalmente em recorrencias lineares
//
//https://www.codemarathon.com.br/conteudos/matematica/recorrencia-linear
//


const int D = 2;
const int MOD = 1000000007;
struct Matriz{
  int mat[D][D];
  int* operator[](int i){
    return mat[i];
  }
  Matriz operator*(Matriz oth){
    Matriz res;
    for(int i=0; i<D; i++){
      for(int j=0; j<D; j++){
        res[i][j] = 0;
        for(int k=0; k<D; k++)
          res[i][j] = (res[i][j]+(mat[i][k]*1LL*oth[k][j])%MOD)%MOD;
      }
    }
    return res;
  }
  Matriz exp(long long e){
    Matriz res;
    for(int i=0; i<D; i++)
      for(int j=0; j<D; j++)
        res[i][j] = (i==j);    
    Matriz base = *this;  
    while(e > 0){
      if(e & 1LL)
        res = res * base;
      base = base*base;
      e = e>>1;
    }
    return res;
  }
};