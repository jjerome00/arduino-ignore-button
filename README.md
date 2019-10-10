# arduino-ignore-button

This code is for an art project. The button will start the device, but ignore any extra button presses for a set amount of time.

You can read more about it here:   
https://www.jjerome.com/2019/07/03/using-arduino-to-ignore-button-presses/

![bread board diagram](bread_board_diagram.png)


## Documentation of Arduino and LED button
The button I am going to use has a built-in LED, so I incorporated it into the design. The button has 4 terminals:   
* 2 vertical: those are for powering the LED   
* 2 horizontal: those are for the button

The relay has 2 positive and 1 negative for providing the power for triggering the Relay.
* pins labeled `S` and `+` must be connected together to positive.
* pin labeled `-` must be connected to negative (neutral)
* Common - goes to one garage door switch terminal
* NO (normally open) - goes to the other garage door switch terminal

#### Arduino

To button LED:
* `GND` (ground) - goes to LED button
* `Digital ~10` - goes to LED button (neutral)

To button:
* `Digital ~9` - goes to button switch
* `GND` (ground) - goes to button switch

To relay:
* `5V` - goes to +/S on rely
* `Digital ~5` - goes to `-` on relay
