# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)

## Reflection

Below i am going to briefly describe some of the steps i took in this project.

I started of by coding the various template functions in PID.cpp.
This was relatively straightforward and I essentially replicated the code/formula from the project lessons.

Thereafter, i had to call the Init, UpdateError and TotalError for the steering value.
After a lot of manual tuning I settled for the following values.

Kp = 0.15
Ki = 0.001
Kd = 2.75

As comments in the code, I still have other combinations that worked as well.

With the above values for steering PID, the car will not leave the track at all.

After this, I took notice of the fact that there was a comment in the code which said that another PID could be used.

I decided to use another PID for the throttle value. I was successful to some extent or so i believe.
I decided to cap my speed at 45 MPh. 

Again after some manual tuning i settled for the following values for the throttle PID.

Kp = 0.2
Ki = 0.01
Kd = 1.0

The issue with the throttle PID, is in the first quarter of lap 1,
the car accelerates to a very high speed of almost 75 Mph.
Thereafter, the car can go around any number of laps and the speed will be fixed at around 45 Mph.

I tried to fix this by tracking the speed.
Whenever the speed is more than 46 Mph, I cap the throttle value at 0.1
However, I got mixed results with this. This is something that I will need to work on later.

For the submission i commented out the above mentioned code snippet to avoid wild oscillations.
Though the second PID seems to work, i need to perfect it to avoid instability.
Things were more stable with just one PID for the steering value.