package Aug24.Assignment;

import java.util.InputMismatchException;
import java.util.Scanner;

public class F1G8Main {

    static F1G8Shape[] shapes = new F1G8Shape[10];
    static int shapeCount = 0;

    public static void main(String[] args) {
    	
        shapes[shapeCount++] = new F1G8Square(6,8);
        shapes[shapeCount++] = new F1G8Triangle(6,10);
        shapes[shapeCount++] = new F1G8Rectangle(10,6,4);
        
    	
        mainLoop();
        
    }


    public static void mainLoop(){
    	
        boolean end = false;
        int userInput;

        Scanner scan = new Scanner(System.in);     

        while (!end){

            menu();
            
            try {
            	
            userInput = scan.nextInt();

            switch (userInput) {
                case 1:
                    add_menu();
                    add_Shape(scan);                                     
                    break;

                case 2:
                    moveShape(scan);                    
                    break;
                
                case 3:
                    reSizeShape(scan);                   
                    break;
                
                case 4:
                    drawShape();                  
                    break;

                case 5:
                    System.out.println("Thank you for using the system.");
                    end = true;                    
                    break;
            
                default:
                    System.out.println("That is not an option...");
                    break;
                    
            	}
            
            } catch(InputMismatchException e) {
            	System.out.println("Invalid input. Please enter a number. (1-5)");
            	scan.nextLine();
            }
            
            System.out.println();

        }

        scan.close();
        
    }
        

    public static void menu(){
    	
        System.out.println("--Menu Selection-- ");
        System.out.println("1. Add Shape");
        System.out.println("2. Move Center");
        System.out.println("3. Resize");
        System.out.println("4. Print Object");
        System.out.println("5. Quit");
        System.out.print("\nEnter Selection (1-5): ");
        
    }

    public static void add_menu(){
    	
        System.out.println("--Shape Selection-- ");
        System.out.println("1. Square");
        System.out.println("2. Triangle");
        System.out.println("3. Rectangle");
        System.out.println("Type 0 to cancel");
        System.out.print("\nEnter Selection (1-3): ");
        
    }

    public static void add_Shape(Scanner scan){
    	
        int userInp;
        int SideLength;
        int height;
        int center;
        
        if (shapeCount >= shapes.length){
            System.out.println("You cant add more shapes");
            return;
        }

        while(true){
        try {
        	
            userInp = scan.nextInt();

            switch (userInp) {
                case 1:

                    while(true){
                    	
                        System.out.print("\nEnter Side Length: ");
                        
                        try {
                        	
                        	SideLength = scan.nextInt();

                        	if(SideLength > 0 ){
                                break;
                            }else{
                                System.out.println("Value must be bigger than 0");
                            }

                        
                        } catch(InputMismatchException e) {
                        	System.out.println("Invalid input. Please enter a positive number");
                        	scan.nextLine();
                        }
                    }
                    
                    while(true){
                    	
                        System.out.print("\nEnter center: ");
                        
                        try {
                        	
                        	center = scan.nextInt();
                        	if(center >= 0) break;
                            System.out.println("Value cannot be less than 0");
                       
                        } catch(InputMismatchException e) {
                        	System.out.println("Invalid input. Please enter a positive number");
                        	scan.nextLine();
                        }
                    }                               

                    shapes[shapeCount++] = new F1G8Square(SideLength, center);
                    break;

                case 2:

                    while(true){
                    	
                        System.out.print("\nEnter Height: ");
                        
                        try {
                        	
                        	height = scan.nextInt();

                        	if(height > 0 && height <= 30) break;
                            System.out.println("Value cannot be less than 0/Value too big, go lower");
                            
                        } catch(InputMismatchException e) {
                        	System.out.println("Invalid input. Please enter a positive number");
                        	scan.nextLine();
                        }                
                    }

                    while(true){
                    	
                        System.out.print("\nEnter center: ");
                        
                        try {
                        	
                        	center = scan.nextInt();

                        	if(center > 0) break;
                            System.out.println("Value cannot be less than 0");

                    }catch(InputMismatchException e) {
                    	System.out.println("Invalid input. Please enter a positive number");
                    	scan.nextLine();
                    	}
                    }
                    
                    
                    shapes[shapeCount++] = new F1G8Triangle(height,center);
                    break;        

                case 3:

                    while(true){
                    	
                        System.out.print("\nEnter Side Length: ");
                        
                        try {
                        	
                        	SideLength = scan.nextInt();

                        	if(SideLength > 0) break;
                            System.out.println("Value cannot be less than 0");
                            
                        } catch(InputMismatchException e) {
                        	System.out.println("Invalid input. Please enter a positive number");
                        	scan.nextLine();
                        }                    
                    }

                    while(true){
                    	
                        System.out.print("\nEnter Height: ");
                        
                        try {
                        	height = scan.nextInt();

                        	if(height > 0) break;
                        	System.out.println("Value cannot be less than 0");
                            
                        } catch(InputMismatchException e) {
                        	System.out.println("Invalid input. Please enter a positive number");
                        	scan.nextLine();
                        }                     
                    }
                

                    while(true){
                    	
                        System.out.print("\nEnter center: ");
                        
                        try {
                        	
                        	center = scan.nextInt();

                        	if(center >= 0) break;
                            System.out.println("Value cannot be less than 0");
                            
                        } catch(InputMismatchException e) {
                        	System.out.println("Invalid input. Please enter a positive number");
                        	scan.nextLine();
                        } 
                    }
                    shapes[shapeCount++] = new F1G8Rectangle(SideLength,height ,center);
                    break;
                    
                case 0:
                    return;
            
                default:
                	
                    System.out.println("That is not an option");
                    break;
                    
            }
            break;
        } catch(InputMismatchException e) {
        	System.out.println("Invalid input. Please enter a number. (1-3)");
        	scan.nextLine();
        }
    }
    }

    public static void moveShape(Scanner scan){

        int pick;
        int newCenter;

        while(true){
        	
            System.out.println("Select object to move: ");
            
            for(int i =0; i < shapeCount; i++){
                System.out.println((i + 1) + ". " + shapes[i].getName());
            }

            System.out.println("0. Cancel");
            System.out.print("\nEnter Selection: (1-" + shapeCount + "): ");
            
            try {
            	
            	pick = scan.nextInt();

            	if(pick == 0) return;
            	
            	if(pick <= -1 || pick > shapeCount){
            		System.out.println("That is not an option...");
            		continue;
            	}
            	
            	break;
            	
            } catch(InputMismatchException e) {
            	System.out.println("Invalid input. Please enter a valid number.");
            	scan.nextLine();
            }
        }

        while(true){
        	
            System.out.print("\nEnter new center point: ");
            
            try {
            	
            	newCenter = scan.nextInt();

            	if(newCenter < 0 ){
            		System.out.println("Cannot be negative value...");
            		continue;
            	}

            	if (shapes[pick - 1].move(newCenter) == true) break;
            	else System.out.println("Value too large, please enter smaller value.");

        } catch(InputMismatchException e) {
        	System.out.println("Invalid input. Please enter a positive number");
        	scan.nextLine();
        	}
        }

        shapes[pick - 1].move(newCenter);
    }

    public static void reSizeShape(Scanner scan){

        int pick;
        int size;

        while (true){
        	
            System.out.println("Select shape to resize: ");
            
            for(int i =0; i < shapeCount; i++){
                System.out.println((i + 1) + ". " + shapes[i].getName());
            }

            System.out.println("0. Cancel");
            System.out.print("\nEnter Selection (1-" + shapeCount + "): ");
            
            try {
            	
            	pick = scan.nextInt();

            	if (pick == 0 ) return;

                

            	if (pick <= -1 || pick > shapeCount){
            		System.out.println("That is not an option...");
            		continue;
            	}

            	break;
            
            } catch(InputMismatchException e) {
            	System.out.println("Invalid input. Please enter a valid number");
            	scan.nextLine();
        		}
        	}

        while(true){
        	
            System.out.print("\nEnter new Length: ");
            
            try {
            	
            	size = scan.nextInt();

            	if (size > 0 ){
            		shapes[pick - 1].resize(size);
            		break;
            	}

            	else System.out.println("Cannot be negative");
            
            }catch(InputMismatchException e) {
            	System.out.println("Invalid input. Please enter a valid number");
            	scan.nextLine();
            }


            
        }

        

        
    }

    public static void drawShape(){
    	
        for(int i = 0; i< shapeCount; i++){
            shapes[i].draw();
            System.out.println();
        }
    }

}
