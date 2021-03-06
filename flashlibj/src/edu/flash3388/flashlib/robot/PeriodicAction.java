package edu.flash3388.flashlib.robot;

import edu.flash3388.flashlib.util.FlashUtil;

public class PeriodicAction extends Action{

	private Action action;
	private int time;
	private int lastRun;
	
	public PeriodicAction(Action action, int time){
		this.action = action;
		this.time = time;
		
		setTimeOut(action.getTimeOut());
		copyRequirements(action);
	}
	public PeriodicAction(Action action, double time){
		this(action, (int)(time * 0.001));
	}
	
	@Override
	protected void initialize(){
		action.initialize();
		lastRun = -1;
	}
	
	@Override
	protected void execute() {
		if(lastRun < 0 || FlashUtil.millisInt() - lastRun >= time){
			action.execute();
			lastRun = FlashUtil.millisInt();
		}
	}

	@Override
	protected boolean isFinished(){
		return action.isFinished();
	}
	
	@Override
	protected void end() {
		action.end();
	}
	
	@Override
	protected void interrupted(){
		action.interrupted();
	}

}
