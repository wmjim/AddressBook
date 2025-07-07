# 编译器
CXX = g++
# 编译选项
CXXFLAGS = -Wall -Wextra -std=c++17
# 源文件
SRCS = main.cpp address_book.cpp contact.cpp
# 目标文件
OBJS = $(SRCS:.cpp=.o)
# 可执行文件
TARGET = address_book

# 默认目标
all: $(TARGET)

# 链接目标文件生成可执行文件
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# 编译源文件生成目标文件
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理生成的文件
clean:
	rm -f $(OBJS) $(TARGET)