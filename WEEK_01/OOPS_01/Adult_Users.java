public class Adult_Users implements Library_User{
    int age;
    String bookType;

    @Override
    public void registerAccount(){
        if(age > 12){
            System.out.println("You have successfully registered under an adult account");
        } 
        else{
            System.out.println("Sorry, age must be greater than 12 to register as an adult");
        }
    }

    @Override
    public void requestBook(){
        if("Fiction".equals(bookType)){
            System.out.println("Book issued successfully; please return the book within 7 days");
        } 
        else{
            System.out.println("Oops, you are allowed to take only adult fiction books");
        }
    }
}
