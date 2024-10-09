CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
TARGET = megaphone
SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

# Rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files
clean:
	@rm -rf $(OBJS)

# Full clean (object files + executable)
fclean: clean
	@rm -rf $(TARGET)

# Rebuild (clean + all)
re: fclean all

# Phony targets to avoid confusion with files named 'clean', 'fclean', etc.
.PHONY: all clean fclean re
