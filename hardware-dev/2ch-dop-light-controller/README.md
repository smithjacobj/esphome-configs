The files contained here are plans for a 2-channel 5v light controller using an ESP32-C3. They were
created in the free and open-source [KiCad](https://kicad.org)

![an image of the PCB](pcb.png?raw=true)

Known issues:
* The solder lugs for the outputs are slightly too small for the tinned "YETOR" connectors listed
  below. I ended up just whittling a little solder and some strands off before insertion.
* The footprint for the fuse mounts are not accurate and require some bending. The fuse mounts used
  are [these](https://www.amazon.com/dp/B08GSG1FNV), which hold APM/ATM/"mini-ATO" style blade
  fuses.
* These fuses also don't come in 2.5A, so I ended up using 2A fuses. It's unlikely you'll overdraw
  with 3 strings per channel; 1 30-light string draws only about 600mA peak. It's more to kill power
  if something shorts out.
* The current design has no reverse polarity protection. Check and check again!
* The "YETOR" connector wire colors are opposite the polarity for the light strings I connected, so do your due diligence on determining polarity there as well. 


There is also an STL file, 7mm_cable_gland.stl, which I created and printed in a urethane resin to
create water-resistant fittings for the project box for the
["YETOR Waterproof Connectors 2 Wire"](https://www.amazon.com/dp/B07WDBLFDN) and power cord to enter
through. It's set for a 3/4" hole (large enough to fit the low voltage connector heads through).

This is an amateur design! Use at your own risk!

THE DESIGN IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE DESIGN OR THE USE OR OTHER DEALINGS IN THE
DESIGN.
