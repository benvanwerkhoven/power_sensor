ARCH=$(shell arch)
CXX=			g++
CXXFLAGS=		-std=c++11 -O2 -g -pthread -fopenmp

python:: PyPowerSensor.cc
			$(CXX) $(CXXFLAGS) -Wall -shared -fPIC `python3 -m pybind11 --includes` PyPowerSensor.cc -o power_sensor`python3-config --extension-suffix`

