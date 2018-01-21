 /**
    main.cpp
    MonEyeyeCpp - simple cpp skeleton.

    Copyright 2016 Monsenhor <filipo at kobkob.org>

    This file is part of MonEyeyeCpp.

    MonEyeyeCpp is free software: you can redistribute it and/or modify
    it under the terms of the GNU AFFERO GENERAL PUBLIC LICENSE as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    MonEyeyeCpp is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with MonEyeyeCpp.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <unistd.h>
#include <config.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>


#ifndef VERSION
#define VERSION 0.01
#endif

using namespace std;

void printUsage (char *ar) {
   fprintf(stderr, "Usage: %s [-d] \"description frase\" [-r \"XXX,XXX.XX\"] || [-p \"XXX,XXX.XX\" ] || [-t file]\n", ar);
}

/**
 * MonEyeyeCpp
 */
int main(int argc, char* argv[]) {
    cout << "MonEyeyeCpp " << VERSION << " - Copyleft GPL 3.0 by Monsenhor" << "\n\n";
    exit(EXIT_SUCCESS);
}


