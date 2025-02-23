CXX=g++
CXXFLAGS=-g -Wall -std=c++11
# Uncomment for parser DEBUG
#DEFS=-DDEBUG

OBJS=amazon.o user.o db_parser.o product.o product_parser.o util.o my_ds.o book.o clothing.o movie.o
SELF_OBJS=amazon

all: amazon selftest_my_ds

amazon: $(OBJS)
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ $(OBJS)

amazon.o: amazon.cpp db_parser.h datastore.h product_parser.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c amazon.cpp
user.o: user.cpp user.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c user.cpp
db_parser.o: db_parser.cpp db_parser.h product.h product_parser.h user.h datastore.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c db_parser.cpp
product.o: product.cpp product.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c product.cpp
product_parser.o: product_parser.cpp product_parser.h product.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c product_parser.cpp
util.o: util.cpp util.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c util.cpp
# New implementations
my_ds.o: my_ds.cpp my_ds.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c my_ds.cpp
book.o: book.cpp book.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c book.cpp
clothing.o: clothing.cpp clothing.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c clothing.cpp
movie.o: movie.cpp movie.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c movie.cpp
# Self tests
selftest: $(SELF_OBJS)
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ $(SELF_OBJS)
selftest_book.o: selftest_book.cpp book.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c selftest_book.cpp
selftest_my_ds: selftest_my_ds.cpp my_ds.h datastore.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c selftest_my_ds.cpp $(OBJS)
clean:
	rm -f *.o amazon
