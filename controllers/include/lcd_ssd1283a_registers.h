/*
 * MIT License
 *
 * Copyright (c) 2022 Damian Ślusarczyk
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 * and associated documentation files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */
/**
 * @file lcd_ssd1283a_registers.h
 * @author Damian Ślusarczyk
 * @brief Contains all SSD1283A register information as a set of macros.
 * 
 * They are used for appropriate writing values into memory of SSD1283A controller.
 */
#ifndef LCD_SSD1283A_REGISTERS_H
#define LCD_SSD1283A_REGISTERS_H

#define SSD1283A_OSCILLATION                                0x00    /**< Memory address for "Oscillator" register */
#define SSD1283A_DRIVER_OUTPUT_CTRL                         0x01    /**< Memory address for "Driver Output Control" register */
#define SSD1283A_DRIVER_AC_CTRL                             0x02    /**< Memory address for "LCD-Driving-Waveform Control" register */
#define SSD1283A_ENTRY_MODE                                 0x03    /**< Memory address for "Entry Mode" register */
#define SSD1283A_CMP_REG_1                                  0x04    /**< Memory address for "Compare Register 1" register */
#define SSD1283A_CMP_REG_2                                  0x05    /**< Memory address for "Compare Register 2" register */
#define SSD1283A_DISPLAY_CTRL                               0x07    /**< Memory address for "Display Control" Register */
#define SSD1283A_FRAME_CYCLE_CTRL                           0x0B    /**< Memory address for "Frame Cycle Control" register */
#define SSD1283A_POWER_CTRL_1                               0x10    /**< Memory address for "Power Control 1" register */
#define SSD1283A_POWER_CTRL_2                               0x11    /**< Memory address for "Power Control 2" register */
#define SSD1283A_POWER_CTRL_3                               0x12    /**< Memory address for "Power Control 3" register */
#define SSD1283A_POWER_CTRL_4                               0x13    /**< Memory address for "Power Control 4" register */
#define SSD1283A_HORIZONTAL_PORCH                           0x16    /**< Memory address for "Horizontal Porch" register */
#define SSD1283A_VERTICAL_PORCH                             0x17    /**< Memory address for "Vertical Porch" register */
#define SSD1283A_POWER_CTRL_5                               0x1E    /**< Memory address for "Power Control 5" register */
#define SSD1283A_POWER_CTRL_6                               0x1F    /**< Memory address for "Power Control 6" register */
#define SSD1283A_RAM_SET                                    0x21    /**< Memory address for "RAM Address Set" register */
#define SSD1283A_RAM_WRITE                                  0x22    /**< Memory address for "Write Data to GRAM" register */
#define SSD1283A_RAM_READ                                   0x22    /**< Memory address for "Read Data from GRAM" register */
#define SSD1283A_RAM_WRITE_MASK_1                           0x23    /**< Memory address for "RAM Write Data Mask 1" register */
#define SSD1283A_RAM_WRITE_MASK_2                           0x24    /**< Memory address for "RAM Write Data Mask 2" register */
#define SSD1283A_VCOM_OTP_1                                 0x28    /**< Memory address for "Vcom OTP 1" register */
#define SSD1283A_VCOM_OTP_2                                 0x29    /**< Memory address for "Vcom OTP 2" register */
#define SSD1283A_GAMMA_CTRL_01                              0x30    /**< Memory address for "Gamma Control 1" register */
#define SSD1283A_GAMMA_CTRL_02                              0x31    /**< Memory address for "Gamma Control 2" register */
#define SSD1283A_GAMMA_CTRL_03                              0x32    /**< Memory address for "Gamma Control 3" register */
#define SSD1283A_GAMMA_CTRL_04                              0x33    /**< Memory address for "Gamma Control 4" register */
#define SSD1283A_GAMMA_CTRL_05                              0x34    /**< Memory address for "Gamma Control 5" register */
#define SSD1283A_GAMMA_CTRL_06                              0x35    /**< Memory address for "Gamma Control 6" register */
#define SSD1283A_GAMMA_CTRL_07                              0x36    /**< Memory address for "Gamma Control 7" register */
#define SSD1283A_GAMMA_CTRL_08                              0x37    /**< Memory address for "Gamma Control 8" register */
#define SSD1283A_GAMMA_CTRL_09                              0x38    /**< Memory address for "Gamma Control 9" register */
#define SSD1283A_GAMMA_CTRL_10                              0x39    /**< Memory address for "Gamma Control 10" register */
#define SSD1283A_GATE_SCAN                                  0x40    /**< Memory address for "Gate Scan Position" register */
#define SSD1283A_VERTICAL_SCROLL_CTRL                       0x41    /**< Memory address for "Vertical Scroll Control" register */
#define SSD1283A_1ST_DISPLAY                                0x42    /**< Memory address for "1st Screen Driving Position" register */
#define SSD1283A_2ND_DISPLAY                                0x43    /**< Memory address for "2nd Screen Driving Position" register */
#define SSD1283A_HORIZONTAL_RAM_SET                         0x44    /**< Memory address for "Horizontal RAM Address Position" register */
#define SSD1283A_VERTICAL_RAM_SET                           0x45    /**< Memory address for "Vertical RAM Address Position" register */

/** The most significant byte value for "Display Control" register in the *first* step to turn on LCD SSD1283A display */
#define SSD1283A_DISPLAY_CTRL_DISPLAYON1_MSB                0x00
/** The least significant byte value for "Display Control" register in the *first* step to turn on LCD SSD1283A display */
#define SSD1283A_DISPLAY_CTRL_DISPLAYON1_LSB                0x21

/** The most significant byte value for "Oscillator" register to turn on LCD SSD1283A display */
#define SSD1283A_OSCILLATION_DISPLAYON_MSB                  0x00
/** The least significant byte value for "Oscillator" register to turn on LCD SSD1283A display */
#define SSD1283A_OSCILLATION_DISPLAYON_LSB                  0x01

/** The most significant byte value for "Display Control" register in the *second* step to turn on LCD SSD1283A display */
#define SSD1283A_DISPLAY_CTRL_DISPLAYON2_MSB                0x00
/** The least significant byte value for "Display Control" register in the *second* step to turn on LCD SSD1283A display */
#define SSD1283A_DISPLAY_CTRL_DISPLAYON2_LSB                0x23

/** The most significant byte value for "Power Control 1" register to turn on LCD SSD1283A display */
#define SSD1283A_POWER_CTRL_1_DISPLAYON_MSB                 0x2F
/** The least significant byte value for "Power Control 1" register to turn on LCD SSD1283A display */
#define SSD1283A_POWER_CTRL_1_DISPLAYON_LSB                 0xC4

/** The most significant byte value for "Display Control" register in the *third* step to turn on LCD SSD1283A display */
#define SSD1283A_DISPLAY_CTRL_DISPLAYON3_MSB                0x00
/** The least significant byte value for "Display Control" register in the *third* step to turn on LCD SSD1283A display */
#define SSD1283A_DISPLAY_CTRL_DISPLAYON3_LSB                0x33

/** The most significant byte value for "Driver Output Control" register to initialize LCD SSD1283A display */
#define SSD1283A_DRIVER_OUTPUT_CTRL_INIT_MSB                0x23
/** The least significant byte value for "Driver Output Control" register to initialize LCD SSD1283A display */
#define SSD1283A_DRIVER_OUTPUT_CTRL_INIT_LSB                0x83

/** The most significant byte value for "Entry Mode" register to initialize LCD SSD1283A display */
#define SSD1283A_ENTRY_MODE_INIT_MSB                        0x68
/** The least significant byte value for "Entry Mode" register to initialize LCD SSD1283A display */
#define SSD1283A_ENTRY_MODE_INIT_LSB                        0x20

/** The most significant byte value for "LCD-Driving-Waveform Control" register to initialize LCD SSD1283A display */
#define SSD1283A_DRIVER_AC_CTRL_INIT_MSB                    0x00
/** The least significant byte value for "LCD-Driving-Waveform Control" register to initialize LCD SSD1283A display */
#define SSD1283A_DRIVER_AC_CTRL_INIT_LSB                    0x00

/** The most significant byte value for "Display Control" register to turn off LCD SSD1283A display */
#define SSD1283A_DISPLAY_CTRL_DISPLAYOFF_MSB                0x00
/** The least significant byte value for "Display Control" register to turn off LCD SSD1283A display */
#define SSD1283A_DISPLAY_CTRL_DISPLAYOFF_LSB                0x00

/** The most significant byte value for "Oscillator" register to turn off LCD SSD1283A display */
#define SSD1283A_OSCILLATION_DISPLAYOFF_MSB                 0x00
/** The least significant byte value for "Oscillator" register to turn off LCD SSD1283A display */
#define SSD1283A_OSCILLATION_DISPLAYOFF_LSB                 0x00

/** The most significant byte value for "Power Control 1" register to turn off LCD SSD1283A display */
#define SSD1283A_POWER_CTRL_1_DISPLAYOFF_MSB                0x00
/** The least significant byte value for "Power Control 1" register to turn off LCD SSD1283A display */
#define SSD1283A_POWER_CTRL_1_DISPLAYOFF_LSB                0x01

#endif /* LCD_SSD1283A_REGISTERS_H */
