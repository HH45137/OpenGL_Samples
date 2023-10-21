#pragma once
#include <iostream>

using namespace std;

namespace OpenGLSamples {
	namespace Based {

		//所有应用的抽象类
		class App {

		public:

			virtual bool init(int _width, int _height, string _title) = 0;

			virtual void run() = 0;

			virtual void close() = 0;

		public:

		private:

		};

	}
}
