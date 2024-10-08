#ifndef QMWORLD_H
#define QMWORLD_H

#include <list>
#include <vector>
#include <glm/vec3.hpp>
#include "QmForceRegistry.h"

namespace Quantum {

	class QmBody;

	class QmWorld {
	public:
		QmWorld();
		QmWorld(bool use_delta, float delta);
		~QmWorld();
		void simulate(float t);
		void addBody(QmBody*);
        void addForceRegistry(const QmForceRegistry &forceRegistry);
		[[nodiscard]] std::vector<QmBody*> getBodies() const;
		[[nodiscard]] std::vector<QmForceRegistry> getForceRegistry() const;
		[[nodiscard]] std::vector<QmForceRegistry> &getForceRegistry();

		void clear();

	private:
		float time = 0.0f;
		float tick_time = 0.0f;
		bool use_delta = false;
		float delta = 0.0f;
		std::vector<QmBody*> bodies;
        std::vector<QmForceRegistry> forceRegistries;
        const glm::vec3 gravity {0.0, -9.81, 0.0};

        void resetBodies();
		float tick(float t);
		void interpolate(float dt);
        void updateForces() const;
		void integrate(float);
	};

}

#endif