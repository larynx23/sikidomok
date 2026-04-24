CXX      := g++
CXXFLAGS := -Wall -Wextra -pedantic -std=c++11 -g
CPPFLAGS := -Iinclude

TARGET := sikidomok
SRCS := $(wildcard src/*.cpp)
OBJS := $(SRCS:.cpp=.o)
HEADERS := $(wildcard include/*.hpp)
PDFS := $(wildcard docs/*.pdf)
ZIP_NAME := $(TARGET)_src.zip
ZIP_FILES := $(HEADERS) $(SRCS) $(PDFS)

.PHONY: all clean zip

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@

src/%.o: src/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

zip:
	rm -f $(ZIP_NAME)
	zip -r $(ZIP_NAME) $(ZIP_FILES)
