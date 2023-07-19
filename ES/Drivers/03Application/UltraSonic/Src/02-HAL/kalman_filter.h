/*********************************************************************************/
/* Author    : Embedded team                                                     */
/* Version   : V01                                                               */
/* Date      : 26 DEC 2021                                                       */
/*********************************************************************************/
#ifndef KALMAN_FILTER_H
#define KALMAN_FILTER_H

typedef struct {
	f32 x ;      // initial_state;
	f32 p ;      //initial_variance;
	f32 ps; //sensor_variance;
	f32 Q ; //variance_over_time;
	f32 k ;
}kalman_variables;

void KalmanFilter_calculate(kalman_variables* filter, u16 distance);

#endif  //KALMAN_FILTER_H
