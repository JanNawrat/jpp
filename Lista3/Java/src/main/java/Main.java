public class Main {
    public static void main(String[] args) throws EncryptionKeyNotSetException {
        DHSetup<GaloisField> setup = new DHSetup<GaloisField>((int a) -> new GaloisField(a));
        System.out.println(setup.getGenerator());
        User<GaloisField> user1 = new User<GaloisField>(setup);
        User<GaloisField> user2 = new User<GaloisField>(setup);
        System.out.println(user1.getPublicKey());
        System.out.println(user2.getPublicKey());
        user1.setKey(user2.getPublicKey());
        user2.setKey(user1.getPublicKey());
        GaloisField m = user1.encrypt(new GaloisField(98765));
        System.out.println(m);
        System.out.println(user2.decrypt(m));
    }
}
