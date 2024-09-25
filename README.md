# Conv
A unit converter made in C++.
It intends to replace my habit of simply searching up every unit conversion on the Internet - why not just do it locally?

### How to use 
Conv uses command line arguments. Simply enter your value, unit to convert from, and unit to convert to, like so:

```./conv 40 m km```

If this feels a bit unnatural, you can use "to" in between:

```./conv 40 m to km```

Conv accepts a wide range of names for units. Abbreviations, full names, and plural forms all work!

Currently, Conv can convert lengths, times, and weights.

### How does it work?
This uses a vector of maps to do its thing. Each map contains a list of possible units and conversion vectors to them. However, some units have conflicting abbreviations! "m" could easily refer to both minutes or meters. So, both unit arguments are checked to make sure that they exist in the same map by iterating through the vector. If the other unit entered is "s", it can be concluded that "m" is referring to "minutes", and "s" to seconds, since these are both in the timeUnits map.

If this check fails and both units aren't found in the same map, you'll get an error.
