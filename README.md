🌟 Key Features

☆ Fixed Flash Allocation: Custom-compiled at a hard 1MB storage boundary . 

☆ Completely fixes the bug where the Pico panics and wipes/deletes your main.py file on reboot.

*CPU Overclocked to 200MHz

☆ Slick Drive Identity: Set up to cleanly mount as a reliable virtual drive just like Circuitpython 

💾 Installation

(1)Hold the BOOTSEL button on your Pico and plug it into your computer.

(2)Drag and drop the firmware.uf2 file from this repository releases onto the RPI-RP2 volume.

(3)Once it reboots, open the drive, drop your main.py code in, and watch it run at top speed without ever losing your files again!
YOU ALSO MAY RENAME THE DRIVE TO WHATEVER YOU LIKE

ITS THAT EASY

next in uploading code go to the pico's drive and create a text file then name it into boot
now copy and paste the code below (reset mechanism using BOOTSEL button)
*****************************************************************************************************************************************
import machine, rp2

machine.freq(200_000_000)

def check_reset(t):
    if rp2.bootsel_button():
        while rp2.bootsel_button():
            pass
        machine.reset()

tim = machine.Timer()
tim.init(period=100, mode=machine.Timer.PERIODIC, callback=check_reset)
******************************************************************************************************************************************

now in notepad click File-Save As then file name boot.py,then change save as type to all files and save it to the root directory of the pico drive not the RPI-RP2 drive

NOW UNPLUG THE PICO AND PLUG IT BACK IN AND THE DRIVE SHOULD POP UP AGAIN NOW PRESS THE BOOTSEL BUTTON AND THE DRIVE SHOULD DISAPPEAR AND APPEAR AGAIN (IF NOT PRESS THE REFRESH BUTTON IN EXPLORER)

now to upload our main.py code create a new txt file there change its name to main then open it in notepad and paste this code

******************************************************************************************************************************************
from machine import Pin
import time

# "LED" automatically targets the onboard LED across all Pico models
led = Pin("LED", Pin.OUT)

while True:
    led.toggle()      # Switches the LED state (On to Off / Off to On)
    time.sleep(0.5)   # Pauses for 0.5 seconds (Change this to adjust speed)
******************************************************************************************************************************************
then file-save as,then name -main.py and change save as type to all files (this is way we upload code here it applies for any code) and save it to the root of the pico,now if you look at the pico the led wont blink,beacuse there is one more step that is to press the BOOTSEL button to reset the pico ans thats the end of this readme


***********************______**************************THE END**************************************************************************
