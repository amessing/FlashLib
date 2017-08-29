# FlashLib
FlashLib is a robotics software development library for Java, originaly designed to improve and help FRC teams, but can work on other non-FRC platforms. Although currently available only for Java, we aim to make FlashLib available for C++ as well.

The latest version of FlashLib is 1.0.1

- [Features](#features)
- [Dependencies](#dependencies)
- [Building](#building)
- [Code Of Conduct](#code-of-conduct)
- [Contributing](#contributing)
- [Disclaimer](#disclaimer)

## Features

The library provides several different tools that can be both used for a robot development and for general softwares:
- Utilities Functions: Including a Log, array utilities, constants handling and data structures.
- Mathmetical Structures and Functionalities: Vectors, Matrices, Complex, Interpolations, Integrals, Differentials, etc.
- Communication Managment: Management of communications between two sides, including camera data communications and general communications, Interfacing with any port or bus: Ip sockets, Serial ports, SPI or I2C buses and more.
- Image Processing: A dynamic vision system which require little to no knowledge about image processing. Can interface with any image processing library, but openCV interfacing is already built-in. 
- Camera interfacing using openCV.
- Sensor and Motor Controllers Interfacing: Interfaing with motor controllers and sensors for Raspberry PI and BeagleBone Black platforms.
- Human Interface Devices Interfacing: Remote control of robots using Human Interfacing Devices.
- Control Station: Pre-Made control software for robots using Raspberry PI and BeagleBone Black platforms. (WIP)
- Action Scheduler: An action scheduling system to allow simple managment of robot system functionalities. Similar to the WPILib scheduling system but more sophisticated.
- Algorithms: Built-In sensor-based motion algorithms and vision-based motion algorithms.
- Generic Drive Systems: Built-in generic drive systems, including: Tank drive, Mecanum drive and Omni-Directional drive.
- Flashboard: A robot operator's sophisticated dashboard with build-in image processing and several tools for working with linux computer platforms.
- HAL: An Hardware Abstraction Layer with several built-in implementations. (WIP)

## Dependencies

FlashLib depends on several libraries for its functionalities:
- The openCV implementation of the vision system uses openCV 3.0.0
- The openCV implementation for camera interfacing uses openCV 3.0.0
- Robots working with the RoboRio platform require WPILib
- Flashboard requires openCV 3.0.0 and Jsch 0.1.54

All of those libraries are available in the "libs" folder of their respective parts.

## Building

Building the library requires gradle. 
To build the entire library, run the buildall script (bash for linux systems, batch for windows systems). 
To build an individual part, run the build script in that part's folder.

You can find the binary files in the "build/libs" folder in each part's directory. Flashboard binary files are located under 
flashboard/build/flashboard

You can get gradle here: https://gradle.org/ (for free of course..)

## Code Of Conduct

FlashLib is here to help the community in the development of robotics solutions, and thus supports an open and welcoming 
envirnoment for users and developers. We expect everyone to act with respect and according to our code of conduct.

Please see [CODE_OF_CONDUCT.md](CODE_OF_CONDUCT.md) for information about our code of conduct.

## Contributing

As an open-source project we readily welcome any one wanting to contribute. But in order to maintain organization we have a few
rules and guidelines for contributions.

Please see [CONTRIBUTING.md](CONTRIBUTING.md) if you are interested in contributing to this project.

## Disclaimer

FlashLib uses the following libraries, but those libraries do not belong to us:
- WPILib: WPILib is a robotics library for FRC teams created by the Worcester Polytechnic Institute: https://github.com/wpilibsuite/allwpilib
- OpenCV: OpenCV is an open source computer vision library: https://github.com/opencv/opencv
- JSCH: Jsch is a remote protocols library: http://www.jcraft.com/jsch/
