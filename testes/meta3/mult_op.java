class mult {
    public static void main(String[] args){
        int i;
        double d;
        boolean b;

        i = 1;
        d = 1.1;
        b = true;

        i = i * i;
        i = i / i;
        i = i % i;

        d = d * d;
        d = d / d;
        d = d % d;

        d = d * i;
        d = d / i;
        d = d % i;

        i = d * i;  // erro 
        i = d / i;  // erro
        i = d % i;  // erro

        d = d * b;  // erro
        d = d / b;  // erro
        d = d % b;  // erro

        d = d * args; // erro
        d = d / args; // erro
        d = d % args; // erro
    }
}