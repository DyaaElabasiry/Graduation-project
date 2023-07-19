/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: USART           ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_

/* options : STREAM_Disable -->0                                                                                 */
/*           STREAM_Enable  -->1                                                                           */
#define DMA1_STREAM_Mode         STREAM_Enable
#define DMA2_STREAM_Mode         STREAM_Enable



/* options : INTERRUPT_Disable -->0                                                                                 */
/*           INTERRUPT_Enable  -->1                                                                            */
#define DIRECT_MODE_ERROR_INTERRUPT      INTERRUPT_Enable
#define TRANSFER_ERROR_INTERRUPT         INTERRUPT_Enable
#define HALF_TRANSFER_INTERRUPT          INTERRUPT_Enable
#define TRANSFER_COMPLETE_INTERRUPT      INTERRUPT_Enable



/* options : DMA_FLOW_CONTROLLER        -->0                                                                                */
/*           PERIPHERAL_FLOW_CONTROLLER -->1                                                                              */
#define PERIPHERAL_FLOW_CONTROLLER_MODE      DMA_FLOW_CONTROLLER



/* options : PERIPHERAL_TO_MEMORY                                                                                   */
/*           MEMORY_TO_PERIPHERAL   
             MEMORY_TO_MEMORY                                                                       */
#define DATA_TRANSFER_DIRECTION          USART_Parity_Control_Disable

/* options : CIRCULAR_MODE_DISABLED                                                                                 */
/*           CIRCULAR_MODE_ENABLED                                                                               */
#define CIRCULAR_MODE         CIRCULAR_MODE_DISABLED


#endif
