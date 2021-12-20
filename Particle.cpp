#include "Particle.h"
#include <math.h>
#include <stdlib.h>
Particle::Particle(): m_ycoord(0), m_xcoord(0){
    m_direction =  (2 * M_PI * rand())/RAND_MAX;
    m_speed = (0.001 * rand())/RAND_MAX;
}
Particle::~Particle(){
    
}
void Particle::update_pos(int interval){
    double x_speed {m_speed * cos(m_direction)};
    double y_speed {m_speed * sin(m_direction)};
    m_xcoord += x_speed * interval;
    m_ycoord += y_speed * interval;
}