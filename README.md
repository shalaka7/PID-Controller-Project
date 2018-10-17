# PID Controller 

In this  project, I use a  PID controller , in order to drive a simulated car around a virtual track. 
The project involves ,

1. Implementing the controller primarily for the steering angle of the car 
2. Tuning coefficients for each PID value in order to calculate a steering angle that keeps the car on the track.

## Results / Reflection

A video of the simulated car driving around the track can be found here.

### Components of PID

"P" - The "P" for proportional means that the car will steer in proportion to the CTE.  CTE gives , as if the car is to the 
left of the line then you would want to steer to the right; if it is far to the left of the middle with a high CTE then you want 
a higher steering angle. If the coefficient is too low, the car may react too slowly to curves when the car gets 
off-center with a higher CTE and if we keep coefficient too high ,the car will constantly overshoot middle.


"I" -  The "I" for integral sums up all CTEs up to that point. If the coefficient is too high for I, the car tends to have
quicker oscillations, and does not tend to get up to a quick speed. A low coefficent for I will cause the car to tend 
to drift to one side of the lane or the other for longer periods of time.


"D" - The "D" for derivate is the change in CTE from one value to the next. This means that 1) if the derivative is 
quickly changing, the car will correct itself 2) if the car is moving outward from the middle, this will cause the steering 
to get larger  Too high of a coefficient leads to almost constant steering angle changes of large degrees, where although
the car will be well-centered it can hardly move. Too low of a D coefficient will lead to the oscillations being too high 
with more overshooting.

These  with what I was expecting.

### Finding the right coefficients

The final values were determined by manual tuning. The ratio of the coefficients to each other that I chose (0.2, 0.004, 3.0) 
seemed to work well, and I also tried lowering & raising them in conjunction with each other as well as tuning each individually.
I found that I was creating too high of steering angles (causing crashes if the speed had gotten too high on a straight) by 
raising them in conjunction with each other, while lowering all of them together meant the car struggled on the larger
curves, sometimes not turning enough and shooting off the track.
I had used Twiddle a little bit to try out different parameters, but found the values found in the project lessons to be sufficient 
under my current implementation. I had also used an approach with SGD (stochastic gradient descent) before, but that 
did not seem to perform as well as Twiddle. I ended up deciding against Twiddle as the results tended to vary greatly .


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
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.



## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 
