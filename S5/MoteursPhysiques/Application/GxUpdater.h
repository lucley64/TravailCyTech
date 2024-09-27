#ifndef MYGXUPDATER_H
#define MYGXUPDATER_H

#include "Quantum/Quantum.h"

class GxParticle;

class GxUpdater : public Quantum::QmUpdater {
public:
	GxUpdater();
	GxUpdater(GxParticle*);
	void update(glm::vec3);

private:
};

#endif


