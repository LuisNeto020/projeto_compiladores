class ClassTeste {

    public static void main(String[] args) {
        // Boolean operators
        boolean b;
        int i;
        double d;
        // undef_t

        Integer.parseInt(undef[undef]);     // undef, undef
        Integer.parseInt(undef[1<<1]);     // undef, none
        Integer.parseInt(undef[0]);         // undef, int
        Integer.parseInt(undef[i]);         // undef, int
        Integer.parseInt(undef[args.length]);      // undef, int
        Integer.parseInt(undef[0.0]);       // undef, double
        Integer.parseInt(undef[d]);       // undef, double
        Integer.parseInt(undef[true]);      // undef, bool
        Integer.parseInt(undef[b]);      // undef, bool
        Integer.parseInt(undef[args]);      // undef, String[]

        Integer.parseInt(args[undef]);     

        
    }

}