#include "Model.h"
#include <wavefront/wavefront.h>
#include <stdexcept>

Model::Model(const char* mSrc)
{
	

	if (WfModelLoad(mSrc, &ModelInUse) != 0)
	{
		throw std::runtime_error("Failed to load model");
	}
}

Model::~Model()
{
	WfModelDestroy(&ModelInUse);
}
