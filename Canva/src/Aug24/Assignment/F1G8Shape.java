package Aug24.Assignment;

public abstract class F1G8Shape implements F1G8Canvas {

    public String name;
    public int center;
    public int SideLength; 

    public F1G8Shape(String name,int SideLength, int center){


        this.name = name;
        this.center = center;
        this.SideLength = SideLength;
    
    }

    public String getName(){
        return name;
    }

    public boolean move(int newCenter){
        if(newCenter + SideLength / 2 <= canvas_Width){
        	this.center= newCenter;
        	return true;
        }else{
            return false;
        }

    }

    public void resize(int newSideLength){
        SideLength = newSideLength;

    }

    public abstract void draw();

    public int getCenter(){
        return center;
    }

    public int getSideLength(){
        return SideLength;
    }

}
