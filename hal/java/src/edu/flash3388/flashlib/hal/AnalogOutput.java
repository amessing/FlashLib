package edu.flash3388.flashlib.hal;

public class AnalogOutput extends IOHandler{

	public AnalogOutput(int port){
		if(ANALOGJNI.checkPortAnalogOutput(port))
			throw new IllegalArgumentException("Unable to initialize analog output: "+port+" is not a valid analog output port");
		int handle = ANALOGJNI.initializeAnalogOutput(port);
		if(handle < 0)
			throw new IllegalStateException("Failed to initialize analog output port: "+port);
		setHandle(handle);
	}
	
	@Override
	public void free() {
		ANALOGJNI.freeAnalogOutput(getHandle());
	}

	public int getValue(){
		return ANALOGJNI.getAnalogValue(getHandle());
	}
	public double getVoltage(){
		return ANALOGJNI.getAnalogVoltage(getHandle());
	}
	
	public void setValue(int value){
		ANALOGJNI.setAnalogValue(getHandle(), value);
	}
	public void setVoltage(double volts){
		ANALOGJNI.setAnalogVoltage(getHandle(), (float)volts);
	}
}
