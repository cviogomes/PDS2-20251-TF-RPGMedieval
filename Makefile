# Nome do compilador C++
CXX = g++

# Adicionamos -MMD e -MP para gerar arquivos de dependência (.d)
# Estes arquivos ajudam o Make a saber que precisa recompilar um .cpp se um .h que ele inclui for modificado.
CXXFLAGS = -std=c++17 -Wall -g -MMD -MP

# Diretórios
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INCLUDE_DIR = include

# Adiciona o diretório "include" ao caminho de busca do compilador
CXXFLAGS += -I$(INCLUDE_DIR)

# Nome do executável
EXECUTABLE = jogo_medieval
TARGET = $(BIN_DIR)/$(EXECUTABLE)

# Encontra todos os arquivos .cpp na pasta src/
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# Gera os nomes dos arquivos objeto na pasta obj/
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

# Gera os nomes dos arquivos de dependência na pasta obj/
DEPS = $(OBJECTS:.o=.d)

# Regra principal (padrão)
all: $(TARGET)

# Regra de linkagem
$(TARGET): $(OBJECTS)
	@echo "Ligando os objetos para criar o executável final..."
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Inclui os arquivos de dependência gerados.
# O traço na frente ignora erros se os arquivos ainda não existirem.
-include $(DEPS)

# Regra de compilação que lida com os diretórios
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "Compilando $<..."
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Regra de limpeza
clean:
	@echo "Limpando arquivos gerados..."
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# PHONY targets
.PHONY: all clean