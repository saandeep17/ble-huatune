Example Summary
----------------
This application demonstrates how to use HTTP Client.

Peripherals Exercised
---------------------
Board_LED0      Indicates that the board was initialized within main()
Board_EMAC      Connection to network

Resources & Jumper Settings
---------------------------
Please refer to the development board's specific "Settings and Resources"
section in the Getting Started Guide. For convenience, a short summary is also
shown below.

| Development board | Notes                                                  |
| ================= | ====================================================== |
| EK-TM4C1294XL     | N/A                                                    |
| ----------------- | ------------------------------------------------------ |

Build Details
-------------

Before building the application, change the application code in "httpget.c"
marked by "USER STEP" as needed.

Example Usage
-------------
The device must be connected to internet to run this example successfully.

The example turns ON Board_LED0 and starts the network stack. When the stack
receives an IP address from the DHCP server, the IP address is written to the
console.

The example then makes an HTTP GET call to "openweathermap.org" to fetch the
weather information for the city defined and print it to the console.

Application Design Details
--------------------------
This application uses a task for HTTP communication:

httpTask  Creates a connection to the HTTP server. When a connection is
          established, makes an HTTP GET method call using the request URI. The
          response status code, header fields and body from the HTTP server are
          processed to extract the weather information. The connection is
          closed and resources are freed before the task exits.

For GNU and IAR users, please read the following website for details about
semi-hosting:
    http://processors.wiki.ti.com/index.php/TI-RTOS_Examples_SemiHosting
