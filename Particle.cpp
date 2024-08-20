#include "Particle.h"
#include "Matrix.h"

Particle::Particle()
{
	// construtor
	this->life = 0.0f;
	this->position.set( 0.0f, 0.0f,  0.0f );
	this->velocity.set( 0.0f, 0.0f,  0.0f );
	this->scale.set( 1.0f, 1.0f, 1.0f );
	this->rotation = 0.0f;
	this->rotation_velocity = -0.75f;

}

Particle::~Particle()
{
	// nothing to do
}

void Particle::CopyDataOnly( Particle *p )
{
	// copy the data only
	// this way of copying data is more efficient that element by element
	this->position = p->position;
	this->velocity = p->velocity;
	this->scale    = p->scale;
	this->rotation = p->rotation;
	this->rotation_velocity = p->rotation_velocity;
	this->life     = p->life;
}

void Particle::Update(const float& time_elapsed)
{
	Matrix tmp;

	tmp.set(Matrix::MATRIX_ROW_0, &this->curr_Row0);
	tmp.set(Matrix::MATRIX_ROW_1, &this->curr_Row1);
	tmp.set(Matrix::MATRIX_ROW_2, &this->curr_Row2);
	tmp.set(Matrix::MATRIX_ROW_3, &this->curr_Row3);

	float MatrixScale = tmp.Determinant();

	// serious math below - magic secret sauce
	life += time_elapsed;
	position += (velocity * time_elapsed);
	Vect4D z_axis(0.0f, -0.25f, 1.0f);
	Vect4D v(3,4,0);
	position.Cross( z_axis, v);
	v.norm(v);
	position += (v * 0.05f * life);

	if( MatrixScale > 1.0f )
	{
		MatrixScale = 1.0f /MatrixScale;
	};

	rotation += (MatrixScale + rotation_velocity * time_elapsed * 2.01f);
}


// End of file


