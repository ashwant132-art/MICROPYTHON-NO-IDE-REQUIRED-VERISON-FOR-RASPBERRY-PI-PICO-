// Board and hardware specific configuration
#define MICROPY_HW_BOARD_NAME               "Raspberry Pi Pico"
#define MICROPY_HW_USB_MSC (1)

#undef MICROPY_HW_FLASH_STORAGE_BYTES
#define MICROPY_HW_FLASH_STORAGE_BYTES (1024 * 1024)
// Force the USB Mass Storage interface to be read-only to the host PC 
// or write-protected to prevent dual-write sector collisions.
#define MICROPY_HW_USB_MSC_READONLY (0)
