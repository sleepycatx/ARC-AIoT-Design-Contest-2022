#ifndef _MPU_9250_H
#define _MPU_9250_H

#include <stdint.h>

#include "hx_drv_iic_m.h"

#define MPU_9250_REG_SELF_TEST_X_GYRO        (0x00)
#define MPU_9250_REG_SELF_TEST_Y_GYRO        (0x01)
#define MPU_9250_REG_SELF_TEST_Z_GYRO        (0x02)
#define MPU_9250_REG_MAG_CNTL                (0x0A)
#define MPU_9250_REG_SELF_TEST_X_ACCEL       (0x0D)
#define MPU_9250_REG_SELF_TEST_Y_ACCEL       (0x0E)
#define MPU_9250_REG_SELF_TEST_Z_ACCEL       (0x0F)
#define MPU_9250_REG_XG_OFFSET_H             (0x13)
#define MPU_9250_REG_XG_OFFSET_L             (0x14)
#define MPU_9250_REG_YG_OFFSET_H             (0x15)
#define MPU_9250_REG_YG_OFFSET_L             (0x16)
#define MPU_9250_REG_ZG_OFFSET_H             (0x17)
#define MPU_9250_REG_ZG_OFFSET_L             (0x18)
#define MPU_9250_REG_SMPLRT_DIV              (0x19)
#define MPU_9250_REG_CONFIG                  (0x1A)
#define MPU_9250_REG_GYRO_CONFIG             (0x1B)
#define MPU_9250_REG_ACCEL_CONFIG            (0x1C)
#define MPU_9250_REG_ACCEL_CONFIG2           (0x1D)
#define MPU_9250_REG_LP_ACCEL_ODR            (0x1E)
#define MPU_9250_REG_WOM_THR                 (0x1F)
#define MPU_9250_REG_FIFO_EN                 (0x23)
#define MPU_9250_REG_INT_PIN_CFG             (0x37)
#define MPU_9250_REG_INT_ENABLE              (0x38)
#define MPU_9250_REG_INT_STATUS              (0x3A)
#define MPU_9250_REG_ACCEL_XOUT_H            (0x3B)
#define MPU_9250_REG_ACCEL_XOUT_L            (0x3C)
#define MPU_9250_REG_ACCEL_YOUT_H            (0x3D)
#define MPU_9250_REG_ACCEL_YOUT_L            (0x3E)
#define MPU_9250_REG_ACCEL_ZOUT_H            (0x3F)
#define MPU_9250_REG_ACCEL_ZOUT_L            (0x40)
#define MPU_9250_REG_TEMP_OUT_H              (0x41)
#define MPU_9250_REG_TEMP_OUT_L              (0x42)
#define MPU_9250_REG_GYRO_XOUT_H             (0x43)
#define MPU_9250_REG_GYRO_XOUT_L             (0x44)
#define MPU_9250_REG_GYRO_YOUT_H             (0x45)
#define MPU_9250_REG_GYRO_YOUT_L             (0x46)
#define MPU_9250_REG_GYRO_ZOUT_H             (0x47)
#define MPU_9250_REG_GYRO_ZOUT_L             (0x48)
#define MPU_9250_REG_SIGNAL_PATH_RESET       (0x68)
#define MPU_9250_REG_MOT_DETECT_CTRL         (0x69)
#define MPU_9250_REG_USER_CTRL               (0x6A)
#define MPU_9250_REG_PWR_MGMT_1              (0x6B)
#define MPU_9250_REG_PWR_MGMT_2              (0x6C)
#define MPU_9250_REG_FIFO_COUNTH             (0x72)
#define MPU_9250_REG_FIFO_COUNTL             (0x73)
#define MPU_9250_REG_FIFO_R_W                (0x74)
#define MPU_9250_REG_WHO_AM_I                (0x75)
#define MPU_9250_REG_XA_OFFSET_H             (0x77)
#define MPU_9250_REG_XA_OFFSET_L             (0x78)
#define MPU_9250_REG_YA_OFFSET_H             (0x7A)
#define MPU_9250_REG_YA_OFFSET_L             (0x7B)
#define MPU_9250_REG_ZA_OFFSET_H             (0x7D)
#define MPU_9250_REG_ZA_OFFSET_L             (0x7E)

typedef enum
{
    ACCEL_FULL_SCALE_2G  = 0,
    ACCEL_FULL_SCALE_4G  = 1,
    ACCEL_FULL_SCALE_8G  = 2,
    ACCEL_FULL_SCALE_16G = 3,
}mpu_9250_accel_full_scale_t;

typedef enum
{
    FIFO_MODE_REPLACE_OLDEST_DATA_WHEN_FIFO_FULL = 0,
    FIFO_MODE_STOP_ADDTIONAL_WRITES_WHEN_FIFO_FULL = 1,
}mpu_9250_fifo_mode_t;

typedef struct
{
    uint8_t accel_full_scale;  
}mpu_9250_config_t;

typedef struct
{
    union
    {
        uint8_t ubyte;        
        struct
        {
            uint8_t reserved:3;
            uint8_t accel_fs_sel:2;
            uint8_t az_st_en:1;
            uint8_t ay_st_en:1;
            uint8_t ax_st_en:1;      
        }bitfields;
    };    
}mpu_reg_accel_config_t;

typedef struct
{
    union
    {
        uint8_t ubyte;  
        struct
        {
            uint8_t accel_lpf_config:3;
            uint8_t accel_fchoice_b:1;
            uint8_t reserved:4;
            
        }bitfields;
    };
}mpu_reg_accel_config2_t;

typedef struct
{
    union
    {
        uint8_t ubyte;    
        struct
        {
            uint8_t dlpf_config:3;
            uint8_t ext_sync_set:3;
            uint8_t fifo_mode:1;
            uint8_t reserved:1;
            
        }bitfields;
    };
}mpu_reg_config_t;

typedef struct
{
    union
    {
        uint8_t ubyte;     
        struct
        {
            uint8_t slv_0:1;
            uint8_t slv_1:1;
            uint8_t slv_2:1;
            uint8_t accel:1;
            uint8_t gyro_zout:1;
            uint8_t gyro_yout:1;
            uint8_t gyro_xout:1;
            uint8_t temp_out:1;
        }bitfields;    
    };    
}mpu_reg_fifo_enable_t;

typedef struct
{
    union
    {
        uint8_t ubyte; 
        struct
        {
            uint8_t sig_cond_rst:1;
            uint8_t i2c_mst_rst:1;
            uint8_t fifo_rst:1;
            uint8_t reserved1:1;
            uint8_t i2c_if_dis:1;
            uint8_t i2c_mst_en:1;
            uint8_t fifo_en:1;
            uint8_t reserved2:1;
        }bitfields;    
    };
    
}mpu_reg_user_ctrl_t;

typedef struct
{
    union
    {
        uint8_t ubyte; 
        struct
        {
            uint8_t clksel:3;
            uint8_t pd_ptat:1;
            uint8_t gyro_standby:1;
            uint8_t cycle:1;
            uint8_t sleep:1;
            uint8_t h_reset:1;
            
        }bitfields;

    }; 
}mpu_reg_pwr_mgmt1_t;



typedef struct
{
    union
    {
        uint8_t ubyte;
        struct
        {
            uint8_t disabled_zg:1;
            uint8_t disabled_yg:1;
            uint8_t disabled_xg:1;
            uint8_t disabled_za:1;
            uint8_t disabled_ya:1;
            uint8_t disabled_xa:1;
            uint8_t reserved:2;            
        }bitfields;
    };
}mpu_reg_pwr_mgmt2_t;

uint8_t mpu9250_init(void);
void mpu9250_Get_Data(int16_t* x, int16_t* y, int16_t* z);
void I2C_mpu9250_WRITE_API(uint8_t reg_addr, uint8_t reg_data);
void I2C_mpu9250_READ_API(uint8_t reg_addr, uint8_t* read_buf, uint8_t read_len);

#endif