#include "utils.h"
#include <cmath>

int sgn(float val) {
    if(val >= 0) return 1;
    else return -1;
}

float deg_to_rad(float deg) {
    return deg * M_PI / 180;
}
