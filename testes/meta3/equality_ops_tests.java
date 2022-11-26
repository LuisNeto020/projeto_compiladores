class equality_or_equity_question_mark {
    public static void main(String[] args){
        int i;
        double d;
        boolean b;
        i = 0;
        d = 1.1;
        b = true;

        // valid        
        if (i == i){}
        if (i == 1){}
        if (d == d){}
        if (d == 1.1){}
        if (b == b){}
        if (b == true){}

        //only numeric types with numeric types are valid
        //only boolean types with boolean types are valid
        if (i == d){}
        if (i == b){}   // error
        if (d == b){}   // error

        // valid        
        if (i != i){}
        if (i != 1){}
        if (d != d){}
        if (d != 1.1){}
        if (b != b){}
        if (b != true){}

        //only numeric types with numeric types are valid
        //only boolean types with boolean types are valid
        if (i != d){}
        if (i != b){}   // error
        if (d != b){}   // error

        if (args == args){}
        if (args != i){}    // error
    }
}