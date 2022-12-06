/*
 * scheduler.h
 *
 *  Created on: Nov 29, 2022
 *      Author: Hong Phat
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>
typedef struct{
	void ( * pTask ) ( void ) ;
	uint32_t Delay ;
	uint32_t Period ;
	uint8_t RunMe;
	uint32_t TaskID ;
	uint32_t oneshot;
} sTasks;

#define SCH_MAX_TASKS 40
void SCH_Init(void);
void SCH_Update(void);
void SCH_Dispatch_Tasks(void);
void SCH_Delete(uint32_t ID);
void SCH_Add_Task(void(*pFunction)(), uint32_t DELAY, uint32_t PERIOD,uint32_t oneshot);
void SCH_Go_To_Sleep(void);


#endif /* INC_SCHEDULER_H_ */
