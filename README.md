## Find finite subgroups of matrix groups ![travis](https://api.travis-ci.org/robertzk/matrix-subgroup-finder.svg)

*Note: This project is in initial development and not currently functional.*

This is a C++ utility to find [finite matrix groups](https://en.wikipedia.org/wiki/Matrix_group)
over certain [number fields](https://en.wikipedia.org/wiki/Algebraic_number_field).
The subgroups considered fall within `GL(n, C)`, where `GL` represents the 
[general linear group](https://en.wikipedia.org/wiki/General_linear_group) and
`C` represents the complex numbers. Further improvements will support restricting
to the four classes of [classical groups](https://en.wikipedia.org/wiki/Classical_group):
the [orthogonal groups](https://en.wikipedia.org/wiki/Orthogonal_group), 
[unitary groups](https://en.wikipedia.org/wiki/Unitary_group),
[special linear groups](https://en.wikipedia.org/wiki/Special_linear_group),
and the [symplectic groups](https://en.wikipedia.org/wiki/Symplectic_group).

### Development

To get started, run the standard:

```bash
./configure && make && make install
```

**Later instructions will be added upon project progression.**

### License

This project is licensed under the MIT License:

Copyright (c) 2015-2016 Robert Krzyzanowski

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

### Authors

This library was created by Robert Krzyzanowski, technoguyrob@gmail.com.

