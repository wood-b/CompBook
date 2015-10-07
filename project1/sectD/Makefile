CXX=g++-4.9
CXXFlags= -g -Wall -std=c++11

ODIR=objects

DEPS = RIS_model.h matrix.h chain_info.h constants.h

_OBJ = RIS_model.o RIS_polymer.o matrix.o chain_info.o constants.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFlags)

PEOmake: $(OBJ)
	g++-4.9 -o $@ $^ $(CXXFlags)


