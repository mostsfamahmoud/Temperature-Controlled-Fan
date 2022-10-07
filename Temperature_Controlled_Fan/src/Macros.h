 /*****************************************************************
 * File Name: Macros.h
 *
 * Description: Commonly Used Macros
 *
 * Author: Mostafa Mahmoud
 *
 * Group:  71
 *
 *****************************************************************/

#ifndef MACROS_H_
#define MACROS_H_

/* Set a bit in the required register */
#define SET_BIT(REG,BIT)       ( REG |= (1 << BIT) )

/* Clear a bit in the required register */
#define CLEAR_BIT(REG,BIT)     ( REG &= ~(1 << BIT) )

/* Toggle a bit in the required register */
#define TOGGLE_BIT(REG,BIT)    ( REG ^= (1 << BIT) )

/* Write a specific bit in the required register according to the value to be passed (1 or 0) */
#define WRITE_BIT(REG,BIT,VAL){\
      switch(VAL){\
      case 0:\
    	  CLEAR_BIT(REG,BIT); break;\
      case 1:\
    	  SET_BIT(REG,BIT); break;\
      }\
}

/* Rotate right the register value with specific number of rotates */
#define ROR(REG,BIT)          ( REG = (REG >> BIT) | (REG << (8 - BIT)) )

/* Rotate left the register value with specific number of rotates */
#define ROL(REG,BIT)          ( REG = (REG << BIT) | (REG >> (8 - BIT)) )

/* Checks if a bit is set in the required register and return 1 if TRUE and 0 Otherwise */
#define BIT_IS_SET(REG,BIT)    ( REG & (1 << BIT))

/* Checks if a bit is cleared in the required register and return 1 if TRUE and 0 Otherwise */
#define BIT_IS_CLEAR(REG,BIT)  ( !(BIT_IS_SET(REG,BIT)) )

/* Return the value of a bit in the required register ( 1 or 0 )*/
#define GET_BIT(REG,BIT)       ( BIT_IS_SET(REG,BIT)? 1 : 0 )

#endif /* MACROS_H_ */
