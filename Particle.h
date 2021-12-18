#ifndef PARTICLE_H
#define PARTICLE_H

class Particle{
// coordinates will be public to avoid using getters each time we refresh the screen
public:
    double m_xcoord;
    double m_ycoord;
    Particle();
    ~Particle();
};



#endif