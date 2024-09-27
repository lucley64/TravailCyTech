#ifndef QMPARTICLE_H
#define QMPARTICLE_H

#include <glm/glm.hpp>
#include "QmBody.h"


namespace Quantum {
	class QmUpdater;

	class QmParticle : public QmBody {
	public:
		QmParticle();
		QmParticle(glm::vec3 position, glm::vec3 velocity, glm::vec3 acceleration, float mass, int charge);
		~QmParticle() override;
		void integrate(float) final;

        void addForce(const glm::vec3 &force) override;

        void reset() override;

        glm::vec3 getAcc();
		glm::vec3 getVel();
		[[nodiscard]] glm::vec3 getPos() const;

        [[nodiscard]] int getCharge() const;

        [[nodiscard]] float getInvMass() const;

        void setUpdater(QmUpdater* updater);


	private:
		QmUpdater* updater = nullptr;
		glm::vec3 position;
		glm::vec3 velocity;
		glm::vec3 acceleration;
        glm::vec3 forceAccumulator{};
        int charge = 1;
        float invMass{};

		float damping{};

	};

}

#endif