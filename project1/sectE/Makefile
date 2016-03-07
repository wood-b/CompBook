CXX=g++-4.9
CXXFlags= -g -Wall -std=c++11

ODIR=objects

DEPS = matrix.h chain_info.h constants.h simulation.h cart_coord.h

_OBJ = matrix.o chain_info.o constants.o polymer_gen.o simulation.o cart_coord.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFlags)

PEOmake: $(OBJ)
	g++-4.9 -o $@ $^ $(CXXFlags)


