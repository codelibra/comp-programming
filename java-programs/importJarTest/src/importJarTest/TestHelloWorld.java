package importJarTest;

import jarTestProject.HelloWorld;

public class TestHelloWorld {
    
    public static void main(String[] args) {
        HelloWorld helloWorld = new HelloWorld();    
        System.out.println(helloWorld.returnName());
    }
    
}
