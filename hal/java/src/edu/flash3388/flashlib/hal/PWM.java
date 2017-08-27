package edu.flash3388.flashlib.hal;

public class PWM extends IOHandler{
	
	public PWM(int port){
		if(PWMJNI.checkPortPwm(port))
			throw new IllegalArgumentException("Unable to initialize PWM: "+port+" is not a valid PWM port");
		int handle = PWMJNI.initializePwm(port);
		if(handle < 0)
			throw new IllegalStateException("Failed to initialize PWM port: "+port);
		setHandle(handle);
	}
	
	@Override
	public void free(){
		PWMJNI.freePwm(getHandle());
	}
	
	public void setRaw(int raw){
		PWMJNI.setRaw(getHandle(), raw);
	}
	
	public void setDuty(double duty){
		if(duty < 0.0 || duty > 1.0)
			throw new IllegalArgumentException("Duty cycle for PWM must be between 0 and 1");
		PWMJNI.setDuty(getHandle(), (float)duty);
	}
	
	public double getDuty(){
		return PWMJNI.getDuty(getHandle());
	}
	
	public int getRaw(){
		return PWMJNI.getRaw(getHandle());
	}
}
