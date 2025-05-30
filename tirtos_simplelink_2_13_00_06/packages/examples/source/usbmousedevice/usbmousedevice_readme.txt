Example Summary
---------------
Sample application to connect to a USB host as a mouse HID device.

Peripherals Exercised
---------------------
Board_LED0      Indicator LED
Board_BUTTON0   Used to simulate a primary mouse button
Board_USBDEVICE Used as HID Mouse device*

Resources & Jumper Settings
---------------------------
Please refer to the development board's specific "Settings and Resources"
section in the Getting Started Guide. For convenience, a short summary is also
shown below.

| Development board | Notes                                                  |
| ================= | ====================================================== |
| DK-TM4C123G       | Please ensure that the board is connected to your host |
| DK-TM4C129X       | via a USB cable. A VCOM (virtual COM) port driver may  |
| EK-TM4C123GXL     | need to be installed.                                  |
| EK-TM4C1294XL     |                                                        |
| MSP-EXP430F5529   |                                                        |
| MSP-EXP430F5529LP |                                                        |
| TMDXDOCK28M36     |                                                        |
| ----------------- | ------------------------------------------------------ |
| TMDXDOCKH52C1     | Please ensure that the board is connected to your host |
|                   | via a USB cable. A VCOM (virtual COM) port driver may  |
|                   | need to be installed.                                  |
|                   | Connectivity Bank 30-31: B-C position (USB)            |
| ----------------- | ------------------------------------------------------ |

Example Usage
-------------
Run the example. Board_LED0 turns ON to indicate TI-RTOS driver
initialization is complete.

The example acts as a mouse to your host; it moves the cursor in a figure eight
pattern.  Pressing Board_BUTTON0 performs a primary click.

If the moving mouse gets annoying, you can suspend the target by hitting Alt-F8
in CCS.

USB drivers can be found at the following locations:
    Tiva USB Drivers:
    Windows USB drivers are located in the products directory:
    <tirtos_install_dir>\products\<TivaWare_install_dir>\windows_drivers

    MSP430 USB Drivers:
    Windows USB drivers are located within the CCS project's USB_config/
    directory.

    Concerto Family USB Drivers:
    Windows USB drivers are located in the products directory:
    <tirtos_install_dir>\products\<MWare_install_dir>\windows_drivers

Application Design Details
--------------------------
This application uses one tasks:

  'mouse' performs the following actions:
      Waits for the device to connected to a USB host.

      Once connected it sends predefined mouse offsets (from the
      mouseLookupTable[]) along with primary click status.

For GNU and IAR users, please read the following website for details about
semi-hosting:
    http://processors.wiki.ti.com/index.php/TI-RTOS_Examples_SemiHosting
