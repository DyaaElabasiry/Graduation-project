/*********************************************************************************/
/* Author    : Embedded team                                                     */
/* Version   : V01                                                               */
/* Date      : 26 DEC 2021                                                       */
/*********************************************************************************/

#include "../00-LIB/STD_TYPES.h"

#include "kalman_filter.h"



void KalmanFilter_calculate(kalman_variables* filter, u16 distance)
{

	// state prediction
  filter->p += filter->Q ;

  // measurement update
  filter->k = 1.0 * filter->p / (filter->p + filter->ps);
  filter->x = (1 - filter->k) * filter->x + filter->k * distance;
  filter->p = (1 - filter->k) * filter->p;

}
