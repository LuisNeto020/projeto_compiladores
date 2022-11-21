/* Juc implementation of integer division */
/** and verification **/

class divide {
  public static int num, den;
  public static void main(String[] args) {
    int quo, q, r;

    num = Integer.parseInt(args[0]);
    den = Integer.parseInt(args[1]);
    q = num / den;
    r = num % den;
    quo = 0;
    while (den <= num) {
      num = num-den;
      quo = quo+1;
    }

    boolean check;
    check = quo==q && num==r;
    if (check) {
        System.out.print(quo);
        System.out.print(num); // the remainder
    } else
        // Never reached
        System.out.print(check);
  }
}
