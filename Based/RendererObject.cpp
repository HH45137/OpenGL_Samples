#include "RendererObject.h"

namespace OpenGLSamples::Based {

	bool RendererObject::init()
	{
		if (!mesh->init()) {
			return false;
		}

		return true;
	}

	void RendererObject::close()
	{

	}

	RendererObject::RendererObject()
	{

	}

	RendererObject::~RendererObject()
	{

	}

}

