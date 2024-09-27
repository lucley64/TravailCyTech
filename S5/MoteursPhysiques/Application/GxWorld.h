#ifndef GXWORLD_H
#define GXWORLD_H

#include <list>

class GxParticle;

class GxWorld {
public:
	GxWorld();
	~GxWorld();
	void addParticle(GxParticle*);
	std::list<GxParticle*> getParticles();
	void setParticles(std::list<GxParticle*>);

	void clear();

private:
	std::list<GxParticle*> particles;
};

#endif