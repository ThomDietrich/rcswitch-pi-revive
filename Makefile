#DEBUG		= -g -DDEBUG

CXXFLAGS	= $(DEBUG) -Wall -O2 -fPIC -DRPI

all: send receive sendTriState sendRev sendInter _rcswitch.so

send: RCSwitch.o send.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi
	
receive: RCSwitch.o receive.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi

sendTriState: RCSwitch.o sendTriState.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi

sendRev: RCSwitch.o sendRev.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi

sendInter: RCSwitch.o sendInter.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi

rcswitch_wrap.cxx: RCSwitch.h rcswitch.i
	swig -c++ -python rcswitch.i

rcswitch_wrap.o: rcswitch_wrap.cxx
	$(CXX) $(CXXFLAGS) -c $+ -o $@ -I/usr/include/python2.7

_rcswitch.so: rcswitch_wrap.o RCSwitch.o
	$(CXX) -shared $(LDFLAGS) $+ -o $@ -lwiringPi

clean:
	$(RM) *.o *.so *.pyc *.cxx send receive sendTriState sendRev sendInter

install:
	# Testing needed
	#cp send /usr/local/bin/send
	#mkdir -p /usr/lib/python2.7/dist-packages
	#cp rcswitch.py /usr/lib/python2.7/dist-packages
	#cp _rcswitch.so /usr/lib/python2.7/dist-packages
