# Maze-solving-robot

In this project I have devised a robot which will move from any position in a maze to any target point.The robot acts according to a code written purely in Arduino, 
which directs it to explore the maze containing random turns. The robot is autonomous and follows a derivative of wall following algorithm.

### Advantages of the project

Robots can be autonomous or semi-autonomous and range from humanoids such as Honda's Advanced Step in Innovative Mobility (ASIMO) and TOSY's TOSY Ping Pong Playing Robot (TOPIO) 
to industrial robots, medical operating robots, patient assist robots, dog therapy robots, collectively programmed swarm robots, UAV drones such as General Atomics MQ-1 Predator, 
and even microscopic nano-robots. By mimicking a lifelike appearance or automating movements, a robot may convey a sense of intelligence or thought of its own. Autonomous Things are 
expected to proliferate in the coming decade, with home robotics and the autonomous car as some of the main drivers.  

###### This built robot is an autonomous robot.

### Possible Solution

This problem can be solved using multiple algorithms such as: 
  * Wall follower algorithm
  * Pledge algorithm
  * Dead-end Filling
And many more.

###### For my project, I have used the Left-Hand algorithm to traverse the maze in the first pass and make the robot automatically move in the shortest distance in the second pass.

### OBJECTIVE

* #### Model Objectives: 
  The model should traverse the given maze, appropriately implementing the left-hand algorithm and learn the true shortest path when it reaches the end of the maze.
  During the second run of the robot, it should travel only on the calculated shortest path form the Start to the End.

* #### Real Life Practical Objectives:
  In a real life scenario, this algorithm can be set up in catastrophy-hit places (landslides, flooding, etc.) to find a way out of the affected location. Since it is nearly impossible 
  for living beings to find a way out themselves, these robots can easily overcome that problem as they can be modified to work on any terrain or weather conditions, yet using the same 
  algorithm to solve the problem.

### METHODOLOGY

#### Components Required
  * [Arduino UNO](#arduino-uno)
  * [L298N Motor Driver](#l298n-motor-driver)
  * [Infrared Sensor](#infrared-sensor)
  * [Ultrasonic Senor](#ultrasonic-sensor)
  * DC Geared Motors, 60rpm
  * 12V 3A Battery
  * Breadboard and jumper wires
  * 4 Wheel Chassis

#### Components Descriptions

* #### Arduino UNO
  The Arduino UNO is an open-source microcontroller board based on the Microchip ATmega328P microcontroller and developed by Arduino.cc. The board is equipped with 
  sets of digital and analog input/output (I/O) pins that may be interfaced to various expansion boards (shields) and other circuits. The board has 14 Digital pins, 
  6 Analog pins, and programmable with the Arduino IDE (Integrated Development Environment) via a type B USB cable. It can be powered by a USB cable or by an external 9 volt battery, 
  though it accepts voltages between 7 and 20 volts.
  
* #### L298N Motor Driver
  The L298N H-bridge module can be used with motors that have a voltage of between 5 and 35V DC. With the module used in this tutorial, there is also an onboard 5V regulator, 
  so if your supply voltage is up to 12V you can also source 5V from the board.
  
* #### Infrared Sensor
  An infrared sensor is an electronic instrument that is used to sense certain characteristics of its surroundings. It does this by either emitting or detecting infrared radiation. 
  Infrared sensors are also capable of measuring the heat being emitted by an object and detecting motion.

* #### Ultrasonic Sensor
  HC-SR04 Ultrasonic (US) sensor is a 4 pin module, whose pin names are Vcc, Trigger, Echo and Ground respectively. This sensor is a very popular sensor used in many applications where 
  measuring distance or sensing objects are required. The module has two eyes like projects in the front which forms the Ultrasonic transmitter and Receiver.

##### Any given perfect maze (without any loops) can be easily solved and traversed back in path using this algorithm.

###### note: Maze solving algorithm via left hand approach works for all but close looped mazes.

  
### Future Scope

  * The algorithm can be improved to include more ‘n’ junction-road variables and be able to solve a maze with known loops. 
  * The robot can be modified according to the terrain that it has to be used on. 
