package Aug24.Assignment;

    
public interface F1G8Canvas {
    int canvas_Width = 100;

    void draw();
    boolean move(int newCenter);
    void resize(int newSideLength);
    String getName();
    
}
