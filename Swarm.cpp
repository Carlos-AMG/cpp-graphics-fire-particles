#include "Swarm.h"

Swarm::Swarm(): pastTime(0){
    m_sParticles = new Particle[NPARTICLES];
}

Swarm::~Swarm(){
    delete [] m_sParticles;
}
void Swarm::update(int elapsed_time){
    int interval = elapsed_time - pastTime;
    for (int i = 0; i < Swarm::NPARTICLES; i++){
        m_sParticles[i].update_pos(interval);
    }
    pastTime = elapsed_time;
}