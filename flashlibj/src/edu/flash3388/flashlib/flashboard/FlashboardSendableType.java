package edu.flash3388.flashlib.flashboard;

/**
 * Type values for Flashboard controls.
 * 
 * @author Tom Tzook
 * @since FlashLib 1.0.0
 */
public class FlashboardSendableType {
	private FlashboardSendableType(){}
	
	public static final byte CHOOSER = 0x01;
	public static final byte ACTIVATABLE = 0x02;
	public static final byte JOYSTICK = 0x03;
	public static final byte DOUBLE = 0x05;
	public static final byte BOOLEAN = 0x06;
	public static final byte STRING = 0x07;
	public static final byte INPUT = 0xf;
	public static final byte LOG = 0x08;
	public static final byte TESTER = 0x09;
	public static final byte MOTOR = 0xa;
	public static final byte VISION = 0xb;
	public static final byte PDP = 0xe;
	public static final byte SLIDER = 0x10;
	public static final byte ESTOP = 0x00;
	public static final byte PIDTUNER = 0x04;
}
