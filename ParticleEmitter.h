#ifndef PARTICLEEMITTER_H
#define PARTICLEEMITTER_H

#include "Math\Matrix.h"
#include "Math\Vect4D.h"
#include "Particle.h"

#include <vector>

class ParticleEmitter
{
public:
	ParticleEmitter();
	~ParticleEmitter();
	
	void SpawnParticle();
	void update();
	void draw();

	void addParticleToList(Particle *p );
	void removeParticleFromList( Particle *p );

	void Execute(Vect4D& pos, Vect4D& vel, Vect4D& sc);

private:
	
	std::vector<Particle> drawBuffer;
	Vect4D	start_position;
	Vect4D	start_velocity;
	Vect4D	vel_variance;
	Vect4D	pos_variance;

	Particle *headParticle;
	
	float	max_life;
	int		max_particles;
	int		last_active_particle;
	float	spawn_frequency;
	float	last_spawn;
	float	last_loop;


	// added for speed efficiency
	int bufferCount;
	float	scale_variance;

};

#endif // PARTICLEEMITTER_H
