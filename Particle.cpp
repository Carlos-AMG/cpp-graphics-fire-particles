#include "Particle.h"
#include <math.h>
#include <stdlib.h>
Particle::Particle(): m_ycoord(0), m_xcoord(0){
    m_direction =  (2 * M_PI * rand())/RAND_MAX;
    m_speed = (0.04 * rand())/RAND_MAX;
    m_speed *= m_speed;
}
Particle::~Particle(){
    //destructor
}
void Particle::update_pos(int interval){
    m_direction += interval * 0.0004;
    double x_speed {m_speed * cos(m_direction)};
    double y_speed {m_speed * sin(m_direction)};
    m_xcoord += x_speed * interval;
    m_ycoord += y_speed * interval;
}