class Teste{
    // varios fielddecl seguidos
    public static int a,b,c,d;
    // varios inputs na funcao
    public static void main(int a, double c, boolean d, int h){
        // varios var decl seguidos
        int x,y,z,k,l,m,o,p;
        // if sem nada la dentro, 2 blocks
        if (x1) {}
        // if com 1 statement, 1 block no final
        if (x2) {
            a = 1;
        }
        if (x3){ // if com 2 statements, block no dps da Expr do if
            b = 2;
            c = 3;
        }
        else{
            d=4;
        }
        if (x4); // mesma ideia que ter duas brackets, 2 blocks

        if (true) {} else if (false) {}
        // 1 block para o if(1 caso de cima), e depois 1 block também para o proximo if
        // NOTA: aqui o block do 1 if tem que vir antes do segundo if, senao vai dar erro, isto é testado!!

        a = b.length; // teste para dotlength
        b = 1; // declit
        c = false; // boollit
        c1 = true;
        d = 1.0; // reallit
        Integer.parseInt(abc[a=1]); // parseArgs

        // teste de calls sem nada, calls la dentro
        passarAComp(Zbording,passarAComp(Epossivel),compPassar(ouChumbar),chumbar(tambemSefaz(ESoFazer)));

    }
}