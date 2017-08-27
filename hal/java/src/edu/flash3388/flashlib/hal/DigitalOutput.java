package edu.flash3388.flashlib.hal;

public class DigitalOutput extends IOHandler{

	public DigitalOutput(int port){
		if(DIOJNI.checkPortDigitalOutput(port))
			throw new IllegalArgumentException("Unable to initialize digital output: "+port+" is not a valid digital input port");
		int handle = DIOJNI.initializeDigitalOutput(port);
		if(handle < 0)
			throw new IllegalStateException("Failed to initialize digital output port: "+port);
		setHandle(handle);
	}
	
	@Override
	public void free() {
		DIOJNI.freeDigitalOutput(getHandle());
	}

	public boolean get(){
		return DIOJNI.get(getHandle());
	}
	
	public void set(boolean high){
		DIOJNI.set(getHandle(), high);
	}
	public void pulseOut(double length){
		DIOJNI.pulseOut(getHandle(), (float)length);
	}
}
