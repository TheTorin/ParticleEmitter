#ifndef PARTICLE_H
#define PARTICLE_H

// include
#include "Vect4D.h"

class Particle
{
public:
	friend class ParticleEmitter;
	
	Particle();	
	~Particle();

	void* operator new (size_t i) {
		return _mm_malloc(i, 16);
	}

	void operator delete(void* p) {
		_mm_free(p);
	}

	void Update(const float& time_elapsed);
	void CopyDataOnly( Particle *p );
private:

	Vect4D	position;
	Vect4D	velocity;
	Vect4D	scale;
	
	Vect4D	curr_Row0;
	Vect4D	curr_Row1;
	Vect4D  curr_Row2;
	Vect4D  curr_Row3;

	Particle *next;
	Particle *prev;

	float	rotation_velocity;
	float	rotation;
	float	life;
};


#endif //PARTICLE_H
