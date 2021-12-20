#ifndef SWARM_H
#define SWARM_H
#include "Particle.h"


class Swarm{
private:
    Particle *m_sParticles;
    int pastTime;
public:
    static const int NPARTICLES = 5000;
    void update(int elapsed_time);
    Swarm();
    ~Swarm();
    const Particle * const getParticles() {return m_sParticles;}
};

#endif