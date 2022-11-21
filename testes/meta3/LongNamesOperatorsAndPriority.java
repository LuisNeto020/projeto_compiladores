class LocalVariables {
    public static int factorial_mas_com_muitos_mais_carateres_para_ver_se_a_memoria_esta_bem;
    public static void factorial_mas_com_muitos_mais_carateres_para_ver_se_a_memoria_esta_bem(int n,int x,double y) {
        int local_mas_com_muitos_mais_carateres_para_ver_se_a_memoria_esta_bem;
    }
    
    public static int operators(int n,int x) {
        int a, b;
        double c, d;
        boolean e, f;

        a = 1;
        b = 1;
        c = 2.0;
        d = 3.0;
        e = true;
        f = false;

        a = a +  b;
        a = a -  b;
        a = a *  b;
        a = a /  b;
        a = a %  b;

        c = a +  b;
        c = a -  b;
        c = a *  b;
        c = a /  b;
        c = a %  b;

        c = c +  b;
        c = c -  b;
        c = c *  b;
        c = c /  b;
        c = c %  b;

        c = b +  c;
        c = b -  c;
        c = b *  c;
        c = b /  c;
        c = b %  c;

        c = a +  b;
        c = a -  b;
        c = a *  b;
        c = a /  b;
        c = a %  b;

        e = a >  c;
        e = a >= c;
        e = a <  c;
        e = a <= c;
        e = a == c;
        e = a != c;

        e = c >  a;
        e = c >= a;
        e = c <  a;
        e = c <= a;
        e = c == a;
        e = c != a;

        return a;
    }
    
    public static int operators2(int n,int x) {
        int a, b;
        double c, d;
        boolean e, f;

        a = 2;
        b = 3;
        c = 2;

        a = 2 +  2;
        a = a -  2;
        a = 2 *  b;

        c = 2.0 +  b;
        c = a   -  2.0;
        c = 2.0 *  2.0;
        c = a   /  2;
        c = 2   %  2.0;

        e = true == false;
        e = false != false;

        return a;
    }

    public static boolean n;
    public static void priority(String[] args) {
        double n;
        int a;

        a = 1;
        n = 0;

        n = a + n;
        n = a - a;

        Integer.parseInt(args[0]);
        System.out.print(n);
        System.out.print(Integer.parseInt(args[0]));
        System.out.print(args.length);

        return;
    }
}
