# servo_calibration

An Arduino sketch for calibrating the servos and finding the maximum and minimum PWM values for the servos to rotate from 0 to 180 degrees. Attach each servo to a specific port on the PWM servo driver and go through the tedious process of trial and error to find out the limits. **Up to 16 servos can be attached, but only one servo can be calibrated at a time.** Code can be further modified for calibrating multiple servos at a time.

### Requirements

- Make sure the hardware is properly connected and working.
- Make sure the index of the port where you connected the servo is known and is specified in the parameter.

### Required Arduino Libraries

- Adafruit PWM Servo Driver Library (v1.2.1)

### Hardware configuration

| AdaFruit PWM Servo Driver | Arduino Uno |
| ------------------------- | ----------- |
| VCC                       | 5V          |
| GND                       | GND         |
| SDA                       | A4          |
| SCL                       | A5          |

---

> Note: for now, Arduino is powered externally by PC, and PWM driver is powered by 5V converted source.

### Parameters

Adjust the following parameters for tuning the leg movement:

- `servonum`: index of the port on the PWM servo driver to which the servo is attached. Follow 0-indexing.
- `SERVOMIN`: Minimum PWM value for trial
- `SERVOMAX`: Maximum PWM value for trial

### IMPORTANT

After finding out the max and min values, **make sure to use these values in proper index in codes that need the max and min values of the servos.** The indices of the `SERVO_MIN` and `SERVO_MAX` arrays correspond to the index of Servo driver port (0-15).

> Feel free to contribute to the code by suggesting any bug fix or implementing new features (and make my efforts worth the pain of going through this tedious process of writing readme files :') )
