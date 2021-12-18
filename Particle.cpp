#include "Particle.h"
#include <stdlib.h>
Particle::Particle(){
    m_xcoord = ((2.0 * rand())/RAND_MAX) - 1; // range from -1 to 1
    m_ycoord = ((2.0 * rand())/RAND_MAX) - 1; // range from -1 to 1
}
Particle::~Particle(){
    
}