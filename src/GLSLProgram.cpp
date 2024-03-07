#include "../headers/GLSLProgram.h"
#include "../headers/Errors.h"
#include <fstream>
#include <vector>

namespace rogue_engine {
GLSLProgram::GLSLProgram()
    : _numAttributes(0), _programID(0), _vertexShaderID(0),
      _fragmentShaderID(0) {}

GLSLProgram::~GLSLProgram() {}

void GLSLProgram::compileShaders(const std::string &vertexShaderFilePath,
                                 const std::string &fragmentShaderFilepath) {
  _vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
  if (_vertexShaderID == 0) {
    fatalError("Vertex Shader Failed To Be Created");
  }
  _fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
  if (_fragmentShaderID == 0) {
    fatalError("Fragment Shader Failed To Be Created");
  }
  compileShaders(vertexShaderFilePath, _vertexShaderID);
  compileShaders(fragmentShaderFilepath, _fragmentShaderID);
};

void GLSLProgram::linkShaders() {

  // Attach our shaders to our program
  glAttachShader(_programID, _vertexShaderID);
  glAttachShader(_programID, _fragmentShaderID);

  // Link our program
  glLinkProgram(_programID);

  // Note the different functions here: glGetProgram* instead of glGetShader*.
  GLint isLinked = 0;
  glGetProgramiv(_programID, GL_LINK_STATUS, (int *)&isLinked);
  if (isLinked == GL_FALSE) {
    GLint maxLength = 0;
    glGetProgramiv(_programID, GL_INFO_LOG_LENGTH, &maxLength);

    // The maxLength includes the NULL character
    std::vector<char> errorLog(maxLength);
    glGetProgramInfoLog(_programID, maxLength, &maxLength, &errorLog[0]);

    // We don't need the program anymore.
    glDeleteProgram(_programID);
    // Don't leak shaders either.
    glDeleteShader(_vertexShaderID);
    glDeleteShader(_fragmentShaderID);

    std::printf("%s\n", &(errorLog[0]));
    fatalError("Shaders failed to link");
  }

  // Always detach shaders after a successful link.
  glDetachShader(_programID, _vertexShaderID);
  glDetachShader(_programID, _fragmentShaderID);
  glDeleteShader(_vertexShaderID);
  glDeleteShader(_fragmentShaderID);
};

void GLSLProgram::addAttribute(const std::string &attributeName) {
  glBindAttribLocation(_programID, _numAttributes++, attributeName.c_str());
};

GLint GLSLProgram::getUniformLocation(const std::string &uniformName) {
  GLint location = glGetUniformLocation(_programID, uniformName.c_str());
  if (location == GL_INVALID_INDEX) {
    fatalError("Uniform " + uniformName + " not found in shader!");
  }
  return location;
};

// enable shader
void GLSLProgram::use() {
  glUseProgram(_programID);
  // enable all the attributes we added with addAttribute
  for (int i = 0; i < _numAttributes; i++) {
    glEnableVertexAttribArray(i);
  };
};

void GLSLProgram::unUse() {
  glUseProgram(0);
  for (int i = 0; i < _numAttributes; i++) {
    glDisableVertexAttribArray(i);
  };
};

void GLSLProgram::compileShaders(const std::string &filePath, GLuint id) {
  // Vertex and fragment shaders are successfully compiled.
  // Now time to link them together into a program.
  // Get a program object.
  _programID = glCreateProgram();

  std::ifstream vertexFile(filePath);
  if (vertexFile.fail()) {
    perror(filePath.c_str());
    fatalError("Failed To Open " + filePath);
  }
  std::string filecontents = "";
  std::string line;

  while (std::getline(vertexFile, line)) {
    filecontents += line + "\n";
  };
  vertexFile.close();

  const char *contentsPtr = filecontents.c_str();
  glShaderSource(id, 1, &contentsPtr, nullptr);

  glCompileShader(id);

  GLint success = 0;
  glGetShaderiv(id, GL_COMPILE_STATUS, &success);

  if (success == GL_FALSE) {
    GLint maxLength = 0;
    glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);

    // The maxLength includes the NULL character
    std::vector<char> errorLog(maxLength);
    glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);

    // Provide the infolog in whatever manor you deem best.
    // Exit with failure.
    glDeleteShader(id); // Don't leak the shader.

    std::printf("%s\n", &(errorLog[0]));
    fatalError("Shader " + filePath + " Failed To Compile");
  }
};
} // namespace rogue_engine
