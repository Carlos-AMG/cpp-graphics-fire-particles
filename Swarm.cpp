#include "Swarm.h"

Swarm::Swarm(){
    m_sParticles = new Particle[NPARTICLES];
}

Swarm::~Swarm(){
    delete [] m_sParticles;
}
