import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        BigInteger first = new BigInteger("5555123456789987654321");
        BigInteger second = new BigInteger("2222987654321123456789");

        long startTime = System.nanoTime();
        BigInteger sumValue = first.add(second);
        System.out.println("Sum value = " + sumValue);
        long endTime = System.nanoTime();
        double elapsedTime = (endTime - startTime) / 1_000_000_000.0;
        System.out.println("Elapsed time: " + (elapsedTime*1000) + " ms");
        long usedMemory = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
        System.out.println("Memory usage: " + usedMemory / 1024 + " KB");
        
        startTime = System.nanoTime();
        BigInteger subValue = first.subtract(second);
        System.out.println("Subtract value = " + subValue);
        endTime = System.nanoTime();
        elapsedTime = (endTime - startTime) / 1_000_000_000.0;
        System.out.println("Elapsed time: " + (elapsedTime*1000) + " ms");
        usedMemory = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
        System.out.println("Memory usage: " + usedMemory / 1024 + " KB");
        
        startTime = System.nanoTime();
        BigInteger mulValue = first.multiply(second);
        System.out.println("Multiply value = " + mulValue);
        endTime = System.nanoTime();
        elapsedTime = (endTime - startTime) / 1_000_000_000.0;
        System.out.println("Elapsed time: " + (elapsedTime*1000) + " ms");
        usedMemory = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
        System.out.println("Memory usage: " + usedMemory / 1024 + " KB");
        
        startTime = System.nanoTime();
        BigInteger divValue = first.divide(second);
        System.out.println("Divide value = " + divValue);
        endTime = System.nanoTime();
        elapsedTime = (endTime - startTime) / 1_000_000_000.0;
        System.out.println("Elapsed time: " + (elapsedTime*1000) + " ms");
        usedMemory = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
        System.out.println("Memory usage: " + usedMemory / 1024 + " KB");
        
        startTime = System.nanoTime();
        BigInteger modValue = first.mod(second);
        System.out.println("Modulo value = " + modValue);
        endTime = System.nanoTime();
        elapsedTime = (endTime - startTime) / 1_000_000_000.0;
        System.out.println("Elapsed time: " + (elapsedTime*1000) + " ms");
        usedMemory = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
        System.out.println("Memory usage: " + usedMemory / 1024 + " KB");
        
        startTime = System.nanoTime();
        BigInteger power = new BigInteger("10");
        BigInteger exp = new BigInteger("1000");         
        BigInteger powValue = power.mod(exp);
        System.out.println("Power value = " + powValue);
        endTime = System.nanoTime();
        elapsedTime = (endTime - startTime) / 1_000_000_000.0;
        System.out.println("Elapsed time: " + (elapsedTime*1000) + " ms");
        usedMemory = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
        System.out.println("Memory usage: " + usedMemory / 1024 + " KB");
    }
}