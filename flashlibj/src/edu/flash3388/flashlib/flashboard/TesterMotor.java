package edu.flash3388.flashlib.flashboard;

import edu.flash3388.flashlib.communications.Sendable;
import edu.flash3388.flashlib.robot.devices.FlashSpeedController;
import edu.flash3388.flashlib.robot.devices.ModableMotor;
import edu.flash3388.flashlib.util.FlashUtil;
import edu.flash3388.flashlib.util.beans.BooleanSource;
import edu.flash3388.flashlib.util.beans.DoubleSource;

/**
 * Represents a tracking wrapper for motors on the Flashboard.
 * 
 * @author Tom Tzook
 * @since FlashLib 1.0.0
 */
public class TesterMotor extends Sendable{
	
	public static final byte UPDATE_TESTER_NAME = 0x5;
	
	private String testerName;
	private boolean sendData = false, updateTesterName = false;
	private FlashSpeedController controller;
	private DoubleSource voltSource, ampSource;
	private BooleanSource brakeModeSource;
	
	private double speed = 0.0, voltage = 0.0, current = 0.0;
	private boolean brakemode = false;
	
	/**
	 * Creates a new tester wrapper for a motor. 
	 * 
	 * @param name name of the motor
	 * @param controller the motor controller
	 * @param tester the tester which will use it
	 */
	public TesterMotor(String name, FlashSpeedController controller, Tester tester) {
		super(name, FlashboardSendableType.MOTOR);
		this.controller = controller;
		testerName = tester.getName();
		
		if(controller instanceof ModableMotor)
			brakeModeSource = ()->((ModableMotor)controller).inBrakeMode();
	}

	/**
	 * Sets the source for the motor voltage usage.
	 * @param source voltage source
	 * @return this instance
	 */
	public TesterMotor setVoltageSource(DoubleSource source){
		voltSource = source;
		return this;
	}
	/**
	 * Sets the source for the motor current usage.
	 * @param source current source
	 * @return this instance
	 */
	public TesterMotor setCurrentSource(DoubleSource source){
		ampSource = source;
		return this;
	}
	/**
	 * Sets the source for the motor brake mode.
	 * @param source brake mode source
	 * @return this instance
	 */
	public TesterMotor setBrakeModeSource(BooleanSource source){
		brakeModeSource = source;
		return this;
	}
	
	void setDataSending(boolean send){
		sendData = send;
	}
	
	private boolean getBrakeMode(){
		return brakeModeSource != null? brakeModeSource.get() : brakemode;
	}
	private double getSpeed(){
		return controller.get();
	}
	private double getCurrent(){
		return ampSource != null? ampSource.get() : current;
	}
	private double getVoltage(){
		return voltSource != null? voltSource.get() : voltage;
	}
	
	@Override
	public void newData(byte[] data) {
	}
	@Override
	public byte[] dataForTransmition() {
		if(updateTesterName){
			 updateTesterName = false;
			 byte[] data = testerName.getBytes();
			 byte[] send = new byte[data.length+1];
			 send[0] = UPDATE_TESTER_NAME;
			 System.arraycopy(data, 0, send, 1, data.length);
			 return send;
		}
		
		speed = getSpeed();
		current = getCurrent();
		brakemode = getBrakeMode();
		voltage = getVoltage();
		
		byte[] data = new byte[25];
		int pos = 0;
		FlashUtil.fillByteArray(speed, data); pos += 8;
		FlashUtil.fillByteArray(current, pos, data); pos += 8;
		FlashUtil.fillByteArray(voltage, pos, data); pos += 8;
		data[pos] = (byte) (brakemode? 1 : 0);
		
		return data;
	}
	@Override
	public boolean hasChanged(){
		return updateTesterName || (sendData && (getBrakeMode() != brakemode || 
				getSpeed() != speed || getCurrent() != current || getVoltage() != voltage));
	}
	@Override
	public void onConnection() {
		updateTesterName = true;
	}
	@Override
	public void onConnectionLost() {
	}
}
