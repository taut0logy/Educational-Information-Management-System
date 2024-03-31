CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra

SRCS := main.cpp Teacher.cpp Course.cpp User.cpp Utility.cpp
OBJS := $(SRCS:.cpp=.o)
EXEC := educational_info_management_system

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del -f $(OBJS) $(EXEC)
