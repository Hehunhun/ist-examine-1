#include "PID.h"

void PID_init(PID_posititon_t *pid_init)
{
	pid_init->kp=0;
	pid_init->ki=0;
	pid_init->kd=0;
	pid_init->I_MAX=0;
	pid_init->pid_value=0;
	pid_init->pid_value_max=0;
	pid_init->p=0;
	pid_init->i=0;
	pid_init->d=0;
	pid_init->D_last=0;
	
	
}

float PID_SET(PID_posititon_t*pid_set,float kp,float ki,float kd,float I_MAX,float pid_value_max,float set_value,float real_value)
{
	pid_set->kp=kp;
	pid_set->ki=ki;
	pid_set->kd=kd;
	pid_set->I_MAX=I_MAX;
	pid_set->pid_value_max=pid_value_max;
	
	pid_set->p=set_value-real_value;
	pid_set->i=pid_set->i+pid_set->p;
	pid_set->d=pid_set->p-pid_set->D_last;
	pid_set->D_last=pid_set->p;
	
	// I限幅
	if(pid_set->i>=pid_set->I_MAX)
	{
		pid_set->i=pid_set->I_MAX;
	}
	else if(pid_set->i<=-pid_set->I_MAX)
	{
		pid_set->i=-pid_set->I_MAX;
	}
	
	pid_set->pid_value=pid_set->kp*pid_set->p+pid_set->ki*pid_set->i+pid_set->kd*pid_set->d;
	
	// 输出限幅
	if(pid_set->pid_value>=pid_set->pid_value_max)
	{
		pid_set->pid_value=pid_set->pid_value_max;
	}
	else if(pid_set->pid_value<=-pid_set->pid_value_max)
	{
		pid_set->pid_value=-pid_set->pid_value_max;
	}
	
	return(pid_set->pid_value);

}
