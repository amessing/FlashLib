package edu.flash3388.flashlib.robot.devices;

/**
 * Interface for speed controllers.
 * 
 * @author Tom Tzook
 * @since FlashLib 1.0.0
 */
public interface FlashSpeedController{
	/**
	 * Sets the speed of the motor controller by this object. The speed is a percentage known as 
	 * percent voltage bus (vbus), which describes a percentage of the currently available voltage to
	 * be supplied to the motor. The sign of the speed describes the direction of rotation.
	 * <p>
	 * If the motor controller is set to inverted directions, the directions are switched.
	 * </p>
	 * 
	 * @param speed [-1 to 1] describing the percent vbus
	 */
	void set(double speed);
	/**
	 * Sets the speed of the motor controller by this object. The speed is a percentage known as 
	 * percent voltage bus (vbus), which describes a percentage of the currently available voltage to
	 * be supplied to the motor. 
	 * <p>
	 * If the motor controller is set to inverted directions, the directions are switched.
	 * </p>
	 * 
	 * @param speed [0 to 1] describing the absolute percent vbus
	 * @param direction the direction of rotation [-1/1]
	 */
	void set(double speed, int direction);
	/**
	 * Sets the speed of the motor controller by this object. The speed is a percentage known as 
	 * percent voltage bus (vbus), which describes a percentage of the currently available voltage to
	 * be supplied to the motor. 
	 * <p>
	 * If the motor controller is set to inverted directions, the directions are switched.
	 * </p>
	 * 
	 * @param speed [0 to 1] describing the absolute percent vbus
	 * @param direction true - forwards, false - backwards
	 */
	void set(double speed, boolean direction);
	
	/**
	 * Stops the motor by setting the speed controller to a stop value. Usually 0.
	 */
	void stop();
	
	/**
	 * Gets the currently set percent vbus in the motor controller.
	 * @return used percent vbus
	 */
	double get();
	
	/**
	 * Gets whether or not the directions of the motor are inverted
	 * @return true if the motor is inverted, false otherwise.
	 */
	boolean isInverted();
	/**
	 * Sets the reversing of directions by the motor controller.
	 * @param inverted true to reverse directions, false otherwise
	 */
	void setInverted(boolean inverted);
}
