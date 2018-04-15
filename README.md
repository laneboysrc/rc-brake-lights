# RC Brake & Reversing Light controller

This project is an easy-to-build light controller for Radio Controlled cars that simulates realistic brake and reversing lights.

It hooks between your ESC and receiver.

The brake lights automatically turn on for a short, random time when the throttle goes to neutral. The reversing lights turn on when driving backwards.

The light controller supports various ESC modes to ensure the lights are in sync with the way your ESC controlls the drive motor.

The aim of the project is to make it easy to build anyone with minimal electronics knowledge. If you are unable to build it yourself please contact [laneboysrc@gmail.com]<laneboysrc@gmail.com>; we'd be happy to sell you one.

If you are looking for more features check out our original [DIY RC Light Controller](https://github.com/laneboysrc/rc-light-controller).


## Building the electronics

The core of the light controller is the inexpensive STC STC15W104. It is a modern interpretation of the venerable 8051 MCU. This MCU was chosen due to its very low cost and because it can be programmed with an inexpensive USB-to-serial adapter, or using the serial port on a Raspberry Pi.

You can find the STC15W104 usually on eBay, AliExpress, Electrodragon, LSCS ...

Beside the MCU you need 3 resistors, a diode and a capacitor. The complete [list of components](electronics/BOM%20-%20Bill%20of%20Materials.txt) can be found in the `electronics/` folder

Due to the small number of required components, the light controller can be easily built on a perfboard. The follwing image shows how to wire everything up:

![Perfboard construction](electronics/rc-brake-lights_breadboard.png)

(The [Fritzing](http://fritzing.org) source file for this drawing is provided in the `fritzing/` folder)

If you plan to build several controllers it may be worth-wile to order printed circuit boards. [Gerber files](gerber-rc-brake-lights.zip) for manufacturing PCBS are provided, as well as the [KiCad source files](electronics/). Note that the PCB uses SMD components rather than through-hole. Still, it is designed for hand-soldering.


## Loading the firmware

You can find the pre-compiled firmware released as part of the project.

If you want to build or modify the firmware you will need [SDCC](http://sdcc.sourceforge.net) and [GNU Make](https://www.gnu.org/software/make/).

To flash the firmware into the STC15W104, use [STCGAL](https://github.com/grigorig/stcgal).

### Using a USB-to-serial adapter

// FIXME

### Using a Raspberry Pi

// FIXME


## Connecting the light controller to your RC system

The light controller plugs between your ESC and receiver. The `B` output drives two red LEDs in parallel for the brake light function, the `R` output drives two white LEDs in parallel for the reversing light function.

![Wiring diagram](doc/rc-brake-lights-wiring.png)


## Setup

Depending on your RC system, out of the box the light controller may operate in the wrong direction (forward and backward reversed). To change this, press and hold the setup button on the light controller for 3 seconds. The LEDs will start flashing quickly.

Now move the throttle on the transmitter to the `forward` driving direction. When LEDs will go out and the light controller has now learned the correct direction of the throttle signal for `forward`. This setting is preserved, so you only have to do this once.


## Changing the ESC mode

When it comes to brake function, ESC models behave differently. The light controller can be programmed for the specific behaviour of your ESC. The following modes are supported:

### Forward/Brake/Reverse with timeout
When driving forward and then immediately pushing the throttle to reverse, the ESC performs a brake function. The ESC only allows driving backwards if the ESC has remained in neutral position for a few seconds.

Example: The China 320A ESC, HPI SC-15WP

### Forward/Brake/Reverse
After going forward and then into reverse, the ESC always performs the brake function -- even if the throttle remained in neutral for a long time.

Example: Tamiya ESCs

### Forward/Reverse (Crawler mode)
Crawler ESC with drag brake, where the ESC switches from forward directly
into reverse.

### Forward/Brake
ESC in race mode where reversing is not allowed.


To change the ESC mode, perform the following steps:
Press and hold the setup button on the light controller. After 3 seconds, the LEDs will start to flash quickly. Press the setup button one more time. The light controller enters the ESC mode setting and flashes the current ESC mode number:

* 1 flash: Forward/Brake/Reverse with timeout
* 2 flashes: Forward/Brake/Reverse
* 3 flashes: Forward/Reverse (Crawler mode)
* 4 flashes: Forward/Brake

Press the setup button repeatadly until the desired ESC mode has been selected. Then press-and hold the setup button unitl the LEDs stop flashing. The ESC mode has now been persistently stored.

