public class Library_Interface_Demo{
    public static void main(String[] args){
        Kid_Users kid = new Kid_Users();
        
        kid.age = 10;
        kid.registerAccount();
        
        kid.age = 18;
        kid.registerAccount();
        
        kid.bookType = "Kids";
        kid.requestBook();
        
        kid.bookType = "Fiction";
        kid.requestBook();

        System.out.println();

        Adult_Users adult = new Adult_Users();
        
        adult.age = 5;
        adult.registerAccount();
        
        adult.age = 23;
        adult.registerAccount();
        
        adult.bookType = "Kids";
        adult.requestBook();
        
        adult.bookType = "Fiction";
        adult.requestBook();
    }
}
