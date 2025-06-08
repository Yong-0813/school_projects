package Aug24.Assignment;

public class F1G8Square extends F1G8Shape{

    private static int count = 1;

    public F1G8Square(int dimension, int center){
        super("Square" + count,dimension,center);
        count++;
    }

    @Override
    public void draw(){
        int center = getCenter();
        int dimension = getSideLength();
        for(int i=0; i < dimension; i++){
            System.out.println(" ".repeat(center) +  "*  ".repeat(dimension));
        }
    }
    
}
