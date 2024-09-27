#ifndef GXPARTICLE_H
#define GXPARTICLE_H

#include <glm/glm.hpp>

class GxParticle {
public:
	GxParticle();
	GxParticle(glm::vec3 c, float rad, glm::vec3);
	~GxParticle();
	void setPos(glm::vec3);
	void setCol(glm::vec3);
	void setRad(float);
	glm::vec3 getPos();
	glm::vec3 getColor();
	float getRadius();

private:
	glm::vec3 position;
	glm::vec3 color;
	float radius;
};



#endif