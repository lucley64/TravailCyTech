#include "GxUpdater.h"
#include "GxParticle.h"

GxUpdater::GxUpdater()
= default;

GxUpdater::GxUpdater(GxParticle* object)
{
	this->gxObject = object;
}


void GxUpdater::update(const glm::vec3 pos)
{
	static_cast<GxParticle*>(gxObject)->setPos(pos);
}


