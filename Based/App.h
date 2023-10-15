#pragma once
#include <iostream>
#include "Type.h"

using namespace std;

namespace OpenGLSamples {
	namespace Based {

		//����Ӧ�õĳ�����
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
