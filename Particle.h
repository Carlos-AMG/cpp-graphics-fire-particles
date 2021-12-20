#ifndef PARTICLE_H
#define PARTICLE_H

class Particle{
// coordinates will be public to avoid using getters each time we refresh the screen
// we use polar coordinates to make the explosion effecto look as if particles explode from the centre of the screen (origin)
public:
    double m_speed; //speed of particles
    double m_direction; //angle of the particle
    double m_xcoord;
    double m_ycoord;
    void update_pos(int interval);
    Particle();
    ~Particle();
};



#endif