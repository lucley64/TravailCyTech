#include "GxUpdater.h"
#include "GxParticle.h"

GxUpdater::GxUpdater()
{
}

GxUpdater::GxUpdater(GxParticle* object)
{
	this->gxObject = object;
}


void GxUpdater::update(glm::vec3 pos)
{
	((GxParticle*)gxObject)->setPos(pos);
}


