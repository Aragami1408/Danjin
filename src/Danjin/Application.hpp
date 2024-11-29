#pragma once

#include <Danjin/Common.h>

namespace Danjin {
class DANJIN_API Application {
	public:
		Application();
		virtual ~Application();

		void run();
};

Application *createApplication();
}
