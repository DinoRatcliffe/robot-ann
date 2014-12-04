#### Make File ####
###################

CC = g++
CFLAGS = -g
SRCDIR = src
BINDIR = bin
PROGRAM = nnets

$(PROGRAM): $(SRCDIR)/$(PROGRAM).cpp
			$(CC) $(CFLAGS) -o $(BINDIR)/$(PROGRAM) $(SRCDIR)/*.cpp \
