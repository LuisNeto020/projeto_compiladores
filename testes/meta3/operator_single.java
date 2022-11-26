class operator_single {
   // nota nao tenho a certeza dos erros nem da ordem, é so para ver se estou a pensar bem
   public static void main(String[] args){
      int i;
      double d;
      boolean b;
      b = false;

      // logica de baixo tambem se aplicas ao minus
      // possivel
      i = + 5;
      // nao é possivel? pelo menos em java nao é
      i = +2.0; 

      // ambos possiveisç
      d = + 1;
      d = + 2.0;

      // ambos nao possiveis
      b = + false;
      b = + true;

      // possivel
      int tamanho;
      tamanho = args.length;

      // nao possivel
      i = i.length;
      i = d.length;


      // not só da para boolean
      i = !i;
      d = !d;
      b = !b;

      // referencias ambiguas
      f(1,1);
      }
      public static void f(int a, double b){}
      public static void f(double a, int b){}


}