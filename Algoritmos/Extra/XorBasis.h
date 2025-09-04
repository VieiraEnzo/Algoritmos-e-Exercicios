//Xor Basis

struct Basis{
  vector <int> basis;
  Basis(){

  }
  Basis(int x){
    add(x);
  }
  Basis operator+(Basis other) const{
    Basis res;
    for(int x : basis){
      res.add(x);
    }
    for(int x : other.basis){
      res.add(x);
    }
    return res;
  }
  void add(int x){
    for(auto& i : basis){
      x = min(x, x^i);
    }
    if(x){
      basis.push_back(x);
    }
  }
};
