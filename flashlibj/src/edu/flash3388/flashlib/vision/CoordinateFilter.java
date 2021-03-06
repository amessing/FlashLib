package edu.flash3388.flashlib.vision;

import edu.flash3388.flashlib.util.beans.DoubleProperty;
import edu.flash3388.flashlib.util.beans.IntegerProperty;
import edu.flash3388.flashlib.util.beans.SimpleDoubleProperty;
import edu.flash3388.flashlib.util.beans.SimpleIntegerProperty;

/**
 * Filers out contours by their proximity to a coordinate in the frame.
 * 
 * @author Tom Tzook
 * @since FlashLib 1.0.0
 * @see VisionSource#closestToCoordinate(double, double, int)
 */
public class CoordinateFilter extends VisionFilter{
	
	private DoubleProperty x = new SimpleDoubleProperty(),
						   y = new SimpleDoubleProperty();
	private IntegerProperty amount = new SimpleIntegerProperty();

	public CoordinateFilter(){}
	public CoordinateFilter(double x, double y, int amount){
		this.x.set(x);
		this.y.set(y);
		this.amount.set(amount);
	}
	
	/**
	 * A {@link DoubleProperty}.
	 * Indicates the x coordinate to filter around.
	 * @return the property
	 */
	public DoubleProperty xProperty(){
		return x;
	}
	/**
	 * A {@link DoubleProperty}.
	 * Indicates the y coordinate to filter around.
	 * @return the property
	 */
	public DoubleProperty yProperty(){
		return y;
	}
	/**
	 * An {@link IntegerProperty}.
	 * Indicates the maximum amount of contours to leave after the filter process.
	 * Must be non-negative
	 * @return the property
	 */
	public IntegerProperty amountProperty(){
		return amount;
	}
	
	@Override
	public void process(VisionSource source) {
		source.closestToCoordinate(x.get(), y.get(), amount.get());
	}
}
