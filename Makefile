# --- Ferramentas, Flags e diretórios---
CXX        := g++
INCLUDE_DIR:= include
CXXFLAGS   := -std=c++17 -Wall -g -MMD -MP -I$(INCLUDE_DIR)
LDFLAGS    := -lwinmm
SRC_DIR    := src
OBJ_DIR    := obj
BIN_DIR    := bin
TEST_DIR   := tests
COVERAGE_FLAGS := --coverage


# Executáveis
EXEC       := jogo_medieval.exe
TEST_EXE   := jogo_tests.exe

# Fontes e objetos
SOURCES    := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS    := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))
DEPS       := $(OBJECTS:.o=.d)

# Fontes de teste
TEST_SRCS  := $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJ   := $(TEST_SRCS:$(TEST_DIR)/%.cpp=$(OBJ_DIR)/%_test.o)
TEST_DEPS  := $(TEST_OBJ:.o=.d)

# --- Alvos Padrão ---
all: dirs $(BIN_DIR)/$(EXEC)

# --- Build do jogo ---
$(BIN_DIR)/$(EXEC): $(OBJECTS)
	@echo "[Link]  $@"
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# --- Build dos objetos genéricos ---
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | dirs
	@echo "[Comp]  $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# --- Build dos objetos de teste ---
$(OBJ_DIR)/%_test.o: $(TEST_DIR)/%.cpp | dirs
	@echo "[Comp]  $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# --- Link da suíte de testes ---
.PHONY: test
test: dirs $(OBJECTS) $(TEST_OBJ)
	@echo "[Link]  $(TEST_EXE)"
	$(CXX) $(CXXFLAGS) -o $(BIN_DIR)/$(TEST_EXE) $(filter-out $(OBJ_DIR)/main.o, $(OBJECTS)) $(TEST_OBJ) $(LDFLAGS)
	@echo "===== Executando testes ====="
	@$(BIN_DIR)/$(TEST_EXE)

# --- Inclui dependências automaticamente ---
-include $(DEPS) $(TEST_DEPS)

# --- Criação de diretórios ---
.PHONY: dirs
dirs:
ifeq ($(OS),Windows_NT)
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)
else
	@mkdir -p $(OBJ_DIR) $(BIN_DIR)
endif


# Alvo para build com cobertura
.PHONY: coverage
coverage: CXXFLAGS += $(COVERAGE_FLAGS)
coverage: LDFLAGS += $(COVERAGE_FLAGS)
coverage: clean all

# Alvo para gerar relatório gcovr (texto)
.PHONY: gcovr
gcovr:
	@py -m gcovr -r . > $(TEST_DIR)/gcovr.txt

# Alvo para gerar relatório gcovr (HTML)
.PHONY: gcovr-html
gcovr-html:
	@py -m gcovr -r . --html --html-details -o $(TEST_DIR)/cobertura.html
	
# --- Limpeza completa ---
.PHONY: clean
clean:
	@echo "[Clean] Removendo objetos, dependencias e binarios..."
ifeq ($(OS),Windows_NT)
	@if exist $(OBJ_DIR) del /q $(OBJ_DIR)\*.o $(OBJ_DIR)\*.d
	@if exist $(OBJ_DIR) del /q $(OBJ_DIR)\*.gcno $(OBJ_DIR)\*.d $(OBJ_DIR)\*.gcda
	@if exist $(BIN_DIR) del /q $(BIN_DIR)\*.exe
	@if exist $(TEST_DIR) del /q $(TEST_DIR)\*.html $(TEST_DIR)\*.css
	@if exist erros.log del erros.log
	
else
	@rm -rf $(OBJ_DIR)/* $(BIN_DIR)/*
endif
