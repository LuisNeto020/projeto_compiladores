class Narrow {
    public static void main(String[] args){
        int i;
        double d;
        boolean b;

        d = 1.1;
        d = 1;
        d = i;
        d = b; // error

        d = i * 1;
        d = i * 1.1;
        d = i * d;
        d = i * b; // error

        d = fun_dd(1,2);
        d = fun_dd(3.0,4);
        d = fun_dd(5.0,6.0);

        d = fun_di(1,1);
        d = fun_di(1.0,1);
        d = fun_di(1,1.0); // error
        d = fun_di(1.0,1.0); // error

        d = fun_ii(1,1); 
        d = fun_ii(1.0,1); // error
        d = fun_ii(1,1.0); // error
        d = fun_ii(1.0,1.0); // error

    }

    public static int fun_dd(double a, double b){return 1;}
    public static int fun_di(double a, int b){return 1;}
    public static int fun_ii(int a, int b){return 1;}
}