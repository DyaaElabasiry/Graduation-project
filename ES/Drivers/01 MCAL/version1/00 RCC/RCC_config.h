/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: RCC           ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/* options : RCC_u8Clk_Disable                                                                                   */
/*           RCC_u8Clk_Enable                                                                               */
#define RCC_u8HSION_Mode         RCC_u8Clk_Enable
#define RCC_u8HSEON_Mode         RCC_u8Clk_Disable
#define RCC_u8PLL_Mode           RCC_u8Clk_Enable


/* options : RCC_u8BYPASSED                                                                                   */
/*           RCC_u8NOT_BYPASSED                                                                               */
#define RCC_u8HSEPYB             RCC_u8NOT_BYPASSED

/* Clock Security System PIN configuration as it is set and cleared by software to enable clk security system*/
/* options : RCC_u8CLK_DETECTOR_OFF                                                                           */
/*           RCC_u8CLK_DETECTOR_ON                                                                            */
    
#define RCC_u8CSSON              RCC_u8CLK_DETECTOR_ON

   
 /* Note: you can choose any number from 000010 to 111111 */
#define PLL_InClk_Division_Factor           000010

 /* Note: you can choose any number from 000000010 to 110110000 */
#define PLL_VCO_Multiplication_Factor       000000010

 /* Note: you can choose any number from 00 to 11 */
#define PLL_MainClk_Division_Factor         00

 /* Note: you can choose any number from 0010 to 1111 */
#define PLL_USB_OTG_Division_Factor         0010

/* options : HSIClk_Selected                                                                                   */
/*           HSEClk_Selected                                                                               */
#define PLL_Clk_Source            HSIClk_Selected

/* options : RCC_u8HSI_SYSCLK                                                                                   */
/*           RCC_u8HSE_SYSCLK
             RCC_u8PLL_SYSCLK
*/
#define System_Clk_Source         RCC_u8HSI_SYSCLK

/* options 1-RCC_u8SYSCLK_Division_by_1    
           2-RCC_u8SYSCLK_Division_by_2  
           3-RCC_u8SYSCLK_Division_by_4  
           4-RCC_u8SYSCLK_Division_by_8  
           5-RCC_u8SYSCLK_Division_by_16 
           6-RCC_u8SYSCLK_Division_by_64 
           7-RCC_u8SYSCLK_Division_by_128
           8-RCC_u8SYSCLK_Division_by_256
           9-RCC_u8SYSCLK_Division_by_512   */

#define RCC_u8AHB_PRESCALER     RCC_u8SYSCLK_Division_by_2


/*Options 1-RCC_u8AHB_CLK_Division_by_1 
          2-RCC_u8AHB_CLK_Division_by_2 
          3-RCC_u8AHB_CLK_Division_by_4 
          4-RCC_u8AHB_CLK_Division_by_8 
          5-RCC_u8AHB_CLK_Division_by_16

*/
#define RCC_u8APB1_PRESCALER    RCC_u8AHB_CLK_Division_by_2  /*Shoudn't excced 84 MHZ*/
#define RCC_u8APB2_PRESCALER    RCC_u8AHB_CLK_Division_by_2  /*Shoudn't excced 42 MHZ*/

/*Options 1-HSI_MCO1_Selected 
          2-LSE_MCO1_Selected 
          3-HSE_MCO1_Selected 
          4-PLL_MCO1_Selected 

*/
#define Microcontroller_Clk_Output1   HSE_MCO1_Selected

/*Options 1-SYSCLK_MCO2_Selected 
          2-PLLI2S_MCO2_Selected 
          3-HSE_MCO2_Selected    
          4-PLL_MCO2_Selected    

*/

#define Microcontroller_Clk_Output2   SYSCLK_MCO2_Selected

/*Options      1-RCC_u8MCO_CLK_Division_No   
               2-RCC_u8MCO_CLK_Division_by_2 
               3-RCC_u8MCO_CLK_Division_by_3 
               4-RCC_u8MCO_CLK_Division_by_4 
               5-RCC_u8MCO_CLK_Division_by_5 
*/
#define Microcontroller_Clk1_Prescaler   RCC_u8MCO_CLK_Division_by_2
#define Microcontroller_Clk2_Prescaler   RCC_u8MCO_CLK_Division_by_2

/*Options 1-RCC_u8GPIO_Reset   
          2-RCC_u8GPIO_Reset_NO
*/
#define GPIOA_Reset_State               RCC_u8GPIO_Reset_NO
#define GPIOB_Reset_State               RCC_u8GPIO_Reset_NO
#define GPIOC_Reset_State               RCC_u8GPIO_Reset_NO

#endif
