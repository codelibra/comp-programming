package jarTestProject;

public class HelloWorld {
    public String returnName() {
        HelloAgain testAgain = new HelloAgain();
        return "Shiv" + testAgain.returnInteger().toString();
    }
}
