class ClassTeste {

    public static void main(String[] args) {
        boolean b;
        int i;
        double d;
        // undef
        // args as String[]

        // should pass
        b = true && true;
        b = !true && true;
        b = true && !true;
        b = !true && !true;

        b = true || true;
        b = !true || true;
        b = true || !true;
        b = !true || !true;

        b = true ^ true;
        b = !true ^ true;
        b = true ^ !true;
        b = !true ^ !true;

        i = 10 ^ 10;
        i = true ^ true;
        i = 10.0 ^ 10.0;

        b = b;
        b = !b;

    }
}