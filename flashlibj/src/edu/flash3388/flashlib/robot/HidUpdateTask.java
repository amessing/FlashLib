package edu.flash3388.flashlib.robot;

/**
 * A runnable implementation which calls {@link FlashRobotUtil#updateHID()} if {@link Robot#isOperatorControl()} from
 * the {@link RobotFactory} implementation returns true.
 * 
 * @author Tom Tzook
 * @since FlashLib 1.0.1
 */
public class HidUpdateTask implements Runnable{
	
	@Override
	public void run() {
		if(RobotFactory.getImplementation().isOperatorControl())
			FlashRobotUtil.updateHID();
	}
}
