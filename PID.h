#ifndef _PID_H
#define _PID_H

typedef struct
{
	float kp,ki,kd;
	float p,i,d;
	float D_last;
	float pid_value;
	float I_MAX;
	float pid_value_max;
}PID_posititon_t;

void PID_init(PID_posititon_t *pid_init);
int PID_SET(PID_posititon_t*pid_set,float kp,float ki,float kd,float I_MAX,float pid_value_max,float set_value,float real_value);

#endif

