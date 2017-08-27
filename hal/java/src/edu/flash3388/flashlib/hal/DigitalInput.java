package edu.flash3388.flashlib.hal;

public class DigitalInput extends IOHandler{

	public DigitalInput(int port){
		if(DIOJNI.checkPortDigitalInput(port))
			throw new IllegalArgumentException("Unable to initialize digital input: "+port+" is not a valid digital input port");
		int handle = DIOJNI.initializeDigitalInput(port);
		if(handle < 0)
			throw new IllegalStateException("Failed to initialize digital input port: "+port);
		setHandle(handle);
	}
	
	@Override
	public void free() {
		DIOJNI.freeDigitalInput(getHandle());
	}

	public boolean get(){
		return DIOJNI.get(getHandle());
	}
}
