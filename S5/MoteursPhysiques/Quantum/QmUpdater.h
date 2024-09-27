#ifndef QMUPDATER_H
#define QMUPDATER_H

#include <glm/glm.hpp>

namespace Quantum {

	class QmUpdater {
	public:
		QmUpdater() {};
		~QmUpdater() {};
		virtual void update(glm::vec3) = 0;

	protected:
		void* gxObject;
	};

}

#endif