class Error {
	public static void a(int b) {
		b = b + 2;
		return;
	}
    public static void main(String[] args) {
        System.out.print(a(3));
    }
}