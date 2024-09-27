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
		~QmWorld();
		void simulate(float t);
		void addBody(QmBody*);
        void addForceRegistry(const QmForceRegistry &forceRegistry);
		[[nodiscard]] std::vector<QmBody*> getBodies() const;

		void clear();

	private:
		float time;
		std::vector<QmBody*> bodies;
        std::vector<QmForceRegistry> forceRegistries;
        const glm::vec3 gravity {0.0, -9.81, 0.0};

        void resetBodies();

        void updateForces();
		void integrate(float);
	};

}

#endif