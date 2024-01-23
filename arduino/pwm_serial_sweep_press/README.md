# pwm_serial_sweep_press

An Arduino sketch for testing the servo movements and required angles for one leg. The leg is assumed to have 3 servos:

- **Shoulder servo (servo 0):** moves leg along the xy plane
- **Elbow servo (servo 1):** used for pressing the gripper on the surface.
- **Gripper servo (servo 2):** used for the release mechanism of the gripper.

### Requirements

- Make sure the hardware is properly connected and working.
- Make sure that the max, min PWM values for each servo is known and in proper index position. To calibrate the servos, run `servo_calibratin.ino`

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

| Servo    | AdaFruit PWM Servo Driver |
| -------- | ------------------------- |
| shoulder | 0                         |
| elbow    | 1                         |
| gripper  | 2                         |

---

> Note: for now, Arduino is powered externally by PC, and PWM driver is powered by 5V converted source.

### Parameters

Adjust the following parameters for tuning the leg movement:

- `SERVO_DIR`: change if you need to change the positive direction of the servo at that index. `1` for default direction, `-1` for flipped direction.
- `THETA1_INIT`: Angle of shoulder servo at startup
- `THETA2_INIT `: Angle of elbow servo at startup
- `THETA3_INIT`: Angle of gripper servo at startup
- `THETA1_FRONT_ANGLE`: Angle of shoulder servo when leg at front position
- `THETA1_BACK_ANGLE`: Angle of shoulder servo when leg at back position
- `THETA2_PRESSURE_ANGLE`: Angle of elbow servo when leg is pressing down
- `THETA2_RELEASE_ANGLE`: Angle of elbow servo when leg is pulling up
- `THETA3_PULL_ANGLE`: Angle of gripper servo needed to disengage the gripper
- `THETA3_RELEASE_ANGLE`: Angle of gripper servo to release the tension

### How to use

- Upload the code into Arduino and open up Serial Monitor at 9600 baud rate.
- Provide any random string input in the serial monitor to see an action performing.
- Actions will be performed each time an input is provided. Actions will repeat in alternating pattern. For example, first input will trigger forward leg movement. A second input afterwards will trigger backward leg movement, and so on.
  > NOTE: Sometimes an input may not trigger any action (due to reasons unknown). Waiting for a few seconds and trying again usually solves the problem. If it still does not work, restart the Arduino and restart the serial monitor.

> Feel free to contribute to the code by suggesting any bug fix or implementing new features (and make my efforts worth the pain of going through this tedious process of writing readme files :') )
