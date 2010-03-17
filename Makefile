CFLAGS			= -Wall
LDFLAGS 		= -lstdc++
BINDIR			= bin
SOURCEDIR		= src
PLOTDIR			= plot
EXECUTABLE 		= $(BINDIR)/exe
SOURCE			= $(wildcard $(SOURCEDIR)/*.cpp)
OBJECTS  		= $(addprefix $(BINDIR)/, $(addsuffix .o, $(basename $(notdir $(SOURCE)))))


$(EXECUTABLE) : $(OBJECTS)
	gcc $(LDFLAGS) -o $(EXECUTABLE) $(OBJECTS)


.PHONY: plot run xy
plot: $(EXECUTABLE)
	gnuplot $(PLOTDIR)/plot.gnu

xy: $(EXECUTABLE)
	gnuplot $(PLOTDIR)/xy.gnu

run: $(EXECUTABLE)
	./$(EXECUTABLE) | tee $(PLOTDIR)/data.out


$(BINDIR)/%.o : $(SOURCEDIR)/%.cpp
	gcc -o $@ -c $(CFLAGS) $<
	
$(BINDIR)/main.o: $(SOURCEDIR)/Pendulum.h $(SOURCEDIR)/Constants.h
$(BINDIR)/Pendulum.o: $(SOURCEDIR)/Object.h $(SOURCEDIR)/Pendulum.h $(SOURCEDIR)/Constants.h
$(BINDIR)/Object.o: $(SOURCEDIR)/Object.h $(SOURCEDIR)/Constants.h


clean:
	rm $(BINDIR)/*

