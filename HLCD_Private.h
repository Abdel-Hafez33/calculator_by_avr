/*
 * HLCD_Private.h
 *
 *  Created on: Sep 22, 2024
 *      Author: Abdel Hafez
 */

#ifndef HLCD_PRIVATE_H_
#define HLCD_PRIVATE_H_

#define equation_local_address (A_u8rowNum)*0x40+A_u8colNum
#define set_pin7_on                      128
#define block_bits                       8
#define set_pin6_on                      64
//character arabic
 #define ALEF_HAMZA { \
    0b00100,  /*   *   (Hamza) */ \
    0b00010,  /*  *    (Hamza tail) */ \
    0b00000,  /*       */ \
    0b00100,  /*   *   (Alef) */ \
    0b00100,  /*   *   (Alef) */ \
    0b00100,  /*   *   (Alef) */ \
    0b00100,  /*   *   (Alef) */ \
    0b01110   /*  ***  (Alef base) */ \
}  
// character ا
#define ALEF { \
    0b00000,  /*        */ \
    0b00000,  /*        */ \
    0b00000,  /*        */ \
    0b00100,  /*   *    (Alef stem) */ \
    0b00100,  /*   *    (Alef stem) */ \
    0b00100,  /*   *    (Alef stem) */ \
    0b00100,  /*   *    (Alef stem) */ \
    0b01110   /*  ***   (Alef base) */ \
}
//character ب
#define BA { \
    0b00000,  /*        */ \
    0b00000,  /*        */ \
    0b00000,  /*        */ \
    0b01110,  /*  ***   (Top horizontal line) */ \
    0b00001,  /*      * (Right edge vertical) */ \
    0b01111,  /*  ****  (Bottom line) */ \
    0b00000,  /*        */ \
    0b00010   /*   *    (Dot below the letter) */ \
}
//chacter ت
#define TAA { \
    0b00000,  /*        */ \
    0b01010,  /*  * *   (Two dots above the letter) */ \
    0b00000,  /*        */ \
    0b01110,  /*  ***   (Top horizontal line) */ \
    0b00001,  /*      * (Right edge vertical) */ \
    0b01111,  /*  ****  (Bottom line) */ \
    0b00000,  /*        */ \
    0b00000   /*        (Empty bottom row) */ \
}
//character ث
#define THAA { \
    0b01010,  /*  * *   (Two dots) */ \
    0b00100,  /*   *    (Middle dot) */ \
    0b00000,  /*        (Space) */ \
    0b01110,  /*  ***   (Top horizontal line) */ \
    0b00001,  /*      * (Right edge vertical) */ \
    0b01111,  /*  ****  (Bottom line) */ \
    0b00000,  /*        (Space below) */ \
    0b00000   /*        (Empty bottom row) */ \
}
//character ج
#define JEEM { \
    0b00000,  /*        */ \
    0b00000,  /*        */ \
    0b00000,  /*        */ \
    0b00111,  /*   ***  (Top curve) */ \
    0b00100,  /*   *    (Vertical part) */ \
    0b00100,  /*   *    (Vertical part) */ \
    0b01111,  /*  ****  (Bottom curve) */ \
    0b00010   /*   *    (Dot below) */ \
}
//character ح
#define HAA { \
    0b00000,  /*        */ \
    0b00000,  /*        */ \
    0b00000,  /*        */ \
    0b01110,  /*  ***   (Top curve) */ \
    0b01000,  /*  *     (Left vertical line) */ \
    0b01000,  /*  *     (Left vertical line) */ \
    0b01110,  /*  ***   (Bottom curve) */ \
    0b00000   /*        (Empty bottom row) */ \
}
//character خ 
#define KHAA { \
    0b00100,  /*   *    (Dot above the character) */ \
    0b00000,  /*        (Space) */ \
    0b00000,  /*        (Space) */ \
    0b01110,  /*  ***   (Top curve) */ \
    0b00010,  /*     *  (Right vertical line) */ \
    0b00010,  /*     *  (Right vertical line) */ \
    0b01111,  /*  ****  (Bottom curve) */ \
    0b00000   /*        (Empty bottom row) */ \
}
// character د
#define DAAL { \
    0b00000,  /*        */ \
    0b00000,  /*        */ \
    0b00000,  /*        */ \
    0b01110,  /*  ***   (Top curve) */ \
    0b00001,  /*      * (Right vertical line) */ \
    0b00001,  /*      * (Right vertical line) */ \
    0b01111,  /*  ****  (Bottom curve) */ \
    0b00000   /*        (Empty bottom row) */ \
}
// character ذ
#define DHAL { \
    0b00100,  /*   *    (Dot above the character) */ \
    0b00000,  /*        (Space) */ \
    0b00000,  /*        (Space) */ \
    0b01110,  /*  ***   (Top curve) */ \
    0b00001,  /*      * (Right vertical line) */ \
    0b00001,  /*      * (Right vertical line) */ \
    0b01111,  /*  ****  (Bottom curve) */ \
    0b00000   /*        (Empty bottom row) */ \
}
//character ر
#define RAA { \
    0b00000,  /*        */ \
    0b00000,  /*        */ \
    0b01110,  /*  ***   */ \
    0b00001,  /*      * */ \
    0b00010,  /*     *  */ \
    0b00010,  /*     *  */ \
    0b01111,  /*  ****  */ \
    0b00000   /*        */ \
}
//character ز
#define ZAA { \
    0b00000,  /*        */ \
    0b00100,  /*   *    */ \
    0b00100,  /*   *    */ \
    0b01110,  /*  ***   */ \
    0b00100,  /*   *    */ \
    0b00010,  /*     *  */ \
    0b00000,  /*        */ \
    0b00000   /*        */ \
}
//character س 
#define SAA { \
    0b00000,  /*        */ \
    0b01110,  /*  ***   */ \
    0b00010,  /*     *  */ \
    0b00100,  /*   *    */ \
    0b00010,  /*     *  */ \
    0b01110,  /*  ***   */ \
    0b00000,  /*        */ \
    0b00000   /*        */ \
}
// character ش
#define SHEEN { \
    0b01110,  /*  ***   */ \
    0b10001,  /* *   *  */ \
    0b01110,  /*  ***   */ \
    0b00010,  /*     *  */ \
    0b01110,  /*  ***   */ \
    0b00000,  /*        */ \
    0b00000,  /*        */ \
    0b00000   /*        */ \
}
//character ض
#define DAD { \
    0b01110,  /*  ***   */ \
    0b10001,  /* *   *  */ \
    0b01110,  /*  ***   */ \
    0b00001,  /*      * */ \
    0b00001,  /*      * */ \
    0b01111,  /*  ****  */ \
    0b00000,  /*        */ \
    0b00000   /*        */ \
}
//character ع
#define AIN { \
    0b00100,  /*   *    */ \
    0b01110,  /*  ***   */ \
    0b00001,  /*      * */ \
    0b00001,  /*      * */ \
    0b01110,  /*  ***   */ \
    0b00000,  /*        */ \
    0b00000,  /*        */ \
    0b00000   /*        */ \
}
//chacter غ
#define GHAIN { \
    0b01110,  /*  ***   */ \
    0b10001,  /* *   *  */ \
    0b01111,  /*  ****  */ \
    0b00001,  /*      * */ \
    0b10001,  /* *   *  */ \
    0b01110,  /*  ***   */ \
    0b00000,  /*        */ \
    0b00000   /*        */ \
}
#define CONNECTED_JEEM { \
    0b00000,  /*        */ \
    0b00110,  /*   **   */ \
    0b01001,  /*  *  *  */ \
    0b01111,  /*  ****  */ \
    0b00010,  /*     *  */ \
    0b00100,  /*   *    */ \
    0b00000,  /*        */ \
    0b00000   /*        */ \
}
#endif /* HLCD_PRIVATE_H_ */
