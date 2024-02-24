/*
 * BIT_math.h
 *
 * Created: 11/19/2023 11:45:52 PM
 *  Author: Mohamed
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_				
/*******************************_BIT_MATH_H_***********************************/
#define SET_BIT(REG,BN)	    ((REG)|=(1<<(BN)))
#define CLR_BIT(REG,BN)	    ((REG)&=~(1<<(BN)))
#define TOG_BIT(REG,BN)	    ((REG)^=(1<<(BN)))
#define GET_BIT(REG,BN)	    ((REG>>BN)&1)  //((REG & 1<<BN) >>BN)
#define ROR(REG,N)			(((REG)>>(N))|((REG)<<(8-(N))))
#define ROL(REG,N)			(((REG)<<(N))|((REG)>>(8-(N))))
#define IS_HIGH(REG,N) 		(((REG)>>(N))&1)
#define IS_LOW(REG,N)		(!(((REG)>>(N))&1))
/*****************************************************************************/
/***********************************END***************************************/
/*****************************************************************************/
#endif /* BIT_MATH_H_ */