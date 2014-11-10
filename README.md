# bee `basically eighty eighty`

[![Build Status](https://travis-ci.org/jacob-hegna/bee.svg?branch=master)](https://travis-ci.org/jacob-hegna/bee)

bee is an open source, BASIC interpreter/8080 compiler.  It started out as simply another implementation of the BASIC language, but with the dawn of my [`open8080`](https://github.com/jacob-hegna/open8080) project, it now has the expressed goal of compiling BASIC to 8080 bytecode.
## Usage
To interpret BASIC

```
bee -i main.bs
```

To compile to 8080 assembly

```
bee -o main.bs
```

To assemble the 8080 code

```
open8080 -a a.out
```

## Building
Clone the repo:

```
git clone https://github.com/jacob-hegna/bee
```

Move to the folder and build

```
cd bee
make
make install
```

It will install to `/usr/local/bin/bee`.

To remove `bee`, simply run `make remove`.

## Copyright and License
bee is Copyright 2013 Jacob Hegna.

This file is a part of bee.

bee is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program.  If not, see <http://www.gnu.org/licenses/>.
