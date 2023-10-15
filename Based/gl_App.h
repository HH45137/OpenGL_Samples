#pragma once
#include "App.h"
#include "Type.h"


namespace OpenGLSamples {
	namespace Based {

		//OpenGL App
		class GL_App : public App
		{
		public:
			Type::win_info_s info;

		public:
			GL_App();
			~GL_App();

			bool init(int _width, int _height, string _title);

			void run();

			void close();

		private:

		};
	}
}