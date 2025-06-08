package Aug24.Assignment;

public class F1G8Rectangle extends F1G8Shape{

    private int height;
    private static int count = 1;

    public F1G8Rectangle(int dimension,int height, int center){
        super("Rectangle" + count,dimension,center);
        this.height = height;

        count++;
    }

    @Override
    public void draw(){
        int center = getCenter();
        int dimension = getSideLength();
        for(int i=0; i < height; i++){
            System.out.println(" ".repeat(center) +  "*  ".repeat(dimension));
        }
    }
    
}
