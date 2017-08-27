package edu.flash3388.flashlib.hal;

public class AnalogInput extends IOHandler{

	public AnalogInput(int port){
		if(ANALOGJNI.checkPortAnalogInput(port))
			throw new IllegalArgumentException("Unable to initialize analog input: "+port+" is not a valid analog output port");
		int handle = ANALOGJNI.initializeAnalogInput(port);
		if(handle < 0)
			throw new IllegalStateException("Failed to initialize analog input port: "+port);
		setHandle(handle);
	}
	
	@Override
	public void free() {
		ANALOGJNI.freeAnalogInput(getHandle());
	}

	public int getValue(){
		return ANALOGJNI.getAnalogValue(getHandle());
	}
	public double getVoltage(){
		return ANALOGJNI.getAnalogVoltage(getHandle());
	}
}
