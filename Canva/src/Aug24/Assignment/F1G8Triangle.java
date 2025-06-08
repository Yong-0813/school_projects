package Aug24.Assignment;

public class F1G8Triangle extends F1G8Shape{

    private static int count = 1;   
    
    public F1G8Triangle( int height, int center){
        super("Triangle" + count,height,center);   
        count++;   
    }

    @Override
    public void draw(){
        int center = getCenter();
        int height = getSideLength();
        for(int i=1; i <= height; i++){
            System.out.println(" ".repeat(center + (height)) +  "*  ".repeat(i));
        }
    }
}
