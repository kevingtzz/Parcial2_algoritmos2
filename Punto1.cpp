#include <cstdio>
#include <algorithm>

class Elephant{
  private:
    int index, Weight, Smart;
    
  public:
    Elephant();
    Elephant(int, int, int);
    //~Elephant();

    int get_index();
    int get_Weight();
    int get_Smart();

    bool operator < (Elephant X) const{ //Se sobrecarga el operador '<' para evaluar los atributos "Weight" y "Smart" de cada elefante.
      if(Weight != X.Weight) return Weight < X.Weight;
      return Smart > X.Smart;
    }
};
    
Elephant::Elephant() {}
    
Elephant::Elephant(int _index, int _Weight, int _Smart) {
  index = _index;
  Weight = _Weight;
  Smart = _Smart;
}

int Elephant::get_index() {
  return index;
}

int Elephant::get_Weight() {
  return Weight;
}

int Elephant::get_Smart() {
  return Smart;
}
    

int main(){
  int n = 0, Weight, Smart;
  Elephant elephants[1000]; //Se inicializa un array de estructuras de elefantes con maximo 1000 elefantes
    
  while(scanf("%d %d", &Weight, &Smart) == 2) { //Mientras hayan dos datos de entrada se asignaran a una de las estructuras del arreglo. 
    elephants[n] = Elephant(++n, Weight, Smart);
  }

  std::sort(elephants, elephants+n);//Teniendo en cuenta la sobrecarga efectuada en el operador  '<'  se organiza el arreglo con un sort
    
  int dp[n], next[n], ans = 0, start;
    
  for(int i = n-1; i >= 0; i--){
    dp[i] = 1;
    next[i] = -1;
        
    for(int j = i + 1; j < n; j++){
      if(elephants[i].get_Weight() < elephants[j].get_Weight() && elephants[i].get_Smart() > elephants[j].get_Smart() && 1+dp[j] > dp[i]){
	      dp[i] = 1 + dp[j];
	      next[i] = j;
      }
    }
        
    if(dp[i] > ans){
      ans = dp[i];
      start = i;
    }
  }
    
  printf("%d\n", ans);
  for(int i = start; i != -1; i = next[i]) printf("%d\n", elephants[i].get_index());
    
  return 0;
}
