#pragma once
#include <iostream>
#include "Type.h"

using namespace std;

namespace OpenGLSamples {
	namespace Based {

		//所有应用的抽象类
		class App {

		public:
			Type::win_info_s info;

		public:
			App();
			~App();

			bool init(int _width, int _height, string _title);

			void run();

			void close();

		private:

		};

	}
}
