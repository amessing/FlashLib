/*
 * hw_gpio.h
 *
 *  Created on: Jun 14, 2017
 *      Author: zuk
 */

#ifndef HW_GPIO_H_
#define HW_GPIO_H_

/*************************************************************************\
 * Registers Definition
\*************************************************************************/

#define GPIO_REVISION           (0x0)
#define GPIO_SYSCONFIG          (0x10)
#define GPIO_IRQSTATUS_RAW(n)   (0x24 + (n * 4))
#define GPIO_IRQSTATUS(n)       (0x2C + (n * 4))
#define GPIO_IRQSTATUS_SET(n)   (0x34 + (n * 4))
#define GPIO_IRQSTATUS_CLR(n)   (0x3C + (n * 4))
#define GPIO_IRQWAKEN(n)        (0x44 + (n * 4))
#define GPIO_SYSSTATUS          (0x114)
#define GPIO_CTRL               (0x130)
#define GPIO_OE                 (0x134)
#define GPIO_DATAIN             (0x138)
#define GPIO_DATAOUT            (0x13C)
#define GPIO_LEVELDETECT(n)     (0x140 + (n * 4))
#define GPIO_RISINGDETECT       (0x148)
#define GPIO_FALLINGDETECT      (0x14C)
#define GPIO_DEBOUNCENABLE      (0x150)
#define GPIO_DEBOUNCINGTIME     (0x154)
#define GPIO_CLEARDATAOUT       (0x190)
#define GPIO_SETDATAOUT         (0x194)

/**************************************************************************\
 * Field Definition Macros
\**************************************************************************/

/* IRQSTATUS_CLR_1 */
#define GPIO_IRQSTATUS_CLR_1_INTLINE   		 (0xFFFFFFFFu)
#define GPIO_IRQSTATUS_CLR_1_INTLINE_SHIFT   (0x00000000u)

/* SYSCONFIG */
#define GPIO_SYSCONFIG_AUTOIDLE   			(0x00000001u)
#define GPIO_SYSCONFIG_AUTOIDLE_SHIFT   	(0x00000000u)
#define GPIO_SYSCONFIG_AUTOIDLE_AUTOMATIC   (0x1u)
#define GPIO_SYSCONFIG_AUTOIDLE_FREERUN   	(0x0u)

#define GPIO_SYSCONFIG_ENAWAKEUP   			(0x00000004u)
#define GPIO_SYSCONFIG_ENAWAKEUP_SHIFT   	(0x00000002u)
#define GPIO_SYSCONFIG_ENAWAKEUP_DISABLE  	(0x0u)
#define GPIO_SYSCONFIG_ENAWAKEUP_ENABLE   	(0x1u)

#define GPIO_SYSCONFIG_IDLEMODE   					(0x00000018u)
#define GPIO_SYSCONFIG_IDLEMODE_SHIFT   			(0x00000003u)
#define GPIO_SYSCONFIG_IDLEMODE_FORCEIDLE   		(0x0u)
#define GPIO_SYSCONFIG_IDLEMODE_NOIDLE   			(0x1u)
#define GPIO_SYSCONFIG_IDLEMODE_SMARTIDLE   		(0x2u)
#define GPIO_SYSCONFIG_IDLEMODE_SMARTIDLEWAKEUP   	(0x3u)

#define GPIO_SYSCONFIG_SOFTRESET   					(0x00000002u)
#define GPIO_SYSCONFIG_SOFTRESET_SHIFT   			(0x00000001u)
#define GPIO_SYSCONFIG_SOFTRESET_NORMAL   			(0x0u)
#define GPIO_SYSCONFIG_SOFTRESET_RESET   			(0x1u)

/* SYSSTATUS */
#define GPIO_SYSSTATUS_RESETDONE   			(0x00000001u)
#define GPIO_SYSSTATUS_RESETDONE_SHIFT      (0x00000000u)
#define GPIO_SYSSTATUS_RESETDONE_COMPLETE   (0x1u)
#define GPIO_SYSSTATUS_RESETDONE_ONGOING    (0x0u)


/* CTRL */
#define GPIO_CTRL_DISABLEMODULE  		 	(0x00000001u)
#define GPIO_CTRL_DISABLEMODULE_SHIFT    	(0x00000000u)
#define GPIO_CTRL_DISABLEMODULE_DISABLED    (0x1u)
#define GPIO_CTRL_DISABLEMODULE_ENABLED     (0x0u)

#define GPIO_CTRL_GATINGRATIO   			(0x00000006u)
#define GPIO_CTRL_GATINGRATIO_SHIFT   		(0x00000001u)
#define GPIO_CTRL_GATINGRATIO_N_1   		(0x0u)
#define GPIO_CTRL_GATINGRATIO_N_2   		(0x1u)
#define GPIO_CTRL_GATINGRATIO_N_4   		(0x2u)
#define GPIO_CTRL_GATINGRATIO_N_8   		(0x3u)

/* OE */
#define GPIO_OE_OUTPUTEN             		(0xFFFFFFFFu)
#define GPIO_OE_OUTPUTEN_SHIFT       		(0x00000000u)
#define GPIO_OE_OUTPUTEN_DISABLED    		(0x00000001u)
#define GPIO_OE_OUTPUTEN_ENABLED     		(0x00000000u)


/* DATAIN */
#define GPIO_DATAIN_DATAIN           (0xFFFFFFFFu)
#define GPIO_DATAIN_DATAIN_SHIFT     (0x00000000u)


/* DATAOUT */
#define GPIO_DATAOUT_DATAOUT         (0xFFFFFFFFu)
#define GPIO_DATAOUT_DATAOUT_SHIFT   (0x00000000u)



#endif /* HW_GPIO_H_ */
