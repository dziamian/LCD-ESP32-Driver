#ifndef LCD_SSD1283A_REGISTERS_H
#define LCD_SSD1283A_REGISTERS_H

#define SSD1283A_OSCILLATION                                0x00
#define SSD1283A_DRIVER_OUTPUT_CTRL                         0x01
#define SSD1283A_DRIVER_AC_CTRL                             0x02
#define SSD1283A_ENTRY_MODE                                 0x03
#define SSD1283A_CMP_REG_1                                  0x04
#define SSD1283A_CMP_REG_2                                  0x05
#define SSD1283A_DISPLAY_CTRL                               0x07
#define SSD1283A_FRAME_CYCLE_CTRL                           0x0B
#define SSD1283A_POWER_CTRL_1                               0x10
#define SSD1283A_POWER_CTRL_2                               0x11
#define SSD1283A_POWER_CTRL_3                               0x12
#define SSD1283A_POWER_CTRL_4                               0x13
#define SSD1283A_HORIZONTAL_PORCH                           0x16
#define SSD1283A_VERTICAL_PORCH                             0x17
#define SSD1283A_POWER_CTRL_5                               0x1E
#define SSD1283A_POWER_CTRL_6                               0x1F
#define SSD1283A_RAM_SET                                    0x21
#define SSD1283A_RAM_WRITE                                  0x22
#define SSD1283A_RAM_READ                                   0x22
#define SSD1283A_RAM_WRITE_MASK_1                           0x23
#define SSD1283A_RAM_WRITE_MASK_2                           0x24
#define SSD1283A_VCOM_OTP_1                                 0x28
#define SSD1283A_VCOM_OTP_2                                 0x29
#define SSD1283A_GAMMA_CTRL_01                              0x30
#define SSD1283A_GAMMA_CTRL_02                              0x31
#define SSD1283A_GAMMA_CTRL_03                              0x32
#define SSD1283A_GAMMA_CTRL_04                              0x33
#define SSD1283A_GAMMA_CTRL_05                              0x34
#define SSD1283A_GAMMA_CTRL_06                              0x35
#define SSD1283A_GAMMA_CTRL_07                              0x36
#define SSD1283A_GAMMA_CTRL_08                              0x37
#define SSD1283A_GAMMA_CTRL_09                              0x38
#define SSD1283A_GAMMA_CTRL_10                              0x39
#define SSD1283A_GATE_SCAN                                  0x40
#define SSD1283A_VERTICAL_SCROLL_CTRL                       0x41
#define SSD1283A_1ST_DISPLAY                                0x42
#define SSD1283A_2ND_DISPLAY                                0x43
#define SSD1283A_HORIZONTAL_RAM_SET                         0x44
#define SSD1283A_VERTICAL_RAM_SET                           0x45

#define SSD1283A_DISPLAY_CTRL_INIT1_MSB                     0x00
#define SSD1283A_DISPLAY_CTRL_INIT1_LSB                     0x21

#define SSD1283A_OSCILLATION_INIT_MSB                       0x00
#define SSD1283A_OSCILLATION_INIT_LSB                       0x01

#define SSD1283A_DISPLAY_CTRL_INIT2_MSB                     0x00
#define SSD1283A_DISPLAY_CTRL_INIT2_LSB                     0x23

#define SSD1283A_POWER_CTRL_1_INIT_MSB                      0x2F
#define SSD1283A_POWER_CTRL_1_INIT_LSB                      0xC4

#define SSD1283A_DISPLAY_CTRL_INIT3_MSB                     0x00
#define SSD1283A_DISPLAY_CTRL_INIT3_LSB                     0x33

#define SSD1283A_DRIVER_OUTPUT_CTRL_INIT_MSB                0x23
#define SSD1283A_DRIVER_OUTPUT_CTRL_INIT_LSB                0x83

#define SSD1283A_ENTRY_MODE_INIT_MSB                        0x68
#define SSD1283A_ENTRY_MODE_INIT_LSB                        0x20

#define SSD1283A_DRIVER_AC_CTRL_INIT_MSB                    0x00
#define SSD1283A_DRIVER_AC_CTRL_INIT_LSB                    0x00

#endif /* LCD_SSD1283A_REGISTERS_H */
