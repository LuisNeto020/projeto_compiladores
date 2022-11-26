class if_tests {
    public static void main(String[] args){
        int a;
        if (true){a = 0;}
        if (1){a = 0;}      //error
        if (1.0){a = 0;}    //error
        if (args){a = 0;}   //error
        if (a<<1){a = 0;}   //error
    }
}