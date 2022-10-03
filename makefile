compile:
	cd source ; g++ sha256.cpp RBFGen.cpp -o rbfgen ; g++ sha256.cpp IPCheck.cpp -o ipcheck
