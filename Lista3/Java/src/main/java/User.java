import java.util.Random;

public class User<T extends Arithmetic> {
    private final DHSetup setup;
    private int secret;
    private T encryptionKey;
    private boolean encryptionKeySet = false;

    public User(DHSetup<T> setup) {
        this.setup = setup;
        Random rand = new Random();
        this.secret = rand.nextInt(1, 2147483647);
    }

    public T getPublicKey() {
        return (T) setup.power(setup.getGenerator(), secret);
    }

    public void setKey(T a) {
        encryptionKey = (T) setup.power(a, secret);
        encryptionKeySet = true;
    }

    public T encrypt(T m) throws EncryptionKeyNotSetException {
        if(!encryptionKeySet) {
            throw new EncryptionKeyNotSetException("Encryption key not set");
        }
        m.multiply(encryptionKey);
        return m;
    }

    public T decrypt(T c) throws EncryptionKeyNotSetException {
        if(!encryptionKeySet) {
            throw new EncryptionKeyNotSetException("Encryption key not set");
        }
        c.divide(encryptionKey);
        return c;
    }
}
