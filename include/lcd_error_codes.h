#ifndef LCD_ERROR_CODES_H
#define LCD_ERROR_CODES_H

typedef enum LCD_error_t        LCD_error_t;

enum LCD_error_t
{
    LCD_OK = 0,
    LCD_INV_ARG,
    LCD_INV_OP,
    LCD_INV_RES,
    LCD_COM_FAIL,
};

#endif /* LCD_ERROR_CODES_H */
