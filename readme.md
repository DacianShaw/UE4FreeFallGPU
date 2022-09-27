# UE4 simulating 1000 cubes free fall with compute shader
This DEMO use compute shader to simulate free fall of  1024 cubes in UE4.

<img src="https://media.giphy.com/media/vFKqnCdLPNOKc/giphy.gif" width="900" height="450" />

### Impletion details
**1. Data Structures**
In this practice project, I use 2 32 x 32 pixels render targets to represent position and velocity of 1024 cubes(represented by static mesh).

**2. Calculation of position and velocity**
I applied computer shader to update velocity and position in this project. COompute shader is imported as a plugin, velocity and position information and read and wrote in 2 render targtes.

**3. Initialization**
Position render target is initialized by a noise texure, velocity render target is initialized by 0.


